#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    const char* tasksFile;
    std::vector<std::string> tasks;
    unsigned int startSize;

    void print_rand_task();
    void add_new_task();
};

#endif // MAINWINDOW_H
