#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image imageIncrement {image.width()*2, image.height()*2};

    for (float y{0}; y < image.height(); y++)
    {
        for (float x{0}; x < image.width()/2; x++)
        {
            // sil::Image imageIncrement {imageIncrement.width()+image.width(), imageIncrement.height()+image.height()};
            imageIncrement.pixel(x, y) = image.pixel(x, y);
            imageIncrement.pixel(x + x*(image.width()-1), y + y*(image.height()-1)) = image.pixel(x, y);
            imageIncrement.pixel(x, y + y*(image.height()-1)) = image.pixel(x, y);
            imageIncrement.pixel(x + x*(image.width()-1), y) = image.pixel(x, y);
        }
    }

    image.save("output/pouet.png");
}