mkdir build
cd build
cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ..
cmake --build . --config Debug

cd Debug
./AOH3_SAVE_EDITOR.exe

$SHELL