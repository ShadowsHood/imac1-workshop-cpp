#include <sil/sil.hpp>
int main ()
{
    sil::Image image{500, 500};
    int thickness = 2000;
     
    // TODO: modifier l'image
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {   
        if (((y-250)*(y-250) + (x-250)*(x-250) <= 10000) && ((y-250)*(y-250) + (x-250)*(x-250) > 10000 - thickness))
        {
        image.pixel(x,y).r = 1.f;
        image.pixel(x,y).g = 1.f;
        image.pixel(x,y).b = 1.f;
        }
    }
}
    image.save("output/pouet.png");
}