#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString home = QDir::homePath();
    QFile file(home.append(qPrintable("/tmp/button2file.txt")));
    if(!file.open(QIODevice::Append)){
        ui->pushButton->setText(qPrintable("OPEN ERROR"));
        return;
    }

    QTextStream out(&file);
    out << "write" << endl;

    file.close();
}
