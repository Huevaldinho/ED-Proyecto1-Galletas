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
    ColaBandas.cpp \
    Horno.cpp \
    ListaBandejas.cpp \
    ListaPaquetes.cpp \
    MaquinaEmpacadora.cpp \
    MaquinaEnsambladora.cpp \
    MaquinaMezclaMasaChocolate.cpp \
    Planificador.cpp \
    Receta.cpp \
    Supervisores.cpp \
    Transportador.cpp \
    Transportadores.cpp \
    controlador.cpp \
    main.cpp \
    ventanaconfigurar.cpp \
    ventanaprincipal.cpp

HEADERS += \
    ../../../../../Escritorio/TEC/Cursos - Semestre 2/Estructuras de Datos/Semana 9/EjemploMutex/CrearPunteros.h \
    Almacen.h \
    Carrito.h \
    ColaAlmacen.h \
    ColaBandas.h \
    Estructuras.h \
    Horno.h \
    ListaBandejas.h \
    ListaPaquetes.h \
    MaquinaEmpacadora.h \
    MaquinaEnsambladora.h \
    MaquinaMezclaMasaChocolate.h \
    Nodo.h \
    NodoBandas.h \
    NodoBandeja.h \
    NodoColaPeticiones.h \
    Planificador.h \
    Punteros.h \
    Receta.h \
    Supervisor.h \
    Transportador.h \
    Transportadores.h \
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
