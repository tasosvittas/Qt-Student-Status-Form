#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QIntValidator>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QLineEdit *nameEdit, *lnEdit,
        *amEdit, *semesterEdit;
    QLabel *stSliderLabel, *hiddenSliderLabel;
    QWidget *mainWidget;
    QSlider *studentSlider;
    QVBoxLayout *mainLayout;
    QHBoxLayout *row1, *row2;
    QPushButton *pushButton;

public slots:
    void showStudentSlot();
    void studentSlot(int value);
};
#endif // MAINWINDOW_H
