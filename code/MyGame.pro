TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "D:/SFML-2.5.1/include"
LIBS += -L"D:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        audio.cpp \
        balls.cpp \
        coins.cpp \
        generator.cpp \
        hero.cpp \
        main.cpp \
        menu.cpp \
        panel.cpp \
        poziom1.cpp \
        poziom2.cpp \
        poziom3.cpp \
        poziom4.cpp \
        poziom5.cpp \
        poziomabstra.cpp \
        poziomtextury.cpp \
        scena.cpp

HEADERS += \
    audio.h \
    balls.h \
    coins.h \
    generator.h \
    hero.h \
    menu.h \
    panel.h \
    poziom1.h \
    poziom2.h \
    poziom3.h \
    poziom4.h \
    poziom5.h \
    poziomabstra.h \
    poziomtextury.h \
    scena.h
