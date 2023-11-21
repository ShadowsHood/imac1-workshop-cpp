#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"

int main()
{
    set_random_seed(666);
    sil::Image image{"images/logo.png"};
    // sil::Image imageOut{image};

    int max_bloc_x {100};
    int max_bloc_y {10};

    // int iteration_glitch {random_int(10, 100)};
    int iteration_glitch {30};

    for (int i = 0; i < iteration_glitch; i++)
    {
        int rand_start_x {random_int(0, image.width()-(1+max_bloc_x))};
        int rand_end_x {random_int(rand_start_x, rand_start_x+max_bloc_x)};
        int rand_start_y {random_int(0, image.height()-(1+max_bloc_y))};
        int rand_end_y {random_int(rand_start_y, rand_start_y+max_bloc_y)};

        int rand_offset_x {random_int(0, image.width())};
        int rand_offset_y {random_int(0, image.height())};
        // avec restriction
        // int rand_offset_x {random_int(-rand_start_x, image.width()-1-(rand_end_x))};
        // int rand_offset_y {random_int(-rand_start_y, image.height()-1-(rand_end_y))};

        for (int x {rand_start_x}; x <= rand_end_x; x++)
        {
            for (int y {rand_start_y}; y <= rand_end_y; y++)
            {
                std::swap(image.pixel(x, y), image.pixel((x+rand_offset_x)%image.width(), (y+rand_offset_y)%image.height()) );
                // avec restriction
                // std::swap(image.pixel(x, y), image.pixel((x+rand_offset_x), (y+rand_offset_y)) );
            }
        }
    }

    image.save("output/pouet.png");
}