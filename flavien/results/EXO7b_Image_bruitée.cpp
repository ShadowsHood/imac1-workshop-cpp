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
        Nombre2 = random_int (0,5);
        Nombre3 = random_float (0,1);
        Nombre4 = random_float (0,1);
        Nombre5 = random_float (0,1);
        if ( Nombre2 == 3)
    {
        image.pixel(x, y).r = Nombre3;
        image.pixel(x, y).g = Nombre4;
        image.pixel(x, y).b = Nombre5;
    }
    }
}
    image.save("output/pouet.png");
}