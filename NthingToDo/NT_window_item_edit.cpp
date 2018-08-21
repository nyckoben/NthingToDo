#include "NT_window_item_edit.h"


NT_window_item_edit::NT_window_item_edit(NthingToDo *nthingToDo, QWidget *parent)
	: QDialog(parent), m_p_nthingToDo(nthingToDo)
{
	ui.setupUi(this);

	QObject::connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(this->on_btn_ok()));
}

void NT_window_item_edit::on_btn_ok(void)
{
	NT_item_data data;
	data.m_description = ui.lineEdit->text().toStdString();
	data.m_start_time = ui.dateTimeEdit->dateTime().offsetFromUtc();
	data.m_end_time = ui.dateTimeEdit_2->dateTime().offsetFromUtc();
	data.m_level = ui.lineEdit_2->text().toInt();
	m_p_nthingToDo->m_ui_item_manager.add_ui_item(data);
}
