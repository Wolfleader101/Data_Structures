#include <iostream>
#include "List.h"


int main()
{
	List<int> array = List<int>(5);
	std::cout << "Length: " << array.length() << std::endl;
	std::cout << "Size: " << array.size() << std::endl;
	uint32_t insertion = array.insert(2);
	std::cout << "Length: " << array.length() << std::endl;
	std::cout << "Size: " << array.size() << std::endl;
	std::cout << "last el: " << array.get(6) << std::endl;

	std::cin.get();
}