#######################################################################
                 Contrastio: Contrast Ratio Calculator
#######################################################################


*Contrastio* implements the contrast ratio formula laid out in WCAG20.

Resources
=========

* `Web Content Accessibility Guidelines (WCAG) 2.0`__
* `Understanding WCAG 2.0 - Contrast (Minimum): Understanding SC 1.4.3`__

.. __: https://www.w3.org/TR/WCAG20/
.. __: https://www.w3.org/TR/UNDERSTANDING-WCAG20/visual-audio-contrast-contrast.html


Definitions
===========

These are taken from WCAG.


contrast ratio
~~~~~~~~~~~~~~

source__

.. __: https://www.w3.org/TR/WCAG20/#contrast-ratiodef

::

	(L1 + 0.05) / (L2 + 0.05)
  
where

  * L1 is the relative luminance of the lighter of the colors, and

  * L2 is the relative luminance of the darker of the colors.

Note 1: Contrast ratios can range from 1 to 21 (commonly written 1:1 to 21:1).

Note 2: Because authors do not have control over user settings as to how text
is rendered (for example font smoothing or anti-aliasing), the contrast ratio
for text can be evaluated with anti-aliasing turned off.

Note 3: For the purpose of Success Criteria 1.4.3 and 1.4.6, contrast is
measured with respect to the specified background over which the text is
rendered in normal usage. If no background color is specified, then white is
assumed.

Note 4: Background color is the specified color of content over which the
text is to be rendered in normal usage. It is a failure if no background
color is specified when the text color is specified, because the user's
default background color is unknown and cannot be evaluated for sufficient
contrast. For the same reason, it is a failure if no text color is specified
when a background color is specified.

Note 5: When there is a border around the letter, the border can add contrast
and would be used in calculating the contrast between the letter and its
background. A narrow border around the letter would be used as the letter. A
wide border around the letter that fills in the inner details of the letters
acts as a halo and would be considered background.

Note 6: WCAG conformance should be evaluated for color pairs specified in the
content that an author would expect to appear adjacent in typical
presentation. Authors need not consider unusual presentations, such as color
changes made by the user agent, except where caused by authors' code.


relative luminance
~~~~~~~~~~~~~~~~~~

source__

.. __: https://www.w3.org/TR/WCAG20/#relativeluminancedef

the relative brightness of any point in a colorspace, normalized to 0 for
darkest black and 1 for lightest white

Note 1: For the sRGB colorspace, the relative luminance of a color is
defined as ::

  L = 0.2126 * R + 0.7152 * G + 0.0722 * B

where R, G and B are defined as::

    if RsRGB <= 0.03928 then R = RsRGB/12.92 else R = ((RsRGB+0.055)/1.055) ^ 2.4

    if GsRGB <= 0.03928 then G = GsRGB/12.92 else G = ((GsRGB+0.055)/1.055) ^ 2.4

    if BsRGB <= 0.03928 then B = BsRGB/12.92 else B = ((BsRGB+0.055)/1.055) ^ 2.4

and RsRGB, GsRGB, and BsRGB are defined as::

    RsRGB = R8bit/255

    GsRGB = G8bit/255

    BsRGB = B8bit/255

The "^" character is the exponentiation operator. (Formula taken from
[sRGB] and [IEC-4WD]).

Note 2: Almost all systems used today to view Web content assume sRGB
encoding. Unless it is known that another color space will be used to
process and display the content, authors should evaluate using sRGB
colorspace. If using other color spaces, see Understanding Success
Criterion 1.4.3.

Note 3: If dithering occurs after delivery, then the source color value is
used. For colors that are dithered at the source, the average values of the
colors that are dithered should be used (average R, average G, and average B).

Note 4: Tools are available that automatically do the calculations when
testing contrast and flash.

Note 5: A MathML version of the relative luminance definition is available. 
