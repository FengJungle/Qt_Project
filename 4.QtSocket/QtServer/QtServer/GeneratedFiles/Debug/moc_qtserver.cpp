/****************************************************************************
** Meta object code from reading C++ file 'qtserver.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      43,    9,    9,    9, 0x08,
      57,    9,    9,    9, 0x08,
      80,    9,    9,    9, 0x08,
     113,  101,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QtServer[] = {
    "QtServer\0\0sendMessage()\0acceptConnection()\0"
    "receiveData()\0acceptFileConnection()\0"
    "updateFileProgress()\0socketError\0"
    "displayError(QAbstractSocket::SocketError)\0"
};

void QtServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtServer *_t = static_cast<QtServer *>(_o);
        switch (_id) {
        case 0: _t->sendMessage(); break;
        case 1: _t->acceptConnection(); break;
        case 2: _t->receiveData(); break;
        case 3: _t->acceptFileConnection(); break;
        case 4: _t->updateFileProgress(); break;
        case 5: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QtServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtServer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QtServer,
      qt_meta_data_QtServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtServer))
        return static_cast<void*>(const_cast< QtServer*>(this));
    return QWidget::qt_metacast(_clname);
}

int QtServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
