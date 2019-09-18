QT += core
QT += gui
QT += quick

# set cplusplus version ...
win32-msvc{
    QMAKE_CXXFLAGS += /std:c++latest
}else{
    CONFIG += c++17
}

SOURCES += $$PWD/main.cpp
RESOURCES += qml.qrc

CONFIG(debug,debug|release){
    TARGET = QuickCutImage_debug
}else{
    TARGET = QuickCutImage
}

# out put dir ...
DESTDIR = $$[QT_INSTALL_BINS]




