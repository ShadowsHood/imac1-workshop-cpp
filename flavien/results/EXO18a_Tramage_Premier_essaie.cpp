
#include <sil/sil.hpp>
#include "random.hpp"
int main()
{
    sil::Image image{"images/mains.jpg"};
    
    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        float total {};
        if ((x % 2 == 0) && (y % 2 == 0))
        {
            total = ((image.pixel(x,y).r + + image.pixel(x,y).b + image.pixel(x,y).g) / 3) + 0.1;
            if (total > 0.5)
            {
                image.pixel(x,y).r = 1.f;
                image.pixel(x,y).g = 1.f;
                image.pixel(x,y).b = 1.f; 
            }
            else if (total <= 0.5)
            {
                image.pixel(x,y).r = 0.f;
                image.pixel(x,y).g = 0.f;
                image.pixel(x,y).b = 0.f; 
            }
            
        }
        else if ((x % 3 == 0) && (y % 3 == 0))
        {
            total = ((image.pixel(x,y).r + image.pixel(x,y).b + image.pixel(x,y).g) / 3) - 0.1;
             if (total > 0.5)
            {
                image.pixel(x,y).r = 1.f;
                image.pixel(x,y).g = 1.f;
                image.pixel(x,y).b = 1.f; 
            }
            else if (total <= 0.5)
            {
                image.pixel(x,y).r = 0.f;
                image.pixel(x,y).g = 0.f;
                image.pixel(x,y).b = 0.f; 
            }
        }
        else 
        { 
            total = ((image.pixel(x,y).r + image.pixel(x,y).b + image.pixel(x,y).g) / 3);
             if (total > 0.5)
            {
                if ((x % 10 == 0) && (y % 10 == 0))
                {
                    image.pixel(x,y).r = 0.f;
                    image.pixel(x,y).g = 0.f;
                    image.pixel(x,y).b = 0.f; 
                }
                else
                { 
                image.pixel(x,y).r = 1.f;
                image.pixel(x,y).g = 1.f;
                image.pixel(x,y).b = 1.f; 
                }
            }
            else if ((total <= 0.5) && (total > 0.4))
            {
                 if ((x % 4 == 0) && (y % 4 == 0))
                {
                    image.pixel(x,y).r = 1.f;
                    image.pixel(x,y).g = 1.f;
                    image.pixel(x,y).b = 1.f; 
                }
                else
                { 
                image.pixel(x,y).r = 0.f;
                image.pixel(x,y).g = 0.f;
                image.pixel(x,y).b = 0.f; 
                }
            }
            else if ((total <= 0.4) && (total >= 0.25))
            {
                 if ((x % 5 == 0) && (y % 5 == 0))
                {
                    image.pixel(x,y).r = 1.f;
                    image.pixel(x,y).g = 1.f;
                    image.pixel(x,y).b = 1.f; 
                }
                else
                { 
                image.pixel(x,y).r = 0.f;
                image.pixel(x,y).g = 0.f;
                image.pixel(x,y).b = 0.f; 
                }
            }
            else 
            {
               image.pixel(x,y).r = 0.f;
                image.pixel(x,y).g = 0.f;
                image.pixel(x,y).b = 0.f;  
            }
        }
        
    }
}

image.save("output/pouet.png");
}