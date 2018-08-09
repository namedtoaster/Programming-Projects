#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tasksFile("C:\\Users\\afdav\\Documents\\Repos\\Programming-Projects\\programming\\cpp\\1-practice\\03-Qt_projects\\Tasker\\Tasker\\tasks")
{
    ui->setupUi(this);

    // load the file with all of the tasks
    std::ifstream input;
    input.open(tasksFile);

    // put all saved tasks into the vector
    std::string line;
    while (std::getline(input, line)) {
        tasks.push_back(line);
    }

    // record how big the vector is so you know where to start saving from after you add new tasks
    startSize = tasks.size();

    // connect the slots
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

    std::cout << "tasks size: " << tasks.size() << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;

    if (tasks.size() > startSize) {
        std::ofstream output;
        output.open(tasksFile, std::ios::app);

        for (int i = startSize; i < tasks.size(); i++) {
            output << '\n' << tasks[i];
        }
    }
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
    ui->label->setText(QString::fromStdString(tasks[randNum]));
}

// TODO: obviously need to refactor to make part of GUI
void MainWindow::add_new_task()
{
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << tasks[i] << std::endl;
    }

    std::cout << "Task: ";
    std::string input;
    getline(std::cin, input);
    tasks.push_back(input);
}
