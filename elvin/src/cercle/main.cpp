#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include <cmath>
    
int main()
{
    float const pi {M_PI}; // Pense à mettre des const aussi souvent que possible. Je ne vais pas faire la remarque partout, mais je pense que tu es capable de repérer les endroits où tu aurais pu en mettre.
    float const r {150.0f};

    sil::Image image{500/*width*/, 500/*height*/};
    float centreX {image.width()/2.0f};
    float centreY {image.height()/2.0f};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float calc {(x - centreX)*(x - centreX) + (y - centreY)*(y - centreY)}; // calc c'est un nom générique qui n'importe aucune info. Un nom plus clair aurait été "distance_au_carre" par exemple.
            if (
                calc <= r*r && calc >= (r-10)*(r-10)
            ) {
                image.pixel(x, y) = glm::vec3{1.0f};
            } else {
                image.pixel(x, y) = glm::vec3{0.0f};
            }
        }
    }
    

    image.save("output/pouet.png");
    image.save("final/cercle.png");
}