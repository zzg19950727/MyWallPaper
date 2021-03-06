#ifndef DESKTOPGO_H
#define DESKTOPGO_H
#include "dockermanager.h"
#include "ui_setwindow.h"
#include "videowidget.h"
#include <Qsystemtrayicon>
#include <QWidgetAction>
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include <QPoint>
#include <QLabel>

typedef struct __SystemTray
{
    QSystemTrayIcon *m_systemTray;

    QMenu* m_trayMenu;

    //菜单上部分
    QWidget* m_topWidget;
    QWidgetAction* m_topWidgetAction;
    QLabel* m_topLabel;

    //菜单中间部分
    QWidget* m_mdWidget;
    QWidgetAction* m_mdWidgetAction;
    QPushButton* m_setBtn;
    QPushButton* m_repairBtn;

    //菜单下面部分
    QWidget* m_bottomWidget;
    QWidgetAction* m_bottomWidgetAction;
    QPushButton* m_aboutBtn;
    QPushButton* m_exitBtn;
}SystemTray, *PSystemTray;

namespace Ui
{
    class Form;
}

class DesktopGo : public QWidget
{
    Q_OBJECT
public:
    explicit DesktopGo(QWidget *parent = 0);
    ~DesktopGo();
    void initUI();
    void initTrayUI();
    //重新定义鼠标拖拽移动窗口功能
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void bgItemChanged(int);
    void openFile();
    void repair();
    void quit();
    void addDocker();
    void auto_save();

private slots:
    void showSetWindow();
    void hideSetWindow();
    void showBackground();

private:
    //托盘菜单
    PSystemTray systray;
    //壁纸控件
    VideoWidget* background;
    int bgCount;
    //桌面整理控件
    DockerManager dockers;
    //设置界面
    Ui::Form* setwindow;
    QPoint __dragPosition;
    QTimer timer;
};
#endif // DESKTOPGO_H
