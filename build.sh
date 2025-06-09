mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake ..
cmake --build . --config Debug

$SHELL