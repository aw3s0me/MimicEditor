/****************************************************************************
** Meta object code from reading C++ file 'schemascene.h'
**
** Created: Mon 1. Apr 08:59:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MimicEditor/schemascene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schemascene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SchemaScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,
      44,   13,   12,   12, 0x05,
      77,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     111,  106,   12,   12, 0x0a,
     130,  125,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SchemaScene[] = {
    "SchemaScene\0\0item\0itemInserted(SchemaItem*)\0"
    "textInserted(QGraphicsTextItem*)\0"
    "itemSelected(QGraphicsItem*)\0mode\0"
    "setMode(Mode)\0type\0setItemType(SchemaItem::ItemType)\0"
};

void SchemaScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SchemaScene *_t = static_cast<SchemaScene *>(_o);
        switch (_id) {
        case 0: _t->itemInserted((*reinterpret_cast< SchemaItem*(*)>(_a[1]))); break;
        case 1: _t->textInserted((*reinterpret_cast< QGraphicsTextItem*(*)>(_a[1]))); break;
        case 2: _t->itemSelected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->setMode((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        case 4: _t->setItemType((*reinterpret_cast< SchemaItem::ItemType(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SchemaScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SchemaScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_SchemaScene,
      qt_meta_data_SchemaScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SchemaScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SchemaScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SchemaScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SchemaScene))
        return static_cast<void*>(const_cast< SchemaScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int SchemaScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SchemaScene::itemInserted(SchemaItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SchemaScene::textInserted(QGraphicsTextItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SchemaScene::itemSelected(QGraphicsItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE