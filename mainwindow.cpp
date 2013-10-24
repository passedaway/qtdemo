#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpClient = NULL;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonExit_clicked()
{
    close();
}

void MainWindow::on_pushButtonBrowser_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/", "files (*)");
    ui->lineEditPortPath->setText(s );
}

void MainWindow::timer_update()
{
    int tmp = tcpClient->get_all();
    ui->labelSpeed->setText(QString("%0 MBps").arg(tmp));
    printf("tmp=%d\n", tmp);
    fflush(stdout);
}

#include <stdio.h>
#include <iostream>

void MainWindow::on_pushButtonStart_clicked()
{
   timer->start(100);

   printf("hello,world\n");

   if(tcpClient == NULL )
   {
       tcpClient = new TcpClient(1234, 123, "D:/tmp");
   }
     tcpClient->start();

}

void MainWindow::on_pushButtonStop_clicked()
{
#if 0
    TcpClient *tmp = new TcpClient(5678, 456, "C:/tmp");
    tmp->start();
    //tmp->sleep(500);
    //tmp->stop();
   delete tmp;
     return;
#endif


    if( tcpClient )
    {
        tcpClient->stop();
       // delete tcpClient;
        //tcpClient = NULL;
    }
    //tmp->stop();

    timer->stop();
}
