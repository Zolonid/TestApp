/****************************************************************************
** Meta object code from reading C++ file 'connectionmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestApp/connectionmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectionmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnectionManager_t {
    QByteArrayData data[13];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectionManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectionManager_t qt_meta_stringdata_ConnectionManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ConnectionManager"
QT_MOC_LITERAL(1, 18, 14), // "serverResponse"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "response"
QT_MOC_LITERAL(4, 43, 16), // "connectionStatus"
QT_MOC_LITERAL(5, 60, 6), // "isOpen"
QT_MOC_LITERAL(6, 67, 8), // "sendData"
QT_MOC_LITERAL(7, 76, 4), // "data"
QT_MOC_LITERAL(8, 81, 20), // "showConnectionWindow"
QT_MOC_LITERAL(9, 102, 11), // "onReadyRead"
QT_MOC_LITERAL(10, 114, 13), // "onStateChange"
QT_MOC_LITERAL(11, 128, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(12, 157, 8) // "newState"

    },
    "ConnectionManager\0serverResponse\0\0"
    "response\0connectionStatus\0isOpen\0"
    "sendData\0data\0showConnectionWindow\0"
    "onReadyRead\0onStateChange\0"
    "QAbstractSocket::SocketState\0newState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   50,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ConnectionManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectionManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serverResponse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->connectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->showConnectionWindow(); break;
        case 4: _t->onReadyRead(); break;
        case 5: _t->onStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConnectionManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionManager::serverResponse)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConnectionManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionManager::connectionStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConnectionManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ConnectionManager.data,
    qt_meta_data_ConnectionManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConnectionManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConnectionManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ConnectionManager::serverResponse(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConnectionManager::connectionStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
