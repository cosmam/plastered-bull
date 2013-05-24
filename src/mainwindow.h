#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "timefunctions.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public Q_SLOTS:

private:
    Ui::MainWindow * m_ui;
};

#endif // MAINWINDOW_H
