/****************************************************************************
** Meta object code from reading C++ file 'node1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../node1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'node1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_node1_t {
    QByteArrayData data[14];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_node1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_node1_t qt_meta_stringdata_node1 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "node1"
QT_MOC_LITERAL(1, 6, 13), // "Signal_Return"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "Node1_Danger"
QT_MOC_LITERAL(4, 34, 10), // "Node1_Safe"
QT_MOC_LITERAL(5, 45, 23), // "on_back_1Button_clicked"
QT_MOC_LITERAL(6, 69, 16), // "Slot_RefreshTime"
QT_MOC_LITERAL(7, 86, 12), // "Slot_Warning"
QT_MOC_LITERAL(8, 99, 11), // "error_index"
QT_MOC_LITERAL(9, 111, 29), // "on_temperature1Button_clicked"
QT_MOC_LITERAL(10, 141, 23), // "on_humi_1Button_clicked"
QT_MOC_LITERAL(11, 165, 24), // "on_light_1Button_clicked"
QT_MOC_LITERAL(12, 190, 23), // "on_smog_1Button_clicked"
QT_MOC_LITERAL(13, 214, 26) // "on_pushButton_data_clicked"

    },
    "node1\0Signal_Return\0\0Node1_Danger\0"
    "Node1_Safe\0on_back_1Button_clicked\0"
    "Slot_RefreshTime\0Slot_Warning\0error_index\0"
    "on_temperature1Button_clicked\0"
    "on_humi_1Button_clicked\0"
    "on_light_1Button_clicked\0"
    "on_smog_1Button_clicked\0"
    "on_pushButton_data_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_node1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void node1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<node1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_Return(); break;
        case 1: _t->Node1_Danger(); break;
        case 2: _t->Node1_Safe(); break;
        case 3: _t->on_back_1Button_clicked(); break;
        case 4: _t->Slot_RefreshTime(); break;
        case 5: _t->Slot_Warning((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->on_temperature1Button_clicked(); break;
        case 7: _t->on_humi_1Button_clicked(); break;
        case 8: _t->on_light_1Button_clicked(); break;
        case 9: _t->on_smog_1Button_clicked(); break;
        case 10: _t->on_pushButton_data_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (node1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&node1::Signal_Return)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (node1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&node1::Node1_Danger)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (node1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&node1::Node1_Safe)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject node1::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_node1.data,
    qt_meta_data_node1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *node1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *node1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_node1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int node1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void node1::Signal_Return()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void node1::Node1_Danger()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void node1::Node1_Safe()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
