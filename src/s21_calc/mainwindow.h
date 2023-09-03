#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>
#include <QKeyEvent>
#include <qdatetime.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include "../s21_smart_calc.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QDate date;

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, h, fillerX, maxBorderX, minBorderX, maxBorderY, minBorderY, result;
    QString tax, endResultmount, accumulatedInterest;
    int N;
    char *PRE;
    QVector <double> x, y;

protected:
    void keyPressEvent(QKeyEvent *e) override;

private slots:
    void charEntity();
    void addVectorGraph();

    datum* fillDate();
    void on_CalcCredit_clicked();
    void on_CalcDeposit_clicked();
    void on_equalsButton_clicked();
    void on_delButton_clicked();
    void on_ACButton_clicked();
    void on_BuildGraph_clicked();
};

#endif // MAINWINDOW_H
