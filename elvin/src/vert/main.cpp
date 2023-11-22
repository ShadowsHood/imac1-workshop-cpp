#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};

    // // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    // for (int x{0}; x < image.width(); x++)
    // {
    //     for (int y{0}; y < image.height(); y++)
    //     {
    //         image.pixel(x, y).r = 0.f;
    //     }
    // }

    // Ou alors, si on n'a pas besoin de connaître le x et le y, on a une syntaxe plus concise pour itérer sur tous les pixels :
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }

    image.save("output/pouet.png");
    image.save("final/vert.png");
}