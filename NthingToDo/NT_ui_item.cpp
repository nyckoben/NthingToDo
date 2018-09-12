#include "NT_ui_item.h"


NT_ui_item::NT_ui_item(NT_item item, QWidget *p_centralWidget) : m_item(item), m_p_centralWidget(p_centralWidget)
{
	if (item.m_left_time > 0)
	{
		m_p_label = new QLabel(m_p_centralWidget);
		//m_p_label->setObjectName(QStringLiteral("label"));
		//m_p_label->setGeometry(QRect(0, 0, 1900, 20));//长度由manager设置
		m_p_label->setText(m_item.m_data.m_description.c_str());
		m_p_label->setStyleSheet(m_color_strs[m_item.m_data.m_level].c_str());
		//m_p_label->setStyleSheet("background-color:rgb(100,100,100)");
	}
}
