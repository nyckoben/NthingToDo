#pragma once
#include <time.h>
#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include "ui_NthingToDo.h"
#include "NT_window_item_edit.h"
#include "NT_ui_item_manager.h"

class NT_window_item_edit;

class NthingToDo : public QMainWindow
{
	Q_OBJECT

public:
	NthingToDo(QWidget *parent = Q_NULLPTR);

	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void creatTrayIcon();

	NT_ui_item_manager m_ui_item_manager;
	QPoint last;
	QSystemTrayIcon* m_p_systemTray;
	QMenu* m_p_ContextMenu;
	NT_window_item_edit *m_p_window_item_edit;

	Ui::NthingToDoClass ui;

private slots :
	void on_addEvent(void);
};
