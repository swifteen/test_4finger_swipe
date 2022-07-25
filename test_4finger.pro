QT += widgets
TARGET = test_4finger

TEMPLATE=app

HEADERS   = gesturelabel.h \
            gesturewidget.h \
            fourfingertap.h
SOURCES   = gesturelabel.cpp \
            main.cpp \
            gesturewidget.cpp \
            fourfingertap.cpp

# install

INSTALLS += target

FORMS += \
    gesturewidget.ui

