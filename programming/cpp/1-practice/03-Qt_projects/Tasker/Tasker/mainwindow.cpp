#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the path where the files exist
    QString path = QCoreApplication::applicationDirPath();
    path.append("/../../Tasker/");

    // Set the path of the file
    tasksFile.setFileName(path + "tasks");

    // load the file with all of the tasks
    if (!tasksFile.open(QFile::ReadOnly | QFile::Text)) {
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
}

MainWindow::~MainWindow()
{
    delete ui;

    // load the file with all of the tasks
    if (!tasksFile.open(QFile::WriteOnly | QFile::Text)) {
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
    print_rand_task();
}

void MainWindow::print_rand_task()
{
    srand(time(NULL));

    // pick a random number between 0 and vector.size
    unsigned int randNum = rand() % tasks.size();

    // display that task in the label
    ui->label->setText(tasks[randNum]);
}

// TODO: obviously need to refactor to make part of GUI
void MainWindow::add_new_task()
{

}
