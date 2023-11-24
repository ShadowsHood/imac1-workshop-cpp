#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cmath>
#include <glm/gtx/matrix_transform_2d.hpp>

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

int main()
{
    float pi {M_PI};
    set_random_seed(666);

    sil::Image image{"images/logo.png"};
    int width {image.width()};
    int height {image.height()};

    sil::Image imageOut{width, height};

    // glm::vec2 centre {0, 0};
    glm::vec2 centre {(width/2)-1, (height/2)-1};


    for (int x{0}; x < width; x++)
    {
        for (int y{0}; y < height; y++)
        {
            int distance_origine {static_cast<int>(sqrt((x-centre.x)*(x-centre.x) + (y-centre.y)*(y-centre.y)))};
            float angle {distance_origine*pi+random_float(-0.05f, 0.05f)};
            glm::vec2 new_coord {rotated(glm::vec2{x, y}, centre, angle)};
            new_coord.x = glm::round(new_coord.x);
            new_coord.y = glm::round(new_coord.y);
            if (new_coord.x >= 0 && new_coord.x <= width-1 && new_coord.y >= 0 && new_coord.y <= height-1) {
                imageOut.pixel(x, y) = image.pixel(new_coord.x, new_coord.y);
            }
        }
    }

    imageOut.save("output/pouet.png");
    // image.save("final/vortex.png");
}