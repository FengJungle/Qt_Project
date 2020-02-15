/****************************************************************************
** Meta object code from reading C++ file 'happychat.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../happychat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'happychat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HappyChat[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      37,   10,   10,   10, 0x08,
      47,   10,   10,   10, 0x08,
      58,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HappyChat[] = {
    "HappyChat\0\0processPendingDatagrams()\0"
    "sendmsg()\0savefile()\0clearMsg()\0"
};

void HappyChat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HappyChat *_t = static_cast<HappyChat *>(_o);
        switch (_id) {
        case 0: _t->processPendingDatagrams(); break;
        case 1: _t->sendmsg(); break;
        case 2: _t->savefile(); break;
        case 3: _t->clearMsg(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HappyChat::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HappyChat::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HappyChat,
      qt_meta_data_HappyChat, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HappyChat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HappyChat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HappyChat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HappyChat))
        return static_cast<void*>(const_cast< HappyChat*>(this));
    return QWidget::qt_metacast(_clname);
}

int HappyChat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
