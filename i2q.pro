TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
# CONFIG += c++11
CONFIG += qt
INCLUDEPATH += . \
		../i2pd
LIBS += -L../i2pd -li2pd \
		-lcryptopp -lpthread \
		-lboost_system -lboost_date_time -lboost_filesystem -lboost_regex -lboost_program_options
SOURCES += MainWindow.cpp \
		main.cpp
HEADERS += MainWindow.h


