/****************************************************************************
** Meta object code from reading C++ file 'serial_port_test.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Serial_port_test/serial_port_test.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_port_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Serial_port_test_t {
    QByteArrayData data[20];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Serial_port_test_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Serial_port_test_t qt_meta_stringdata_Serial_port_test = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Serial_port_test"
QT_MOC_LITERAL(1, 17, 8), // "recvData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 17), // "message_filtering"
QT_MOC_LITERAL(4, 45, 11), // "eventFilter"
QT_MOC_LITERAL(5, 57, 7), // "watched"
QT_MOC_LITERAL(6, 65, 7), // "QEvent*"
QT_MOC_LITERAL(7, 73, 5), // "event"
QT_MOC_LITERAL(8, 79, 13), // "indexOfNthStr"
QT_MOC_LITERAL(9, 93, 9), // "sourceStr"
QT_MOC_LITERAL(10, 103, 3), // "str"
QT_MOC_LITERAL(11, 107, 1), // "N"
QT_MOC_LITERAL(12, 109, 15), // "updateHighlight"
QT_MOC_LITERAL(13, 125, 24), // "on_openSerialBtn_clicked"
QT_MOC_LITERAL(14, 150, 21), // "on_clear_data_clicked"
QT_MOC_LITERAL(15, 172, 21), // "on_start_test_clicked"
QT_MOC_LITERAL(16, 194, 21), // "on_close_test_clicked"
QT_MOC_LITERAL(17, 216, 26), // "on_start_filtering_clicked"
QT_MOC_LITERAL(18, 243, 25), // "on_stop_filtering_clicked"
QT_MOC_LITERAL(19, 269, 15) // "on_send_clicked"

    },
    "Serial_port_test\0recvData\0\0message_filtering\0"
    "eventFilter\0watched\0QEvent*\0event\0"
    "indexOfNthStr\0sourceStr\0str\0N\0"
    "updateHighlight\0on_openSerialBtn_clicked\0"
    "on_clear_data_clicked\0on_start_test_clicked\0"
    "on_close_test_clicked\0on_start_filtering_clicked\0"
    "on_stop_filtering_clicked\0on_send_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Serial_port_test[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    2,   76,    2, 0x0a /* Public */,
       8,    3,   81,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    0,   93,    2, 0x08 /* Private */,
      18,    0,   94,    2, 0x08 /* Private */,
      19,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 6,    5,    7,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    9,   10,   11,
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

void Serial_port_test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Serial_port_test *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvData(); break;
        case 1: { bool _r = _t->message_filtering();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->indexOfNthStr((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->updateHighlight(); break;
        case 5: _t->on_openSerialBtn_clicked(); break;
        case 6: _t->on_clear_data_clicked(); break;
        case 7: _t->on_start_test_clicked(); break;
        case 8: _t->on_close_test_clicked(); break;
        case 9: _t->on_start_filtering_clicked(); break;
        case 10: _t->on_stop_filtering_clicked(); break;
        case 11: _t->on_send_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Serial_port_test::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Serial_port_test.data,
    qt_meta_data_Serial_port_test,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Serial_port_test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Serial_port_test::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Serial_port_test.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Serial_port_test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
