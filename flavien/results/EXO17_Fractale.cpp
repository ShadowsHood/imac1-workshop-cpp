#include <complex>
#include <sil/sil.hpp>

int main ()
{
    sil::Image image{1000, 1000};
  
    
    int x1 {};
    int y1 {};
    double x2 {};
    double y2 {};
    

    for ( double x{0}; x <4 ; x = x + 1.0/250)
    {
        for (double y{0}; y < 4; y = y + 1.0/250)
         {
                int x1 = static_cast<int>(x * 250);
                int y1 = static_cast<int>(y * 250);

            std::complex<double> z1 {0.0,0.0};
            std::complex<double> c {x-2,y-2};
            int compte {};

            for (int a{0}; a < 500; a++)
            {
                z1 = z1 * z1 + c;
                compte +=1;  
                if (std::abs(z1) > 2)
                {
                    double value = static_cast<double>(a)/ static_cast<double> (50);
                
                    image.pixel(x1,y1).r = value;
                    image.pixel(x1,y1).g = value;
                    image.pixel(x1,y1).b = value;
                    break;
                } 
            }
            if (compte == 500) 
            {
                image.pixel(x1,y1).r = 1.f;
                image.pixel(x1,y1).g = 1.f;
                image.pixel(x1,y1).b = 1.f;
            }
            
        }
    }
   
    // TODO: modifier l'image


    image.save("output/pouet.png");
}