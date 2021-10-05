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

	// resize method from cppref
	void resize(size_t newSize)
	{
		if (newSize == 0) { // this check is not strictly needed, but zero-size realloc is deprecated in C
			std::free(m_Data); // free the memory
			m_Data = nullptr;
		}
		else {
			if (void* mem = std::realloc(m_Data, newSize))
			{
				m_Data = static_cast<T*>(mem);
			}
			else
			{
				throw std::bad_alloc();
			}
		}
	}

public:
	List()
		: m_Length(0), m_Size(0), m_Data(nullptr){}

	List(uint32_t length) 
		: m_Length(length), m_Size(length * sizeof(T)), m_Data((T*)std::calloc(length, sizeof(T)))
	{
	}

	~List() {
		std::free(m_Data);
	}

	size_t size() const	{return m_Size;}

	uint32_t length() const	{return m_Length;}

	void add(T el)
	{
		m_Length++;
		m_Size = m_Length * sizeof(T);
		resize(m_Size);
		m_Data[m_Length] = el;

	}

	void insert(uint32_t index, T el)
	{
		if (index <= m_Length)
		{
			if (m_Data[index] == 0)
			{
				m_Data[index] = el;
			}
		}


		//m_Length++;
		//m_Size = m_Length * sizeof(T);
		//resize(m_Size);
		//m_Data[m_Length] = el;

		//return m_Length;
	}

	T get(uint32_t index)
	{
		return m_Data[index];
	}

};