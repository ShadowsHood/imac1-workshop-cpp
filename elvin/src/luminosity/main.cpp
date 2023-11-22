#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

int main()
{
    bool darken {0};
    std::cout << "Voulez vous assombrir (0) ou eclaircir (1) : ";
    std::cin >> darken;

    sil::Image image{"images/photo.jpg"};

    if (darken) {
        for (glm::vec3& color : image.pixels())
        {
            color.r = sqrtf(color.r);
            color.g = sqrtf(color.g);
            color.b = sqrtf(color.b);
        }
    } else {
        for (glm::vec3& color : image.pixels())
        {
            color.r *= color.r;
            color.g *= color.g;
            color.b *= color.b;
        }
    }

    image.save("output/pouet.png");
    image.save("final/luminosity.png");
}