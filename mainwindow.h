#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include "tcpclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonBrowser_clicked();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    TcpClient *tcpClient;

private slots:
    void timer_update();
};

#endif // MAINWINDOW_H
