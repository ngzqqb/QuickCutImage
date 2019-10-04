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

SOURCES += $$PWD/CutimageImage/CutimageImage.cpp
HEADERS += $$PWD/CutimageImage/CutimageImage.hpp

SOURCES += $$PWD/GLEWSupport/glew.c
INCLUDEPATH += $$PWD/GLEWSupport
DEFINES *= GLEW_NO_GLU
DEFINES *= GLEW_STATIC
win32:{
    LIBS+= -lopengl32 -lgdi32 -luser32 -lkernel32
} else {
###libglu1-mesa-dev
###libgl1-mesa-dev
###libxi-dev
###libxmu-dev
    LIBS+=-lXmu -lXi -lGL -lXext -lX11
}
HEADERS += $$PWD/GLEWSupport/sstd_glew.hpp
SOURCES += $$PWD/GLEWSupport/sstd_glew.cpp
SOURCES += $$PWD/GLEWSupport/sstd_glew_initialization.cpp


