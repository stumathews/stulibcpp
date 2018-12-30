// Tests the C API
#include <iostream>
#include <dlfcn.h>
#include <unistd.h>

# define GETFUNC(funchandle, lib, funcName) (*(void**)(&funchandle) = dlsym(lib, funcName))

int main(int argc, const char** argv)
{
  int ret = 0;
  void* (*initLib)();
  void (*closeLib)();
  int (*sub)(int, int);

  #if __linux
    void* lib = dlopen("libstucpp.so", RTLD_LAZY);
  #elif __APPLE__
    void* lib = dlopen("libstucpp.dylib", RTLD_LAZY);
  #endif

  if (!lib)
    {
      std::cerr << "Could not open library" << std::endl;
      return 2;
    }

  reinterpret_cast<void*&>(initLib) = dlsym(lib, "initLib");
  reinterpret_cast<void*&>(closeLib) = dlsym(lib, "closeLib");
  reinterpret_cast<void*&>(sub) = dlsym(lib, "sub");

  // Init the lib
  initLib();
  std::cout << sub(10,5) << std::endl;
  closeLib();
  return ret;
}
