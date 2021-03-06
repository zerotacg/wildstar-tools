#-------------------------------------------------
#
# Project created by QtCreator 2014-02-28T14:50:10
#
#-------------------------------------------------

QT       += gui

CONFIG( debug, debug|release ) {
    TARGET = wildstar_data_d
} else {
    TARGET = wildstar_data
}

TEMPLATE = lib
#VERSION = 0.1.0

DESTDIR = $$OUT_PWD/../out

INCLUDEPATH += include

DEFINES += WILDSTAR_DATA_LIBRARY

SOURCES += \
    src/wildstar/data/c_package.cpp \
    src/wildstar/data/c_archive_index.cpp \
    src/wildstar/data/c_index_directory_node.cpp \
    src/wildstar/data/c_index_file_node.cpp \
    src/wildstar/data/a_index_node.cpp \
    src/wildstar/data/c_archive.cpp \
    src/wildstar/data/c_hash.cpp \
    src/wildstar/data/area/c_area.cpp \
    src/wildstar/data/area/c_chunk.cpp \
    src/wildstar/data/i_streamable.cpp \
    src/wildstar/data/c_tex_handler.cpp

HEADERS  += \
    include/wildstar/data/global.h \
    include/wildstar/data/exception.h \
    include/wildstar/data/c_package.h \
    include/wildstar/data/c_package.h \
    include/wildstar/data/c_archive_index.h \
    include/wildstar/data/c_index_directory_node.h \
    include/wildstar/data/c_index_file_node.h \
    include/wildstar/data/a_index_node.h \
    include/wildstar/data/c_archive.h \
    include/wildstar/data/c_hash.h \
    include/wildstar/data/area/c_area.h \
    include/wildstar/data/area/c_chunk.h \
    include/wildstar/data/i_streamable.h \
    include/wildstar/data/c_array.h \
    include/wildstar/data/c_tex_handler.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
