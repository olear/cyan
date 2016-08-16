/*
* Cyan <https://github.com/olear/cyan>,
* Copyright (C) 2016 Ole-André Rodlie
*
* Cyan is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as published
* by the Free Software Foundation.
*
* Cyan is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Cyan.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
*/

#ifndef CYAN_H
#define CYAN_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QToolBar>
#include <QComboBox>
#include <QCheckBox>
#include <QDockWidget>
#include <QDial>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScrollBar>
#include <QMouseEvent>
#include <QWheelEvent>

class CyanView : public QGraphicsView
{
Q_OBJECT
public:
     explicit CyanView(QWidget* parent = NULL);

signals:
    void resetZoom();
    void myZoom(double scaleX, double scaleY);
    void proof();

public slots:
    void doZoom(double scaleX, double scaleY);

protected:
    virtual void wheelEvent(QWheelEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
};

class Cyan : public QMainWindow
{
    Q_OBJECT

public:
    Cyan(QWidget *parent = 0);
    ~Cyan();
private:
    QGraphicsScene *scene;
    CyanView *view;
    QToolBar *mainBar;
    QToolBar *convertBar;
    QToolBar *profileBar;
    QComboBox *rgbProfile;
    QComboBox *cmykProfile;
    QComboBox *grayProfile;
    QComboBox *inputProfile;
    QComboBox *outputProfile;
    QComboBox *monitorProfile;
    QComboBox *renderingIntent;
    QCheckBox *blackPoint;
    QDockWidget *modulateDock;
    QDial *brightDial;
    QDial *hueDial;
    QDial *satDial;
};

#endif // CYAN_H