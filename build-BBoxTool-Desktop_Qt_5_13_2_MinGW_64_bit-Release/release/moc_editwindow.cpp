/****************************************************************************
** Meta object code from reading C++ file 'editwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../BBoxTool/editwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditWindow_t {
    QByteArrayData data[24];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditWindow_t qt_meta_stringdata_EditWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EditWindow"
QT_MOC_LITERAL(1, 11, 11), // "eventFilter"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "target"
QT_MOC_LITERAL(4, 31, 7), // "QEvent*"
QT_MOC_LITERAL(5, 39, 5), // "event"
QT_MOC_LITERAL(6, 45, 19), // "on_btnReset_clicked"
QT_MOC_LITERAL(7, 65, 18), // "on_btnNext_clicked"
QT_MOC_LITERAL(8, 84, 27), // "on_lstFilesList_itemClicked"
QT_MOC_LITERAL(9, 112, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 129, 4), // "item"
QT_MOC_LITERAL(11, 134, 11), // "imageLoader"
QT_MOC_LITERAL(12, 146, 4), // "path"
QT_MOC_LITERAL(13, 151, 8), // "drawrect"
QT_MOC_LITERAL(14, 160, 2), // "x1"
QT_MOC_LITERAL(15, 163, 2), // "y1"
QT_MOC_LITERAL(16, 166, 2), // "x2"
QT_MOC_LITERAL(17, 169, 2), // "y2"
QT_MOC_LITERAL(18, 172, 26), // "create_and_read_annot_file"
QT_MOC_LITERAL(19, 199, 8), // "filePath"
QT_MOC_LITERAL(20, 208, 18), // "on_btnPrev_clicked"
QT_MOC_LITERAL(21, 227, 29), // "denormalize_and_dra_rectangle"
QT_MOC_LITERAL(22, 257, 9), // "coordLine"
QT_MOC_LITERAL(23, 267, 24) // "on_btnDeleteBbox_clicked"

    },
    "EditWindow\0eventFilter\0\0target\0QEvent*\0"
    "event\0on_btnReset_clicked\0on_btnNext_clicked\0"
    "on_lstFilesList_itemClicked\0"
    "QListWidgetItem*\0item\0imageLoader\0"
    "path\0drawrect\0x1\0y1\0x2\0y2\0"
    "create_and_read_annot_file\0filePath\0"
    "on_btnPrev_clicked\0denormalize_and_dra_rectangle\0"
    "coordLine\0on_btnDeleteBbox_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    4,   77,    2, 0x08 /* Private */,
      18,    1,   86,    2, 0x08 /* Private */,
      20,    0,   89,    2, 0x08 /* Private */,
      21,    1,   90,    2, 0x08 /* Private */,
      23,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   22,
    QMetaType::Void,

       0        // eod
};

void EditWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_btnReset_clicked(); break;
        case 2: _t->on_btnNext_clicked(); break;
        case 3: _t->on_lstFilesList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->imageLoader((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->drawrect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->create_and_read_annot_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_btnPrev_clicked(); break;
        case 8: _t->denormalize_and_dra_rectangle((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 9: _t->on_btnDeleteBbox_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_EditWindow.data,
    qt_meta_data_EditWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EditWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
