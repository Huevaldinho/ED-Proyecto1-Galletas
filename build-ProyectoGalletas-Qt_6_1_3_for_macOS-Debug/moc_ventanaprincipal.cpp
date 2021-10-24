/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ProyectoGalletas/ventanaprincipal.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaPrincipal_t {
    const uint offsetsAndSize[22];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(17, 21), // "on_btnIniciar_clicked"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 19), // "on_btnPausa_clicked"
QT_MOC_LITERAL(60, 21), // "on_btnDetener_clicked"
QT_MOC_LITERAL(82, 35), // "on_btnCambiarEstadoMaquina1_c..."
QT_MOC_LITERAL(118, 35), // "on_btnCambiarEstadoMaquina2_c..."
QT_MOC_LITERAL(154, 35), // "on_btnCambiarEstadoMaquina3_c..."
QT_MOC_LITERAL(190, 22), // "on_btnReanudar_clicked"
QT_MOC_LITERAL(213, 39), // "on_btnCambiarEstadoEnsamblado..."
QT_MOC_LITERAL(253, 32) // "on_btnCambiarEstadoHorno_clicked"

    },
    "VentanaPrincipal\0on_btnIniciar_clicked\0"
    "\0on_btnPausa_clicked\0on_btnDetener_clicked\0"
    "on_btnCambiarEstadoMaquina1_clicked\0"
    "on_btnCambiarEstadoMaquina2_clicked\0"
    "on_btnCambiarEstadoMaquina3_clicked\0"
    "on_btnReanudar_clicked\0"
    "on_btnCambiarEstadoEnsambladora_clicked\0"
    "on_btnCambiarEstadoHorno_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    0 /* Private */,
       3,    0,   69,    2, 0x08,    1 /* Private */,
       4,    0,   70,    2, 0x08,    2 /* Private */,
       5,    0,   71,    2, 0x08,    3 /* Private */,
       6,    0,   72,    2, 0x08,    4 /* Private */,
       7,    0,   73,    2, 0x08,    5 /* Private */,
       8,    0,   74,    2, 0x08,    6 /* Private */,
       9,    0,   75,    2, 0x08,    7 /* Private */,
      10,    0,   76,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VentanaPrincipal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnIniciar_clicked(); break;
        case 1: _t->on_btnPausa_clicked(); break;
        case 2: _t->on_btnDetener_clicked(); break;
        case 3: _t->on_btnCambiarEstadoMaquina1_clicked(); break;
        case 4: _t->on_btnCambiarEstadoMaquina2_clicked(); break;
        case 5: _t->on_btnCambiarEstadoMaquina3_clicked(); break;
        case 6: _t->on_btnReanudar_clicked(); break;
        case 7: _t->on_btnCambiarEstadoEnsambladora_clicked(); break;
        case 8: _t->on_btnCambiarEstadoHorno_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject VentanaPrincipal::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_VentanaPrincipal.offsetsAndSize,
    qt_meta_data_VentanaPrincipal,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_VentanaPrincipal_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
