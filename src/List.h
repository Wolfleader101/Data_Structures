#pragma once

#include <cstdint>
#include <cstdlib>

template<typename T>
class List
{
private:
	T* m_Data;
	uint32_t m_Length;

	void resize(uint32_t newLength)
	{
		if (newLength == 0) {
			delete m_Data;
			m_Data = nullptr;
		}
		else {

			if (T* mem = new T[newLength])
			{
				if (newLength < m_Length)
				{
					for (int i = 0; i < newLength; ++i)
					{
						mem[i] = m_Data[i];
					}
					m_Length--;
				}
				else
				{
					for (int i = 0; i < m_Length; ++i)
					{
						mem[i] = m_Data[i];
					}

					mem[newLength - 1] = 0;
					m_Length++;
				}
				
				std::swap(mem, m_Data);
				

				delete[] mem;
			}
			else
			{
				throw std::bad_alloc();
			}
		}
	}

public:
	List()
		: m_Length(0), m_Data(nullptr){}

	List(uint32_t length) 
		: m_Length(length), m_Data(new T[length])
	{
		for (int i = 0; i < m_Length; ++i)
		{
			m_Data[i] = 0;
		}
	}

	~List() {delete m_Data;}

	//size_t size() const	{return m_Size;}

	uint32_t length() const	{return m_Length;}

	void add(T el)
	{
		const auto new_size = m_Length + 1;

		resize(new_size);

		m_Data[new_size - 1] = el;
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

	T pop()
	{
		const auto new_size = m_Length - 1;
		const auto popped_item = m_Data[new_size];

		resize(new_size);

		return popped_item;
	}

	T get(uint32_t index)
	{
		return m_Data[index];
	}

};