/****************************************************************************
** Meta object code from reading C++ file 'appdefines.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/common/appdefines.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appdefines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_AppEnums_t {
    uint offsetsAndSizes[8];
    char stringdata0[9];
    char stringdata1[10];
    char stringdata2[20];
    char stringdata3[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AppEnums_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AppEnums_t qt_meta_stringdata_AppEnums = {
    {
        QT_MOC_LITERAL(0, 8),  // "AppEnums"
        QT_MOC_LITERAL(9, 9),  // "SCREEN_ID"
        QT_MOC_LITERAL(19, 19),  // "SCREEN_ID_HOME_MENU"
        QT_MOC_LITERAL(39, 21)   // "SCREEN_ID_HOME_SETTUP"
    },
    "AppEnums",
    "SCREEN_ID",
    "SCREEN_ID_HOME_MENU",
    "SCREEN_ID_HOME_SETTUP"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AppEnums[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    2,   19,

 // enum data: key, value
       2, uint(AppEnums::SCREEN_ID_HOME_MENU),
       3, uint(AppEnums::SCREEN_ID_HOME_SETTUP),

       0        // eod
};

Q_CONSTINIT const QMetaObject AppEnums::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppEnums.offsetsAndSizes,
    qt_meta_data_AppEnums,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AppEnums_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AppEnums, std::true_type>
    >,
    nullptr
} };

void AppEnums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *AppEnums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppEnums::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppEnums.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppEnums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
