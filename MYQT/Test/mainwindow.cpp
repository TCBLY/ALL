#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //1. 初始化菜单以及工具栏(包括各种Action)
    m_CMenusAndTools = new CMenusAndTools(this);
    m_CMenusAndTools->CreateMenusAndTools();
}

MainWindow::~MainWindow()
{
}

