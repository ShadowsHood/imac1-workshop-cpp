#include <sil/sil.hpp>
#include "random.hpp"
int main()
{
    sil::Image image{"images/mains.jpg"};
    set_random_seed(1);
    int UnSurNeuf {};
    int UnSurHuit {};
    int UnSurSept {};
    int UnSurVingtCinq {};
    int UnSurVingt {};
    int UnSurQuinze {};
    int UnSurDix {};
    int UnSurCinq {};

    
    for (int x{0}; x < image.width(); x++)
        {
        for (int y{0}; y < image.height(); y++)
            {
            float total {};
            if ((x % 2 == 0) && (y % 2 == 0))
            { 
            total = (((image.pixel(x,y).r + + image.pixel(x,y).b + image.pixel(x,y).g) / 3) + 0.1);
                
                
                if (total > 0.9)
                    {
                    image.pixel(x,y).r = 1.f;
                    image.pixel(x,y).g = 1.f;
                    image.pixel(x,y).b = 1.f; 
                    }


                else if ((total > 0.8) && (total <= 0.9))
                    {
                    UnSurVingt = random_int(1,21);
                    if (UnSurVingt == 1)
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


                else if ((total > 0.7) && (total <= 0.8))
                    {
                    UnSurQuinze = random_int(1,16);
                    if (UnSurQuinze == 1)
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


                else if ((total > 0.6) && (total <= 0.7))
                    {
                    UnSurDix = random_int(1,11);
                    if (UnSurDix == 1)
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

                
                else if ((total > 0.5) && (total <= 0.6))
                    {
                    UnSurCinq = random_int(1,6);
                    if (UnSurCinq == 1)
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


                else if ((total > 0.4) && (total <= 0.5))
                    {
                    UnSurDix = random_int(1,11);
                    if (UnSurDix == 1)
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


                else if ((total > 0.3) && (total <= 0.4))
                    {
                    UnSurQuinze = random_int(1,16);
                    if (UnSurQuinze == 1)
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


                else if ((total > 0.2) && (total <= 0.3))
                    {
                    UnSurVingt = random_int(1,21);
                    if (UnSurVingt == 1)
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


                else if ((total > 0.1) && (total <= 0.2))
                    {
                    UnSurVingtCinq = random_int(1,26);
                    if (UnSurVingtCinq == 1)
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


                else if (total <= 0.1)
                    {
                    image.pixel(x,y).r = 0.f;
                    image.pixel(x,y).g = 0.f;
                    image.pixel(x,y).b = 0.f; 
                    }
            }




        else if ((x % 3 == 0) && (y % 3 == 0))
            { 
            total = (((image.pixel(x,y).r + + image.pixel(x,y).b + image.pixel(x,y).g) / 3) - 0.1);
                
                
                if (total > 0.9)
                    {
                    image.pixel(x,y).r = 1.f;
                    image.pixel(x,y).g = 1.f;
                    image.pixel(x,y).b = 1.f; 
                    }


                else if ((total > 0.8) && (total <= 0.9))
                    {
                    UnSurVingt = random_int(1,21);
                    if (UnSurVingt == 1)
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


                else if ((total > 0.7) && (total <= 0.8))
                    {
                    UnSurQuinze = random_int(1,16);
                    if (UnSurQuinze == 1)
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


                else if ((total > 0.6) && (total <= 0.7))
                    {
                    UnSurDix = random_int(1,11);
                    if (UnSurDix == 1)
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

                
                else if ((total > 0.5) && (total <= 0.6))
                    {
                    UnSurCinq = random_int(1,6);
                    if (UnSurCinq == 1)
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


                else if ((total > 0.4) && (total <= 0.5))
                    {
                    UnSurDix = random_int(1,11);
                    if (UnSurDix == 1)
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


                else if ((total > 0.3) && (total <= 0.4))
                    {
                    UnSurQuinze = random_int(1,16);
                    if (UnSurQuinze == 1)
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


                else if ((total > 0.2) && (total <= 0.3))
                    {
                    UnSurVingt = random_int(1,21);
                    if (UnSurVingt == 1)
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


                else if ((total > 0.1) && (total <= 0.2))
                    {
                    UnSurVingtCinq = random_int(1,26);
                    if (UnSurVingtCinq == 1)
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


                else if (total <= 0.1)
                    {
                    image.pixel(x,y).r = 0.f;
                    image.pixel(x,y).g = 0.f;
                    image.pixel(x,y).b = 0.f; 
                    }
            }







            else if ( x % 10 == 0 && y % 10 == 0 && x % 9 == 0 && y % 9 == 0 && x % 8 == 0 && y % 8 == 0 && x % 7 == 0 && y % 7 == 0 && x % 6 == 0 && y % 6 == 0) 
            { 
            total = ((image.pixel(x,y).r + + image.pixel(x,y).b + image.pixel(x,y).g) / 3);
                
                
                if (total > 0.9)
                    {
                    image.pixel(x,y).r = 1.f;
                    image.pixel(x,y).g = 1.f;
                    image.pixel(x,y).b = 1.f; 
                    }


                else if ((total > 0.8) && (total <= 0.9))
                    {
                    
                    if (x % 10 == 0 && y % 10 == 0)
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


                else if ((total > 0.7) && (total <= 0.8))
                    {
                    if (x % 9 == 0 && y % 9 == 0)
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


                else if ((total > 0.6) && (total <= 0.7))
                    {
                    if (x % 8 == 0 && y % 8 == 0)
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

                
                else if ((total > 0.5) && (total <= 0.6))
                    {
                    if (x % 7 == 0 && y % 7 == 0)
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


                else if ((total > 0.4) && (total <= 0.5))
                    {

                    if (x % 7 == 0 && y % 7 == 0)
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


                else if ((total > 0.3) && (total <= 0.4))
                    {
                    if (x % 8 == 0 && y % 8 == 0)
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


                else if ((total > 0.2) && (total <= 0.3))
                    {
                    if (x % 9 == 0 && y % 9 == 0)
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


                else if ((total > 0.1) && (total <= 0.2))
                    {
                    if (x % 10 == 0 && y % 10 == 0)
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


                else if (total <= 0.1)
                    {
                    image.pixel(x,y).r = 0.f;
                    image.pixel(x,y).g = 0.f;
                    image.pixel(x,y).b = 0.f; 
                    }
            }





            else 
            { 
            total = (((image.pixel(x,y).r + + image.pixel(x,y).b + image.pixel(x,y).g) / 3) - 0.1);
                
                
                if (total > 0.9)
                    {
                    image.pixel(x,y).r = 1.f;
                    image.pixel(x,y).g = 1.f;
                    image.pixel(x,y).b = 1.f; 
                    }


                else if ((total > 0.8) && (total <= 0.9))
                    {
                    UnSurVingt = random_int(1,21);
                    if (UnSurVingt == 1)
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


                else if ((total > 0.7) && (total <= 0.8))
                    {
                    UnSurQuinze = random_int(1,16);
                    if (UnSurQuinze == 1)
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


                else if ((total > 0.6) && (total <= 0.7))
                    {
                    UnSurDix = random_int(1,11);
                    if (UnSurDix == 1)
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

                
                else if ((total > 0.5) && (total <= 0.6))
                    {
                    UnSurCinq = random_int(1,6);
                    if (UnSurCinq == 1)
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


                else if ((total > 0.4) && (total <= 0.5))
                    {
                    UnSurDix = random_int(1,11);
                    if (UnSurDix == 1)
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


                else if ((total > 0.3) && (total <= 0.4))
                    {
                    UnSurQuinze = random_int(1,16);
                    if (UnSurQuinze == 1)
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


                else if ((total > 0.2) && (total <= 0.3))
                    {
                    UnSurVingt = random_int(1,21);
                    if (UnSurVingt == 1)
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


                else if ((total > 0.1) && (total <= 0.2))
                    {
                    UnSurVingtCinq = random_int(1,26);
                    if (UnSurVingtCinq == 1)
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


                else if (total <= 0.1)
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
*/