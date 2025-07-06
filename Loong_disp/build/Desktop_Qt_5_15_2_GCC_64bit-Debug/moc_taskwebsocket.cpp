/****************************************************************************
** Meta object code from reading C++ file 'taskwebsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../test/Loong_disp/taskwebsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskwebsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_taskWebSocket_t {
    QByteArrayData data[12];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_taskWebSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_taskWebSocket_t qt_meta_stringdata_taskWebSocket = {
    {
QT_MOC_LITERAL(0, 0, 13), // "taskWebSocket"
QT_MOC_LITERAL(1, 14, 25), // "Signal_WebSocketConnected"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 28), // "Signal_WebSocketDisconnected"
QT_MOC_LITERAL(4, 70, 21), // "Signal_WebSocketError"
QT_MOC_LITERAL(5, 92, 5), // "error"
QT_MOC_LITERAL(6, 98, 15), // "TaskSendToCloud"
QT_MOC_LITERAL(7, 114, 23), // "Slot_WebSocketConnected"
QT_MOC_LITERAL(8, 138, 26), // "Slot_WebSocketDisconnected"
QT_MOC_LITERAL(9, 165, 19), // "Slot_WebSocketError"
QT_MOC_LITERAL(10, 185, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(11, 214, 19) // "Slot_ReconnectTimer"

    },
    "taskWebSocket\0Signal_WebSocketConnected\0"
    "\0Signal_WebSocketDisconnected\0"
    "Signal_WebSocketError\0error\0TaskSendToCloud\0"
    "Slot_WebSocketConnected\0"
    "Slot_WebSocketDisconnected\0"
    "Slot_WebSocketError\0QAbstractSocket::SocketError\0"
    "Slot_ReconnectTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_taskWebSocket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    5,
    QMetaType::Void,

       0        // eod
};

void taskWebSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<taskWebSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_WebSocketConnected(); break;
        case 1: _t->Signal_WebSocketDisconnected(); break;
        case 2: _t->Signal_WebSocketError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->TaskSendToCloud(); break;
        case 4: _t->Slot_WebSocketConnected(); break;
        case 5: _t->Slot_WebSocketDisconnected(); break;
        case 6: _t->Slot_WebSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->Slot_ReconnectTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (taskWebSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskWebSocket::Signal_WebSocketConnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (taskWebSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskWebSocket::Signal_WebSocketDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (taskWebSocket::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskWebSocket::Signal_WebSocketError)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject taskWebSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_taskWebSocket.data,
    qt_meta_data_taskWebSocket,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *taskWebSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *taskWebSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_taskWebSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int taskWebSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void taskWebSocket::Signal_WebSocketConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void taskWebSocket::Signal_WebSocketDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void taskWebSocket::Signal_WebSocketError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
