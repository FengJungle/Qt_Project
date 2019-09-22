/****************************************************************************
** Meta object code from reading C++ file 'QTreadTest_0.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTreadTest_0.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTreadTest_0.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTreadTest_0[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QTreadTest_0[] = {
    "QTreadTest_0\0\0sendMessage(QList<double>)\0"
    "controlTimer()\0"
};

void QTreadTest_0::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QTreadTest_0 *_t = static_cast<QTreadTest_0 *>(_o);
        switch (_id) {
        case 0: _t->sendMessage((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 1: _t->controlTimer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QTreadTest_0::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QTreadTest_0::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QTreadTest_0,
      qt_meta_data_QTreadTest_0, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTreadTest_0::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTreadTest_0::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTreadTest_0::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTreadTest_0))
        return static_cast<void*>(const_cast< QTreadTest_0*>(this));
    return QWidget::qt_metacast(_clname);
}

int QTreadTest_0::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QTreadTest_0::sendMessage(QList<double> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
