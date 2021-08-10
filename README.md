# CMake std::filesystem

A CMake project to test using `<std::filesystem>`/`<std::experimental/filesystem>` in a CMake based project, using either clang or GCC.

## Building with C++17 and std::filesystem

```bash
mkdir -p build && cd build
cmake .. -DCXXSTD=17 -DCMAKE_BUILD_TYPE=Release
cmake --build . --target all -j 8
./bin/Release/stdfilesystem-test
```

## Building with C++14 and std::experimental::filesystem

```bash
mkdir -p build && cd build
cmake .. -DCXXSTD=14 -DCMAKE_BUILD_TYPE=Release
cmake --build . --target all -j 8
./bin/Release/stdfilesystem-test
```
