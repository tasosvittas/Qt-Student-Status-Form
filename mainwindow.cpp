#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
{
    setFixedSize(300,300);
    setWindowTitle("Student Status");
    mainWidget=new QWidget;
    setCentralWidget(mainWidget);
    mainWidget->setFixedSize(this->width(),this->height());
    mainLayout=new QVBoxLayout;
    mainWidget->setLayout(mainLayout);
    row1=new QHBoxLayout;
    row2=new QHBoxLayout;
    mainLayout->addLayout(row1);
    mainLayout->addLayout(row2);

    nameEdit=new QLineEdit;
    nameEdit->setPlaceholderText("Student Name");
    lnEdit=new QLineEdit;
    lnEdit->setPlaceholderText("Student Lastname");
    row1->addWidget(nameEdit);
    row1->addWidget(lnEdit);

    amEdit=new QLineEdit;
    amEdit->setPlaceholderText("Am");
    amEdit->setValidator(new QIntValidator(1000,9999,this));
    semesterEdit=new QLineEdit;
    semesterEdit->setPlaceholderText("Semester");
    semesterEdit->setValidator(new QIntValidator(1,20,this));
    row2->addWidget(amEdit);
    row2->addWidget(semesterEdit);

    stSliderLabel = new QLabel;
    stSliderLabel->setText("Student Average Grade Slider");
    mainLayout->addWidget(stSliderLabel);

    studentSlider = new QSlider(Qt::Horizontal);
    studentSlider->setRange(0,10);
    studentSlider->setTickInterval(1);
    connect(studentSlider,SIGNAL(valueChanged(int)),this,SLOT(studentSlot(int)));
    mainLayout->addWidget(studentSlider);
    hiddenSliderLabel = new QLabel;
    mainLayout->addWidget(hiddenSliderLabel);

    pushButton = new QPushButton;
    pushButton->setText("Show Student Status");
    connect(pushButton,SIGNAL(clicked(bool)),this,SLOT(showStudentSlot()));
    mainLayout->addWidget(pushButton);
}

void MainWindow::studentSlot(int value)
{
   hiddenSliderLabel->setText("Average Grade: "+QString::number(value));
}

void MainWindow::showStudentSlot()
{
    QString text = nameEdit->text()+","+lnEdit->text()+
            ","+amEdit->text()+","+semesterEdit->text()+","+hiddenSliderLabel->text();
    QMessageBox::information(this,this->windowTitle(),text);
}

