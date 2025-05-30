//
// Copyright (c) 2009, Jim Hourihan
// All rights reserved.
//
// SPDX-License-Identifier: Apache-2.0
//
#ifndef __MuQt5__QLocalSocketType__h__
#define __MuQt5__QLocalSocketType__h__
#include <iostream>
#include <Mu/Class.h>
#include <Mu/MuProcess.h>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>
#include <QtNetwork/QtNetwork>
#include <QtWebEngine/QtWebEngine>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QtQml/QtQml>
#include <QtQuick/QtQuick>
#include <QtQuickWidgets/QtQuickWidgets>
#include <QtSvg/QtSvg>
#include <MuQt5/Bridge.h>

namespace Mu
{
    class MuQt_QLocalSocket;

    //
    //  NOTE: file generated by qt2mu.py
    //

    class QLocalSocketType : public Class
    {
    public:
        typedef MuQt_QLocalSocket MuQtType;
        typedef QLocalSocket QtType;

        //
        //  Constructors
        //

        QLocalSocketType(Context* context, const char* name,
                         Class* superClass = 0, Class* superClass2 = 0);

        virtual ~QLocalSocketType();

        static bool isInheritable() { return true; }

        static inline ClassInstance* cachedInstance(const MuQtType*);

        //
        //  Class API
        //

        virtual void load();

        MemberFunction* _func[13];
    };

    // Inheritable object

    class MuQt_QLocalSocket : public QLocalSocket
    {
    public:
        virtual ~MuQt_QLocalSocket();
        MuQt_QLocalSocket(Pointer muobj, const CallEnvironment*,
                          QObject* parent);
        virtual qint64 bytesAvailable() const;
        virtual qint64 bytesToWrite() const;
        virtual bool canReadLine() const;
        virtual void close();
        virtual bool isSequential() const;
        virtual bool open(OpenMode openMode);
        virtual bool waitForBytesWritten(int msecs);
        virtual bool waitForReadyRead(int msecs);
        virtual bool atEnd() const;
        virtual qint64 pos() const;
        virtual bool reset();
        virtual bool seek(qint64 pos);
        virtual qint64 size() const;

    public:
        const QLocalSocketType* _baseType;
        ClassInstance* _obj;
        const CallEnvironment* _env;
    };

    inline ClassInstance*
    QLocalSocketType::cachedInstance(const QLocalSocketType::MuQtType* obj)
    {
        return obj->_obj;
    }

} // namespace Mu

#endif // __MuQt__QLocalSocketType__h__
