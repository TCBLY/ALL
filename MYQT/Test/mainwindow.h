#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MenusAndTools/CMenusAndTools.h"

//class CMenusAndTools;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    CMenusAndTools *m_CMenusAndTools;
};
#endif // MAINWINDOW_H
