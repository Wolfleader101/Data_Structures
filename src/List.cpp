#include "List.h"



template<typename T>
List<T>::List() {
	m_Length = 1;
	m_Size = m_Length * sizeof(T); // min length is 1
	m_Data = (T*)malloc(m_Size);
}

template<typename T>
List<T>::List(uint32_t length) {
	m_Length = length;
	m_Size = m_Length * sizeof(T);
	m_Data = (T*)malloc(m_Size);
}

template<typename T>
List<T>::~List() {
	free(m_Data);
}

template<typename T>
size_t List<T>::size() const
{
	return m_Size;
}

template<typename T>
uint32_t List<T>::length() const
{
	return m_Length;
}
