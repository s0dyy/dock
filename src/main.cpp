/*
 * Copyright (C) 2020 ~ 2021 CyberOS Team.
 *
 * Author:     rekols <revenmartin@gmail.com>
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

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QTranslator>
#include <QLocale>

#include "applicationmodel.h"
#include "mainwindow.h"

#include "volumemanager.h"
#include "battery.h"
#include "brightness.h"
#include "controlcenterdialog.h"
#include "statusnotifier/statusnotifiermodel.h"
#include "appearance.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    qmlRegisterType<DockSettings>("Cyber.Dock", 1, 0, "DockSettings");
    qmlRegisterType<VolumeManager>("Cyber.Dock", 1, 0, "Volume");
    qmlRegisterType<Battery>("Cyber.Dock", 1, 0, "Battery");
    qmlRegisterType<Brightness>("Cyber.Dock", 1, 0, "Brightness");
    qmlRegisterType<ControlCenterDialog>("Cyber.Dock", 1, 0, "ControlCenterDialog");
    qmlRegisterType<StatusNotifierModel>("Cyber.Dock", 1, 0, "StatusNotifierModel");
    qmlRegisterType<Appearance>("Cyber.Dock", 1, 0, "Appearance");

    QString qmFilePath = QString("%1/%2.qm").arg("/usr/share/cyber-dock/translations/").arg(QLocale::system().name());
    if (QFile::exists(qmFilePath)) {
        QTranslator *translator = new QTranslator(QApplication::instance());
        if (translator->load(qmFilePath)) {
            QGuiApplication::installTranslator(translator);
        } else {
            translator->deleteLater();
        }
    }

    MainWindow w;

    return app.exec();
}
