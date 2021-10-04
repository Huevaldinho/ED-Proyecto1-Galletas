QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Almacen.cpp \
    Carrito.cpp \
    ColaAlmacen.cpp \
    Horno.cpp \
    ListaPaquetes.cpp \
    MaquinaEmpacadora.cpp \
    MaquinaEnsambladora.cpp \
    MaquinaMezclaMasaChocolate.cpp \
    Paquete.cpp \
    Planificador.cpp \
    Receta.cpp \
    Supervisores.cpp \
    TransportadoraMezcladoraEnsambladora.cpp \
    controlador.cpp \
    main.cpp \
    ventanaconfigurar.cpp \
    ventanaprincipal.cpp

HEADERS += \
    Estructuras.h \
    controlador.h \
    ventanaconfigurar.h \
    ventanaprincipal.h

FORMS += \
    ventanaconfigurar.ui \
    ventanaprincipal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
