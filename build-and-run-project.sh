# Script to automate CMake project build process

rm -rf build && mkdir build && cd build
cmake ..
cmake --build .
./fuel_management_system