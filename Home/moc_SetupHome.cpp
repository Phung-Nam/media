/****************************************************************************
** Meta object code from reading C++ file 'SetupHome.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/controller/SetupHome.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SetupHome.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_SetupHome_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[16];
    char stringdata5[9];
    char stringdata6[28];
    char stringdata7[21];
    char stringdata8[17];
    char stringdata9[12];
    char stringdata10[24];
    char stringdata11[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SetupHome_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SetupHome_t qt_meta_stringdata_SetupHome = {
    {
        QT_MOC_LITERAL(0, 9),  // "SetupHome"
        QT_MOC_LITERAL(10, 20),  // "myValueVolumeChanged"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 13),  // "myValueVolume"
        QT_MOC_LITERAL(46, 15),  // "languageChanged"
        QT_MOC_LITERAL(62, 8),  // "language"
        QT_MOC_LITERAL(71, 27),  // "sourceLanguegeScreenChanged"
        QT_MOC_LITERAL(99, 20),  // "sourceLanguegeScreen"
        QT_MOC_LITERAL(120, 16),  // "setMyValueVolume"
        QT_MOC_LITERAL(137, 11),  // "setLanguage"
        QT_MOC_LITERAL(149, 23),  // "setSourceLanguegeScreen"
        QT_MOC_LITERAL(173, 4)   // "test"
    },
    "SetupHome",
    "myValueVolumeChanged",
    "",
    "myValueVolume",
    "languageChanged",
    "language",
    "sourceLanguegeScreenChanged",
    "sourceLanguegeScreen",
    "setMyValueVolume",
    "setLanguage",
    "setSourceLanguegeScreen",
    "test"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SetupHome[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   75, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    4 /* Public */,
       4,    1,   59,    2, 0x06,    6 /* Public */,
       6,    1,   62,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   65,    2, 0x0a,   10 /* Public */,
       9,    1,   68,    2, 0x0a,   12 /* Public */,
      10,    1,   71,    2, 0x0a,   14 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   74,    2, 0x02,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00015103, uint(0), 0,
       5, QMetaType::QString, 0x00015103, uint(1), 0,
       7, QMetaType::QString, 0x00015103, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SetupHome::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SetupHome.offsetsAndSizes,
    qt_meta_data_SetupHome,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SetupHome_t,
        // property 'myValueVolume'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'language'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'sourceLanguegeScreen'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SetupHome, std::true_type>,
        // method 'myValueVolumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'languageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sourceLanguegeScreenChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setMyValueVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setLanguage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setSourceLanguegeScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'test'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SetupHome::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SetupHome *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->myValueVolumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->languageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sourceLanguegeScreenChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setMyValueVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setLanguage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setSourceLanguegeScreen((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->test(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SetupHome::*)(int );
            if (_t _q_method = &SetupHome::myValueVolumeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SetupHome::*)(QString );
            if (_t _q_method = &SetupHome::languageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SetupHome::*)(QString );
            if (_t _q_method = &SetupHome::sourceLanguegeScreenChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SetupHome *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->myValueVolume(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->language(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->sourceLanguegeScreen(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SetupHome *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMyValueVolume(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setLanguage(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setSourceLanguegeScreen(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SetupHome::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetupHome::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetupHome.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SetupHome::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SetupHome::myValueVolumeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SetupHome::languageChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SetupHome::sourceLanguegeScreenChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
