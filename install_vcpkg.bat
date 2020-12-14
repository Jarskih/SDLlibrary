git clone https://github.com/microsoft/vcpkg
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install sdl2 sdl2-image --triplet x64-windows
.\vcpkg\vcpkg integrate install