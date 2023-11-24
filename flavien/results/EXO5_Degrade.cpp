#include <sil/sil.hpp>

int main ()
{
    sil::Image image{300, 200/};
    // TODO: modifier l'image
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        image.pixel(x, y).r = x/299.f;
        image.pixel(x,y).g = x/299.f;
        image.pixel(x, y).b = x/299.f;
        
    }
}
    image.save("output/pouet.png");
}