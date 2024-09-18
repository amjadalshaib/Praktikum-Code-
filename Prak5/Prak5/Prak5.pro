QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airport.cpp \
    algorithmen.cpp \
    booking.cpp \
    buchungsfenster.cpp \
    check.cpp \
    customer.cpp \
    flightbooking.cpp \
    hotelbooking.cpp \
    main.cpp \
    mainwindow.cpp \
    rentalcarreservation.cpp \
    trainticket.cpp \
    travel.cpp \
    travelagency.cpp \
    travelagencyui.cpp

HEADERS += \
    airport.h \
    booking.h \
    buchungsfenster.h \
    check.h \
    customer.h \
    flightbooking.h \
    graph.h \
    hotelbooking.h \
    json.hpp \
    mainwindow.h \
    rentalcarreservation.h \
    trainticket.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    buchungsfenster.ui \
    mainwindow.ui \
    travelagencyui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Graphics.qrc

DISTFILES += \
    Car.jpeg \
    Flug.png \
    Hotel.png \
    import_icon.png \
    pngtree-vector-save-icon-png-image_322173.jpg \
    search.png
