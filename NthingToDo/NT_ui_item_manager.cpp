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
	if (0 < ui_item.m_item.m_left_time && ui_item.m_item.m_left_time < time(NULL) + (60 * 60 * 24))//24小时内的任务
	{
		m_set_ui_items.insert(ui_item);
		flush_ui_position();
	}


	return 0;
}

int NT_ui_item_manager::flush_ui_position()
{
	int start_position = 0;
	for (std::set<NT_ui_item>::iterator iter = m_set_ui_items.begin(); iter != m_set_ui_items.end(); ++iter)
	{
		int end_position = start_position + iter->m_item.m_left_time * m_width / (60 * 60 * 24);
		iter->m_p_label->setGeometry(QRect(start_position, 0, end_position, 20));
		iter->m_p_label->resize(end_position - start_position, 20);
		iter->m_p_label->move(start_position, 0);
		iter->m_p_label->update(); 
		iter->m_p_centralWidget->update();
		((NthingToDo*)m_p_mainWindow)->ui.horizontalLayout->addWidget(iter->m_p_label);
		m_p_mainWindow->setCentralWidget(iter->m_p_centralWidget);
		start_position = end_position;
	}
	m_p_mainWindow->update();
	m_p_mainWindow->show();
// 	m_p_mainWindow->showNormal();
// 	m_p_mainWindow->resize(m_p_mainWindow->size());
// 	m_p_mainWindow->adjustSize();
	return 0;
}