// CApi_win.cpp
// Uses C-Style GetProcAddress() to obtain functions in library

#include <windows.h>
#include <iostream>
#include "WinCApiTest.h"
#include "Timing.h"

typedef void* ( *INIT)();
typedef void ( *END)();
typedef int ( *SUB)(int,int);

void callTimingFunctions(const HINSTANCE& lib)
{		
	GetMsDurationOf(lib);	
}

void GetMsDurationOf(const HINSTANCE & lib)
{
	
	typedef double(*retDbl)(void (fn)(), InDuration);
	retDbl func = (retDbl)GetProcAddress(lib, "GetDurationOfIn");
	std::cout << "That took " << func([]() {
		Sleep(1);
		std::cout << "How fast did I run?" << std::endl;
	}, MilliSeconds) << " miliseconds" << std::endl;
}

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
	
	// Start testing
	callTimingFunctions(lib);

    end();
    return 0;
}
