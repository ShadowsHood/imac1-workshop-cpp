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
            switch (rand_color) {
                case 0:
                    color.r = 1.f;
                    color.g = 0.f;
                    color.b = 0.f;
                    break;
                case 1:
                    color.r = 0.f;
                    color.g = 1.f;
                    color.b = 0.f;
                    break;
                case 2:
                    color.r = 0.f;
                    color.g = 0.f;
                    color.b = 1.f;
                    break;
                
                default:
                    break;
            }
        }
    }

    image.save("output/pouet.png");
    image.save("final/bruit.png");
}