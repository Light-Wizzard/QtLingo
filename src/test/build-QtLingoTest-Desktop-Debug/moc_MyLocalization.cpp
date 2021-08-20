/****************************************************************************
** Meta object code from reading C++ file 'MyLocalization.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyLocalization.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLocalization.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLocalization_t {
    QByteArrayData data[6];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLocalization_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLocalization_t qt_meta_stringdata_MyLocalization = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MyLocalization"
QT_MOC_LITERAL(1, 15, 14), // "MyMessageTypes"
QT_MOC_LITERAL(2, 30, 11), // "Information"
QT_MOC_LITERAL(3, 42, 8), // "Question"
QT_MOC_LITERAL(4, 51, 7), // "Warning"
QT_MOC_LITERAL(5, 59, 8) // "Critical"

    },
    "MyLocalization\0MyMessageTypes\0Information\0"
    "Question\0Warning\0Critical"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLocalization[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    4,   19,

 // enum data: key, value
       2, uint(MyLocalization::Information),
       3, uint(MyLocalization::Question),
       4, uint(MyLocalization::Warning),
       5, uint(MyLocalization::Critical),

       0        // eod
};

void MyLocalization::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MyLocalization::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyLocalization.data,
    qt_meta_data_MyLocalization,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyLocalization::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLocalization::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLocalization.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyLocalization::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
