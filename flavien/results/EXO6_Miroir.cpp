#include <sil/sil.hpp>

int main ()
{
     sil::Image image{"images/logo.png"};
     sil::Image image2{"images/logocopy.png"};
     
     
    // TODO: modifier l'image
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        image.pixel(x, y).r = image2.pixel(image2.width() - 1 - x,y).r;
        image.pixel(x, y).g = image2.pixel(image2.width() - 1 - x,y).g;
        image.pixel(x, y).b = image2.pixel(image2.width() - 1 - x,y).b;
    }
}
    image.save("output/pouet.png");
}