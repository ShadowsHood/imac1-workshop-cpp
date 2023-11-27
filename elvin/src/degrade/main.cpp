#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{300/*width*/, 200/*height*/};

    for (float x{0}; x < image.width(); x++) // On n'aime pas faire des boucles sur les float, car à cause des erreurs de précision lors de calculs entre float, il se pourrait que tu loupes une valeur de ta boucle, si les erreurs s'accumulent et dépassent 1. On préférera donc faire une boucle sur des int, et les static_cast en float au besoin lors de ton calcul x / image.width()
    {
        for (float y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = glm::vec3{x / (image.width() - 1)};
        }
    }

    image.save("output/pouet.png");
    image.save("final/degrade.png");
}