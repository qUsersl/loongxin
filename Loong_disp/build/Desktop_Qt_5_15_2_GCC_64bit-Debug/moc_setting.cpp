/****************************************************************************
** Meta object code from reading C++ file 'setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_setting_t {
    QByteArrayData data[12];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setting_t qt_meta_stringdata_setting = {
    {
QT_MOC_LITERAL(0, 0, 7), // "setting"
QT_MOC_LITERAL(1, 8, 13), // "Signal_Return"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(4, 45, 16), // "Slot_RefreshTime"
QT_MOC_LITERAL(5, 62, 37), // "on_doubleSpinBox_tempMax_valu..."
QT_MOC_LITERAL(6, 100, 4), // "arg1"
QT_MOC_LITERAL(7, 105, 37), // "on_doubleSpinBox_tempMin_valu..."
QT_MOC_LITERAL(8, 143, 37), // "on_doubleSpinBox_humiMax_valu..."
QT_MOC_LITERAL(9, 181, 37), // "on_doubleSpinBox_humiMin_valu..."
QT_MOC_LITERAL(10, 219, 38), // "on_doubleSpinBox_lightMax_val..."
QT_MOC_LITERAL(11, 258, 38) // "on_doubleSpinBox_lightMin_val..."

    },
    "setting\0Signal_Return\0\0on_backButton_clicked\0"
    "Slot_RefreshTime\0on_doubleSpinBox_tempMax_valueChanged\0"
    "arg1\0on_doubleSpinBox_tempMin_valueChanged\0"
    "on_doubleSpinBox_humiMax_valueChanged\0"
    "on_doubleSpinBox_humiMin_valueChanged\0"
    "on_doubleSpinBox_lightMax_valueChanged\0"
    "on_doubleSpinBox_lightMin_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       8,    1,   68,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      11,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_Return(); break;
        case 1: _t->on_backButton_clicked(); break;
        case 2: _t->Slot_RefreshTime(); break;
        case 3: _t->on_doubleSpinBox_tempMax_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_doubleSpinBox_tempMin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_doubleSpinBox_humiMax_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_doubleSpinBox_humiMin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_doubleSpinBox_lightMax_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_doubleSpinBox_lightMin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&setting::Signal_Return)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject setting::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_setting.data,
    qt_meta_data_setting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_setting.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void setting::Signal_Return()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
