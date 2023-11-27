#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
 
    for (glm::vec3& color : image.pixels())
{
    color.r = 1 - color.r; // On peut écrire ça en une seule ligne : color = 1.f - color
    color.g = 1 - color.g; // glm définit tout plein d'opérations sur les couleurs, et ces opérations s'exécutent composante par composante
    color.b = 1 - color.b; // Vous auriez pu faire ça à plein d'endroits dans votre cas, je ne vais pas faire la remarque à chaque fois mais je pense que vous saurez identifier ces endroits.
}
    image.save("output/pouet.png");
}