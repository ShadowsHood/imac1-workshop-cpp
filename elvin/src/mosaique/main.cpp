#include <sil/sil.hpp>
#include <iostream>

int main()
{
    int nbrepeat {6};
    sil::Image image{"images/logo.png"};
    sil::Image imageIncrement {image.width()*nbrepeat, image.height()*nbrepeat};

    // for (float i = 0; i < nbrepeat; i++) {
    //     for (float j = 0; j < nbrepeat; j++) {

    //         for (float x {0}; x < image.width(); x++){
    //             for (float y {0}; y < image.height(); y++) {

    //                 imageIncrement.pixel(x+(image.width()*i), y+(image.height()*j)) = image.pixel(x, y);

    //             }
    //         }

    //     }
    // }

    for (int x {0}; x < imageIncrement.width(); x++) {
        for (int y {0}; y < imageIncrement.height(); y++) {
            imageIncrement.pixel(x, y) = image.pixel(x % image.width(), y % image.height());
        }
    }

    imageIncrement.save("output/pouet.png");
    imageIncrement.save("final/mosaique.png");
}