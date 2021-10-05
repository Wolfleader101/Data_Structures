#pragma once

// TODO implement static array

template<typename T, int N> 
class Array
{
private:
	T m_Array[N];
public:
	Array() {}
	~Array() {}

	int size() const
	{
		return N * sizeof(T);
	}

	int length() const
	{
		return N;
	}

};

