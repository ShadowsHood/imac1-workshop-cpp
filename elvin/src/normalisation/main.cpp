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

    float moyenne(float a, float b, float c) {
        return (a + b + c) / 3.0f;
    }

int main()
{

    sil::Image image{"images/photo_faible_contraste.jpg"};
    int width {image.width()};
    int height {image.height()};


    float brightest_pixel_c { 
        moyenne(image.pixel(0, 0).r, image.pixel(0, 0).g, image.pixel(0, 0).b)
    };

    float darkest_pixel_c {
        moyenne(image.pixel(0, 0).r, image.pixel(0, 0).g, image.pixel(0, 0).b)
    };

    for (int x{0}; x < width; x++)
    {
        for (int y{0}; y < height; y++)
        {
            float color {moyenne(image.pixel(x, y).r, image.pixel(x, y).g, image.pixel(x, y).b)};
            if (color > brightest_pixel_c) brightest_pixel_c = color;
            if (color < darkest_pixel_c) darkest_pixel_c = color;
        }
    }

    float middle_pixel_c {(brightest_pixel_c + darkest_pixel_c)/2};

    float plage_to_lighten {sqrtf((brightest_pixel_c - middle_pixel_c)*(brightest_pixel_c - middle_pixel_c))};

    float plage_to_darken {sqrtf((middle_pixel_c - darkest_pixel_c)*(middle_pixel_c - darkest_pixel_c))};

    for (int x{0}; x < width; x++)
    {
        for (int y{0}; y < height; y++)
        {
            float color {moyenne(image.pixel(x, y).r, image.pixel(x, y).g, image.pixel(x, y).b)};

            if (color > middle_pixel_c) {

                image.pixel(x, y).r += ((image.pixel(x, y).r - middle_pixel_c)/plage_to_lighten)*(1 - brightest_pixel_c);

                image.pixel(x, y).g += ((image.pixel(x, y).g - middle_pixel_c)/plage_to_lighten)*(1 - brightest_pixel_c);

                image.pixel(x, y).b += ((image.pixel(x, y).b - middle_pixel_c)/plage_to_lighten)*(1 - brightest_pixel_c);

            } else if (color < middle_pixel_c) {

                image.pixel(x, y).r -= ((middle_pixel_c - image.pixel(x, y).r)/plage_to_darken)*(darkest_pixel_c);

                image.pixel(x, y).g -= ((middle_pixel_c - image.pixel(x, y).g)/plage_to_darken)*(darkest_pixel_c);

                image.pixel(x, y).b -= ((middle_pixel_c - image.pixel(x, y).b)/plage_to_darken)*(darkest_pixel_c);

            } else {
                image.pixel(x, y) = image.pixel(x, y);
            }
        }
    }
    

    image.save("output/pouet.png");
    image.save("final/normalisation.png");
}