#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
// #include "random.hpp"
#include <cmath>

                // Convertir RGB en HSL
                glm::vec3 rgbToHsl(const glm::vec3& rgb) {
                    float minVal = std::min(std::min(rgb.r, rgb.g), rgb.b);
                    float maxVal = std::max(std::max(rgb.r, rgb.g), rgb.b);
                    float delta = maxVal - minVal;

                    float h = 0.0f;
                    float s = 0.0f;
                    float l = (maxVal + minVal) / 2.0f;

                    if (delta != 0.0f) {
                        s = (l < 0.5f) ? (delta / (maxVal + minVal)) : (delta / (2.0f - maxVal - minVal));

                        if (rgb.r == maxVal) {
                            h = (rgb.g - rgb.b) / delta + ((rgb.g < rgb.b) ? 6.0f : 0.0f);
                        } else if (rgb.g == maxVal) {
                            h = (rgb.b - rgb.r) / delta + 2.0f;
                        } else if (rgb.b == maxVal) {
                            h = (rgb.r - rgb.g) / delta + 4.0f;
                        }

                        h /= 6.0f;
                    }

                    return glm::vec3(h, s, l);
                }

                // Convertir HSL en RGB
                glm::vec3 hslToRgb(const glm::vec3& hsl) {
                    float h = hsl.r;
                    float s = hsl.g;
                    float l = hsl.b;

                    float c = (1.0f - std::abs(2.0f * l - 1.0f)) * s;
                    float x = c * (1.0f - std::abs(std::fmod(h * 6.0f, 2.0f) - 1.0f));
                    float m = l - 0.5f * c;

                    float r, g, b;

                    if (h < 1.0f / 6.0f) {
                        r = c;
                        g = x;
                        b = 0.0f;
                    } else if (h < 2.0f / 6.0f) {
                        r = x;
                        g = c;
                        b = 0.0f;
                    } else if (h < 3.0f / 6.0f) {
                        r = 0.0f;
                        g = c;
                        b = x;
                    } else if (h < 4.0f / 6.0f) {
                        r = 0.0f;
                        g = x;
                        b = c;
                    } else if (h < 5.0f / 6.0f) {
                        r = x;
                        g = 0.0f;
                        b = c;
                    } else {
                        r = c;
                        g = 0.0f;
                        b = x;
                    }

                    return glm::vec3{r + m, g + m, b + m};
                }


int main()
{

    sil::Image image{"images/photo_faible_contraste.jpg"};
    int width {image.width()};
    int height {image.height()};


    float brightest_pixel_l {rgbToHsl(image.pixel(0, 0)).z};
    float darkest_pixel_l {rgbToHsl(image.pixel(0, 0)).z};

    for (int x{0}; x < width; x++)
    {
        for (int y{0}; y < height; y++)
        {
            glm::vec3 hsl_pixel {rgbToHsl(image.pixel(x, y))};
            if (hsl_pixel.z > brightest_pixel_l) brightest_pixel_l = hsl_pixel.z;
            if (hsl_pixel.z < darkest_pixel_l) darkest_pixel_l = hsl_pixel.z;
        }
    }

    float middle_pixel_l {(brightest_pixel_l + darkest_pixel_l)/2};
    float plage_to_lighten {sqrtf((brightest_pixel_l - middle_pixel_l)*(brightest_pixel_l - middle_pixel_l))};
    float plage_to_darken {sqrtf((middle_pixel_l - darkest_pixel_l)*(middle_pixel_l - darkest_pixel_l))};

    for (int x{0}; x < width; x++)
    {
        for (int y{0}; y < height; y++)
        {
            glm::vec3 hsl_pixel {rgbToHsl(image.pixel(x, y))};

            if (hsl_pixel.z > middle_pixel_l) {
                hsl_pixel.z += (sqrtf((hsl_pixel.z-middle_pixel_l)*(hsl_pixel.z-middle_pixel_l))/plage_to_lighten)*(1 - brightest_pixel_l);
                image.pixel(x, y) = hslToRgb(hsl_pixel);

            } else if (hsl_pixel.z < middle_pixel_l) {

                hsl_pixel.z -= (sqrtf((middle_pixel_l - hsl_pixel.z)*(middle_pixel_l - hsl_pixel.z))/plage_to_darken)*(darkest_pixel_l);
                image.pixel(x, y) = hslToRgb(hsl_pixel);

            }
        }
    }
    

    image.save("output/pouet.png");
    image.save("final/normalisation-lum.png");
}