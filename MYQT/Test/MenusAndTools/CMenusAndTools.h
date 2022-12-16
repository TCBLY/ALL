#ifndef CMENUSANDTOOLS_H
#define CMENUSANDTOOLS_H

#include <QMainWindow>
#include <QObject>
#include <QAction>
#include <QMenuBar>

QT_BEGIN_NAMESPACE
class QAction;
//class QMenuBar;
QT_END_NAMESPACE

class CMenusAndTools : public QObject
{
    Q_OBJECT
public:
    explicit CMenusAndTools(QObject *parent = nullptr);
    void CreateMenusAndTools();

signals:

private slots:
    void UpThemes(QAction *Theme);

private:
    void CreateActions();
    void CreateMenus();

    QMainWindow *MainWindow;

    QMenu *FileMenu;
    QMenu *ViewMenu;
    QMenu *AboutMenu;

    QActionGroup *ThemesActionGroup;
    //QList<QAction*> Themes;
};

#endif // CMENUSANDTOOLS_H
