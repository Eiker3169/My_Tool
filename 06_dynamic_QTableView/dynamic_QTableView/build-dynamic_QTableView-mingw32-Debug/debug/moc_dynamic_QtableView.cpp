/****************************************************************************
** Meta object code from reading C++ file 'dynamic_QtableView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../dynamic_QTableView/dynamic_QtableView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dynamic_QtableView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dynamic_QTableView_t {
    QByteArrayData data[7];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dynamic_QTableView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dynamic_QTableView_t qt_meta_stringdata_dynamic_QTableView = {
    {
QT_MOC_LITERAL(0, 0, 18), // "dynamic_QTableView"
QT_MOC_LITERAL(1, 19, 23), // "on_columnSectionClicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 6), // "column"
QT_MOC_LITERAL(4, 51, 7), // "checked"
QT_MOC_LITERAL(5, 59, 7), // "add_row"
QT_MOC_LITERAL(6, 67, 25) // "on_actionexport_triggered"

    },
    "dynamic_QTableView\0on_columnSectionClicked\0"
    "\0column\0checked\0add_row\0"
    "on_actionexport_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dynamic_QTableView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       5,    0,   34,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dynamic_QTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dynamic_QTableView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_columnSectionClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->add_row(); break;
        case 2: _t->on_actionexport_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dynamic_QTableView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_dynamic_QTableView.data,
    qt_meta_data_dynamic_QTableView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dynamic_QTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dynamic_QTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dynamic_QTableView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int dynamic_QTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
