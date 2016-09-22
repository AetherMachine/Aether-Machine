QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "Aether Machine"
TEMPLATE = app

HEADERS += MainWindow.h \
    GraphicsEngine.h \
    ScriptEngine.h \
    OpenGLWidget.h

SOURCES += main.cpp\
    MainWindow.cpp \
    GraphicsEngine.cpp \
    ScriptEngine.cpp \
    OpenGLWidget.cpp

FORMS += MainWindow.ui
