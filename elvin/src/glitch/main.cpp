#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"

int main()
{
    set_random_seed(666);
    // frequence à changer
    int freq {5};
    sil::Image image{"images/logo.png"};

    for (glm::vec3& color : image.pixels())
    {
        int rand_select {random_int(0, freq)};
        if (rand_select == 1)
        {
            int rand_color {random_int(0, 3)};
        }
    }


    image.save("output/pouet.png");
}