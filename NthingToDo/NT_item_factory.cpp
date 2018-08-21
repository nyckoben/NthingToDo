#include "NT_item_factory.h"
#include "NT_db.h"

NT_item * NT_item_factory::creat_NT_item(const NT_item_data &data)
{
	return new NT_item_disposable(data);
}

int NT_item_factory::load_NT_item_from_db(time_t before_time, std::set<NT_item> &set_item)
{
	NT_db nt_db;
	std::set<NT_item_data> item_data;
	nt_db.get_item_data_from_db(before_time, item_data);
	for (std::set<NT_item_data>::const_iterator iter = item_data.begin(); iter != item_data.end(); ++iter)
	{
		NT_item item(*iter);
		set_item.insert(item);
	}
	return 0;
}