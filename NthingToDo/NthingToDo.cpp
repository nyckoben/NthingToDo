#include "NthingToDo.h"

NthingToDo::NthingToDo(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);//根据ui文件配置界面

	this->setWindowFlags(Qt::FramelessWindowHint);

	QRect deskRect = QApplication::desktop()->availableGeometry();
	this->resize(deskRect.width(), 20);

	QWidget *centralWidget = new QWidget(this);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));
	centralWidget->setEnabled(true);
	centralWidget->setMaximumSize(QSize(deskRect.width(), 20));
	this->setCentralWidget(centralWidget);
	
	//this->setWindowTitle(QApplication::translate("NthingToDoClass", "NthingToDo", Q_NULLPTR));
	QMetaObject::connectSlotsByName(this);

	creatTrayIcon();
	m_ui_item_manager.m_width = deskRect.width();//改成初始化？
	m_ui_item_manager.set_centralWidget(centralWidget);
	time_t t_now = time(NULL);
	m_ui_item_manager.load_ui_item_from_db(t_now + 3600 * 24);
}


//可以在构造函数中初始一下last变量用其成员函数setX,setY就是了
//接下来就是对三个鼠标事件的重写
void NthingToDo::mousePressEvent(QMouseEvent *e)
{
	QRect deskRect = QApplication::desktop()->availableGeometry();
	if (e->button() == Qt::LeftButton)
	{
		last = e->globalPos();
	}
	else if (e->button() == Qt::RightButton)
	{

	}
	else if (e->button() == Qt::MidButton)
	{

	}
	
}
void NthingToDo::mouseMoveEvent(QMouseEvent *e)
{
	//int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	last = e->globalPos();
	move(0, y() + dy);
}
void NthingToDo::mouseReleaseEvent(QMouseEvent *e)
{
	//int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	move(0, y() + dy);
}

void NthingToDo::creatTrayIcon()
{
	QIcon icon("./32X32.ico");//源码目录
	m_p_systemTray = new QSystemTrayIcon(this);
	m_p_systemTray->setIcon(icon);
	m_p_systemTray->setToolTip("NthingToDo");

	m_p_ContextMenu = new QMenu(this);

	QAction  *addAct = new QAction("add event", this);
	connect(addAct, SIGNAL(triggered()), this, SLOT(on_addEvent(void)));
	m_p_ContextMenu->addAction(addAct);

	m_p_ContextMenu->addSeparator();
	QAction  *quitAct = new QAction("Quit", this);
	connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
	m_p_ContextMenu->addAction(quitAct);

	m_p_systemTray->setContextMenu(m_p_ContextMenu);
	m_p_systemTray->show();
}

void NthingToDo::on_addEvent(void)//不加void，connect回调会识别不到是这个函数
{
	m_p_window_item_edit = new NT_window_item_edit(this);
	m_p_window_item_edit->show();
}