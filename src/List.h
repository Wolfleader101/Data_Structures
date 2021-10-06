#pragma once

#include <cstdint>
#include <cstdlib>

template<typename T>
class List
{
private:
	T* m_Data;
	uint32_t m_Length;

	void resize(uint32_t new_length)
	{
		if (new_length == 0) {
			m_Data = new T[0];
			m_Length = 0;
		}
		else {

			if (T* mem = new T[new_length])
			{
				auto to_read = std::min(new_length, m_Length);
				for (uint32_t i = 0; i < to_read; ++i)
				{
					mem[i] = m_Data[i];
				}

				if (new_length > m_Length)
				{
					int diff = new_length - m_Length;
					for (int i = 1; i <= diff; ++i)
					{
						int z = new_length - i;
						mem[z] = 0;
					}
				}

				std::swap(mem, m_Data);
				m_Length = new_length;

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
		: m_Length(0), m_Data(new T[0]) {}

	List(uint32_t length)
		: m_Length(length), m_Data(new T[length])
	{
		for (int i = 0; i < m_Length; ++i)
		{
			m_Data[i] = 0;
		}
	}

	List(T* array, int length)
		: m_Length(length)
	{
		m_Data = new T[m_Length];
		for (uint32_t i = 0; i < m_Length; ++i)
		{
			m_Data[i] = array[i];
		}
	}

	~List() { delete m_Data; }

	uint32_t const& length() const { return m_Length; }

	void clear()
	{ 
		resize(0);
	}

	void add(T item)
	{
		const auto new_size = m_Length + 1;

		resize(new_size);

		m_Data[new_size - 1] = item;
	}

	void replace(uint32_t index, T item, bool only_if_null = false)
	{
		if (index <= m_Length && m_Length != 0)
		{
			if (only_if_null && m_Data[index] == 0)
			{
				m_Data[index] = item;
			}
			else
			{
				m_Data[index] = item;
			}

		}
		else {
			throw std::range_error("Index is out of bounds or length is 0");
		}
	}

	void insert(uint32_t index, T item)
	{
		if (index <= m_Length && m_Length != 0)
		{
			const auto new_size = m_Length + 1;
			if (T* mem = new T[new_size])
			{
				T prev_value = 0;
				for (uint32_t i = 0; i < new_size; ++i)
				{
					if (i < index)
					{
						mem[i] = m_Data[i];
						continue;
					}
					if (i == index)
					{
						prev_value = m_Data[i];
						mem[i] = item;
						continue;
					}
					if (i > index)
					{
						mem[i] = prev_value;
						prev_value = m_Data[i];
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
		}
		else
		{
			throw std::range_error("Index is out of bounds or length is 0");
		}
	}

	void removeAt(uint32_t index)
	{
		if (index <= m_Length && m_Length != 0)
		{
			const auto new_size = m_Length - 1;
			if (T* mem = new T[new_size])
			{
				for (uint32_t i = 0; i < new_size; ++i)
				{
					if (i < index)
					{
						mem[i] = m_Data[i];
						continue;
					}

					if (i >= index)
					{
						mem[i] = m_Data[i + 1];
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
		}
		else
		{
			throw std::range_error("Index is out of bounds or length is 0");
		}

		//const auto new_size = m_Length - 1;
		//const auto popped_item = m_Data[new_size];

		//resize(new_size);

		//return popped_item;
	}
	
	void reverse()
	{
		if (T* mem = new T[m_Length])
		{
			for (int i = 0; i < m_Length; ++i)
			{
				int z = m_Length - (i + 1);
				mem[i] = m_Data[z];
			}

			std::swap(mem, m_Data);

			delete[] mem;
		}
		else
		{
			throw std::bad_alloc();
		}
	}

	bool remove(T item)
	{
		for (uint32_t i = 0; i < m_Length; ++i)
		{
			if (m_Data[i] == item)
			{
				removeAt(i);
				return true;
			}
		}

		return false;
	}

	bool contains(T item)
	{
		for (uint32_t i = 0; i < m_Length; ++i)
		{
			if (m_Data[i] == item) return true;
		}

		return false;
	}

	T pop()
	{
		const auto new_size = m_Length - 1;
		const auto popped_item = m_Data[new_size];

		resize(new_size);

		return popped_item;
	}

	T const& get(uint32_t index)
	{
		return m_Data[index];
	}

	T* getAddr(uint32_t index)
	{
		return &m_Data[index];
	}

	int32_t indexOf(T item)
	{
		for(uint32_t i = 0; i < m_Length; ++i)
		{
			if (m_Data[i] == item) return i;
		}
		return -1;
	}

};