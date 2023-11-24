#include "random.hpp"
#include <sil/sil.hpp>

int main()
{
    set_random_seed(3);
    sil::Image image{"images/logo.png"};
    sil:: Image image2{"images/logo.png"};
    // TODO: modifier l'image
    int Largeur {};
    int Longueur {};
    int x {};
    int y {};

    for (int a {0}; a < 100; a++)
    {
        x = random_int (1, 300);
        y = random_int (2, 345);
        Largeur = random_int (2, 150);
        Longueur = random_int (2, 30);

        
        for (int i {x}; i < Largeur + x; i++)
            {
            for (int j{y}; j < Longueur + y; j++)
                {
                if ((i+Longueur < 300 ) && (j+Longueur < 345))
                    { 
                    image2.pixel(i,j) = image.pixel(i+Largeur, j+Largeur);
                    }
                }
            }
        
    }
    image2.save("output/pouet.png");
}