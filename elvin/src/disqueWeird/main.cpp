#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include <cmath>
    
int main()
{
    float pi {M_PI};
    float r {150.0f};

    sil::Image image{500/*width*/, 500/*height*/};
    float centreX {image.width()/2.0f};
    float centreY {image.height()/2.0f};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (
                ((x - centreX)*(x - centreX) + (y - centreY)*(x - centreX))
                <= r*r
            ) {
                image.pixel(x, y) = glm::vec3{1.0f};
            } else {
                image.pixel(x, y) = glm::vec3{0.0f};
            }

            // if ((y-250)*(y-250) + (x-250)*(x-250) <= 10000) {
            //     image.pixel(x,y).r = 1.f;
            //     image.pixel(x,y).g = 1.f;
            //     image.pixel(x,y).b = 1.f;
            // }
        }
    }
    

    image.save("output/pouet.png");
    image.save("final/disqueWeird.png");
}