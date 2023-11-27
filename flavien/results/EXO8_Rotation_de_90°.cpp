#include <sil/sil.hpp>

int main ()
{
     sil::Image image{"images/logo.png"};
     sil::Image image3{345, 300}; // Utilise image.width() et image.height() au lieu de 345 et 300
     
     
    // TODO: modifier l'image
 
for (int x{0}; x < image3.width(); x++)
{
    for (int y{0}; y < image3.height(); y++)
    {
        image3.pixel(x, y) = image.pixel(y, image.height() - x - 1); // Tu peux assigner l'entièreté du glm::vec3 en une seule ligne
    }
}
    image3.save("output/pouet.png");
}