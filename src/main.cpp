#include <iostream>
#include "List.h"


int main()
{
	List<int> array = List<int>(5);
	std::cout << "Length: " << array.length() << std::endl;
	std::cout << "Size: " << array.size() << std::endl;

	array.add(2);
	array.insert(0, 5);

	std::cout << "Length: " << array.length() << std::endl;
	std::cout << "Size: " << array.size() << std::endl;
	std::cout << "first el: " << array.get(0) << std::endl;
	std::cout << "last el: " << array.get(array.length()) << std::endl;

	std::cin.get();
}