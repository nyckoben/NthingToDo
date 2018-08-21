#include "NthingToDo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NthingToDo w;
	w.show();
	return a.exec();
}
