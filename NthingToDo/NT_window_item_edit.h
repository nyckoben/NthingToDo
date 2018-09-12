#pragma once
#include <QDialog>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

#include "ui_NT_window_item_edit.h"
#include "NT_db.h"
#include "NthingToDo.h"

class NthingToDo;

class NT_window_item_edit : public QDialog
{
	Q_OBJECT
public:
	NT_window_item_edit(NthingToDo *nthingToDo,QWidget *parent = Q_NULLPTR);
	void accept();

private:
	Ui::NT_window_item_edit ui;
	NthingToDo *m_p_nthingToDo;
};