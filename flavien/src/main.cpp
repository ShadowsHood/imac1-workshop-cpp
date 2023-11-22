#include <sil/sil.hpp>

/* EXO 1 Ne garder que le vert

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    for (glm::vec3& color : image.pixels())
{
    color.r = 0.f;
    color.b = 0.f;
}
    image.save("output/pouet.png");
}
*/




/* EXO 2  Échanger les canaux

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    for (glm::vec3& color : image.pixels())
{
    std::swap (color.r, color.b);
}
    image.save("output/pouet.png");
}
*/




/* EXO 3 Noir & Blanc


int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
 
    for (glm::vec3& color : image.pixels())
{
    float total {};
    total = (color.r + color.b + color.g) / 3;
    color.r = total;
    color.b = total;
    color.g = total;
}
    image.save("output/pouet.png");
}
*/





/* EX0 4  Négatif


int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
 
    for (glm::vec3& color : image.pixels())
{
    color.r = 1 - color.r;
    color.b = 1 - color.b;
    color.g = 1 - color.g;
}
    image.save("output/pouet.png");
}
*/





/* EXO 5 Dégradé


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

*/





/* EXO 6  Miroir


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

*/


/* EX0 7 Image bruitée

#include "random.hpp"

int main()
{
    set_random_seed(1);
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    int Nombre {};
    int Nombre2 {};
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
    Nombre = random_float (0, 10);
    Nombre2 = random_float (0,10);
    if (Nombre + Nombre2 == 2)
    {
    image.pixel(x, y).r = 1;
    image.pixel(x, y).g = 0;
    image.pixel(x, y).b = 0;
    }

    if (Nombre + Nombre2 == 1)
    {
    image.pixel(x, y).r = 0;
    image.pixel(x, y).g = 1;
    image.pixel(x, y).b = 0;
    }

    if (Nombre + Nombre2 == 0)
       {
    image.pixel(x, y).r = 0;
    image.pixel(x, y).g = 0;
    image.pixel(x, y).b = 1;
    }
    }
}
    image.save("output/pouet.png");
}

*/


/* EXO8 Rotation de 90°


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
*/


/* EXO9 RGB Split



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
*/


/* EXO 10 Luminosité - Assombrir 
#include <math.h>
int main ()
{
     sil::Image image{"images/photo.jpg"};
     
     
    // TODO: modifier l'image
 
     for (glm::vec3& color : image.pixels())
{
    color.r *= color.r;
    color.b *= color.b;
    color.g *= color.g;
}
    image.save("output/pouet.png");
}
*/

/*  EXO 10 Luminosité - Eclaircire    
#include <math.h>
int main ()
{
     sil::Image image{"images/photo.jpg"};
     
     
    // TODO: modifier l'image
 
     for (glm::vec3& color : image.pixels())
{
    color.r = sqrt(color.r);
    color.b *= sqrt(color.b);
    color.g *= sqrt(color.g);
}
    image.save("output/pouet.png");
}
*/





/* EXO 11 DISQUE

int main ()
{
    sil::Image image{500, 500};
     
     
    // TODO: modifier l'image
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {   
        if ((y-250)*(y-250) + (x-250)*(x-250) <= 10000)
        {
        image.pixel(x,y).r = 1.f;
        image.pixel(x,y).g = 1.f;
        image.pixel(x,y).b = 1.f;
        }
    }
}
    image.save("output/pouet.png");
}
*/






/* EXO 12 Cercle

int main ()
{
    sil::Image image{500, 500};
    int thickness = 2000;
     
    // TODO: modifier l'image
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {   
        if (((y-250)*(y-250) + (x-250)*(x-250) <= 10000) && ((y-250)*(y-250) + (x-250)*(x-250) > 10000 - thickness))
        {
        image.pixel(x,y).r = 1.f;
        image.pixel(x,y).g = 1.f;
        image.pixel(x,y).b = 1.f;
        }
    }
}
    image.save("output/pouet.png");
}
*/




/* EX0 13 ROSACE

int main ()
{
    sil::Image image{500, 500};
    double pi = 3.141592653589793;
    int thickness = 1000;
     
     
    // TODO: modifier l'image
 
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {   
        if (((y-250)*(y-250) + (x-250)*(x-250) <= 10000) && ((y-250)*(y-250) + (x-250)*(x-250) > 10000 - thickness))
        {
        image.pixel(x,y).r = 1.f;
        image.pixel(x,y).g = 1.f;
        image.pixel(x,y).b = 1.f;
        }
    }
}

for (int a{0}; a <= 6; a++)
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {   
        if (((y- 250 - (100 * std::sin(a*pi/3)))*(y - 250 - (100 * std::sin(a*pi/3))) + (x- 250 - (100 * std::cos(a*pi/3)))*(x- 250 - (100 * std::cos(a*pi/3))) <= 10000)
        && ((y - 250 - (100 * std::sin(a*pi/3)))*(y - 250 - (100 * std::sin(a*pi/3))) + (x- 250 - (100 * std::cos(a*pi/3)))*(x- 250 - (100 * std::cos(a*pi/3))) > 10000 - thickness))
        {
        image.pixel(x,y).r = 1.f;
        image.pixel(x,y).g = 1.f;
        image.pixel(x,y).b = 1.f;
        }
    }
}

    image.save("output/pouet.png");
}
*/





/* EXO 14 MOSAÏQUE 
int main ()
{
    sil::Image image1{"images/logo.png"};
    sil::Image image2{1500, 1725};
    
    // TODO: modifier l'image
for (int x2{0}; x2 <image2.width(); x2 += 300 )
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
*/




/*   EXO 15 Mosaïque miroir 

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

*/



/* EXO 16 Glitch

#include "random.hpp"

int main()
{
    set_random_seed(3);
    sil::Image image{"images/logo.png"};
    sil:: Image image2{"images/logo.png"};
    // TODO: modifier l'image
    int Largeur {};
    int Longueur {};
    int x {};
    int y {};

    for (int a {0}; a < 100; a++)
    {
        x = random_int (1, 300);
        y = random_int (2, 345);
        Largeur = random_int (2, 150);
        Longueur = random_int (2, 30);

        
        for (int i {x}; i < Largeur + x; i++)
            {
            for (int j{y}; j < Longueur + y; j++)
                {
                if ((i+Longueur < 300 ) && (j+Longueur < 345))
                    { 
                    image2.pixel(i,j) = image.pixel(i+Largeur, j+Largeur);
                    }
                }
            }
        
    }
    image2.save("output/pouet.png");
}

*/








/* EXO 18 Fractale 



#include <complex>
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
*/