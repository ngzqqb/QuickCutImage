QT += core
QT += gui
QT += quick
QT += widgets

# set cplusplus version ...
win32-msvc{
    QMAKE_CXXFLAGS += /std:c++latest
}else{
    CONFIG += c++17
}

SOURCES += $$PWD/main.cpp
RESOURCES += $$PWD/TheQml/qml.qrc

CONFIG(debug,debug|release){
    TARGET = QuickCutImage_debug
}else{
    TARGET = QuickCutImage
    DEFINES *= NDEBUG
}

# out put dir ...
DESTDIR = $$[QT_INSTALL_BINS]

# sources ...

HEADERS += $$PWD/all_in_one.hpp
SOURCES += $$PWD/register_all_in_one.cpp

SOURCES += $$PWD/CutImageScene/CutImageScene.cpp
HEADERS += $$PWD/CutImageScene/CutImageScene.hpp

SOURCES += $$PWD/CutImageView/CutImageView.cpp
HEADERS += $$PWD/CutImageView/CutImageView.hpp












