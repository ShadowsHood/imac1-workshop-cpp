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
                ((x - centreX)*(x - centreX) + (y - centreY)*(y - centreY))
                <= r*r
            ) {
                image.pixel(x, y) = glm::vec3{1.0f};
            } else {
                image.pixel(x, y) = glm::vec3{0.0f};
            }
        }
    }
    


    image.save("output/pouet.png");
}