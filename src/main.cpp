#include <stdio.h>
#include <string>

// Include <version> if it is available for feature macros.
#if defined(__has_include) 
    #if __has_include(<version>)
        #include <version>
    #endif
#endif

// Must have complex ifndef soup, as __has_include cannot be used on the same line it is checked for.
#if defined(__cpp_lib_filesystem) && __cplusplus >= 201703L
    #define USE_STD_EXPERIMENTAL_FILESYSTEM 0
#elif defined(__cpp_lib_experimental_filesystem)
    #define USE_STD_EXPERIMENTAL_FILESYSTEM 1
#elif defined(__has_include)
    #if __has_include(<filesystem>) && __cplusplus >= 201703L
        #define USE_STD_EXPERIMENTAL_FILESYSTEM 0
    #elif __has_include(<experimental/filesystem>)
        #define USE_STD_EXPERIMENTAL_FILESYSTEM 1
    #endif
#endif
#if !defined(USE_STD_EXPERIMENTAL_FILESYSTEM)
    #error "Could not determine support of <filesystem> or <experimental/filesystem>"
#elif USE_STD_EXPERIMENTAL_FILESYSTEM
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#else
    #include <filesystem>
    namespace fs = std::filesystem;
#endif
// #undef USE_STD_EXPERIMENTAL_FILESYSTEM

int main(int argc, char* argv[]) { 

    #if defined(USE_STD_EXPERIMENTAL_FILESYSTEM)
        printf("USE_STD_EXPERIMENTAL_FILESYSTEM %d\n", USE_STD_EXPERIMENTAL_FILESYSTEM);
    #endif

    // Printf the output of feature macros.
    #if defined(__cpp_lib_filesystem) 
        printf("defined(__cpp_lib_filesystem) %d \n", __cpp_lib_filesystem);
    #endif
    #if defined(__has_include) 
        #if __has_include(<filesystem>)
            printf("__has_include(<filesystem>)\n");
        #endif
    #endif

    #if defined(__cpp_lib_experimental_filesystem) 
        printf("defined(__cpp_lib_experimental_filesystem) %d \n", __cpp_lib_experimental_filesystem);
    #endif
    #if defined(__has_include) 
        #if __has_include(<experimental/filesystem>)
            printf("__has_include(<experimental/filesystem>)\n");
        #endif
    #endif

    #if defined(__cplusplus)
        // Will be defined as 201703L in c++17, but that doesn't actually mean that <filesystem> is available (GCC < 8). 
        // Defined as 201402L in GCC in c++14 mode
        printf("__cplusplus %ld\n", __cplusplus);
    #endif

    // Try using some filesystem features.
    fs::path p = fs::current_path();
    printf("current_path %s\n", p.c_str());

    return EXIT_SUCCESS;
}