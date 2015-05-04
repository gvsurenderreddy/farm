/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2015  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "data/databasehelper.h"
#include "QtSql/QSqlQuery"
#include <qvariant.h>
DatabaseHelper::DatabaseHelper(std::string filepath, int version)
{

}

QSqlDatabase DatabaseHelper::getReadableDatabase()
{
    return this->db;
}
QSqlDatabase DatabaseHelper::getWritableDatabase()
{
    return this->db;
}

void DatabaseHelper::setVersion(std::string version)
{
    QSqlQuery query = db.exec("PRAGMA user_version="+version);
}


int DatabaseHelper::getVersion()
{
    QSqlQuery query = db.exec("PRAGMA user_version");
    return query.value(0).toInt();
}

DatabaseHelper::~DatabaseHelper()
{

}
