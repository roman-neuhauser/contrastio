#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

struct RGB
{
  RGB(uint8_t r, uint8_t g, uint8_t b)
  : r(r)
  , g(g)
  , b(b)
  {}
  uint8_t r, g, b;
};

RGB
make_RGB(std::string const &s)
{
  std::string sr, sg, sb;
  if (s.size() == 3) {
    sr = s.substr(0, 1); sr = sr + sr;
    sg = s.substr(1, 1); sg = sg + sg;
    sb = s.substr(2, 1); sb = sb + sb;
  } else {
    sr = s.substr(0, 2);
    sg = s.substr(2, 2);
    sb = s.substr(4, 2);
  }
  auto r = std::stoul(sr, 0, 16);
  auto g = std::stoul(sg, 0, 16);
  auto b = std::stoul(sb, 0, 16);
  return RGB(r, g, b);
}

struct sRGB
{
  sRGB(RGB const &rgb)
  : r(float(rgb.r) / 255)
  , g(float(rgb.g) / 255)
  , b(float(rgb.b) / 255)
  {}
  float const r, g, b;
};

auto
weight(float s)
{
  return s <= 0.03928
    ? s / 12.92
    : std::pow(((s + 0.055) / 1.055), 2.4)
  ;
}

auto
relative_luminance(sRGB const &c)
{
  auto R = weight(c.r);
  auto G = weight(c.g);
  auto B = weight(c.b);
  return 0.2126*R + 0.7152*G + 0.0722*B;
}

int
main(int argc, char **argv)
{
  if (argc != 3) {
    std::cerr << "usage: contrastio CSS1 CSS2" << std::endl;
    return 111;
  }

  auto c1 = std::string(argv[1]);
  auto c2 = std::string(argv[2]);

  if (c1.at(0) == '#')
    c1 = c1.substr(1);
  if (c2.at(0) == '#')
    c2 = c2.substr(1);

  auto Lx = relative_luminance(sRGB(make_RGB(c1)));
  auto Ly = relative_luminance(sRGB(make_RGB(c2)));

  auto L1 = std::max(Lx, Ly);
  auto L2 = std::min(Lx, Ly);

  std::cout << ((L1 + 0.05) / (L2 + 0.05)) << std::endl;
  return 0;
}
