/****************************************************************************
** Meta object code from reading C++ file 'qonlinetts.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../third-party/qonlinetranslator/src/qonlinetts.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qonlinetts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QOnlineTts_t {
    QByteArrayData data[14];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QOnlineTts_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QOnlineTts_t qt_meta_stringdata_QOnlineTts = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QOnlineTts"
QT_MOC_LITERAL(1, 11, 5), // "Voice"
QT_MOC_LITERAL(2, 17, 7), // "NoVoice"
QT_MOC_LITERAL(3, 25, 5), // "Zahar"
QT_MOC_LITERAL(4, 31, 5), // "Ermil"
QT_MOC_LITERAL(5, 37, 4), // "Jane"
QT_MOC_LITERAL(6, 42, 6), // "Oksana"
QT_MOC_LITERAL(7, 49, 5), // "Alyss"
QT_MOC_LITERAL(8, 55, 5), // "Omazh"
QT_MOC_LITERAL(9, 61, 7), // "Emotion"
QT_MOC_LITERAL(10, 69, 9), // "NoEmotion"
QT_MOC_LITERAL(11, 79, 7), // "Neutral"
QT_MOC_LITERAL(12, 87, 4), // "Good"
QT_MOC_LITERAL(13, 92, 4) // "Evil"

    },
    "QOnlineTts\0Voice\0NoVoice\0Zahar\0Ermil\0"
    "Jane\0Oksana\0Alyss\0Omazh\0Emotion\0"
    "NoEmotion\0Neutral\0Good\0Evil"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QOnlineTts[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    7,   24,
       9,    9, 0x0,    4,   38,

 // enum data: key, value
       2, uint(QOnlineTts::NoVoice),
       3, uint(QOnlineTts::Zahar),
       4, uint(QOnlineTts::Ermil),
       5, uint(QOnlineTts::Jane),
       6, uint(QOnlineTts::Oksana),
       7, uint(QOnlineTts::Alyss),
       8, uint(QOnlineTts::Omazh),
      10, uint(QOnlineTts::NoEmotion),
      11, uint(QOnlineTts::Neutral),
      12, uint(QOnlineTts::Good),
      13, uint(QOnlineTts::Evil),

       0        // eod
};

void QOnlineTts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QOnlineTts::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QOnlineTts.data,
    qt_meta_data_QOnlineTts,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QOnlineTts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QOnlineTts::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QOnlineTts.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QOnlineTts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
