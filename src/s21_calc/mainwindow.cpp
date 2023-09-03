#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QStyle>
#include <QString>
#include <QWidget>
#include <QTextEdit>
#include <QDir>
#include <cmath>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_open_br, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_close_br, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_unary_minus, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_x_number, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(charEntity()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(charEntity()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return && ui->SmartCalc->isActiveWindow())
        on_equalsButton_clicked();
    else if(e->key() == Qt::Key_Return && ui->CreditCalc->isActiveWindow())
        on_CalcCredit_clicked();
}

void MainWindow::charEntity()
{
    QPushButton *currentCharEntity = (QPushButton *)sender();
    if(currentCharEntity->text() == "+/-")
        ui->textEdit->setText(ui->textEdit->text() + "-");
    else if(currentCharEntity->text() == "/")
        ui->textEdit->setText(ui->textEdit->text() + "/");
    else
        ui->textEdit->setText(ui->textEdit->text() + currentCharEntity->text());
}

void MainWindow::addVectorGraph(){
     double temp_result = FALSE;

      QByteArray temp = ui->minX->text().toLocal8Bit();
      minBorderX = temp.toDouble();
      temp = ui->maxX->text().toLocal8Bit();
      maxBorderX = temp.toDouble();
      temp = ui->minY->text().toLocal8Bit();
      minBorderY = temp.toDouble();
      temp = ui->maxY->text().toLocal8Bit();
      maxBorderY = temp.toDouble();

      if(result <= 1000000 + 100 && result >= -1000000 - 100){
        x.clear();
        y.clear();
          result < s21_epsilon ? temp_result = result * (-1) : (temp_result = result);
          if(temp_result < 10)
          h = 0.0001;
          else if(temp_result >= 10 && temp_result < 100)
          h = 0.001;
          else if(temp_result >= 100 && temp_result < 1000)
          h = 0.01;
          else if(temp_result >= 1000 && temp_result < 10000)
          h = 0.1;
          else if(temp_result >= 10000 )
          h = 1.0;

          xBegin = result;
          result >= maxBorderY ? maxBorderY = result + 1 : result;
          result <= minBorderY ? minBorderY = result - 1 : result;

          xEnd = maxBorderX + h;
          N = (xEnd - xBegin) / h + 2;
          for(fillerX = xBegin; fillerX <= xEnd; fillerX += h)
          {
            result = calc_polish_reverse_entry(PRE, fillerX);
            x.push_back(fillerX);
            y.push_back(result);
            result >= maxBorderY ? maxBorderY = result + 1 : result;
          }

          xEnd = minBorderX - h;
          for(fillerX = xBegin; fillerX >= xEnd; fillerX -= h)
          {
            result = calc_polish_reverse_entry(PRE, fillerX);
            x.push_back(fillerX);
            y.push_back(result);
            result <= minBorderY ? minBorderY = result - 1 : result;
          }
      }
}

datum* MainWindow::fillDate()
{
      datum *date_add_drop = (datum *) calloc(UNO, sizeof(datum));
      if(date_add_drop){
        date_add_drop->date = date.day();
        date_add_drop->month = date.month();
        date_add_drop->year = date.year();
      }

      return date_add_drop;
}


void MainWindow::on_equalsButton_clicked()
{
  int error = FALSE;
  QByteArray bArray = ui->textEdit->text().toLocal8Bit();
  if(bArray != "")
  {
    QByteArray xArray = ui->xValue->text().toLocal8Bit();
    char *qstringToChar = bArray.data();
    double xNumber = xArray.toDouble();
    PRE = string_conversion(qstringToChar, &error);
    ui->PRE->setText(PRE);
    if(!error){
            result = calc_polish_reverse_entry(PRE, xNumber);
            ui->resultCalc->setText(QString::number(result, 'g', 15));
    }
  } else
    ui->resultCalc->setText("EMPTY_STRING");
}


void MainWindow::on_delButton_clicked()
{
  QString temp = ui->textEdit->text();
  temp.chop(1);
  ui->textEdit->setText(temp);
}


void MainWindow::on_ACButton_clicked()
{
  ui->textEdit->setText("");
  ui->PRE->setText("");
  ui->resultCalc->setText("");
}


void MainWindow::on_BuildGraph_clicked()
{
  ui->widgetGraph->clearGraphs();
  addVectorGraph();
  ui->widgetGraph->xAxis->setRange(minBorderX, maxBorderX);
  ui->widgetGraph->yAxis->setRange(minBorderY, maxBorderY);
  ui->widgetGraph->addGraph();
  ui->widgetGraph->graph()->setLineStyle(QCPGraph::lsLine);
  ui->widgetGraph->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
  ui->widgetGraph->graph()->addData(x,y);
  ui->widgetGraph->replot();
}


void MainWindow::on_CalcCredit_clicked()
{
  credit *current_calc = (credit*)calloc(UNO, sizeof(credit));

  if(current_calc){
    current_calc->loan_body = ui->doubleSpinLoanBody->value();
    current_calc->term = ui->spinBoxTermCredit->value();
    current_calc->interest_rate = ui->doubleSpinInterestCredit->value();
    ui->radioButtonAnnuitete->isChecked() ? current_calc->type_of_pay = ANNUITETTE : current_calc->type_of_pay = DIFFERENTIAL;
    s21_credit_calc(current_calc);
    ui->lineEditMonthlyPaymentResult->setText(QString::number(current_calc->monthly_payment_max, 'f', 2));
    if(current_calc->type_of_pay == DIFFERENTIAL)
            ui->lineEditMonthlyPaymentResult->setText(ui->lineEditMonthlyPaymentResult->text() + " ... " + QString::number(current_calc->monthly_payment_min, 'f', 2));
    ui->lineEditOverpayResult->setText(QString::number(current_calc->loan_overpayment, 'f', 2));
    ui->lineEditTotalPaymentResult->setText(QString::number(current_calc->total_payment, 'f', 2));
    free(current_calc);
  }
}


void MainWindow::on_CalcDeposit_clicked()
{
  deposit *current_calc = (deposit*)calloc(UNO, sizeof(deposit));

  if(current_calc){
    current_calc->amount = ui->depositAmount->value();
    current_calc->term = ui->termOfDeposit->value();
    current_calc->interest_capitalization = ui->Capitalisation->isChecked();
    current_calc->payout_frequency = payout_frequency(ui->PaymentPeriod->currentIndex());
    if(ui->checkBoxAddition->isChecked()){
            date = ui->dateEditAdd->date();
            current_calc->add_list = (drop_add_lists*)calloc(UNO, sizeof(drop_add_lists));
            current_calc->add_list->date_add_drop = fillDate();
            current_calc->add_list->amount = ui->addAmmount->value();
            current_calc->add_list->frequency = check_frequence_add_drop(ui->additionPeriod->currentIndex());
    }
    if(ui->checkBoxTakeDown->isChecked()){
            date = ui->dateEditTakeDown->date();
            current_calc->drop_list = (drop_add_lists*)calloc(UNO, sizeof(drop_add_lists));
            current_calc->drop_list->date_add_drop = fillDate();
            current_calc->drop_list->amount = ui->dropAmount->value();
            current_calc->drop_list->frequency = check_frequence_add_drop(ui->takeDownPeriod->currentIndex());
    }
    current_calc->term = ui->termOfDeposit->value();
    date = ui->dateStartDeposit->date();
    current_calc->start_date = fillDate();
    current_calc->interest_rate = ui->interstRateDeposit->value();
    current_calc->tax_rate = ui->KeyRate->value();

    s21_deposit_calc(current_calc);

    tax = QString().asprintf("%0.2f", current_calc->tax_amount);
    endResultmount = QString().asprintf("%0.2f", current_calc->end_term_amount);
    accumulatedInterest = QString().asprintf("%0.2f", current_calc->accumulated_balance_interest);


    ui->TaxSumm->setText(tax);
    ui->TotalInterestPayments->setText(accumulatedInterest);
    ui->DepositAmountTotal->setText(endResultmount);


    if(current_calc->add_list) free(current_calc->add_list);
    if(current_calc->drop_list) free(current_calc->drop_list);
    free(current_calc);
  }
}
