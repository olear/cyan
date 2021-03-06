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
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScrollBar>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QByteArray>

#include "yellow.h"
#include "magenta.h"

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
    Yellow cms;
    Magenta proc;
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
    QPushButton *mainBarLoadButton;
    QPushButton *mainBarSaveButton;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *openImageAction;
    QAction *saveImageAction;
    QAction *quitAction;
    QByteArray currentImageData;
    QByteArray currentImageProfile;
    QByteArray currentImageNewProfile;
    QCheckBox *monitorCheckBox;
    QAction *exportEmbeddedProfileAction;

private slots:
    void readConfig();
    void writeConfig();
    void aboutCyan();
    void openImageDialog();
    void saveImageDialog();
    void openImage(QString file);
    void saveImage(QString file);
    void getColorProfiles(int colorspace, QComboBox *box, bool isMonitor);
    void loadDefaultProfiles();
    void saveDefaultProfiles();
    void updateRgbDefaultProfile(int index);
    void updateCmykDefaultProfile(int index);
    void updateGrayDefaultProfile(int index);
    void updateMonitorDefaultProfile(int index);
    void getImage(magentaImage result);
    void imageClear();
    void resetImageZoom();
    void setImage(QByteArray image);
    void updateImage();
    QByteArray getMonitorProfile();
    QByteArray getOutputProfile();
    void getConvertProfiles();
    void inputProfileChanged(int index);
    void outputProfileChanged(int index);
    void monitorCheckBoxChanged(bool triggered);
    void enableUI();
    void disableUI();
    void triggerMonitor();
    void exportEmbeddedProfileDialog();
    void exportEmbeddedProfile(QString file);
};

#endif // CYAN_H
