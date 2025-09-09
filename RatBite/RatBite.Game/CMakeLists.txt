# CMakeList.txt : projet CMake pour RatBite.Game, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (RatBite.Game "RatBite.Game.cpp" "RatBite.Game.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RatBite.Game PROPERTY CXX_STANDARD 20)
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add SFML directory
set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-3.0.0/lib/cmake/SFML")

# Find SFML package
find_package(SFML 3 COMPONENTS graphics window system REQUIRED)

# Link SFML libraries
target_link_libraries(MySFMLProject PRIVATE SFML::Graphics SFML::Window SFML::System)