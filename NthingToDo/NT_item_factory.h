#pragma once
#include <time.h>
#include <set>
#include "NT_item.h"

class NT_item_factory
{
public:
	static NT_item * creat_NT_item(const NT_item_data &data);
	static int load_NT_item_from_db(time_t before_time, std::set<NT_item> &set_item);

private:


};