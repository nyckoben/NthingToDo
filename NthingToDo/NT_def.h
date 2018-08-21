#pragma once
#include <string>
#include <time.h>

enum NT_level
{
	low,
	high,
};

class NT_item_data
{
public:
	NT_item_data() :m_id(-1), m_start_time(0), m_end_time(0), m_level(0) {}
	int m_id;
	time_t m_start_time;
	time_t m_end_time;
	std::string m_description;
	int m_level;

	bool NT_item_data::operator<(const NT_item_data & right) const
	{
		if (this->m_end_time == right.m_end_time)
		{
			return this->m_level > right.m_level;//如果level也相等呢？
		}
		else
		{
			return this->m_end_time < right.m_end_time;
		}
	}

};
