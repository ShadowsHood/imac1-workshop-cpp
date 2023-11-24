#define _USE_MATH_DEFINES
#include <sil/sil.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // Pour std::accumulate
#include <random>   // Pour std::random_device et std::mt19937
#include <limits>
#include <cmath>

// Fonction pour trouver le centroïde le plus proche d'une couleur
glm::vec3 closestCentroid(const glm::vec3& color, const std::vector<glm::vec3>& centroids) {
    // Initialiser avec une distance maximale possible
    float minDistance = std::numeric_limits<float>::max();
    glm::vec3 closestCentroid;

    // Parcourir les centroïdes
    for (const auto& centroid : centroids) {
        // Calculer la distance entre la couleur cible et le centroïde
        float distance = glm::distance(color, centroid);

        // Mettre à jour le centroïde le plus proche
        if (distance < minDistance) {
            minDistance = distance;
            closestCentroid = centroid;
        }
    }

    return closestCentroid;
}

// Fonction pour effectuer l'algorithme K-means
std::vector<glm::vec3> kMeans(const std::vector<glm::vec3>& pixels, int k, int maxIterations) {
    // Initialisation aléatoire des centroïdes
    std::vector<glm::vec3> centroids;
    std::sample(pixels.begin(), pixels.end(), std::back_inserter(centroids), k, std::mt19937{std::random_device{}()});

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // Affecter chaque pixel au centroïde le plus proche
        std::vector<std::vector<glm::vec3>> clusters(k);
        for (const auto& pixel : pixels) {
            auto closest = std::min_element(centroids.begin(), centroids.end(), [&pixel](const auto& a, const auto& b) {
                return glm::distance(pixel, a) < glm::distance(pixel, b);
            });
            clusters[std::distance(centroids.begin(), closest)].push_back(pixel);
        }

        // Mettre à jour les centroïdes
        for (int i = 0; i < k; ++i) {
            if (!clusters[i].empty()) {
                glm::vec3 sum = std::accumulate(clusters[i].begin(), clusters[i].end(), glm::vec3(0.0f));
                centroids[i] = sum / static_cast<float>(clusters[i].size());
            }
        }
    }

    return centroids;
}

int main() {
    sil::Image image{"images/photo.jpg"};

    int color_number = 3;

    std::vector<glm::vec3> centroids = kMeans(image.pixels(), color_number, 10);

    for (glm::vec3& color : image.pixels()) {
        glm::vec3 newColor = closestCentroid(color, centroids);
        color = newColor;
    }

    image.save("output/pouet.png");
    image.save("final/kmeans-gpt.png");

    return 0;
}