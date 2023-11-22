#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{300/*width*/, 200/*height*/};

    for (float x{0}; x < image.width(); x++)
    {
        for (float y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = glm::vec3{x / (image.width() - 1)};
        }
    }

    image.save("output/pouet.png");
    image.save("final/degrade.png");
}