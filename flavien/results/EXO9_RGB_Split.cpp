#include <sil/sil.hpp>

int main ()
{
     sil::Image image{"images/logo.png"};
     sil::Image image2{"images/logocopy.png"};
     sil::Image image3{360, 345};
     sil::Image image4{360,345};
     sil::Image image5{300,345};
     
     
    // TODO: modifier l'image
 
for (int x{0}; x < image3.width(); x++)
{
    for (int y{0}; y < image3.height(); y++)
    {   
        
        if ((x < 330) && (x >= 31))
        {
        image3.pixel(x, y).r = image.pixel(x - 30 ,y).r;
        image3.pixel(x, y).g = image.pixel(x - 30,y).g;
        image3.pixel(x, y).b = image.pixel(x - 30,y).b;
        }
    }
}
for (int x{0}; x < image3.width(); x++)
{
    for (int y{0}; y < image3.height(); y++)
    {   
        if ((x > 30) && (x < 330))
        {
        image4.pixel(x, y).r = image3.pixel(x - 30 ,y).r;
        image4.pixel(x, y).g = image3.pixel(x,y).g;
        image4.pixel(x, y).b = image3.pixel(x + 30,y).b;
        }
    }
}
for (int x{0}; x < image3.width(); x++)
{
    for (int y{0}; y < image3.height(); y++)
    {   
        if ((x > 0) && (x < 300))
        {
        image5.pixel(x, y).r = image4.pixel(x + 30,y).r;
        image5.pixel(x, y).g = image4.pixel(x + 30,y).g;
        image5.pixel(x, y).b = image4.pixel(x + 30,y).b;
        }
    }
}
    image5.save("output/pouet.png");
}