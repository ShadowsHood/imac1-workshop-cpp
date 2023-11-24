#include <sil/sil.hpp>

int main ()
{
     sil::Image imageReverseVertical{"images/logo.png"};
     sil::Image imageReverseHorizontal{"images/logo.png"};
     sil::Image imageReverseHorizontalEtVertical{"images/logo.png"};
     sil::Image image2{"images/logocopy.png"};
     sil::Image image3{1500, 1725};
     
     
    // TODO: modifier l'image
 
for (int x{0}; x < image2.width(); x++)
{
    for (int y{0}; y < image2.height(); y++)
    {
        imageReverseVertical.pixel(x, y) = image2.pixel(image2.width() - 1 - x,y);
        imageReverseHorizontal.pixel(x, y) = image2.pixel(x,image2.height() - 1 - y);
    } 
}
for (int x{0}; x < image2.width(); x++)
{
    for (int y{0}; y < image2.height(); y++)
    {
         imageReverseHorizontalEtVertical.pixel(x, y) = imageReverseHorizontal.pixel(image2.width() - 1 - x,y);
    } 
}

for (int x2{0}; x2 <image3.width(); x2 += 300 )
    {
        for (int y2{0}; y2<image3.height(); y2 += 345 )
        {
            for (int x1{x2}; x1 < image2.width() + x2 ; x1++)
                {
                    for (int y1{y2}; y1 < image2.height() +y2 ; y1++)

                    {
                        if ((x2 % 600 == 0 ) && (y2 % 690 == 0))
                        {
                            image3.pixel(x1,y1) = image2.pixel(x1 - x2,y1 - y2);
                        }
                        else if ((x2 % 300 == 0 ) && (x2 % 600 != 0 ) && (y2 % 690 == 0))
                        {
                            image3.pixel(x1,y1) = imageReverseVertical.pixel(x1 - x2,y1 - y2); 
                        }
                        else if ((x2 % 600 == 0 ) && (y2 % 345 == 0) && (y2 % 690 != 0 ) )
                        {
                            image3.pixel(x1,y1) = imageReverseHorizontal.pixel(x1 - x2,y1 - y2);
                        }
                        else if ((x2 % 300 == 0 ) && (x2 % 600 != 0 ) && (y2 % 345 == 0 ) && (y2 % 690 != 0 )  )
                        {
                            image3.pixel(x1,y1) = imageReverseHorizontalEtVertical.pixel(x1 - x2,y1 - y2);
                        }
                    }
                }        
   
        }   
    }   


    image3.save("output/pouet.png");
}