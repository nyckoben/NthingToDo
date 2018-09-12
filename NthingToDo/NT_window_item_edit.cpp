#include "NT_window_item_edit.h"


NT_window_item_edit::NT_window_item_edit(NthingToDo *nthingToDo, QWidget *parent)
	: QDialog(parent), m_p_nthingToDo(nthingToDo)
{
	ui.setupUi(this);
	QDateTime tNow;
	tNow.setTime_t(time(NULL));
	ui.dateTimeEdit_2->setDateTime(tNow);

// 	ui.retranslateUi(this);
// 	QObject::connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
// 	QObject::connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
// 
// 	QMetaObject::connectSlotsByName(this);
}

void NT_window_item_edit::accept()
{
	NT_item_data data;
	data.m_description = ui.lineEdit->text().toStdString();
	data.m_start_time = ui.dateTimeEdit->dateTime().toTime_t();
	data.m_end_time = ui.dateTimeEdit_2->dateTime().toTime_t();
	data.m_level = ui.lineEdit_2->text().toInt();

	NT_db nt_db;
	nt_db.add_item_data_to_db(data);
	
	m_p_nthingToDo->m_ui_item_manager->load_ui_item_from_db(time(NULL) + 3600 * 24);

	//m_p_nthingToDo->m_ui_item_manager.add_ui_item(data);
	//todo ¹Ø±Õ´°¿Ú
}
