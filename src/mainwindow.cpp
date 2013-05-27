#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "customgoal.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    Data::CustomGoal * goal = new Data::CustomGoal();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

