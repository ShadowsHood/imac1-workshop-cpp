#include <sil/sil.hpp>
#include <iostream>

int main()
{
    int decalage {60};
    sil::Image image{"images/logo.png"};
    sil::Image imageGlitch{image.width()+decalage, image.height()};

    for (int x{0}; x < imageGlitch.width(); x++)
    {
        for (int y{0}; y < imageGlitch.height(); y++)
        {
            if(x < imageGlitch.width() - (1+decalage)) {
                imageGlitch.pixel(x, y).b = image.pixel(x, y).b;
                imageGlitch.pixel(x+(decalage/2), y).g = image.pixel(x, y).g;
                imageGlitch.pixel(x+decalage, y).r = image.pixel(x, y).r;
            }
        }
    }

    imageGlitch.save("output/pouet.png");
    imageGlitch.save("final/splitXcropped.png");
}