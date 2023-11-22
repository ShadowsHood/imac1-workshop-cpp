#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{"images/logo.png"};

    for (float y{0}; y < image.height()/2; y++)
    {
        for (float x{0}; x < image.width()/2; x++)
        {
            std::swap(image.pixel(x, y), image.pixel(image.width() - (x+1), image.height() - (y+1)) );
        }
    }

    image.save("output/pouet.png");
    image.save("final/miroirDouble.png");
}