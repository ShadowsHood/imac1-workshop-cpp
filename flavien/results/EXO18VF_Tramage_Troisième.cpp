#include <sil/sil.hpp>
#include "random.hpp"
int main()
{
    sil::Image image{"images/mains.jpg"};
    sil::Image image2{1500, 1500};
    double total {};
    set_random_seed(1);
    int UnSurDeux {};
    // TODO: modifier l'image

   for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {   
            UnSurDeux = random_int(1,3);
            if (UnSurDeux == 1)
                { 
                image.pixel(x,y).r += 0.02;
                image.pixel(x,y).g += 0.02;
                image.pixel(x,y).b += 0.02;
                }
            if (UnSurDeux == 2)
                {
                image.pixel(x,y).r -= 0.02;
                image.pixel(x,y).g -= 0.02;
                image.pixel(x,y).b -= 0.02;
                }

        }
    }


    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {   
            
            total = (((image.pixel(x,y).r + + image.pixel(x,y).b + image.pixel(x,y).g) / 3));
                
                
             
                if ((total > 0.95) && (total <= 1))
                    {
                    image2.pixel(x,y).r = 1.f;
                    image2.pixel(x,y).g = 1.f;
                    image2.pixel(x,y).b = 1.f; 
                    }

                else if ((total > 0.9) && (total <= 0.95))
                    {
                    if (x % 10 == 0 && y % 10  == 0)
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    
                    }

                else if ((total > 0.85) && (total <= 0.9))
                    {
                    if ((x % 9 == 0 && y % 9 == 0) || (x % 10 == 0 && y % 10 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }


                else if ((total > 0.8) && (total <= 0.85))
                    {
                    if ((x % 8 == 0 && y % 8 == 0) || (x % 9 == 0 && y % 9 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f;  
                        }
                     else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }


                else if ((total > 0.75) && (total <= 0.8))
                    {
                    if ((x % 7 == 0 && y % 7 == 0) || (x % 8 == 0 && y % 8 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f;  
                        }
                     else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }

                
                else if ((total > 0.7) && (total <= 0.75))
                    {
                        if ((x % 6 == 0 && y % 6 == 0) || (x % 7 == 0 && y % 7 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f;  
                        }
                        else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }


                else if ((total > 0.65) && (total <= 0.7))
                    {
                        if ((x % 3 == 0 && y % 3 == 0) || (x % 6 == 0 && y % 6 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f;  
                        }
                        else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }


                else if ((total > 0.6) && (total <= 0.65))
                    {
                    if ((x % 4 == 0 && y % 4 == 0) || (x % 5 == 0 && y % 5 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f;  
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }


                else if ((total > 0.55) && (total <= 0.6))
                    {
                    if ((x % 3 == 0 && y % 3 == 0) || (x % 5 == 0 && y % 5 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f;  
                        }
                     else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }


                else if ((total > 0.5) && (total <= 0.55))
                    {
                    if ((x % 2 == 0 && y % 2 == 0))
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f;  
                        }
                     else 
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    }


                else if ((total > 0.45) && (total <= 0.5))
                    {
                    if ((x % 3 == 0 && y % 3 == 0) || (x % 4 == 0 && y % 4 == 0) || (x % 5 == 0 && y % 5 == 0) || (x % 6 == 0 && y % 6 == 0) || (x % 7 == 0 && y % 7 == 0) || (x % 8 == 0 && y % 8 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }

                else if ((total > 0.4) && (total <= 0.45))
                    {
                     if ((x % 3 == 0 && y % 3 == 0) || (x % 4 == 0 && y % 4 == 0) || (x % 5 == 0 && y % 5 == 0) | (x % 6 == 0 && y % 6 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                else if ((total > 0.35) && (total <= 0.4))
                    {
                    if ((x % 3 == 0 && y % 3 == 0) || (x % 4 == 0 && y % 4 == 0) || (x % 5 == 0 && y % 5 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }

                
                else if ((total > 0.3) && (total <= 0.35))
                    {
                    if ((x % 3 == 0 && y % 3 == 0) || (x % 4 == 0 && y % 4 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                else if ((total > 0.275) && (total <= 0.3))
                    {
                     if ((x % 3 == 0 && y % 3 == 0) || (x % 5 == 0 && y % 5 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }

                else if ((total > 0.25) && (total <= 0.275))
                    {
                     if (x % 3 == 0 && y % 3  == 0)
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                else if ((total > 0.2) && (total <= 0.25))
                    {
                     if ((x % 4 == 0 && y % 4 == 0) || (x % 5 == 0 && y % 5 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                else if ((total > 0.175) && (total <= 0.2))
                    {
                     if ((x % 4 == 0 && y % 4 == 0) || (x % 7 == 0 && y % 7 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }



                 else if ((total > 0.16) && (total <= 0.175))
                    {
                     if ((x % 4 == 0 && y % 4 == 0) || (x % 8 == 0 && y % 8 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }

                   else if ((total > 0.15) && (total <= 0.16))
                    {
                     if (x % 4 == 0 && y % 4  == 0)
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                else if ((total > 0.1) && (total <= 0.15))
                    {
                     if ((x % 5 == 0 && y % 5 == 0) || (x % 6 == 0 && y % 6 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }

                    else if ((total > 0.5) && (total <= 0.1))
                    {
                        if (x % 5 == 0 && y % 5  == 0)
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                    else if ((total > 0.25) && (total <= 0.5))
                    {
                         if ((x % 6 == 0 && y % 6 == 0) || (x % 7 == 0 && y % 7 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                     else if ((total > 0.05) && (total <= 0.1))
                    {
                         if (x % 6 == 0 && y % 6  == 0)
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                     else if ((total > 0.04) && (total <= 0.05))
                    {
                         if ((x % 7 == 0 && y % 7 == 0) || (x % 8 == 0 && y % 8 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }

                     else if ((total > 0.035) && (total <= 0.04))
                    {
                         if (x % 7 == 0 && y % 7  == 0)
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }

                    else if ((total > 0.03) && (total <= 0.035))
                    {
                         if ((x % 8 == 0 && y % 8 == 0) || (x % 9 == 0 && y % 9 == 0))
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
                        }
                    }


                    else if (total <= 0.03)
                    {
                         if (x % 8 == 0 && y % 8  == 0)
                        {
                            image2.pixel(x,y).r = 1.f;
                            image2.pixel(x,y).g = 1.f;
                            image2.pixel(x,y).b = 1.f; 
                        }
                    else 
                        {
                            image2.pixel(x,y).r = 0.f;
                            image2.pixel(x,y).g = 0.f;
                            image2.pixel(x,y).b = 0.f; 
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
    image2.save("output/pouet.png");
}