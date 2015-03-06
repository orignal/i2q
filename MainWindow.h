#ifndef MAIN_WINDOW_H__
#define MAIN_WINDOW_H__

#include <memory>
#include <QtGui>
#include <QSystemTrayIcon>
#include "Destination.h"
#include "api.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:

		MainWindow (QWidget* parent = nullptr);
		~MainWindow ();

	private:

		void InitLocalUID ();

	private:

		std::unique_ptr<i2p::client::ClientDestination> m_LocalUID;
		QSystemTrayIcon * m_TrayIcon;
};

#endif
