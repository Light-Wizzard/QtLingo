/****************************************************************************
** Meta object code from reading C++ file 'MyOrgSettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyOrgSettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyOrgSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyOrgSettings_t {
    QByteArrayData data[29];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyOrgSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyOrgSettings_t qt_meta_stringdata_MyOrgSettings = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MyOrgSettings"
QT_MOC_LITERAL(1, 14, 20), // "sendInternetProgress"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 18), // "sendUpdateSettings"
QT_MOC_LITERAL(4, 55, 16), // "onUpdateSettings"
QT_MOC_LITERAL(5, 72, 10), // "MyFileinfo"
QT_MOC_LITERAL(6, 83, 12), // "AbsolutePath"
QT_MOC_LITERAL(7, 96, 16), // "AbsoluteFilePath"
QT_MOC_LITERAL(8, 113, 8), // "BaseName"
QT_MOC_LITERAL(9, 122, 9), // "BirthTime"
QT_MOC_LITERAL(10, 132, 13), // "CanonicalPath"
QT_MOC_LITERAL(11, 146, 17), // "CanonicalFilePath"
QT_MOC_LITERAL(12, 164, 16), // "CompleteBaseName"
QT_MOC_LITERAL(13, 181, 14), // "CompleteSuffix"
QT_MOC_LITERAL(14, 196, 9), // "Directory"
QT_MOC_LITERAL(15, 206, 8), // "FileName"
QT_MOC_LITERAL(16, 215, 8), // "FilePath"
QT_MOC_LITERAL(17, 224, 10), // "IsWritable"
QT_MOC_LITERAL(18, 235, 6), // "IsFile"
QT_MOC_LITERAL(19, 242, 8), // "IsFolder"
QT_MOC_LITERAL(20, 251, 8), // "FileSize"
QT_MOC_LITERAL(21, 260, 9), // "IsSymLink"
QT_MOC_LITERAL(22, 270, 13), // "SymLinkTarget"
QT_MOC_LITERAL(23, 284, 14), // "MyMessageTypes"
QT_MOC_LITERAL(24, 299, 11), // "Information"
QT_MOC_LITERAL(25, 311, 8), // "Question"
QT_MOC_LITERAL(26, 320, 7), // "Warning"
QT_MOC_LITERAL(27, 328, 8), // "Critical"
QT_MOC_LITERAL(28, 337, 5) // "Debug"

    },
    "MyOrgSettings\0sendInternetProgress\0\0"
    "sendUpdateSettings\0onUpdateSettings\0"
    "MyFileinfo\0AbsolutePath\0AbsoluteFilePath\0"
    "BaseName\0BirthTime\0CanonicalPath\0"
    "CanonicalFilePath\0CompleteBaseName\0"
    "CompleteSuffix\0Directory\0FileName\0"
    "FilePath\0IsWritable\0IsFile\0IsFolder\0"
    "FileSize\0IsSymLink\0SymLinkTarget\0"
    "MyMessageTypes\0Information\0Question\0"
    "Warning\0Critical\0Debug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyOrgSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       2,   32, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       5,    5, 0x0,   17,   42,
      23,   23, 0x0,    5,   76,

 // enum data: key, value
       6, uint(MyOrgSettings::AbsolutePath),
       7, uint(MyOrgSettings::AbsoluteFilePath),
       8, uint(MyOrgSettings::BaseName),
       9, uint(MyOrgSettings::BirthTime),
      10, uint(MyOrgSettings::CanonicalPath),
      11, uint(MyOrgSettings::CanonicalFilePath),
      12, uint(MyOrgSettings::CompleteBaseName),
      13, uint(MyOrgSettings::CompleteSuffix),
      14, uint(MyOrgSettings::Directory),
      15, uint(MyOrgSettings::FileName),
      16, uint(MyOrgSettings::FilePath),
      17, uint(MyOrgSettings::IsWritable),
      18, uint(MyOrgSettings::IsFile),
      19, uint(MyOrgSettings::IsFolder),
      20, uint(MyOrgSettings::FileSize),
      21, uint(MyOrgSettings::IsSymLink),
      22, uint(MyOrgSettings::SymLinkTarget),
      24, uint(MyOrgSettings::Information),
      25, uint(MyOrgSettings::Question),
      26, uint(MyOrgSettings::Warning),
      27, uint(MyOrgSettings::Critical),
      28, uint(MyOrgSettings::Debug),

       0        // eod
};

void MyOrgSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyOrgSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendInternetProgress(); break;
        case 1: _t->sendUpdateSettings(); break;
        case 2: _t->onUpdateSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyOrgSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyOrgSettings::sendInternetProgress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyOrgSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyOrgSettings::sendUpdateSettings)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MyOrgSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyOrgSettings.data,
    qt_meta_data_MyOrgSettings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyOrgSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyOrgSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyOrgSettings.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyOrgSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MyOrgSettings::sendInternetProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyOrgSettings::sendUpdateSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
