#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"

int main()
{
    set_random_seed(30);
    sil::Image image{"images/logo.png"};

    for (int x{0}; x < image.width(); x++)
    {
        float divideMax {random_float(1, image.width()/2)};
        for (int y{0}; y < image.height()/divideMax; y++)
        {
            std::swap(image.pixel(x, y), image.pixel(y, x));
        }
    }

    image.save("output/pouet.png");
    image.save("final/virtualiser.png");
}