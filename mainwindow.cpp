#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digit_number()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digit_number()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_del2,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_umn,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_del->setCheckable(true);
    ui->pushButton_del2->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_umn->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_number()
{
    QPushButton *button = (QPushButton *)sender();

    long long all_number;
    QString new_label;
    all_number = (ui->label->text() + button->text()).toLongLong();
    new_label = QString::number(all_number);
    ui->label->setText(new_label);
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    num_first = ui->label->text().toDouble();   

    ui->label->setText("");

    button->setChecked(true);

}

void MainWindow::on_pushButton_strv_clicked()
{
    ui->pushButton_min->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_del2->setChecked(false);
    ui->pushButton_umn->setChecked(false);

    ui->label->setText("0");
}

void MainWindow::on_pushButton_str1_clicked()
{

}

void MainWindow::on_pushButton_ravn_clicked()
{

    double labelNumber, num_second;
    QString new_label;

    num_second = ui->label->text().toDouble();

    if(ui->pushButton_min->isChecked()){
       labelNumber = num_first - num_second;
       new_label = QString::number(labelNumber, 'g', 15);

       ui->label->setText(new_label);
       ui->pushButton_min->setChecked(false);
    } else if (ui->pushButton_plus->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    } else if (ui->pushButton_del->isChecked()) {
        if (num_second == 0){
            ui->label->setText("0");
        }

        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_del->setChecked(false);
    } else if (ui->pushButton_del2->isChecked()) {
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_del2->setChecked(false);
    } else if (ui->pushButton_umn->isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_umn->setChecked(false);
}

}

void MainWindow::on_pushButton_podr_clicked()
{

}

double MainWindow::perevodv2(double a)
{


    return a;
}

double MainWindow::perevodv10(double a)
{
    int sum = 0;
    while (a != 0) {
        a/=10;
        sum+=1;
    }


    return a;
}
