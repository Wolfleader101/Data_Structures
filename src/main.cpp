#include <iostream>
#include "List.h"


void PrintList(List<int>& array)
{
	std::cout << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "Length: " << array.length()  << std::endl;
	std::cout << std::endl;

	for (uint32_t i = 0; i < array.length(); ++i)
	{
		std::cout << i << "'s el: " << array.get(i) << std::endl;
	}

	std::cout << "----------" << std::endl;
	std::cout << std::endl;
}

int main()
{
	List<int> array = List<int>(new int[6]{ 1, 2, 3, 4, 5, 6 }, 6);
		
	PrintList(array);

	array.replace(0, 5);
	//array.insert(1, 69);
	//array.insert(2, 420);
	array.insert(3, 29);
	//array.insert(4, 15);
	array.add(2);

	PrintList(array);


	std::cout << "Popped item: " << array.pop() << std::endl;

	PrintList(array);

	std::cout << "index of 29: " << array.indexOf(29) << std::endl;

	//array.clear();

	array.removeAt(3);
	
	array.add(1);

	PrintList(array);

	std::cout << "contains 4: " << array.contains(4) << std::endl;
	std::cout << "could remove: " << array.remove(4) << std::endl;
	std::cout << "contains 4: " << array.contains(4) << std::endl;

	PrintList(array);

	array.sort();

	PrintList(array);

	std::cin.get();
}
