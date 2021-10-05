#include <iostream>
#include "List.h"


int main()
{
	List<int> array = List<int>(5);
	std::cout << "Length: " << array.length() << std::endl;
	array.insert(0, 5);
	
	for (int i = 0; i < array.length(); ++i)
	{
		std::cout << i << "'s el: " << array.get(i) << std::endl;
	}
	std::cout << std::endl;

	
	array.insert(1, 69);
	//array.insert(2, 420);
	//array.insert(3, 29);
	//array.insert(4, 15);
	array.add(2);

	uintptr_t addr = uintptr_t(array.getAddr(0));

	std::cout << "Address: " << addr << std::endl;
	std::cout << "Address value: " << *(int*)addr << std::endl;

	uintptr_t lst_addr = addr + 14;

	std::cout << "Last Address: " << lst_addr << std::endl;
	std::cout << "Last Address value: " << *(int*)lst_addr << std::endl;

	std::cout << "New Length: " << array.length() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < array.length(); ++i)
	{
		std::cout << i << "'s el: " << array.get(i) << std::endl;
	}
	std::cout << std::endl;

	int poppedItem = array.pop();
	std::cout << "New Length: " << array.length() << std::endl;
	std::cout << "Popped item: " << poppedItem << std::endl;
	

	for (int i = 0; i < array.length(); ++i)
	{
		std::cout << i << "'s el: " << array.get(i) << std::endl;
	}
	std::cout << std::endl;
	std::cin.get();
}