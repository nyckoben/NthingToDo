#pragma once
#include <QLabel>
#include "NT_item.h"


class NT_ui_item
{
public:
	NT_ui_item(NT_item item, QWidget *p_centralWidget);
	~NT_ui_item() {}
	
	//void set_ui_manager(NT_ui_item_manager* ui_manager) { m_p_ui_item_manager = ui_manager; }
	
	bool operator<(const NT_ui_item & right) const{ return m_item < right.m_item; }
	//NT_ui_item_manager* m_p_ui_item_manager;

	void set_centralWidget(QWidget *p_widget) { m_p_centralWidget = p_widget; }

	QWidget *m_p_centralWidget;

	NT_item m_item;
	QLabel *m_p_label;

	const std::string m_color_strs[2] = { "background-color:yellow","background-color:red" };
};

