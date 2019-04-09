// CApi_win.cpp
// Uses C-Style GetProcAddress() to obtain functions in library

#include <windows.h>
#include <iostream>
#include "WinCApiTest.h"
#include "Timing.h"
#include <functional>



class TestRunner 
{	
typedef void* ( *INIT)();
typedef void ( *END)();
typedef int ( *SUB)(int,int);
typedef double(*retDbl)(void (fn)(), InDuration);

public:
	TestRunner() { 
		if(!Init()) {
			std::cout << "Failed to initialize" << std::endl;
			end();
		}
	}
	~TestRunner() { 
		std::cout << "Tearing down tests." << std::endl;
		end(); 
	}

	bool Init()
	{
		lib = LoadLibrary("stucpp.dll");

		if (lib == NULL) {
			std::cerr << "Cannot locate the .dll file" << std::endl;
			return false;
		}
		init = (INIT)GetProcAddress(lib, "initLib");
		end = (END)GetProcAddress(lib, "closeLib");
		if (!init || !end)
		{
			std::cerr << "Couldn't find function" << std::endl;
			return false;
		}
		init();
		isInit = true;
		return isInit;
	}

	void RunIfInitialized(std::function<void()> fn)
	{
		if(init) { fn(); }
	}

	void TestTimingFunctions()
	{	
		RunIfInitialized([this](){
			TestGetMsDurationOf();
		});				
		
	}
	void TestArithmeticFunctions()
	{
		RunIfInitialized([this](){
			TestSubtract();
		});
		
	}
private:
	 bool isInit = false;
	 INIT init;
	 END end;
	 HINSTANCE lib;	 

	 
	void TestGetMsDurationOf()
	{		
		retDbl GetDurationOfIn = (retDbl)GetProcAddress(lib, "GetDurationOfIn");
		
		std::cout << "That took " << GetDurationOfIn([]() {
			Sleep(1);
			std::cout << "How fast did I run?" << std::endl;
		}, MilliSeconds) << " miliseconds" << std::endl;

	}
	
	void TestSubtract()
	{
		SUB sub = (SUB)GetProcAddress(lib, "sub");
		std::cout << "100 - 99 = " << sub(100, 99) << std::endl;
	}
};


int main() {

	std::unique_ptr<TestRunner> testRunner = std::unique_ptr<TestRunner>(new TestRunner());	
		
	testRunner->TestArithmeticFunctions();
	testRunner->TestTimingFunctions();
	
    
    return 0;
}
