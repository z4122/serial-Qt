/****************************************************************************
** Meta object code from reading C++ file 'serial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serial_t {
    QByteArrayData data[14];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serial_t qt_meta_stringdata_serial = {
    {
QT_MOC_LITERAL(0, 0, 6), // "serial"
QT_MOC_LITERAL(1, 7, 15), // "serialStartWork"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 27), // "on_openSerialButton_clicked"
QT_MOC_LITERAL(4, 52, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(5, 75, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(6, 97, 25), // "on_locationButton_clicked"
QT_MOC_LITERAL(7, 123, 15), // "serialBoxChange"
QT_MOC_LITERAL(8, 139, 8), // "textShow"
QT_MOC_LITERAL(9, 148, 8), // "getError"
QT_MOC_LITERAL(10, 157, 13), // "readParameter"
QT_MOC_LITERAL(11, 171, 12), // "setParameter"
QT_MOC_LITERAL(12, 184, 13), // "QString2Float"
QT_MOC_LITERAL(13, 198, 5) // "input"

    },
    "serial\0serialStartWork\0\0"
    "on_openSerialButton_clicked\0"
    "on_startButton_clicked\0on_stopButton_clicked\0"
    "on_locationButton_clicked\0serialBoxChange\0"
    "textShow\0getError\0readParameter\0"
    "setParameter\0QString2Float\0input"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    1,   74,    2, 0x0a /* Public */,
       8,    1,   77,    2, 0x0a /* Public */,
       9,    1,   80,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Float, QMetaType::QString,   13,

       0        // eod
};

void serial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serial *_t = static_cast<serial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serialStartWork(); break;
        case 1: _t->on_openSerialButton_clicked(); break;
        case 2: _t->on_startButton_clicked(); break;
        case 3: _t->on_stopButton_clicked(); break;
        case 4: _t->on_locationButton_clicked(); break;
        case 5: _t->serialBoxChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->textShow((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->getError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->readParameter(); break;
        case 9: _t->setParameter(); break;
        case 10: { float _r = _t->QString2Float((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (serial::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serial::serialStartWork)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject serial::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_serial.data,
      qt_meta_data_serial,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *serial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serial.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int serial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void serial::serialStartWork()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
