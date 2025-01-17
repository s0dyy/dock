/*
 * Copyright (C) 2021 CutefishOS Team.
 *
 * Author:     Reion Wong <reionwong@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QObject>

class Activity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool launchPad READ launchPad NOTIFY launchPadChanged)

public:
    static Activity *self();
    explicit Activity(QObject *parent = nullptr);

    bool launchPad() const;

private slots:
    void onActiveWindowChanged();

signals:
    void launchPadChanged();

private:
    QString m_windowClass;
    quint32 m_pid;

    bool m_launchPad;
};

#endif // ACTIVITY_H
