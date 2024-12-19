/****************************************************************************
**
** Copyright (C) 2016 Guenter Schwann
**
** Copyright (C) 2012 IPO.Plan GmbH
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

#include "qobjectlistmodel.h"

#include <QList>

/*
subclass QObjectListModelT<T> to work with a typed QObjectListModel,
e.g.
class RackObjectListModel : public QObjectListModelT<Rack*> {
};
*/

template <class T> class QObjectListModelT : public QObjectListModel
{
public:
    QObjectListModelT<T>(QObject* parent = 0)
        : QObjectListModel(parent)
    {
    }
    QObjectListModelT(const QList<QSharedPointer<T>>& objects, QObject* parent = 0);
    QObjectListModelT(QObjectListModelT<T>* objectListModel, QObject* parent = 0)
        : QObjectListModel(objectListModel, parent)
    {
    }
    QList<QSharedPointer<T>> objectList() const;
    void setObjectList(const QList<QSharedPointer<T>>& objects);
    inline QSharedPointer<T> at(int i) const { return qSharedPointerDynamicCast<T>(m_objects.at(i)); }
    inline QSharedPointer<T> operator[](int i) const { return qSharedPointerDynamicCast<T>(m_objects.at(i)); }
    inline QSharedPointer<T> first() const { return qSharedPointerDynamicCast<T>(m_objects.at(0)); }
    inline QSharedPointer<T> last() const { return qSharedPointerDynamicCast<T>(m_objects.last()); }

    // T get(const int i) const;
    // T getByName(const QString& str) const;
    using value_type = QSharedPointer<T>;

    typedef typename QList<QSharedPointer<T>>::iterator iterator;
    typedef typename QList<QSharedPointer<T>>::const_iterator const_iterator;

    iterator begin() { return objectListRef().begin(); }
    const_iterator begin() const { return objectListRef().begin(); }
    const_iterator cbegin() const { return objectListRef().cbegin(); }

    iterator end() { return objectListRef().end(); }
    const_iterator end() const { return objectListRef().end(); }
    const_iterator cend() const { return objectListRef().end(); }

private:
    QList<QSharedPointer<T>>& objectListRef();
    const QList<QSharedPointer<T>>& objectListRef() const;
};

// template <class T> T QObjectListModelT<T>::getByName(const QString& str) const
// {
//     return static_cast<T>(getByName(str));
// }

// template <class T> T QObjectListModelT<T>::get(const int i) const
// {
//     return static_cast<T>(QObjectListModel::get(i));
// }

template <class T>
QObjectListModelT<T>::QObjectListModelT(const QList<QSharedPointer<T> > &objects, QObject* parent /*= 0*/)
    : QObjectListModel(parent)
{
    setObjectList(objects);
}

template <class T> void QObjectListModelT<T>::setObjectList(const QList<QSharedPointer<T>>& objects)
{
    QList<QSharedPointer<QObject>> list;
    foreach (auto item, objects) {
        list.append(qSharedPointerDynamicCast<QObject>(item));
    }
    QObjectListModel::setObjectList(list);
}

template <class T> QList<QSharedPointer<T>> QObjectListModelT<T>::objectList() const
{
    QList<QSharedPointer<QObject>> list;
    foreach (auto item, QObjectListModel::objectList()) {
        list.append(qSharedPointerDynamicCast<T>(item));
    }
    return list;
}

template <class T> const QList<QSharedPointer<T>>& QObjectListModelT<T>::objectListRef() const
{
    return *reinterpret_cast<const QList<T>*>(&m_objects);
}

template <class T> QList<QSharedPointer<T>>& QObjectListModelT<T>::objectListRef()
{
    return *reinterpret_cast<QList<QSharedPointer<T>>>(&m_objects);
}

#define DECLARE_QBLIST_MODEL(CLASSNAME, TYPENAME)                                                  \
    class CLASSNAME : public QObjectListModelT<TYPENAME>                                           \
    {                                                                                              \
        Q_OBJECT                                                                                   \
    public:                                                                                        \
        CLASSNAME(QObject* parent = NULL)                                                          \
            : QObjectListModelT<TYPENAME>(parent)                                                  \
        {                                                                                          \
        }                                                                                          \
    };
