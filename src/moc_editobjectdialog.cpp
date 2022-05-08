/****************************************************************************
** Meta object code from reading C++ file 'editobjectdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "controllers/editobjectdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editobjectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditObjectDialog_t {
    QByteArrayData data[10];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditObjectDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditObjectDialog_t qt_meta_stringdata_EditObjectDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "EditObjectDialog"
QT_MOC_LITERAL(1, 17, 26), // "on_btnRenameObject_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 26), // "on_btnRemoveObject_clicked"
QT_MOC_LITERAL(4, 72, 29), // "on_btnDeleteAttribute_clicked"
QT_MOC_LITERAL(5, 102, 29), // "on_btnDeleteOperation_clicked"
QT_MOC_LITERAL(6, 132, 26), // "on_btnAddAttribute_clicked"
QT_MOC_LITERAL(7, 159, 26), // "on_btnAddOperation_clicked"
QT_MOC_LITERAL(8, 186, 37), // "on_btnAddAttributeToOperation..."
QT_MOC_LITERAL(9, 224, 41) // "on_btnClearAllOperationAttrib..."

    },
    "EditObjectDialog\0on_btnRenameObject_clicked\0"
    "\0on_btnRemoveObject_clicked\0"
    "on_btnDeleteAttribute_clicked\0"
    "on_btnDeleteOperation_clicked\0"
    "on_btnAddAttribute_clicked\0"
    "on_btnAddOperation_clicked\0"
    "on_btnAddAttributeToOperation_clicked\0"
    "on_btnClearAllOperationAttributes_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditObjectDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditObjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditObjectDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnRenameObject_clicked(); break;
        case 1: _t->on_btnRemoveObject_clicked(); break;
        case 2: _t->on_btnDeleteAttribute_clicked(); break;
        case 3: _t->on_btnDeleteOperation_clicked(); break;
        case 4: _t->on_btnAddAttribute_clicked(); break;
        case 5: _t->on_btnAddOperation_clicked(); break;
        case 6: _t->on_btnAddAttributeToOperation_clicked(); break;
        case 7: _t->on_btnClearAllOperationAttributes_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject EditObjectDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EditObjectDialog.data,
    qt_meta_data_EditObjectDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditObjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditObjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditObjectDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EditObjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
