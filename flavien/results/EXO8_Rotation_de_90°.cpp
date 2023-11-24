#include <sil/sil.hpp>

int main ()
{
     sil::Image image{"images/logo.png"};
     sil::Image image3{345, 300};
     
     
    // TODO: modifier l'image
 
for (int x{0}; x < image3.width(); x++)
{
    for (int y{0}; y < image3.height(); y++)
    {
        image3.pixel(x, y).r = image.pixel(y, image.height() - x - 1).r;
        image3.pixel(x, y).g = image.pixel(y, image.height() - x - 1).g;
        image3.pixel(x, y).b = image.pixel(y, image.height() - x - 1).b;
    }
}
    image3.save("output/pouet.png");
}