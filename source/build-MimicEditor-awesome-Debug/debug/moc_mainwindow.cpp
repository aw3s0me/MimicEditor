/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat 6. Apr 17:51:12 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MimicEditor/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      50,   45,   11,   11, 0x08,
      79,   76,   11,   11, 0x08,
     107,   76,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     222,   11,   11,   11, 0x08,
     250,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     302,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0activateTab(int)\0"
    "closingTab(int)\0item\0itemInserted(SchemaItem*)\0"
    "id\0ButtonItemGroupClicked(int)\0"
    "ButtonPointerTypeGroupClicked(int)\0"
    "on_actionCreate_triggered()\0"
    "on_actionOpen_triggered()\0"
    "on_actionSave_triggered()\0"
    "on_actionSaveAs_triggered()\0"
    "on_actionExit_triggered()\0"
    "on_actionUndo_triggered()\0"
    "on_actionRedo_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->activateTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->closingTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->itemInserted((*reinterpret_cast< SchemaItem*(*)>(_a[1]))); break;
        case 3: _t->ButtonItemGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ButtonPointerTypeGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_actionCreate_triggered(); break;
        case 6: _t->on_actionOpen_triggered(); break;
        case 7: _t->on_actionSave_triggered(); break;
        case 8: _t->on_actionSaveAs_triggered(); break;
        case 9: _t->on_actionExit_triggered(); break;
        case 10: _t->on_actionUndo_triggered(); break;
        case 11: _t->on_actionRedo_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE