#pragma once
#include <time.h>
#include <set>
#include <string>
#include "sqlite3.h"

#include "NT_def.h"

class NT_db
{
public:

	NT_db();
	~NT_db();

	//获取before_time前到期的数据
	int get_item_data_from_db(time_t before_time, std::set<NT_item_data> &data);
	int add_item_data_to_db(NT_item_data &data);
	int del_item_data_to_db(int id);

	int creat_table_for_item();
	const std::string m_table_name = "t_nt_items";
	sqlite3 *m_p_db;
};