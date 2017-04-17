#include <libstucpp.h>
#include <iostream>
#include <vector>


int main(int argc, char** argv)
{
	test();
	TestClass t;	
	t.one();

	std::vector<std::string> strings;
	using StringList = std::vector<std::string>;
	
	StringList::iterator it;
	for (it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << it->c_str() << std::endl;
	}
	return 0;
}
