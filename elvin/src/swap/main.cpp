#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};

    for (glm::vec3& color : image.pixels())
    {
        std::swap(color.r, color.b);
    }

    image.save("output/pouet.png");
    image.save("final/swap.png");
}