/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[16];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 12), // "buzzerSignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 19), // "autoBacklightSignal"
QT_MOC_LITERAL(4, 43, 16), // "terminaterSignal"
QT_MOC_LITERAL(5, 60, 10), // "buzzerSlot"
QT_MOC_LITERAL(6, 71, 17), // "autoBacklightSlot"
QT_MOC_LITERAL(7, 89, 14), // "terminaterSlot"
QT_MOC_LITERAL(8, 104, 9), // "errorSlot"
QT_MOC_LITERAL(9, 114, 14), // "buzzerSlotPush"
QT_MOC_LITERAL(10, 129, 21), // "autoBacklightSlotPush"
QT_MOC_LITERAL(11, 151, 18), // "terminaterSlotPush"
QT_MOC_LITERAL(12, 170, 26), // "on_checkBox_buzzer_clicked"
QT_MOC_LITERAL(13, 197, 40), // "on_spinBox_autoBacklight_edit..."
QT_MOC_LITERAL(14, 238, 32), // "on_comboBox_terminater_activated"
QT_MOC_LITERAL(15, 271, 4) // "arg1"

    },
    "Settings\0buzzerSignal\0\0autoBacklightSignal\0"
    "terminaterSignal\0buzzerSlot\0"
    "autoBacklightSlot\0terminaterSlot\0"
    "errorSlot\0buzzerSlotPush\0autoBacklightSlotPush\0"
    "terminaterSlotPush\0on_checkBox_buzzer_clicked\0"
    "on_spinBox_autoBacklight_editingFinished\0"
    "on_comboBox_terminater_activated\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   88,    2, 0x0a /* Public */,
       6,    1,   91,    2, 0x0a /* Public */,
       7,    1,   94,    2, 0x0a /* Public */,
       8,    1,   97,    2, 0x0a /* Public */,
       9,    0,  100,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x08 /* Private */,
      13,    0,  104,    2, 0x08 /* Private */,
      14,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buzzerSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->autoBacklightSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->terminaterSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->buzzerSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->autoBacklightSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->terminaterSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->errorSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->buzzerSlotPush(); break;
        case 8: _t->autoBacklightSlotPush(); break;
        case 9: _t->terminaterSlotPush(); break;
        case 10: _t->on_checkBox_buzzer_clicked(); break;
        case 11: _t->on_spinBox_autoBacklight_editingFinished(); break;
        case 12: _t->on_comboBox_terminater_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Settings::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::buzzerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::autoBacklightSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::terminaterSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Settings::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Settings.data,
    qt_meta_data_Settings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Settings::buzzerSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Settings::autoBacklightSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Settings::terminaterSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
