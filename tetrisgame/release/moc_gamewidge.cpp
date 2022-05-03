/****************************************************************************
** Meta object code from reading C++ file 'gamewidge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamewidge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWidge_t {
    QByteArrayData data[14];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWidge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWidge_t qt_meta_stringdata_GameWidge = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameWidge"
QT_MOC_LITERAL(1, 10, 8), // "gameOver"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "sentdata"
QT_MOC_LITERAL(4, 29, 5), // "int**"
QT_MOC_LITERAL(5, 35, 4), // "size"
QT_MOC_LITERAL(6, 40, 9), // "startgame"
QT_MOC_LITERAL(7, 50, 5), // "level"
QT_MOC_LITERAL(8, 56, 4), // "poin"
QT_MOC_LITERAL(9, 61, 10), // "paintEvent"
QT_MOC_LITERAL(10, 72, 12), // "QPaintEvent*"
QT_MOC_LITERAL(11, 85, 5), // "event"
QT_MOC_LITERAL(12, 91, 13), // "keyPressEvent"
QT_MOC_LITERAL(13, 105, 10) // "QKeyEvent*"

    },
    "GameWidge\0gameOver\0\0sentdata\0int**\0"
    "size\0startgame\0level\0poin\0paintEvent\0"
    "QPaintEvent*\0event\0keyPressEvent\0"
    "QKeyEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWidge[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   43,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
      12,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   11,

       0        // eod
};

void GameWidge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameWidge *_t = static_cast<GameWidge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameOver(); break;
        case 1: _t->sentdata((*reinterpret_cast< int**(*)>(_a[1]))); break;
        case 2: _t->startgame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 3: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 4: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameWidge::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidge::gameOver)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GameWidge::*_t)(int * * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWidge::sentdata)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject GameWidge::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameWidge.data,
      qt_meta_data_GameWidge,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameWidge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWidge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidge.stringdata0))
        return static_cast<void*>(const_cast< GameWidge*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameWidge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void GameWidge::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameWidge::sentdata(int * * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
