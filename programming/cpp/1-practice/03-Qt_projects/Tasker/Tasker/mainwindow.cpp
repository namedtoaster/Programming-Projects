#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <QtDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the path where the files exist
    QString path = QCoreApplication::applicationDirPath();
#ifdef __APPLE__
    path.append("/../../../../Tasker/");
#elif _WIN32
    path.append("/../../Tasker/");
#endif

    // Set the path of the file
    tasksFile.setFileName(path + "tasks");
    qDebug() << tasksFile.fileName();

    // load the file with all of the tasks
    if (!tasksFile.open(QFile::ReadOnly)) {
        qDebug() << " Could not open file for reading";
        return;
    }

    // put the tasks on the vector
    QTextStream in(&tasksFile);
    QString myText = in.readLine();

    while (myText != NULL) {
        tasks.push_back(myText);
        myText = in.readLine();
    }
    tasksFile.close();

    // record how big the vector is so you know where to start saving from after you add new tasks
    startSize = tasks.size();

    // connect the slots
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton2_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;

    // load the file with all of the tasks
    if (!tasksFile.open(QFile::Append)) {
        qDebug() << " Could not open file for reading";
        return;
    }

    QTextStream out(&tasksFile);
    if (tasks.size() > startSize) {
        for (int i = startSize; i < tasks.size(); i++) {
            out << tasks[i];
        }
    }
    tasksFile.close();
}

void MainWindow::on_pushButton_clicked()
{
    srand(time(NULL));

    // pick a random number between 0 and vector.size
    unsigned int randNum = rand() % tasks.size();

    // display that task in the label
    ui->label->setText(tasks[randNum]);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->textEdit->toPlainText() == NULL) {
        QMessageBox msgBox;
        msgBox.setText("Must input a task");
        msgBox.exec();
    }
    else {
        tasks.push_back(QString("\n") + ui->textEdit->toPlainText());
        ui->textEdit->clear();

        QMessageBox msgBox;
        msgBox.setText("Task was succesfully added!");
        msgBox.exec();
    }
}
