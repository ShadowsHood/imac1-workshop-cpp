#include <sil/sil.hpp>
#include <iostream>

int main()
{
    int nbrepeat {3};
    sil::Image image{"images/logo.png"};
    sil::Image imageIncrement {image.width()*nbrepeat, image.height()*nbrepeat};

    // imageIncrement.pixel(x, y) = image.pixel(x, y);

    for (size_t i = 0; i < nbrepeat; i++)
    {
        for (float y{0}; y < image.height(); y++)
        {
            for (float x{0}; x < image.width(); x++)
            {
                imageIncrement.pixel(x + i*(image.width()-1), y + i*(image.height()-1)) = image.pixel(x, y);
                imageIncrement.pixel(x, y + i*(image.height()-1)) = image.pixel(x, y);
                imageIncrement.pixel(x + i*(image.width()-1), y) = image.pixel(x, y);
            }
        }
    }

    imageIncrement.save("output/pouet.png");
}