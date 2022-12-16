#include "CMenusAndTools.h"

CMenusAndTools::CMenusAndTools(QObject *parent)
    : QObject{parent}
{
    MainWindow = (QMainWindow*)parent;
}

void CMenusAndTools::CreateMenusAndTools()
{
    CreateActions();
    CreateMenus();
}

void CMenusAndTools::CreateActions()
{
    QString  str[8] = {
        "Light",
        "Blue Cerulean",
        "Dark",
        "Brown Sand",
        "Blue NCS",
        "High Contrast",
        "Blue Icy",
        "Qt"
    };

    ThemesActionGroup = new QActionGroup(this);
    ThemesActionGroup->setExclusive(true);
    for(int i = 0; i < 8; i++)
    {
        QAction *Theme = new QAction(tr(str[i].toStdString().c_str()),this);
        Theme->setCheckable(true);
        if(i == 6)
        {
            Theme->setChecked(true);
            UpThemes(Theme);
        }
        ThemesActionGroup->addAction(Theme);
    }

    connect(ThemesActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(UpThemes(QAction*)));

}
void CMenusAndTools::CreateMenus()
{
    FileMenu = MainWindow->menuBar()->addMenu(tr("&File"));

//    FileMenu->addAction(tr("Save layout..."), this, &MainWindow::saveLayout);
//    FileMenu->addAction(tr("Load layout..."), this, &MainWindow::loadLayout);

    FileMenu->addSeparator();
    FileMenu->addAction(tr("&Quit"), MainWindow, &QWidget::close);



    ViewMenu = MainWindow->menuBar()->addMenu(tr("&View"));
    ViewMenu->addSeparator();
    QMenu *ViewMenuThemes = ViewMenu->addMenu(tr("Themes"));
    ViewMenuThemes->addActions(ThemesActionGroup->actions());
    AboutMenu = MainWindow->menuBar()->addMenu(tr("&Help"));
}


void CMenusAndTools::UpThemes(QAction *Theme)
{
    QString  str[8] = {
        "Light",
        "Blue Cerulean",
        "Dark",
        "Brown Sand",
        "Blue NCS",
        "High Contrast",
        "Blue Icy",
        "Qt"
    };
    QPalette pal = MainWindow->window()->palette();
    if (Theme->text() == str[0])
    {
        pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
    }
    else if (Theme->text() == str[1])
    {
        pal.setColor(QPalette::Window, QRgb(0x121218));
        pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    }
    else if (Theme->text() == str[2])
    {
        pal.setColor(QPalette::Window, QRgb(0x40434a));
        pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    }
    else if (Theme->text() == str[3])
    {
        pal.setColor(QPalette::Window, QRgb(0x9e8965));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
    }
    else if (Theme->text() == str[4])
    {
        pal.setColor(QPalette::Window, QRgb(0x018bba));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
    }
    else if (Theme->text() == str[5])
    {
        pal.setColor(QPalette::Window, QRgb(0xffab03));
        pal.setColor(QPalette::WindowText, QRgb(0x181818));
    }
    else if (Theme->text() == str[6])
    {
        pal.setColor(QPalette::Window, QRgb(0xcee7f0));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
    }
    else if (Theme->text() == str[7])
    {
        pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
    }
    MainWindow->window()->setPalette(pal);
}
