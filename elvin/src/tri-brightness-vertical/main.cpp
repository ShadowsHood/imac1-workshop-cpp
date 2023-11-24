#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cmath>
#include <vector>


float brightness (glm::vec3 color) {
    return (color.r + color.g + color.b)/3.f;
}

int main()
{
    set_random_seed(666);

    sil::Image image{"images/logo.png"};

    int width {image.width()};
    int height {image.height()};

    for (int x = 0; x < width; x++) {
        std::vector<glm::vec3> plage{};

        for (int y = 0; y < height; y++) {
            plage.push_back(image.pixel(x, y));
        }

        std::sort(
            plage.begin(),
            plage.end(),
            [](const glm::vec3 &color1, const glm::vec3 &color2) {
                return brightness(color1) < brightness(color2);
            });

        for (int y = 0; y < height; y++) {
            image.pixel(x, y) = plage[y];
        }
    }



    image.save("output/pouet.png");
    image.save("final/tri-brightness-vertical.png");
}