/****************************************************************************
** Meta object code from reading C++ file 'classdiagramview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controllers/classdiagramview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classdiagramview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClassDiagramView_t {
    QByteArrayData data[7];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClassDiagramView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClassDiagramView_t qt_meta_stringdata_ClassDiagramView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ClassDiagramView"
QT_MOC_LITERAL(1, 17, 19), // "on_btnClose_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "on_btnAddObject_clicked"
QT_MOC_LITERAL(4, 62, 38), // "on_btnCreateNewSequenceDiagra..."
QT_MOC_LITERAL(5, 101, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(6, 120, 18) // "on_btnUndo_clicked"

    },
    "ClassDiagramView\0on_btnClose_clicked\0"
    "\0on_btnAddObject_clicked\0"
    "on_btnCreateNewSequenceDiagram_clicked\0"
    "on_btnSave_clicked\0on_btnUndo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClassDiagramView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClassDiagramView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClassDiagramView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnClose_clicked(); break;
        case 1: _t->on_btnAddObject_clicked(); break;
        case 2: _t->on_btnCreateNewSequenceDiagram_clicked(); break;
        case 3: _t->on_btnSave_clicked(); break;
        case 4: _t->on_btnUndo_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ClassDiagramView::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ClassDiagramView.data,
    qt_meta_data_ClassDiagramView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClassDiagramView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassDiagramView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClassDiagramView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClassDiagramView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
