#include <iostream>
#include "List.h"


int main()
{
	List<int> array = List<int>(new int[6]{ 1, 2, 3, 4, 5, 6 }, 6);
	array.replace(0, 5);
	
	std::cout << "Length: " << array.length() << std::endl;
	std::cout << std::endl;

	for (uint32_t i = 0; i < array.length(); ++i)
	{
		std::cout << i << "'s el: " << array.get(i) << std::endl;
	}
	std::cout << std::endl;

	//array.insert(1, 69);
	//array.insert(2, 420);
	array.insert(3, 29);
	//array.insert(4, 15);
	//array.add(2);

	std::cout << "Length: " << array.length() << std::endl;
	std::cout << std::endl;

	for (uint32_t i = 0; i < array.length(); ++i)
	{
		std::cout << i << "'s el: " << array.get(i) << std::endl;
	}
	std::cout << std::endl;

	int poppedItem = array.pop();
	
	std::cout << "Popped item: " << poppedItem << std::endl;
	std::cout << "Length: " << array.length() << std::endl;
	std::cout << std::endl;

	for (uint32_t i = 0; i < array.length(); ++i)
	{
		std::cout << i << "'s el: " << array.get(i) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "index of 29: " << array.indexOf(29) << std::endl;

	//array.clear();

	//array.add(1);


	//for (int i = 0; i < array.length(); ++i)
	//{
	//	std::cout << i << "'s el: " << array.get(i) << std::endl;
	//}
	//std::cout << std::endl;

	std::cin.get();
}
