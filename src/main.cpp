#include <iostream>
#include "List.h"


int main()
{
	List<int> array = List<int>(5);
	std::cout << "Length: " << array.length() << std::endl;
	std::cout << "Size: " << array.size() << std::endl;

	std::cin.get();
}