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
            imageOut.pixel(x, y) = image.pixel((image.width()-1)-y, (image.height()-1)-x);
            // std::swap(image.pixel(x, y), image.pixel((image.width()-1)-x, x));
        }
    }

    imageOut.save("output/pouet.png");
    imageOut.save("final/rotateWeird.png");
}