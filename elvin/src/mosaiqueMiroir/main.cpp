#include <sil/sil.hpp>
#include <iostream>

int main()
{
    int nbrepeat {6};
    sil::Image image{"images/logo.png"};
    sil::Image imageIncrement {image.width()*nbrepeat, image.height()*nbrepeat};
    
    // for (int i {0}; i < nbrepeat; i++) {
    //     for (int j {0}; j < nbrepeat; j++) {

    //         if (i % 2 == 0)
    //         {
    //             if (j % 2 == 0)
    //             {
    //                 for (int x {0}; x < image.width(); x++){
    //                 for (int y {0}; y < image.height(); y++) {
    //                         imageIncrement.pixel(x+(image.width()*i), y+(image.height()*j)) = image.pixel(x, y);
    //                 } }
    //             } else {
    //                 for (int x {0}; x < image.width(); x++){
    //                 for (int y {0}; y < image.height(); y++) {
    //                         imageIncrement.pixel(x+(image.width()*i), y+(image.height()*j)) = image.pixel(x, image.height() - (y+1));
    //                 } }
    //             }
    //         } else {
    //             if (j % 2 == 0)
    //             {
    //                 for (int x {0}; x < image.width(); x++){
    //                 for (int y {0}; y < image.height(); y++) {
    //                         imageIncrement.pixel(x+(image.width()*i), y+(image.height()*j)) = image.pixel(image.width() - (x+1), y);
    //                 } }
    //             } else {
    //                 for (int x {0}; x < image.width(); x++){
    //                 for (int y {0}; y < image.height(); y++) {
    //                         imageIncrement.pixel(x+(image.width()*i), y+(image.height()*j)) = image.pixel(image.width() - (x+1), image.height() - (y+1));
    //                 } }
    //             }
    //         }
    //     }
    // }

    for (int x {0}; x < imageIncrement.width(); x++) {
        for (int y {0}; y < imageIncrement.height(); y++) {

            int iterX {x/image.width()};
            int iterY {y/image.height()};

            if (iterX % 2 == 0)
            {
                if (iterY % 2 == 0)
                {
                    imageIncrement.pixel(x, y) = image.pixel(x % image.width(), y % image.height());
                }
                else
                {
                    imageIncrement.pixel(x, y) = image.pixel(x % image.width(), image.height() - 1 - (y % image.height()));
                }
            }
            else
            {
                if (iterY % 2 == 0)
                {
                    imageIncrement.pixel(x, y) = image.pixel(image.width() - 1 - (x % image.width()), y % image.height());
                }
                else
                {
                    imageIncrement.pixel(x, y) = image.pixel(image.width() - 1 - (x % image.width()), image.height() - 1 - (y % image.height()));
                }
            }
        }
    }

    imageIncrement.save("output/pouet.png");
}