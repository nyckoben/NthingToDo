#include "NT_ui_item_manager.h"

int NT_ui_item_manager::load_ui_item_from_db(time_t before_time)
{
	std::set<NT_item> set_nt_item;
	if (NT_item_factory::load_NT_item_from_db(before_time, set_nt_item))
	{
		return -1;
	}

	m_set_ui_items.clear();
	for (std::set<NT_item>::iterator iter = set_nt_item.begin(); iter != set_nt_item.end(); ++iter)
	{
		NT_ui_item ui_item(*iter, m_p_centralWidget);
		m_set_ui_items.insert(ui_item);
	}
	flush_ui_position();
	return 0;
}

int NT_ui_item_manager::add_ui_item(NT_item_data data)
{
	NT_item item(data);
	NT_ui_item ui_item(item, m_p_centralWidget);
	m_set_ui_items.insert(ui_item);
	flush_ui_position();



	return 0;
}

int NT_ui_item_manager::flush_ui_position()
{
	int start_position = 0;
	for (std::set<NT_ui_item>::iterator iter = m_set_ui_items.begin(); iter != m_set_ui_items.end(); ++iter)
	{
		int end_position = start_position + m_width / m_set_ui_items.size();
		iter->m_p_label->setGeometry(QRect(start_position, 0, end_position, 20));
		start_position = end_position;
	}
	return 0;
}