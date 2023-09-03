/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *calcWidget;
    QWidget *SmartCalc;
    QLineEdit *resultCalc;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_6;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_close_br;
    QPushButton *pushButton_7;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_5;
    QPushButton *ACButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_unary_minus;
    QPushButton *pushButton_ln;
    QPushButton *delButton;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_0;
    QPushButton *pushButton_sqrt;
    QPushButton *equalsButton;
    QPushButton *pushButton_point;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_1;
    QPushButton *pushButton_8;
    QPushButton *pushButton_open_br;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_log;
    QLineEdit *textEdit;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_degree;
    QPushButton *pushButton_div;
    QLineEdit *xValue;
    QPushButton *pushButton_2;
    QLineEdit *PRE;
    QPushButton *pushButton_x_number;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_cos;
    QCustomPlot *widgetGraph;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpinBox *minX;
    QSpinBox *maxX;
    QPushButton *BuildGraph;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *minY;
    QSpinBox *maxY;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QWidget *CreditCalc;
    QLabel *labelLoanBodyCredit;
    QLabel *labelTermCredit;
    QComboBox *comboBoxTypeOfFTermCredit;
    QLabel *labelPeriodInterest;
    QRadioButton *radioButtonAnnuitete;
    QRadioButton *radioButtonDifferential;
    QPushButton *CalcCredit;
    QLabel *labelMonthlyPayment;
    QLabel *labelLoanOverpay;
    QLabel *labelTotalPaymentsCredit;
    QSpinBox *spinBoxTermCredit;
    QDoubleSpinBox *doubleSpinLoanBody;
    QDoubleSpinBox *doubleSpinInterestCredit;
    QLineEdit *lineEditMonthlyPaymentResult;
    QLineEdit *lineEditOverpayResult;
    QLineEdit *lineEditTotalPaymentResult;
    QWidget *depositCalc;
    QLabel *labelDepositTerm;
    QDateEdit *dateStartDeposit;
    QDoubleSpinBox *KeyRate;
    QSpinBox *termOfDeposit;
    QLabel *labelStartDate;
    QDoubleSpinBox *interstRateDeposit;
    QLabel *labelInterstRate;
    QLabel *labelKeyRate;
    QPushButton *CalcDeposit;
    QCheckBox *Capitalisation;
    QLabel *PeriodType;
    QComboBox *PaymentPeriod;
    QCheckBox *checkBoxAddition;
    QCheckBox *checkBoxTakeDown;
    QDateEdit *dateEditAdd;
    QDateEdit *dateEditTakeDown;
    QComboBox *additionPeriod;
    QComboBox *takeDownPeriod;
    QLabel *tax;
    QLabel *totalInterest;
    QLabel *depositEndTerm;
    QLabel *labelTax_2;
    QDoubleSpinBox *depositAmount;
    QTextEdit *TaxSumm;
    QTextEdit *TotalInterestPayments;
    QTextEdit *DepositAmountTotal;
    QDoubleSpinBox *addAmmount;
    QDoubleSpinBox *dropAmount;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(780, 552);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QFont font;
        font.setKerning(false);
        centralwidget->setFont(font);
        centralwidget->setStyleSheet(QString::fromUtf8("QWidjet{\n"
"background-color: rgb(215, 215, 215);\n"
"}"));
        calcWidget = new QTabWidget(centralwidget);
        calcWidget->setObjectName(QString::fromUtf8("calcWidget"));
        calcWidget->setEnabled(true);
        calcWidget->setGeometry(QRect(0, 0, 781, 553));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        calcWidget->setFont(font1);
        calcWidget->setFocusPolicy(Qt::TabFocus);
        SmartCalc = new QWidget();
        SmartCalc->setObjectName(QString::fromUtf8("SmartCalc"));
        SmartCalc->setFont(font);
        SmartCalc->setTabletTracking(true);
        SmartCalc->setFocusPolicy(Qt::NoFocus);
        resultCalc = new QLineEdit(SmartCalc);
        resultCalc->setObjectName(QString::fromUtf8("resultCalc"));
        resultCalc->setGeometry(QRect(-3, 464, 366, 51));
        resultCalc->setFont(font);
        resultCalc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  qproperty-alignment: 'AlignRight';\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        pushButton_sub = new QPushButton(SmartCalc);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(180, 170, 61, 61));
        QFont font2;
        font2.setPointSize(18);
        font2.setKerning(false);
        pushButton_sub->setFont(font2);
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_6 = new QPushButton(SmartCalc);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(119, 170, 61, 61));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_tan = new QPushButton(SmartCalc);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(241, 292, 61, 61));
        QFont font3;
        font3.setPointSize(17);
        font3.setKerning(false);
        pushButton_tan->setFont(font3);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        pushButton_close_br = new QPushButton(SmartCalc);
        pushButton_close_br->setObjectName(QString::fromUtf8("pushButton_close_br"));
        pushButton_close_br->setGeometry(QRect(180, 48, 61, 61));
        pushButton_close_br->setFont(font2);
        pushButton_close_br->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_7 = new QPushButton(SmartCalc);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(-3, 109, 61, 61));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_acos = new QPushButton(SmartCalc);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(302, 231, 61, 61));
        pushButton_acos->setFont(font3);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        pushButton_5 = new QPushButton(SmartCalc);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(58, 170, 61, 61));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        ACButton = new QPushButton(SmartCalc);
        ACButton->setObjectName(QString::fromUtf8("ACButton"));
        ACButton->setGeometry(QRect(302, 48, 61, 61));
        ACButton->setFont(font3);
        ACButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_3 = new QPushButton(SmartCalc);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(119, 231, 61, 61));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_unary_minus = new QPushButton(SmartCalc);
        pushButton_unary_minus->setObjectName(QString::fromUtf8("pushButton_unary_minus"));
        pushButton_unary_minus->setGeometry(QRect(58, 48, 61, 61));
        pushButton_unary_minus->setFont(font2);
        pushButton_unary_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_ln = new QPushButton(SmartCalc);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(241, 109, 61, 61));
        pushButton_ln->setFont(font3);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        delButton = new QPushButton(SmartCalc);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setGeometry(QRect(241, 48, 61, 61));
        delButton->setFont(font3);
        delButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_mod = new QPushButton(SmartCalc);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(241, 353, 61, 61));
        pushButton_mod->setFont(font3);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        pushButton_0 = new QPushButton(SmartCalc);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(-3, 292, 122, 61));
        pushButton_0->setFont(font2);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_sqrt = new QPushButton(SmartCalc);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(302, 353, 61, 61));
        pushButton_sqrt->setFont(font3);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        equalsButton = new QPushButton(SmartCalc);
        equalsButton->setObjectName(QString::fromUtf8("equalsButton"));
        equalsButton->setGeometry(QRect(119, 353, 123, 61));
        equalsButton->setFont(font2);
        equalsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 145, 200);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        equalsButton->setAutoDefault(true);
        pushButton_point = new QPushButton(SmartCalc);
        pushButton_point->setObjectName(QString::fromUtf8("pushButton_point"));
        pushButton_point->setGeometry(QRect(119, 292, 61, 61));
        pushButton_point->setFont(font2);
        pushButton_point->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_9 = new QPushButton(SmartCalc);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(119, 109, 61, 61));
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4 = new QPushButton(SmartCalc);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(-3, 170, 61, 61));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_mult = new QPushButton(SmartCalc);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setGeometry(QRect(180, 231, 61, 61));
        pushButton_mult->setFont(font2);
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_1 = new QPushButton(SmartCalc);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(-3, 231, 61, 61));
        pushButton_1->setFont(font2);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_8 = new QPushButton(SmartCalc);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(58, 109, 61, 61));
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_open_br = new QPushButton(SmartCalc);
        pushButton_open_br->setObjectName(QString::fromUtf8("pushButton_open_br"));
        pushButton_open_br->setGeometry(QRect(119, 48, 61, 61));
        pushButton_open_br->setFont(font2);
        pushButton_open_br->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_plus = new QPushButton(SmartCalc);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(180, 109, 61, 61));
        pushButton_plus->setFont(font2);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_log = new QPushButton(SmartCalc);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(302, 109, 61, 61));
        pushButton_log->setFont(font3);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        textEdit = new QLineEdit(SmartCalc);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(-2, -2, 366, 51));
        textEdit->setFont(font);
        textEdit->setFocusPolicy(Qt::StrongFocus);
        textEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  qproperty-alignment: 'AlignRight';\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        textEdit->setCursorMoveStyle(Qt::VisualMoveStyle);
        pushButton_asin = new QPushButton(SmartCalc);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(302, 170, 61, 61));
        pushButton_asin->setFont(font3);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        pushButton_degree = new QPushButton(SmartCalc);
        pushButton_degree->setObjectName(QString::fromUtf8("pushButton_degree"));
        pushButton_degree->setGeometry(QRect(-3, 48, 61, 61));
        pushButton_degree->setFont(font2);
        pushButton_degree->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_div = new QPushButton(SmartCalc);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(180, 292, 61, 61));
        pushButton_div->setFont(font2);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        xValue = new QLineEdit(SmartCalc);
        xValue->setObjectName(QString::fromUtf8("xValue"));
        xValue->setGeometry(QRect(58, 353, 61, 61));
        xValue->setFont(font);
        xValue->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  qproperty-alignment: 'AlignCenter';\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        pushButton_2 = new QPushButton(SmartCalc);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(58, 231, 61, 61));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        PRE = new QLineEdit(SmartCalc);
        PRE->setObjectName(QString::fromUtf8("PRE"));
        PRE->setGeometry(QRect(-3, 414, 366, 51));
        PRE->setFont(font);
        PRE->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  qproperty-alignment: 'AlignRight';\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        pushButton_x_number = new QPushButton(SmartCalc);
        pushButton_x_number->setObjectName(QString::fromUtf8("pushButton_x_number"));
        pushButton_x_number->setGeometry(QRect(-3, 353, 61, 61));
        QFont font4;
        font4.setPointSize(12);
        font4.setKerning(false);
        pushButton_x_number->setFont(font4);
        pushButton_x_number->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(215, 215, 215);\n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_atan = new QPushButton(SmartCalc);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(302, 292, 61, 61));
        pushButton_atan->setFont(font3);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        pushButton_sin = new QPushButton(SmartCalc);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(241, 170, 61, 61));
        pushButton_sin->setFont(font3);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        pushButton_cos = new QPushButton(SmartCalc);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(241, 231, 61, 61));
        pushButton_cos->setFont(font3);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        widgetGraph = new QCustomPlot(SmartCalc);
        widgetGraph->setObjectName(QString::fromUtf8("widgetGraph"));
        widgetGraph->setEnabled(false);
        widgetGraph->setGeometry(QRect(363, 25, 413, 413));
        widgetGraph->setFont(font);
        widgetGraph->setStyleSheet(QString::fromUtf8("QCPScatterStyle{\n"
"background-color: rgb(255, 151, 57);\n"
"}"));
        label = new QLabel(SmartCalc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(530, 0, 101, 25));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setKerning(false);
        label->setFont(font5);
        label->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(SmartCalc);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(390, 430, 357, 59));
        layoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        minX = new QSpinBox(layoutWidget);
        minX->setObjectName(QString::fromUtf8("minX"));
        minX->setFont(font);
        minX->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	qproperty-alignment: 'AlignCenter';\n"
"}"));
        minX->setMinimum(-1000000);
        minX->setMaximum(-1);
        minX->setSingleStep(1);
        minX->setValue(-10);
        minX->setDisplayIntegerBase(10);

        verticalLayout->addWidget(minX);

        maxX = new QSpinBox(layoutWidget);
        maxX->setObjectName(QString::fromUtf8("maxX"));
        maxX->setFont(font);
        maxX->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	qproperty-alignment: 'AlignCenter';\n"
"}"));
        maxX->setMaximum(1000000);
        maxX->setValue(10);
        maxX->setDisplayIntegerBase(10);

        verticalLayout->addWidget(maxX);


        horizontalLayout->addLayout(verticalLayout);

        BuildGraph = new QPushButton(layoutWidget);
        BuildGraph->setObjectName(QString::fromUtf8("BuildGraph"));
        BuildGraph->setEnabled(true);
        BuildGraph->setFont(font5);

        horizontalLayout->addWidget(BuildGraph);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        minY = new QSpinBox(layoutWidget);
        minY->setObjectName(QString::fromUtf8("minY"));
        minY->setFont(font);
        minY->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	qproperty-alignment: 'AlignCenter';\n"
"}"));
        minY->setMinimum(-1000000);
        minY->setMaximum(-1);
        minY->setValue(-10);

        verticalLayout_2->addWidget(minY);

        maxY = new QSpinBox(layoutWidget);
        maxY->setObjectName(QString::fromUtf8("maxY"));
        maxY->setFont(font);
        maxY->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	qproperty-alignment: 'AlignCenter';\n"
"}"));
        maxY->setMaximum(1000000);
        maxY->setValue(10);

        verticalLayout_2->addWidget(maxY);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(SmartCalc);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(420, 490, 291, 29));
        layoutWidget1->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setFont(font5);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);
        label_3->setFont(font5);

        horizontalLayout_2->addWidget(label_3);

        calcWidget->addTab(SmartCalc, QString());
        CreditCalc = new QWidget();
        CreditCalc->setObjectName(QString::fromUtf8("CreditCalc"));
        labelLoanBodyCredit = new QLabel(CreditCalc);
        labelLoanBodyCredit->setObjectName(QString::fromUtf8("labelLoanBodyCredit"));
        labelLoanBodyCredit->setGeometry(QRect(40, 10, 351, 61));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        labelLoanBodyCredit->setFont(font6);
        labelLoanBodyCredit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelLoanBodyCredit->setTextFormat(Qt::PlainText);
        labelLoanBodyCredit->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable);
        labelTermCredit = new QLabel(CreditCalc);
        labelTermCredit->setObjectName(QString::fromUtf8("labelTermCredit"));
        labelTermCredit->setGeometry(QRect(40, 72, 175, 61));
        labelTermCredit->setFont(font6);
        labelTermCredit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelTermCredit->setTextFormat(Qt::PlainText);
        comboBoxTypeOfFTermCredit = new QComboBox(CreditCalc);
        comboBoxTypeOfFTermCredit->addItem(QString());
        comboBoxTypeOfFTermCredit->addItem(QString());
        comboBoxTypeOfFTermCredit->setObjectName(QString::fromUtf8("comboBoxTypeOfFTermCredit"));
        comboBoxTypeOfFTermCredit->setGeometry(QRect(216, 72, 175, 61));
        comboBoxTypeOfFTermCredit->setFont(font1);
        comboBoxTypeOfFTermCredit->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"  border: 1px solid gray;\n"
"}"));
        labelPeriodInterest = new QLabel(CreditCalc);
        labelPeriodInterest->setObjectName(QString::fromUtf8("labelPeriodInterest"));
        labelPeriodInterest->setGeometry(QRect(40, 134, 351, 61));
        labelPeriodInterest->setFont(font6);
        labelPeriodInterest->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelPeriodInterest->setTextFormat(Qt::PlainText);
        radioButtonAnnuitete = new QRadioButton(CreditCalc);
        radioButtonAnnuitete->setObjectName(QString::fromUtf8("radioButtonAnnuitete"));
        radioButtonAnnuitete->setGeometry(QRect(110, 380, 251, 61));
        radioButtonAnnuitete->setFont(font6);
        radioButtonAnnuitete->setLayoutDirection(Qt::RightToLeft);
        radioButtonAnnuitete->setChecked(true);
        radioButtonDifferential = new QRadioButton(CreditCalc);
        radioButtonDifferential->setObjectName(QString::fromUtf8("radioButtonDifferential"));
        radioButtonDifferential->setGeometry(QRect(400, 380, 251, 61));
        radioButtonDifferential->setFont(font6);
        radioButtonDifferential->setChecked(false);
        CalcCredit = new QPushButton(CreditCalc);
        CalcCredit->setObjectName(QString::fromUtf8("CalcCredit"));
        CalcCredit->setGeometry(QRect(40, 440, 703, 61));
        CalcCredit->setFont(font6);
        CalcCredit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 145, 200);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        labelMonthlyPayment = new QLabel(CreditCalc);
        labelMonthlyPayment->setObjectName(QString::fromUtf8("labelMonthlyPayment"));
        labelMonthlyPayment->setGeometry(QRect(40, 196, 351, 61));
        labelMonthlyPayment->setFont(font6);
        labelMonthlyPayment->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelMonthlyPayment->setTextFormat(Qt::PlainText);
        labelLoanOverpay = new QLabel(CreditCalc);
        labelLoanOverpay->setObjectName(QString::fromUtf8("labelLoanOverpay"));
        labelLoanOverpay->setGeometry(QRect(40, 258, 351, 61));
        labelLoanOverpay->setFont(font6);
        labelLoanOverpay->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelLoanOverpay->setTextFormat(Qt::PlainText);
        labelTotalPaymentsCredit = new QLabel(CreditCalc);
        labelTotalPaymentsCredit->setObjectName(QString::fromUtf8("labelTotalPaymentsCredit"));
        labelTotalPaymentsCredit->setGeometry(QRect(40, 320, 351, 61));
        labelTotalPaymentsCredit->setFont(font6);
        labelTotalPaymentsCredit->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelTotalPaymentsCredit->setTextFormat(Qt::PlainText);
        spinBoxTermCredit = new QSpinBox(CreditCalc);
        spinBoxTermCredit->setObjectName(QString::fromUtf8("spinBoxTermCredit"));
        spinBoxTermCredit->setGeometry(QRect(392, 72, 351, 61));
        spinBoxTermCredit->setFont(font6);
        spinBoxTermCredit->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        spinBoxTermCredit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxTermCredit->setMaximum(18250);
        doubleSpinLoanBody = new QDoubleSpinBox(CreditCalc);
        doubleSpinLoanBody->setObjectName(QString::fromUtf8("doubleSpinLoanBody"));
        doubleSpinLoanBody->setGeometry(QRect(392, 10, 351, 61));
        doubleSpinLoanBody->setFont(font6);
        doubleSpinLoanBody->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        doubleSpinLoanBody->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinLoanBody->setMaximum(999999999999999.000000000000000);
        doubleSpinInterestCredit = new QDoubleSpinBox(CreditCalc);
        doubleSpinInterestCredit->setObjectName(QString::fromUtf8("doubleSpinInterestCredit"));
        doubleSpinInterestCredit->setGeometry(QRect(392, 134, 351, 61));
        doubleSpinInterestCredit->setFont(font6);
        doubleSpinInterestCredit->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        doubleSpinInterestCredit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinInterestCredit->setMaximum(999.000000000000000);
        lineEditMonthlyPaymentResult = new QLineEdit(CreditCalc);
        lineEditMonthlyPaymentResult->setObjectName(QString::fromUtf8("lineEditMonthlyPaymentResult"));
        lineEditMonthlyPaymentResult->setGeometry(QRect(392, 196, 351, 61));
        lineEditMonthlyPaymentResult->setFont(font6);
        lineEditMonthlyPaymentResult->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"  border: 1px solid gray;\n"
"}"));
        lineEditOverpayResult = new QLineEdit(CreditCalc);
        lineEditOverpayResult->setObjectName(QString::fromUtf8("lineEditOverpayResult"));
        lineEditOverpayResult->setGeometry(QRect(392, 258, 351, 61));
        lineEditOverpayResult->setFont(font6);
        lineEditOverpayResult->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"  border: 1px solid gray;\n"
"}"));
        lineEditTotalPaymentResult = new QLineEdit(CreditCalc);
        lineEditTotalPaymentResult->setObjectName(QString::fromUtf8("lineEditTotalPaymentResult"));
        lineEditTotalPaymentResult->setGeometry(QRect(392, 320, 351, 61));
        lineEditTotalPaymentResult->setFont(font6);
        lineEditTotalPaymentResult->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"  border: 1px solid gray;\n"
"}"));
        calcWidget->addTab(CreditCalc, QString());
        depositCalc = new QWidget();
        depositCalc->setObjectName(QString::fromUtf8("depositCalc"));
        labelDepositTerm = new QLabel(depositCalc);
        labelDepositTerm->setObjectName(QString::fromUtf8("labelDepositTerm"));
        labelDepositTerm->setEnabled(false);
        labelDepositTerm->setGeometry(QRect(386, 10, 251, 61));
        labelDepositTerm->setFont(font6);
        labelDepositTerm->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        dateStartDeposit = new QDateEdit(depositCalc);
        dateStartDeposit->setObjectName(QString::fromUtf8("dateStartDeposit"));
        dateStartDeposit->setGeometry(QRect(638, 72, 125, 61));
        dateStartDeposit->setFont(font6);
        dateStartDeposit->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        dateStartDeposit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        KeyRate = new QDoubleSpinBox(depositCalc);
        KeyRate->setObjectName(QString::fromUtf8("KeyRate"));
        KeyRate->setGeometry(QRect(638, 196, 125, 61));
        KeyRate->setFont(font6);
        KeyRate->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        KeyRate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        termOfDeposit = new QSpinBox(depositCalc);
        termOfDeposit->setObjectName(QString::fromUtf8("termOfDeposit"));
        termOfDeposit->setGeometry(QRect(638, 10, 125, 61));
        termOfDeposit->setFont(font6);
        termOfDeposit->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        termOfDeposit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        termOfDeposit->setMaximum(18250);
        labelStartDate = new QLabel(depositCalc);
        labelStartDate->setObjectName(QString::fromUtf8("labelStartDate"));
        labelStartDate->setEnabled(false);
        labelStartDate->setGeometry(QRect(386, 72, 251, 61));
        labelStartDate->setFont(font6);
        labelStartDate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        interstRateDeposit = new QDoubleSpinBox(depositCalc);
        interstRateDeposit->setObjectName(QString::fromUtf8("interstRateDeposit"));
        interstRateDeposit->setGeometry(QRect(638, 134, 125, 61));
        interstRateDeposit->setFont(font6);
        interstRateDeposit->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        interstRateDeposit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        interstRateDeposit->setMaximum(999.000000000000000);
        labelInterstRate = new QLabel(depositCalc);
        labelInterstRate->setObjectName(QString::fromUtf8("labelInterstRate"));
        labelInterstRate->setEnabled(false);
        labelInterstRate->setGeometry(QRect(386, 134, 251, 61));
        labelInterstRate->setFont(font6);
        labelInterstRate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelKeyRate = new QLabel(depositCalc);
        labelKeyRate->setObjectName(QString::fromUtf8("labelKeyRate"));
        labelKeyRate->setEnabled(false);
        labelKeyRate->setGeometry(QRect(386, 196, 251, 61));
        labelKeyRate->setFont(font6);
        labelKeyRate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        CalcDeposit = new QPushButton(depositCalc);
        CalcDeposit->setObjectName(QString::fromUtf8("CalcDeposit"));
        CalcDeposit->setGeometry(QRect(10, 10, 377, 61));
        CalcDeposit->setFont(font6);
        CalcDeposit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 145, 200);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        Capitalisation = new QCheckBox(depositCalc);
        Capitalisation->setObjectName(QString::fromUtf8("Capitalisation"));
        Capitalisation->setGeometry(QRect(10, 72, 377, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Capitalisation->sizePolicy().hasHeightForWidth());
        Capitalisation->setSizePolicy(sizePolicy1);
        Capitalisation->setFont(font6);
        Capitalisation->setLayoutDirection(Qt::LeftToRight);
        Capitalisation->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
""));
        PeriodType = new QLabel(depositCalc);
        PeriodType->setObjectName(QString::fromUtf8("PeriodType"));
        PeriodType->setEnabled(false);
        PeriodType->setGeometry(QRect(10, 134, 283, 61));
        PeriodType->setFont(font6);
        PeriodType->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        PaymentPeriod = new QComboBox(depositCalc);
        PaymentPeriod->addItem(QString());
        PaymentPeriod->addItem(QString());
        PaymentPeriod->addItem(QString());
        PaymentPeriod->addItem(QString());
        PaymentPeriod->addItem(QString());
        PaymentPeriod->addItem(QString());
        PaymentPeriod->addItem(QString());
        PaymentPeriod->setObjectName(QString::fromUtf8("PaymentPeriod"));
        PaymentPeriod->setGeometry(QRect(294, 134, 93, 61));
        QFont font7;
        font7.setPointSize(9);
        font7.setBold(true);
        font7.setKerning(true);
        PaymentPeriod->setFont(font7);
        PaymentPeriod->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"  border: 1px solid gray;\n"
"}"));
        checkBoxAddition = new QCheckBox(depositCalc);
        checkBoxAddition->setObjectName(QString::fromUtf8("checkBoxAddition"));
        checkBoxAddition->setGeometry(QRect(10, 196, 71, 61));
        sizePolicy1.setHeightForWidth(checkBoxAddition->sizePolicy().hasHeightForWidth());
        checkBoxAddition->setSizePolicy(sizePolicy1);
        checkBoxAddition->setFont(font6);
        checkBoxAddition->setLayoutDirection(Qt::LeftToRight);
        checkBoxAddition->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
""));
        checkBoxTakeDown = new QCheckBox(depositCalc);
        checkBoxTakeDown->setObjectName(QString::fromUtf8("checkBoxTakeDown"));
        checkBoxTakeDown->setGeometry(QRect(10, 258, 71, 61));
        sizePolicy1.setHeightForWidth(checkBoxTakeDown->sizePolicy().hasHeightForWidth());
        checkBoxTakeDown->setSizePolicy(sizePolicy1);
        checkBoxTakeDown->setFont(font6);
        checkBoxTakeDown->setLayoutDirection(Qt::LeftToRight);
        checkBoxTakeDown->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
""));
        dateEditAdd = new QDateEdit(depositCalc);
        dateEditAdd->setObjectName(QString::fromUtf8("dateEditAdd"));
        dateEditAdd->setGeometry(QRect(200, 196, 93, 61));
        QFont font8;
        font8.setPointSize(9);
        font8.setBold(true);
        dateEditAdd->setFont(font8);
        dateEditAdd->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"  border: 1px solid gray;\n"
"}"));
        dateEditAdd->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateEditTakeDown = new QDateEdit(depositCalc);
        dateEditTakeDown->setObjectName(QString::fromUtf8("dateEditTakeDown"));
        dateEditTakeDown->setGeometry(QRect(200, 258, 93, 61));
        dateEditTakeDown->setFont(font8);
        dateEditTakeDown->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"  border: 1px solid gray;\n"
"}"));
        dateEditTakeDown->setButtonSymbols(QAbstractSpinBox::NoButtons);
        additionPeriod = new QComboBox(depositCalc);
        additionPeriod->addItem(QString());
        additionPeriod->addItem(QString());
        additionPeriod->addItem(QString());
        additionPeriod->addItem(QString());
        additionPeriod->addItem(QString());
        additionPeriod->addItem(QString());
        additionPeriod->setObjectName(QString::fromUtf8("additionPeriod"));
        additionPeriod->setGeometry(QRect(294, 196, 93, 61));
        additionPeriod->setFont(font8);
        additionPeriod->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"  border: 1px solid gray;\n"
"}"));
        takeDownPeriod = new QComboBox(depositCalc);
        takeDownPeriod->addItem(QString());
        takeDownPeriod->addItem(QString());
        takeDownPeriod->addItem(QString());
        takeDownPeriod->addItem(QString());
        takeDownPeriod->addItem(QString());
        takeDownPeriod->addItem(QString());
        takeDownPeriod->setObjectName(QString::fromUtf8("takeDownPeriod"));
        takeDownPeriod->setGeometry(QRect(294, 258, 93, 61));
        takeDownPeriod->setFont(font8);
        takeDownPeriod->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"  border: 1px solid gray;\n"
"}"));
        tax = new QLabel(depositCalc);
        tax->setObjectName(QString::fromUtf8("tax"));
        tax->setEnabled(false);
        tax->setGeometry(QRect(10, 320, 377, 61));
        tax->setFont(font6);
        tax->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        totalInterest = new QLabel(depositCalc);
        totalInterest->setObjectName(QString::fromUtf8("totalInterest"));
        totalInterest->setEnabled(false);
        totalInterest->setGeometry(QRect(10, 382, 377, 61));
        totalInterest->setFont(font6);
        totalInterest->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        depositEndTerm = new QLabel(depositCalc);
        depositEndTerm->setObjectName(QString::fromUtf8("depositEndTerm"));
        depositEndTerm->setEnabled(false);
        depositEndTerm->setGeometry(QRect(10, 444, 377, 61));
        depositEndTerm->setFont(font6);
        depositEndTerm->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(255, 201, 157);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        labelTax_2 = new QLabel(depositCalc);
        labelTax_2->setObjectName(QString::fromUtf8("labelTax_2"));
        labelTax_2->setEnabled(false);
        labelTax_2->setGeometry(QRect(386, 258, 251, 61));
        labelTax_2->setFont(font6);
        labelTax_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  background-color: rgb(155, 181, 137);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}"));
        depositAmount = new QDoubleSpinBox(depositCalc);
        depositAmount->setObjectName(QString::fromUtf8("depositAmount"));
        depositAmount->setGeometry(QRect(638, 258, 125, 61));
        depositAmount->setFont(font6);
        depositAmount->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        depositAmount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        depositAmount->setMaximum(999999999999999.000000000000000);
        TaxSumm = new QTextEdit(depositCalc);
        TaxSumm->setObjectName(QString::fromUtf8("TaxSumm"));
        TaxSumm->setGeometry(QRect(386, 320, 377, 61));
        TaxSumm->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"  border: 1px solid gray;\n"
"}"));
        TotalInterestPayments = new QTextEdit(depositCalc);
        TotalInterestPayments->setObjectName(QString::fromUtf8("TotalInterestPayments"));
        TotalInterestPayments->setGeometry(QRect(386, 382, 377, 62));
        TotalInterestPayments->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"  border: 1px solid gray;\n"
"}"));
        DepositAmountTotal = new QTextEdit(depositCalc);
        DepositAmountTotal->setObjectName(QString::fromUtf8("DepositAmountTotal"));
        DepositAmountTotal->setGeometry(QRect(386, 444, 377, 61));
        DepositAmountTotal->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"  border: 1px solid gray;\n"
"}"));
        addAmmount = new QDoubleSpinBox(depositCalc);
        addAmmount->setObjectName(QString::fromUtf8("addAmmount"));
        addAmmount->setGeometry(QRect(82, 196, 117, 61));
        addAmmount->setFont(font8);
        addAmmount->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        addAmmount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        addAmmount->setMaximum(999999999999999.000000000000000);
        dropAmount = new QDoubleSpinBox(depositCalc);
        dropAmount->setObjectName(QString::fromUtf8("dropAmount"));
        dropAmount->setGeometry(QRect(82, 258, 117, 61));
        dropAmount->setFont(font8);
        dropAmount->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"  border: 1px solid gray;\n"
"}"));
        dropAmount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dropAmount->setMaximum(999999999999999.000000000000000);
        calcWidget->addTab(depositCalc, QString());
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(textEdit, maxX);
        QWidget::setTabOrder(maxX, minX);
        QWidget::setTabOrder(minX, minY);
        QWidget::setTabOrder(minY, maxY);
        QWidget::setTabOrder(maxY, BuildGraph);
        QWidget::setTabOrder(BuildGraph, doubleSpinLoanBody);
        QWidget::setTabOrder(doubleSpinLoanBody, comboBoxTypeOfFTermCredit);
        QWidget::setTabOrder(comboBoxTypeOfFTermCredit, xValue);
        QWidget::setTabOrder(xValue, spinBoxTermCredit);
        QWidget::setTabOrder(spinBoxTermCredit, doubleSpinInterestCredit);
        QWidget::setTabOrder(doubleSpinInterestCredit, radioButtonAnnuitete);
        QWidget::setTabOrder(radioButtonAnnuitete, radioButtonDifferential);
        QWidget::setTabOrder(radioButtonDifferential, CalcCredit);
        QWidget::setTabOrder(CalcCredit, Capitalisation);
        QWidget::setTabOrder(Capitalisation, PaymentPeriod);
        QWidget::setTabOrder(PaymentPeriod, checkBoxAddition);
        QWidget::setTabOrder(checkBoxAddition, dateEditAdd);
        QWidget::setTabOrder(dateEditAdd, additionPeriod);
        QWidget::setTabOrder(additionPeriod, checkBoxTakeDown);
        QWidget::setTabOrder(checkBoxTakeDown, dateEditTakeDown);
        QWidget::setTabOrder(dateEditTakeDown, takeDownPeriod);
        QWidget::setTabOrder(takeDownPeriod, termOfDeposit);
        QWidget::setTabOrder(termOfDeposit, dateStartDeposit);
        QWidget::setTabOrder(dateStartDeposit, interstRateDeposit);
        QWidget::setTabOrder(interstRateDeposit, KeyRate);
        QWidget::setTabOrder(KeyRate, depositAmount);
        QWidget::setTabOrder(depositAmount, CalcDeposit);
        QWidget::setTabOrder(CalcDeposit, pushButton_degree);
        QWidget::setTabOrder(pushButton_degree, pushButton_div);
        QWidget::setTabOrder(pushButton_div, pushButton_close_br);
        QWidget::setTabOrder(pushButton_close_br, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_tan);
        QWidget::setTabOrder(pushButton_tan, pushButton_x_number);
        QWidget::setTabOrder(pushButton_x_number, pushButton_atan);
        QWidget::setTabOrder(pushButton_atan, pushButton_sin);
        QWidget::setTabOrder(pushButton_sin, pushButton_cos);
        QWidget::setTabOrder(pushButton_cos, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_unary_minus);
        QWidget::setTabOrder(pushButton_unary_minus, ACButton);
        QWidget::setTabOrder(ACButton, pushButton_acos);
        QWidget::setTabOrder(pushButton_acos, pushButton_5);
        QWidget::setTabOrder(pushButton_5, calcWidget);
        QWidget::setTabOrder(calcWidget, resultCalc);
        QWidget::setTabOrder(resultCalc, pushButton_ln);
        QWidget::setTabOrder(pushButton_ln, delButton);
        QWidget::setTabOrder(delButton, pushButton_mod);
        QWidget::setTabOrder(pushButton_mod, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_sub);
        QWidget::setTabOrder(pushButton_sub, PRE);
        QWidget::setTabOrder(PRE, pushButton_open_br);
        QWidget::setTabOrder(pushButton_open_br, pushButton_log);
        QWidget::setTabOrder(pushButton_log, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_plus);
        QWidget::setTabOrder(pushButton_plus, pushButton_asin);
        QWidget::setTabOrder(pushButton_asin, pushButton_0);
        QWidget::setTabOrder(pushButton_0, pushButton_sqrt);
        QWidget::setTabOrder(pushButton_sqrt, equalsButton);
        QWidget::setTabOrder(equalsButton, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_point);
        QWidget::setTabOrder(pushButton_point, pushButton_mult);
        QWidget::setTabOrder(pushButton_mult, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_1);
        QWidget::setTabOrder(pushButton_1, pushButton_3);

        retranslateUi(MainWindow);

        calcWidget->setCurrentIndex(2);
        equalsButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        resultCalc->setPlaceholderText(QCoreApplication::translate("MainWindow", " Result of calculation ", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "Tan", nullptr));
        pushButton_close_br->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "Acos", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        ACButton->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_unary_minus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "Ln", nullptr));
        delButton->setText(QCoreApplication::translate("MainWindow", "del", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "Mod", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "Sqrt", nullptr));
        equalsButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_open_br->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", " Edit expression ", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "Asin", nullptr));
        pushButton_degree->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        xValue->setPlaceholderText(QCoreApplication::translate("MainWindow", " x value", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        PRE->setPlaceholderText(QCoreApplication::translate("MainWindow", " Here will be reverse polish entry ", nullptr));
        pushButton_x_number->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "Atan", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "Sin", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "Cos", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Graph UI", nullptr));
        BuildGraph->setText(QCoreApplication::translate("MainWindow", "Build Graph", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        calcWidget->setTabText(calcWidget->indexOf(SmartCalc), QCoreApplication::translate("MainWindow", "     S21 Smart Calculator     ", nullptr));
        labelLoanBodyCredit->setText(QCoreApplication::translate("MainWindow", "  Loan Body", nullptr));
        labelTermCredit->setText(QCoreApplication::translate("MainWindow", "  Term", nullptr));
        comboBoxTypeOfFTermCredit->setItemText(0, QCoreApplication::translate("MainWindow", "Months", nullptr));
        comboBoxTypeOfFTermCredit->setItemText(1, QCoreApplication::translate("MainWindow", "Years", nullptr));

        labelPeriodInterest->setText(QCoreApplication::translate("MainWindow", "  Period interest", nullptr));
        radioButtonAnnuitete->setText(QCoreApplication::translate("MainWindow", "Annuitete", nullptr));
        radioButtonDifferential->setText(QCoreApplication::translate("MainWindow", "Differential", nullptr));
        CalcCredit->setText(QCoreApplication::translate("MainWindow", "Caclulate", nullptr));
        labelMonthlyPayment->setText(QCoreApplication::translate("MainWindow", "  Monthly Payment", nullptr));
        labelLoanOverpay->setText(QCoreApplication::translate("MainWindow", "  Loan Overpay", nullptr));
        labelTotalPaymentsCredit->setText(QCoreApplication::translate("MainWindow", "  Total Payment", nullptr));
        calcWidget->setTabText(calcWidget->indexOf(CreditCalc), QCoreApplication::translate("MainWindow", "     Smart Credit Calculator     ", nullptr));
        labelDepositTerm->setText(QCoreApplication::translate("MainWindow", "  Term in days", nullptr));
        labelStartDate->setText(QCoreApplication::translate("MainWindow", "  Start deposit", nullptr));
        labelInterstRate->setText(QCoreApplication::translate("MainWindow", "  Interest Rate", nullptr));
        labelKeyRate->setText(QCoreApplication::translate("MainWindow", "  Max Key Rate In Year", nullptr));
        CalcDeposit->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        Capitalisation->setText(QCoreApplication::translate("MainWindow", "Capitalisation", nullptr));
        PeriodType->setText(QCoreApplication::translate("MainWindow", "  Period Type", nullptr));
        PaymentPeriod->setItemText(0, QCoreApplication::translate("MainWindow", "Per Day", nullptr));
        PaymentPeriod->setItemText(1, QCoreApplication::translate("MainWindow", "Per Week", nullptr));
        PaymentPeriod->setItemText(2, QCoreApplication::translate("MainWindow", "Per Month", nullptr));
        PaymentPeriod->setItemText(3, QCoreApplication::translate("MainWindow", "Per Quoter", nullptr));
        PaymentPeriod->setItemText(4, QCoreApplication::translate("MainWindow", "Per Two Quoters", nullptr));
        PaymentPeriod->setItemText(5, QCoreApplication::translate("MainWindow", "Per Year", nullptr));
        PaymentPeriod->setItemText(6, QCoreApplication::translate("MainWindow", "At The End of Period", nullptr));

        checkBoxAddition->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        checkBoxTakeDown->setText(QCoreApplication::translate("MainWindow", "Drop", nullptr));
        additionPeriod->setItemText(0, QCoreApplication::translate("MainWindow", "One-time", nullptr));
        additionPeriod->setItemText(1, QCoreApplication::translate("MainWindow", "Per Month", nullptr));
        additionPeriod->setItemText(2, QCoreApplication::translate("MainWindow", "Per Two Months", nullptr));
        additionPeriod->setItemText(3, QCoreApplication::translate("MainWindow", "Per Quoter", nullptr));
        additionPeriod->setItemText(4, QCoreApplication::translate("MainWindow", "Per Two Quoters", nullptr));
        additionPeriod->setItemText(5, QCoreApplication::translate("MainWindow", "Per Year", nullptr));

        takeDownPeriod->setItemText(0, QCoreApplication::translate("MainWindow", "One-time", nullptr));
        takeDownPeriod->setItemText(1, QCoreApplication::translate("MainWindow", "Per Month", nullptr));
        takeDownPeriod->setItemText(2, QCoreApplication::translate("MainWindow", "Per Two Months", nullptr));
        takeDownPeriod->setItemText(3, QCoreApplication::translate("MainWindow", "Per Quoter", nullptr));
        takeDownPeriod->setItemText(4, QCoreApplication::translate("MainWindow", "Per Two Quoters", nullptr));
        takeDownPeriod->setItemText(5, QCoreApplication::translate("MainWindow", "Per Year", nullptr));

        tax->setText(QCoreApplication::translate("MainWindow", "  Tax", nullptr));
        totalInterest->setText(QCoreApplication::translate("MainWindow", "  Total Interest Payment", nullptr));
        depositEndTerm->setText(QCoreApplication::translate("MainWindow", "  Deposit Amount At The End Of Term", nullptr));
        labelTax_2->setText(QCoreApplication::translate("MainWindow", "  Start Deposit Amount", nullptr));
        calcWidget->setTabText(calcWidget->indexOf(depositCalc), QCoreApplication::translate("MainWindow", "     Smart Deposit Calculator     ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
