mkdir build
cd build
cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ..
cmake --build . --config Debug

$SHELL