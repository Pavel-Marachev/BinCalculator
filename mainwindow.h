#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;


private slots:
    void digit_number();
    void math_operations();
    double perevodv2(double a);
    double perevodv10(double a);

    void on_pushButton_strv_clicked();
    void on_pushButton_str1_clicked();
    void on_pushButton_ravn_clicked();
    void on_pushButton_podr_clicked();
};

#endif // MAINWINDOW_H
