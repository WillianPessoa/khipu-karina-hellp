/*************************************************************************************
 *  Copyright (C) 2010 by Percy Camilo T. Aucahuasi <percy.camilo.ta@gmail.com>      *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/


#ifndef KEOMATH_SPACESMODEL_H
#define KEOMATH_SPACESMODEL_H

#include <QtCore/QAbstractTableModel>

#include "space.h"

#include <kcategorizedsortfilterproxymodel.h>

namespace Analitza
{
class Expression;
}

namespace Keomath
{
class SpacesView;

class SpacesModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    friend class SpacesView;
    enum SpacesModelRoles { Selection=Qt::UserRole+1 };


    
    explicit SpacesModel(QObject *parent=0);

    Qt::ItemFlags flags ( const QModelIndex & index ) const;

    QVariant data( const QModelIndex &index, int role=Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex & =QModelIndex()) const
    {
        return 4;
    }

    virtual bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );


    
    bool addSpace(const Space& space);

    QModelIndex spaceIndex(const Space& space) const;
    const Space & spaceFromId(const QString &id) const;
    const Space & spaceFromIndex(int index) const;


    bool editSpace(const QString& toChange, const Space& func);

    const Space* getSpace(int num) const;

    void clear();

    virtual bool removeRows ( int row, int count, const QModelIndex & parent = QModelIndex() );


public slots:


protected:


    


signals:
    


    void spaceModified(const Space& Space);


private:


    Space::List m_spaceList;
};


class SpacesFilterProxyModel : public KCategorizedSortFilterProxyModel
{
    Q_OBJECT

public:
    SpacesFilterProxyModel(QObject *parent = 0);

    int filterDimension() const
    {
        return m_dimension;
    }
    void setFilterDimension(int dimension);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;


private:
    int m_dimension; 
};







} 


#endif 

