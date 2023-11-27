#include "random.hpp"
#include <sil/sil.hpp>
int main()
{
    set_random_seed(1);
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    int Nombre2 {}; 
    float Nombre3 {};
    float Nombre4 {};
    float Nombre5 {};
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        // Si tes variables n'ont pas de nom pertinent (et en l'occurrence je suis d'accord que ce n'est pas la peine de leur en donner un) alors tu n'as pas besoin de stocker les valeurs de tes random dans des variables, tu peux les utiliser directement :
        if ( random_int (0,5) == 3)
    {
        image.pixel(x, y).r = random_float (0,1);
        image.pixel(x, y).g = random_float (0,1);
        image.pixel(x, y).b = random_float (0,1);
    }
    }
}
    image.save("output/pouet.png");
}