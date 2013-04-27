/****************************************************************************
** Meta object code from reading C++ file 'schemaitem.h'
**
** Created: Sat 27. Apr 18:48:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MimicEditor/schemaitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schemaitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SchemaItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
      11, 0x0,    4,   18,

 // enum data: key, value
      20, uint(SchemaItem::Filter),
      27, uint(SchemaItem::Transformator),
      41, uint(SchemaItem::Amplifier),
      51, uint(SchemaItem::Fourth),

       0        // eod
};

static const char qt_meta_stringdata_SchemaItem[] = {
    "SchemaItem\0ItemType\0Filter\0Transformator\0"
    "Amplifier\0Fourth\0"
};

void SchemaItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SchemaItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SchemaItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SchemaItem,
      qt_meta_data_SchemaItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SchemaItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SchemaItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SchemaItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SchemaItem))
        return static_cast<void*>(const_cast< SchemaItem*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< SchemaItem*>(this));
    return QObject::qt_metacast(_clname);
}

int SchemaItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
