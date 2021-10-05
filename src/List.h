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
				auto to_read = std::min(newLength, m_Length);
				for (int i = 0; i < to_read; ++i)
				{
					mem[i] = m_Data[i];
				}
				// TODO look at ways to make sure if newLength is greater that it initializes values
				//if (newLength > m_Length)
				//{
				//	mem[newLength - 1] = 0;
				//}
				
				std::swap(mem, m_Data);
				m_Length = newLength;
				
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

	uint32_t length() const	{return m_Length;}

	void add(T el)
	{
		const auto new_size = m_Length + 1;

		resize(new_size);

		m_Data[new_size - 1] = el;
	}

	void replace(uint32_t index, T el, bool only_if_null = false)
	{
		if (index <= m_Length)
		{
			if (only_if_null && m_Data[index] == 0)
			{
				m_Data[index] = el;
			}
			else
			{
				m_Data[index] = el;
			}
			
		}
		else {
			//throw
		}
	}

	void insert(uint32_t index, T value)
	{
		if (index <= m_Length)
		{
			const auto new_size = m_Length + 1;

			if (T* mem = new T[new_size])
			{
				auto to_read = std::min(new_size, m_Length);

				T prev_value = 0;
				for (int i = 0; i < to_read; ++i)
				{
					if (i < index)
					{
						mem[i] = m_Data[i];
						continue;
					}
					if (i >= index)
					{
						prev_value = m_Data[i];
						if (i == index)
						{
							mem[i] = value;
							continue;
						}
						mem[i] = prev_value;
					}
					
				}

				std::swap(mem, m_Data);
				m_Length = new_size;

				delete[] mem;
			}
			else
			{
				throw std::bad_alloc();
			}

			//resize(new_size);
			//m_Data[index] = el;
		}
		else
		{
			//throw
		}
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

	T* getAddr(uint32_t index)
	{
		return &m_Data[index];
	}

};