#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image imageOut{image.height(), image.width()};

    for (int x{0}; x < imageOut.width(); x++)
    {
        for (int y{0}; y < imageOut.height(); y++)
        {
            imageOut.pixel(x, y) = image.pixel(y,(image.height()-1)-x);
        }
    }

    imageOut.save("output/pouet.png");
}