#include <sil/sil.hpp>
#include <iostream>

int main()
{
    int decalage {30};
    sil::Image image{"images/logo.png"};
    sil::Image imageGlitch{image.width(), image.height()};

    for (int x{0}; x < imageGlitch.width(); x++)
    {
        for (int y{0}; y < imageGlitch.height(); y++)
        {
            imageGlitch.pixel(x, y).g = image.pixel(x, y).g;
            if (x < imageGlitch.width()-decalage) {
                imageGlitch.pixel(x, y).b = image.pixel(x+decalage, y).b;
                imageGlitch.pixel(x+decalage, y).r = image.pixel(x, y).r;
            } 
        }
    }

    imageGlitch.save("output/pouet.png");
    imageGlitch.save("final/split.png");
}