#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

double num_first;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_dobutok, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_dil, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_dobutok->setCheckable(true);
    ui->pushButton_dil->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString newlabel;

    if(ui->resultshow->text().contains(".") && button->text()=="0")
    {
        newlabel=ui->resultshow->text() + button->text();
    }
    else
    {
        all_numbers=(ui->resultshow->text() + button->text()).toDouble();

        newlabel=QString::number(all_numbers, 'g', 15);
    }

    ui->resultshow->setText(newlabel);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->resultshow->text().contains('.'))
    {
    ui->resultshow->setText(ui->resultshow->text()+".");
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString newlabel;

    if(button->text() == "+/-")
    {
        all_numbers=(ui->resultshow->text()).toDouble();
        all_numbers=all_numbers * -1;

        newlabel=QString::number(all_numbers, 'g', 15);

        ui->resultshow->setText(newlabel);
    }
    else if(button->text() == '%')
    {
        all_numbers=(ui->resultshow->text()).toDouble();
        all_numbers=all_numbers * 0.01;

        newlabel=QString::number(all_numbers, 'g', 15);

        ui->resultshow->setText(newlabel);
    }

}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();


    num_first = ui->resultshow->text().toDouble();
    ui->resultshow->setText("");
    button->setChecked(true);



}


void MainWindow::on_pushButton_result_clicked()
{
    double labelNumber, num_second;
    QString newlabel;

    num_second = ui->resultshow->text().toDouble();


   if(ui->pushButton_plus->isChecked())
   {
     labelNumber=num_first+num_second;
             newlabel= QString::number(labelNumber, 'g', 15);
             ui->resultshow->setText(newlabel);
             ui->pushButton_plus->setChecked(false);
   }
   else if(ui->pushButton_minus->isChecked())
   {
       labelNumber=num_first - num_second;
               newlabel= QString::number(labelNumber, 'g', 15);
               ui->resultshow->setText(newlabel);
               ui->pushButton_minus->setChecked(false);
   }
   else if(ui->pushButton_dobutok->isChecked())
   {
       labelNumber=num_first*num_second;
       newlabel= QString::number(labelNumber, 'g', 15);
       ui->resultshow->setText(newlabel);
       ui->pushButton_dobutok->setChecked(false);
   }
   else if(ui->pushButton_dil->isChecked())
   {
       if(num_second==0)
       {
            ui->resultshow->setText(0);
       }
       else
       {
           labelNumber=num_first/num_second;
           newlabel= QString::number(labelNumber, 'g', 15);
           ui->resultshow->setText(newlabel);

       }
        ui->pushButton_dil->setChecked(false);
   }

}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_dobutok->setChecked(false);
    ui->pushButton_dil->setChecked(false);

    ui->resultshow->setText(0);
}

