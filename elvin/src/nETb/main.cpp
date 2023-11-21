#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    
    for (glm::vec3& color : image.pixels())
    {
        float moy = (color.r + color.g + color.b)/3.0f;
        color.r = moy;
        color.g = moy;
        color.b = moy;
    }

    image.save("output/pouet.png");
}