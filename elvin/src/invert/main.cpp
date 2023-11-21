#include <sil/sil.hpp>

float invert(float number) {
    return 1 - number;
}

int main()
{
    sil::Image image{"images/logo.png"};

    for (glm::vec3& color : image.pixels())
    {
        color.r = invert(color.r);
        color.g = invert(color.g);
        color.b = invert(color.b);
    }

    image.save("output/pouet.png");
}