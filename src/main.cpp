#include <stdio.h>
#if defined(__has_include) && __has_include(<version>)
#include <version>
#endif
#include <string>

// Check for std::filesystem feature flags and header.
#if defined(__cpp_lib_filesystem) || (defined(__has_include) && __has_include(<filesystem>))
#include <filesystem>
namespace fs = std::filesystem;
#elif defined(__cpp_lib_experimental_filesystem) || (defined(__has_include) && __has_include(<experimental/filesystem>))
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else 
#error "<filesystem> or <experimental/filesystem> required"
#endif

int main(int argc, char* argv[]) { 

    // Printf the output of feature macros.
    #if defined(__cpp_lib_filesystem) 
        printf("defined(__cpp_lib_filesystem) \n");
    #endif
    #if defined(__has_include) && __has_include(<filesystem>)
        printf("__has_include(<filesystem>)\n");
    #endif

    #if defined(__cpp_lib_experimental_filesystem) 
        printf("defined(__cpp_lib_filesystem) \n");
    #endif
    #if defined(__has_include) && __has_include(<experimental/filesystem>)
        printf("__has_include(<experimental/filesystem>)\n");
    #endif

    #if defined(__cplusplus)
        // Will be defined as 201703L in c++17, but that doesn't actually mean that <filesystem> is available (GCC < 8). 
        // Defined as 201402L in GCC in c++14 mode
        printf("__cplusplus %ld\n", __cplusplus);
    #endif

    // Try using some filesystem features.
    fs::path p = fs::current_path();
    printf("current_path %s\n", p.c_str());
}