/****************************************************************************
** Meta object code from reading C++ file 'screencontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/controller/screencontroller.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screencontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ScreenController_t {
    uint offsetsAndSizes[30];
    char stringdata0[17];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[11];
    char stringdata5[9];
    char stringdata6[11];
    char stringdata7[11];
    char stringdata8[9];
    char stringdata9[14];
    char stringdata10[10];
    char stringdata11[10];
    char stringdata12[20];
    char stringdata13[2];
    char stringdata14[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ScreenController_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ScreenController_t qt_meta_stringdata_ScreenController = {
    {
        QT_MOC_LITERAL(0, 16),  // "ScreenController"
        QT_MOC_LITERAL(17, 11),  // "signalsHome"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 9),  // "songTitle"
        QT_MOC_LITERAL(40, 10),  // "artistName"
        QT_MOC_LITERAL(51, 8),  // "coverArt"
        QT_MOC_LITERAL(60, 10),  // "onSlotHome"
        QT_MOC_LITERAL(71, 10),  // "pushScreen"
        QT_MOC_LITERAL(82, 8),  // "screenId"
        QT_MOC_LITERAL(91, 13),  // "replaceScreen"
        QT_MOC_LITERAL(105, 9),  // "popScreen"
        QT_MOC_LITERAL(115, 9),  // "popToRoot"
        QT_MOC_LITERAL(125, 19),  // "broadcastDbusSignal"
        QT_MOC_LITERAL(145, 1),  // "n"
        QT_MOC_LITERAL(147, 13)   // "loadMediaList"
    },
    "ScreenController",
    "signalsHome",
    "",
    "songTitle",
    "artistName",
    "coverArt",
    "onSlotHome",
    "pushScreen",
    "screenId",
    "replaceScreen",
    "popScreen",
    "popToRoot",
    "broadcastDbusSignal",
    "n",
    "loadMediaList"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ScreenController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    3,   69,    2, 0x0a,    5 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   76,    2, 0x02,    9 /* Public */,
       9,    1,   79,    2, 0x02,   11 /* Public */,
      10,    0,   82,    2, 0x02,   13 /* Public */,
      11,    0,   83,    2, 0x02,   14 /* Public */,
      12,    1,   84,    2, 0x02,   15 /* Public */,
      14,    0,   87,    2, 0x02,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ScreenController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScreenController.offsetsAndSizes,
    qt_meta_data_ScreenController,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ScreenController_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ScreenController, std::true_type>,
        // method 'signalsHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onSlotHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'pushScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'replaceScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'popScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'popToRoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'broadcastDbusSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadMediaList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ScreenController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScreenController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalsHome((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->onSlotHome((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->pushScreen((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->replaceScreen((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->popScreen(); break;
        case 5: _t->popToRoot(); break;
        case 6: _t->broadcastDbusSignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->loadMediaList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScreenController::*)(QString , QString , QString );
            if (_t _q_method = &ScreenController::signalsHome; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ScreenController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScreenController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScreenController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ScreenController::signalsHome(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
