#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cmath>
#include <vector>

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

// TRI VERTICAL SUR LA LUMINANCE
void tri_vertical_lum (sil::Image& image, int max_iterations) {

    int width {image.width()};
    int height {image.height()};
    
    for (int x = 0; x < max_iterations; x++) {
        std::vector<glm::vec3> plage{};

        int col_index_to_sort {random_int(0, width - 1)};

        for (int y = 0; y < height; y++) {
            plage.push_back(image.pixel(col_index_to_sort, y));
        }

        std::sort(
            plage.begin(),
            plage.end(),
            [](const glm::vec3 &color1, const glm::vec3 &color2) {
                return brightness(color1) < brightness(color2);
            });

        for (int y = 0; y < height; y++) {
            image.pixel(col_index_to_sort, y) = plage[y];
        }
    }

}

// TRI HORIZONTAL SUR LA HUE/TEINTE
void tri_horizontal_hue (sil::Image& image, int max_iterations) {

    int width {image.width()};
    int height {image.height()};

    for (int index {0}; index < max_iterations; index++)
    {
        int row_index_to_sort {random_int(0, height)};

        // HUE
        std::sort(
            image.pixels().begin() + (row_index_to_sort * width), 
            image.pixels().begin() + (row_index_to_sort * width) + width, 
            [](const glm::vec3& color1, const glm::vec3& color2) {
                if (rgbToHsl(color1).x == rgbToHsl(color2).x) {
                    return rgbToHsl(color1).z < rgbToHsl(color2).z;
                }
                return rgbToHsl(color1).x < rgbToHsl(color2).x;
        });
    }

}

int main()
{
    set_random_seed(666);

    sil::Image image{"images/logo.png"};

    int max_iterations {100};

    bool direction_first {0};
    int it_horizontal {0};
    int it_vertical {0};
    int nb_transfo {0};

    std::cout << "Voulez vous trier d'abord verticalement (0) ou horizontalement (1) : ";
    std::cin >> direction_first;

    std::cout << "Combien d'iterations voulez-vous effectuer horizontalement : ";
    std::cin >> it_horizontal;

    std::cout << "Combien d'iterations voulez-vous effectuer veticalement : ";
    std::cin >> it_vertical;

    std::cout << "Combien de fois voulez vous faire ces transformations : ";
    std::cin >> nb_transfo;
    
    for (int i = 0; i < nb_transfo; i++)
    {
        if (direction_first) {
            tri_horizontal_hue (image, it_horizontal);
            tri_vertical_lum (image, it_vertical);
        } else {
            tri_vertical_lum (image, it_vertical);
            tri_horizontal_hue (image, it_horizontal);
        }
    }



    image.save("output/pouet.png");
    image.save("final/tri.png");
}