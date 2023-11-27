cmake_minimum_required(VERSION 3.20)

# You can set the name of your project here
project(ImageEditor)
# Download the sil library
include(FetchContent)
FetchContent_Declare(
    sil
    GIT_REPOSITORY https://github.com/JulesFouchy/Simple-Image-Lib
    GIT_TAG 89bd175cd55fb6daa9e99b218e869c3d516043f4
)
FetchContent_MakeAvailable(sil)
function(add_exercise FOLDER)
    add_executable(${FOLDER})

    # Choose your C++ version
    target_compile_features(${FOLDER} PRIVATE cxx_std_17)

    # Prevents compiler-specific extensions to C++ because they might allow code to compile on your machine but not on other people's machine
    set_target_properties(${FOLDER} PROPERTIES
        CXX_EXTENSIONS OFF)

    # Add all the source files
    file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/${FOLDER}/* lib/*)
    target_sources(${FOLDER} PRIVATE ${SOURCES})
    target_include_directories(${FOLDER} PRIVATE src/${FOLDER} lib)


    # Link sil into the project
    target_link_libraries(${FOLDER} PRIVATE sil)

endfunction(add_exercise)

add_exercise(white)
add_exercise(vert)
add_exercise(swap)
add_exercise(nETb)
add_exercise(invert)
add_exercise(degrade)
add_exercise(miroir)
add_exercise(miroirDouble)
add_exercise(bruit)
add_exercise(rotate90)
add_exercise(rotateWeird)
add_exercise(virtualiser)
add_exercise(split)
add_exercise(splitXcropped)
add_exercise(luminosity)
add_exercise(disque)
add_exercise(cercle)
add_exercise(rosace)
add_exercise(disqueWeird)
add_exercise(mosaique)
add_exercise(mosaiqueMiroir)
add_exercise(glitch)
add_exercise(fractale)
add_exercise(vortex)
add_exercise(vortex-fail-1)
add_exercise(vortex-fail-2)
add_exercise(vortex-fail-3)
add_exercise(vortex-fail-4)
add_exercise(vortex-fail-5)
add_exercise(vortex-fail-6)
add_exercise(vortex-fail-7)
add_exercise(vortex-fail-8)
add_exercise(vortex-fail-9)
add_exercise(vortex-fail-10)
add_exercise(vortex-fail-11)
add_exercise(normalisation)
add_exercise(normalisation-lum)
add_exercise(tri)
add_exercise(tri-double)
add_exercise(tri-brightness)
add_exercise(tri-brightness-all)
add_exercise(tri-brightness-vertical)
add_exercise(tri-random-brightness)
add_exercise(tri-hue)
add_exercise(tri-hue-all)
add_exercise(tri-random-hue)
add_exercise(kmeans)
add_exercise(kmeans-gpt)

add_exercise(generateur-de-tri)

# Crée une cible personnalisée pour exécuter tous les exécutables
add_executable(build_all src/dummy.cpp)

# Utilise add_dependencies pour spécifier les dépendances de la cible personnalisée
add_dependencies(build_all white vert swap nETb invert degrade miroir miroirDouble bruit rotate90 rotateWeird virtualiser split splitXcropped luminosity disque cercle rosace disqueWeird mosaique mosaiqueMiroir glitch fractale vortex vortex-fail-1 vortex-fail-2 vortex-fail-3 vortex-fail-4 vortex-fail-5 vortex-fail-6 vortex-fail-7 vortex-fail-8 vortex-fail-9 vortex-fail-10 vortex-fail-11 normalisation normalisation-lum tri tri-double tri-brightness tri-brightness-all tri-brightness-vertical tri-random-brightness tri-hue tri-hue-all tri-random-hue kmeans kmeans-gpt)

