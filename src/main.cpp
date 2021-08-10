#include <stdio.h>

// @todo - handle different c++ standards

#include <filesystem>

int main(int argc, char* argv[]) { 
    printf("hello world\n");

    std::filesystem::path p = std::filesystem::current_path();

    printf("current_path %s\n", p.c_str());
}