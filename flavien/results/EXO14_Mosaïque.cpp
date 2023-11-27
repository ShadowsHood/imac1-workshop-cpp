#include <sil/sil.hpp>

int main ()
{
    sil::Image image1{"images/logo.png"};
    sil::Image image2{1500, 1725}; // utilise image1.width() * 5 et image1.height() * 5
    
    // TODO: modifier l'image
for (int x2{0}; x2 <image2.width(); x2 += 300 ) // Utilise image1.width() au lieu de 300
    {
        for (int y2{0}; y2<image2.height(); y2 += 345 )
        {
            for (int x1{x2}; x1 < image1.width() + x2 ; x1++)
                {
                    for (int y1{y2}; y1 < image1.height() +y2 ; y1++)

                    {
                        image2.pixel(x1,y1) = image1.pixel(x1 - x2,y1 - y2);
                    }
                }        
                
        }   
    }   

    image2.save("output/pouet.png");
}