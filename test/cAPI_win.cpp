// CApi_win.cpp
// Uses C-Style GetProcAddress() to obtain functions in library

#include <windows.h>
#include <iostream>

typedef void* ( *INIT)();
typedef void ( *END)();
typedef int ( *SUB)(int,int);

int main() {
    HINSTANCE lib = LoadLibrary("stucpp.dll");

    if (lib == NULL) {
        std::cerr << "Cannot locate the .dll file" << std::endl;
        return 1;
    }
    INIT init = (INIT)GetProcAddress(lib, "initLib");
    END end = (END)GetProcAddress(lib, "closeLib");
	SUB sub = (SUB)GetProcAddress(lib, "sub");
    if (!init || !end)
    {
        std::cerr << "Couldn't find function" << std::endl;
        return 1;
    }
    init();
	std::cout << "sub(10,5) = " << sub(10,5) << std::endl;
    end();
    return 0;
}
