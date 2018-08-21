#pragma once
#include <time.h>
#include <string>

#include "NT_def.h"
class NT_item
{

public:
	NT_item(NT_item_data data);
// 	time_t get_left_time();
// 	int set_left_time(time_t left_time);
// 	std::string get_description();
// 	int set_description(std::string &desp);

	//set排序：时间少的在前，等级高的在前
	bool operator<(const NT_item & right)const { return m_data < right.m_data; }


	NT_item_data m_data;
	time_t m_left_time;
};

//一次性事件
class NT_item_disposable : public NT_item
{
public:
	NT_item_disposable(NT_item_data data);

};