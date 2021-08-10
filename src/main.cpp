#include <stdio.h>
#if defined(__has_include) && __has_include(<version>)
#include <version>
#endif
#include <string>

// 201703L	

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
    printf("hello world\n");

    fs::path p = fs::current_path();
    printf("current_path %s\n", p.c_str());

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
        printf("__cplusplus %ld\n", __cplusplus);
    #endif

}