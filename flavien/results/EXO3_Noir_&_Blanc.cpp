#include <sil/sil.hpp>

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