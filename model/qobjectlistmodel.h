/****************************************************************************
**
** Copyright (C) 2016 Guenter Schwann
**
** Copyright (C) 2016 Guenter Schwann
**
** Copyright (C) 2012 IPO.Plan GmbH
**
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#pragma once

#include <QAbstractListModel>
#include <QByteArray>
#include <QHash>
#include <QSharedPointer>

class QObjectListModelIndexByName;

/*
QObjectListModel presents a way to store QObject pointers in a list
which actively sends signals on list change.
It is thus suited for use as QML data storage whith change notification.
When using subclasses of QObjectListModelT, one can even achieve
static type checking on the C++ side.
*/

class QObjectListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    explicit QObjectListModel(QObject* parent = 0);
    QObjectListModel(const QList<QSharedPointer<QObject>>& objects, QObject* parent = 0);
    ~QObjectListModel();

    //    inline QObject * parent() const { return QObject::parent(); }

    // model API
    enum Roles { ObjectRole = Qt::UserRole + 1 };
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    Q_INVOKABLE QVariant dataByRole(const int i, int role) const;

    // directly access underlying QList data storage
    QList<QSharedPointer<QObject>> objectList() const;
    void setObjectList(const QList<QSharedPointer<QObject>>& objects);

    // list API
    void append(QSharedPointer<QObject> object);
    void append(const QList<QSharedPointer<QObject>>& objects);
    void insert(int i, QSharedPointer<QObject> object);
    void insert(int i, const QList<QSharedPointer<QObject>>& objects);
    inline QSharedPointer<QObject> first() const { return m_objects.at(0); }
    inline QSharedPointer<QObject> last() const { return m_objects.last(); }
    inline QSharedPointer<QObject> at(int i) const { return m_objects.at(i); }
    inline QSharedPointer<QObject> operator[](int i) const { return m_objects[i]; }

    void replace(int i, QSharedPointer<QObject> object);
    void move(int from, int to);

    void removeAt(int i, int count = 1);
    QSharedPointer<QObject> takeAt(int i);
    void clear();

    bool contains(QSharedPointer<QObject> object) const;
    inline int lastIndexOf(QSharedPointer<QObject> object, int from = -1) const
    {
        return m_objects.lastIndexOf(object, from);
    }

    inline int count() const { return m_objects.count(); }
    inline int size() const { return m_objects.size(); }
    inline bool isEmpty() const { return m_objects.isEmpty(); }

    // additional QML API
    Q_INVOKABLE QObject* get(const int i) const;
    // Q_INVOKABLE QObject* getByName(const QString& str) const;
    Q_INVOKABLE void listAppend(QSharedPointer<QObject> obj);
    Q_INVOKABLE void listInsert(int at, QSharedPointer<QObject> obj);
    Q_INVOKABLE void listRemove(int at, int count = 1);
    Q_INVOKABLE void listSetFromObjectListModel(QObjectListModel* model);
    Q_INVOKABLE void listSetFromItemModel(
        QAbstractItemModel* model, int role = ObjectRole, int column = 0);

    void dump() const; // print object names
    void touch(); // issues modelreset

signals:
    void countChanged();

protected:
    QList<QSharedPointer<QObject>> m_objects;

#ifdef _DEBUG
    // to record access patterns to decide if indexing is useful
    int m_accessCountIndexOfObject;
    int m_accessCountIndexOfName;
#endif
};
