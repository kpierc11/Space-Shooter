# Work in progress space shooter game built with SDL2
![image](https://github.com/user-attachments/assets/a6d5e21e-ea0b-4600-81d2-d6b6137e662c)


# 1. Remove your old build folder (so CMake starts fresh)
Remove-Item -Recurse -Force .\build

# 2. Reconfigure the project with AVIF support disabled
cmake -S . -B build -DSDL_IMAGE_AVIF=OFF

# 3. Build the project again
cmake --build build --config Debug
