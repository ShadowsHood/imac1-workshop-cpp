#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cmath>

float brightness (glm::vec3 color) {
    return (color.r + color.g + color.b)/3.f;
}

int main()
{
    set_random_seed(666);

    sil::Image image{"images/logo.png"};
    int width {image.width()};
    int height {image.height()};


    int max_iterations {100};
    for (int iter {0}; iter < max_iterations; iter++)
    {
        int row_index_to_sort {random_int(0, height)};

        // BRIGHTNESS
        std::sort(
            image.pixels().begin() + (row_index_to_sort * width), 
            image.pixels().begin() + (row_index_to_sort * width) + width, 
            [](const glm::vec3& color1, const glm::vec3& color2) {
            return brightness(color1) < brightness(color2);
        });

    }
    



    image.save("output/pouet.png");
    image.save("final/tri-random-brightness.png");
}