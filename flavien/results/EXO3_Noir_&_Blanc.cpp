#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
 
    for (glm::vec3& color : image.pixels())
{
    float total { (color.r + color.b + color.g) / 3 }; // Au lieu de créer ta variable puis de l'initialiser à la ligne d'après, tu peux faire les deux en un
    color.r = total;
    color.b = total;
    color.g = total;
}
    image.save("output/pouet.png");
}