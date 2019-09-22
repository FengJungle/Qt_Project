/****************************************************************************
** Meta object code from reading C++ file 'qtclient.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      26,    9,    9,    9, 0x08,
      45,    9,    9,    9, 0x08,
      59,    9,    9,    9, 0x08,
      70,    9,    9,    9, 0x08,
      83,    9,    9,    9, 0x08,
      94,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QtClient[] = {
    "QtClient\0\0connectServer()\0disconnectServer()\0"
    "receiveData()\0sendData()\0selectFile()\0"
    "sendFile()\0updateFileProgress(qint64)\0"
};

void QtClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtClient *_t = static_cast<QtClient *>(_o);
        switch (_id) {
        case 0: _t->connectServer(); break;
        case 1: _t->disconnectServer(); break;
        case 2: _t->receiveData(); break;
        case 3: _t->sendData(); break;
        case 4: _t->selectFile(); break;
        case 5: _t->sendFile(); break;
        case 6: _t->updateFileProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QtClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QtClient,
      qt_meta_data_QtClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtClient))
        return static_cast<void*>(const_cast< QtClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int QtClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
