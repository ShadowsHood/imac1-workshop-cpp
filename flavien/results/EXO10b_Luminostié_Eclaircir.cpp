#include <sil/sil.hpp>
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