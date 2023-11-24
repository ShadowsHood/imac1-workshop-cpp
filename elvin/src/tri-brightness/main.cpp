#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cmath>

                // Convertir RGB en HSL
                glm::vec3 rgbToHsl(const glm::vec3& rgb) {
                    float minVal = std::min(std::min(rgb.r, rgb.g), rgb.b);
                    float maxVal = std::max(std::max(rgb.r, rgb.g), rgb.b);
                    float delta = maxVal - minVal;

                    float h = 0.0f;
                    float s = 0.0f;
                    float l = (maxVal + minVal) / 2.0f;

                    if (delta > 0.000001f && l > 0.2f) {
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

float brightness (glm::vec3 color) {
    return (color.r + color.g + color.b)/3.f;
}

int main()
{
    set_random_seed(666);

    sil::Image image{"images/logo.png"};

    int width {image.width()};
    int height {image.height()};


    // int max_iterations {100};
    for (int index {0}; index < height-1; index++)
    {
        // BRIGHTNESS
        std::sort(
            image.pixels().begin() + (index * width), 
            image.pixels().begin() + (index * width) + width, 
            [](const glm::vec3& color1, const glm::vec3& color2) {
            return brightness(color1) < brightness(color2);
        });

        // // HUE
        // std::sort(
        //     image.pixels().begin() + (index * width), 
        //     image.pixels().begin() + (index * width) + width, 
        //     [](const glm::vec3& color1, const glm::vec3& color2) {
        //         if (rgbToHsl(color1).x == rgbToHsl(color2).x) {
        //             return rgbToHsl(color1).z < rgbToHsl(color2).z;
        //         }
        //         return rgbToHsl(color1).x < rgbToHsl(color2).x;
        //     // return rgbToHsl(color1).z < rgbToHsl(color2).z;
        // });

    }
    



    image.save("output/pouet.png");
    image.save("final/tri-brightness.png");
}