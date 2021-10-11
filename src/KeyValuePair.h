#pragma once

template<typename K, typename V>
class KeyValuePair
{
private:
	K m_Key;
	V m_Value;

public:
	KeyValuePair(K key, V value)
		: m_Key(key), m_Value(value) {}

	K const& key() const
	{
		return m_Key;
	}
	
	V const& value() const
	{
		return m_Value;
	}

};

