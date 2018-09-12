#pragma once
#include "NthingToDo.h"
#include <time.h>
#include <set>
#include "NT_ui_item.h"
#include "NT_item_factory.h"
class NthingToDo;

class NT_ui_item_manager
{
public:
	int load_ui_item_from_db(time_t before_time);

	int flush_ui_position();
	int add_ui_item(NT_item_data data);
	//QWidget* get_centralWidget() { return m_p_centralWidget;  }

	void set_centralWidget(QWidget *p_widget) { m_p_centralWidget = p_widget; }
	void set_mainWindows(NthingToDo *p_window) { m_p_mainWindow = p_window; }
	
	QWidget *m_p_centralWidget;
	NthingToDo *m_p_mainWindow;
	int m_width;
	std::set<NT_ui_item> m_set_ui_items;

};