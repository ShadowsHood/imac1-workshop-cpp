// #define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
// #include "random.hpp"
// #include <cmath>
#include <glm/gtx/matrix_transform_2d.hpp>

glm::vec2 rotated(glm::vec2 v, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{v, 1.f}};
}

int main()
{
    sil::Image image{"images/logo.png"};



    image.save("output/pouet.png");
    // image.save("final/vortex.png");
}