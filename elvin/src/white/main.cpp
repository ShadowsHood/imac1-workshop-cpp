#include <sil/sil.hpp>

// bool zeroOrOne(float number) {
//     return (number >= 0.5f ? 1 : 0);
// }

int main()
{
    sil::Image image{"images/logo.png"};
    
    for (glm::vec3& color : image.pixels())
    {
        
        color.r += color.b + color.g;
        color.g = color.r;
        color.b = color.r;
    }

    image.save("output/pouet.png");
}