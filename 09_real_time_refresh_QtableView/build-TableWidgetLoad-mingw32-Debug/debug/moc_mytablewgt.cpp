/****************************************************************************
** Meta object code from reading C++ file 'mytablewgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TableWidgetLoad/mytablewgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytablewgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyTableWgt_t {
    QByteArrayData data[8];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTableWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTableWgt_t qt_meta_stringdata_MyTableWgt = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyTableWgt"
QT_MOC_LITERAL(1, 11, 13), // "sSendVerValue"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "startRunning"
QT_MOC_LITERAL(4, 39, 22), // "OnVertivalValueChanged"
QT_MOC_LITERAL(5, 62, 7), // "i_value"
QT_MOC_LITERAL(6, 70, 12), // "ReceiverData"
QT_MOC_LITERAL(7, 83, 15) // "ReceiverChanged"

    },
    "MyTableWgt\0sSendVerValue\0\0startRunning\0"
    "OnVertivalValueChanged\0i_value\0"
    "ReceiverData\0ReceiverChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTableWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   45,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyTableWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyTableWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sSendVerValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->startRunning((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->OnVertivalValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ReceiverData(); break;
        case 4: _t->ReceiverChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyTableWgt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTableWgt::sSendVerValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyTableWgt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyTableWgt::startRunning)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyTableWgt::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableWidget::staticMetaObject>(),
    qt_meta_stringdata_MyTableWgt.data,
    qt_meta_data_MyTableWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyTableWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTableWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyTableWgt.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int MyTableWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyTableWgt::sSendVerValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTableWgt::startRunning(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
