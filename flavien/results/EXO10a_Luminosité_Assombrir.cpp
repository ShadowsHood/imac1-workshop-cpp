#include <sil/sil.hpp>
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