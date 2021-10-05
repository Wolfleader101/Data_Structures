#pragma once

#include <cstdint>
#include <cstdlib>

template<typename T>
class List
{
private:
	T* m_Data;
	size_t m_Size;
	uint32_t m_Length;

public:
	//List()
	//{
	//	m_Length = 1;
	//	m_Size = m_Length * sizeof(T); // min length is 1
	//	m_Data = (T*)malloc(m_Size);
	//}

	//List(uint32_t length)
	//{
	//	m_Length = length;
	//	m_Size = m_Length * sizeof(T);
	//	m_Data = (T*)malloc(m_Size);
	//}

	//~List()
	//{
	//	free(m_Data);
	//}

	//size_t size() const
	//{
	//	return m_Size;
	//}

	//uint32_t length() const
	//{
	//	return m_Length;
	//}

};