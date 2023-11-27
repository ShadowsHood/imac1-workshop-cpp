#include "random.hpp"

int main()
{
    set_random_seed(1);
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    int Nombre {};
    int Nombre2 {};
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
    Nombre = random_float (0, 10);
    Nombre2 = random_float (0,10);
    if (Nombre + Nombre2 == 2)
    {
    image.pixel(x, y).r = 1;
    image.pixel(x, y).g = 0;
    image.pixel(x, y).b = 0;
    }

    if (Nombre + Nombre2 == 1)
    {
    image.pixel(x, y).r = 0;
    image.pixel(x, y).g = 1;
    image.pixel(x, y).b = 0;
    }

    if (Nombre + Nombre2 == 0)
       {
    image.pixel(x, y).r = 0;
    image.pixel(x, y).g = 0;
    image.pixel(x, y).b = 1;
    }
    }
}
    image.save("output/pouet.png");
}
