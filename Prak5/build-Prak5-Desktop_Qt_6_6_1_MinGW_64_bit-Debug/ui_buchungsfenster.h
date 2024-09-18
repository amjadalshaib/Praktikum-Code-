/********************************************************************************
** Form generated from reading UI file 'buchungsfenster.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUCHUNGSFENSTER_H
#define UI_BUCHUNGSFENSTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuchungsFenster
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLineEdit *lineEditID;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QDateEdit *dateEditVon;
    QFormLayout *formLayout_6;
    QLabel *label_5;
    QDateEdit *dateEdit_2;
    QFormLayout *formLayout_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBoxPreis;
    QTabWidget *tabWidget;
    QWidget *Zug;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *Von_2;
    QLineEdit *lineEditAbfahrtZ;
    QLabel *label_7;
    QTimeEdit *timeEditAbfahrt;
    QLabel *Bis_2;
    QLineEdit *lineEditAnkunftZ;
    QLabel *label_11;
    QTimeEdit *timeEditAnkunft;
    QLabel *label_3;
    QLineEdit *lineEditZugklasse;
    QLabel *label_9;
    QTableWidget *tableWidgetZ;
    QWidget *Flug;
    QFormLayout *formLayout_8;
    QLabel *Von_3;
    QLineEdit *lineEditAbfahrtF;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QLineEdit *lineEditFDestcode;
    QLabel *Bis_3;
    QLineEdit *lineEditAnkunftF;
    QFormLayout *formLayout_2;
    QLabel *label_13;
    QLineEdit *lineEdittoDestCode;
    QLabel *label_4;
    QLineEdit *lineEditFlugKlasse;
    QLabel *label_2;
    QLineEdit *lineEditAirline;
    QWidget *Hotel;
    QFormLayout *formLayout_4;
    QLabel *Von_4;
    QLineEdit *lineEditHotel;
    QLabel *Bis_4;
    QLineEdit *lineEditTown;
    QLabel *label_21;
    QLineEdit *lineEditZimmertyp;
    QWidget *Car;
    QFormLayout *formLayout_5;
    QLabel *Von_5;
    QLineEdit *lineEditPickup;
    QLabel *Bis_5;
    QLineEdit *lineEditReturn;
    QLabel *label_23;
    QLineEdit *lineEditCartyp;
    QLabel *label;
    QLineEdit *lineEditComany;

    void setupUi(QWidget *BuchungsFenster)
    {
        if (BuchungsFenster->objectName().isEmpty())
            BuchungsFenster->setObjectName("BuchungsFenster");
        BuchungsFenster->resize(385, 657);
        layoutWidget = new QWidget(BuchungsFenster);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(31, 35, 331, 601));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEditID = new QLineEdit(layoutWidget);
        lineEditID->setObjectName("lineEditID");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditID);


        verticalLayout->addLayout(formLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        dateEditVon = new QDateEdit(layoutWidget);
        dateEditVon->setObjectName("dateEditVon");
        dateEditVon->setCalendarPopup(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, dateEditVon);


        verticalLayout->addLayout(formLayout_3);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName("formLayout_6");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_5);

        dateEdit_2 = new QDateEdit(layoutWidget);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setCalendarPopup(true);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, dateEdit_2);


        verticalLayout->addLayout(formLayout_6);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName("formLayout_7");
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_8);

        doubleSpinBoxPreis = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxPreis->setObjectName("doubleSpinBoxPreis");
        doubleSpinBoxPreis->setDecimals(2);
        doubleSpinBoxPreis->setMinimum(0.000000000000000);
        doubleSpinBoxPreis->setMaximum(10000.000000000000000);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, doubleSpinBoxPreis);


        verticalLayout->addLayout(formLayout_7);


        verticalLayout_2->addLayout(verticalLayout);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName("tabWidget");
        Zug = new QWidget();
        Zug->setObjectName("Zug");
        layoutWidget1 = new QWidget(Zug);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(12, 12, 291, 371));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Von_2 = new QLabel(layoutWidget1);
        Von_2->setObjectName("Von_2");

        gridLayout->addWidget(Von_2, 0, 0, 1, 1);

        lineEditAbfahrtZ = new QLineEdit(layoutWidget1);
        lineEditAbfahrtZ->setObjectName("lineEditAbfahrtZ");

        gridLayout->addWidget(lineEditAbfahrtZ, 0, 1, 1, 4);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 0, 1, 3);

        timeEditAbfahrt = new QTimeEdit(layoutWidget1);
        timeEditAbfahrt->setObjectName("timeEditAbfahrt");
        timeEditAbfahrt->setMaximumTime(QTime(23, 59, 59));
        timeEditAbfahrt->setMinimumTime(QTime(0, 0, 0));

        gridLayout->addWidget(timeEditAbfahrt, 1, 3, 1, 2);

        Bis_2 = new QLabel(layoutWidget1);
        Bis_2->setObjectName("Bis_2");

        gridLayout->addWidget(Bis_2, 2, 0, 1, 2);

        lineEditAnkunftZ = new QLineEdit(layoutWidget1);
        lineEditAnkunftZ->setObjectName("lineEditAnkunftZ");

        gridLayout->addWidget(lineEditAnkunftZ, 2, 2, 1, 3);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 3, 0, 1, 3);

        timeEditAnkunft = new QTimeEdit(layoutWidget1);
        timeEditAnkunft->setObjectName("timeEditAnkunft");

        gridLayout->addWidget(timeEditAnkunft, 3, 3, 1, 2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 4);

        lineEditZugklasse = new QLineEdit(layoutWidget1);
        lineEditZugklasse->setObjectName("lineEditZugklasse");

        gridLayout->addWidget(lineEditZugklasse, 4, 4, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        tableWidgetZ = new QTableWidget(layoutWidget1);
        if (tableWidgetZ->columnCount() < 1)
            tableWidgetZ->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetZ->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetZ->setObjectName("tableWidgetZ");

        gridLayout->addWidget(tableWidgetZ, 5, 2, 1, 3);

        tabWidget->addTab(Zug, QString());
        Flug = new QWidget();
        Flug->setObjectName("Flug");
        formLayout_8 = new QFormLayout(Flug);
        formLayout_8->setObjectName("formLayout_8");
        Von_3 = new QLabel(Flug);
        Von_3->setObjectName("Von_3");

        formLayout_8->setWidget(0, QFormLayout::LabelRole, Von_3);

        lineEditAbfahrtF = new QLineEdit(Flug);
        lineEditAbfahrtF->setObjectName("lineEditAbfahrtF");

        formLayout_8->setWidget(0, QFormLayout::FieldRole, lineEditAbfahrtF);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_12 = new QLabel(Flug);
        label_12->setObjectName("label_12");

        horizontalLayout->addWidget(label_12);

        lineEditFDestcode = new QLineEdit(Flug);
        lineEditFDestcode->setObjectName("lineEditFDestcode");
        lineEditFDestcode->setEnabled(true);
        lineEditFDestcode->setReadOnly(true);

        horizontalLayout->addWidget(lineEditFDestcode);


        formLayout_8->setLayout(1, QFormLayout::SpanningRole, horizontalLayout);

        Bis_3 = new QLabel(Flug);
        Bis_3->setObjectName("Bis_3");

        formLayout_8->setWidget(2, QFormLayout::LabelRole, Bis_3);

        lineEditAnkunftF = new QLineEdit(Flug);
        lineEditAnkunftF->setObjectName("lineEditAnkunftF");

        formLayout_8->setWidget(2, QFormLayout::FieldRole, lineEditAnkunftF);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_13 = new QLabel(Flug);
        label_13->setObjectName("label_13");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_13);

        lineEdittoDestCode = new QLineEdit(Flug);
        lineEdittoDestCode->setObjectName("lineEdittoDestCode");
        lineEdittoDestCode->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdittoDestCode);


        formLayout_8->setLayout(3, QFormLayout::SpanningRole, formLayout_2);

        label_4 = new QLabel(Flug);
        label_4->setObjectName("label_4");

        formLayout_8->setWidget(4, QFormLayout::LabelRole, label_4);

        lineEditFlugKlasse = new QLineEdit(Flug);
        lineEditFlugKlasse->setObjectName("lineEditFlugKlasse");

        formLayout_8->setWidget(4, QFormLayout::FieldRole, lineEditFlugKlasse);

        label_2 = new QLabel(Flug);
        label_2->setObjectName("label_2");

        formLayout_8->setWidget(5, QFormLayout::LabelRole, label_2);

        lineEditAirline = new QLineEdit(Flug);
        lineEditAirline->setObjectName("lineEditAirline");

        formLayout_8->setWidget(5, QFormLayout::FieldRole, lineEditAirline);

        tabWidget->addTab(Flug, QString());
        Hotel = new QWidget();
        Hotel->setObjectName("Hotel");
        formLayout_4 = new QFormLayout(Hotel);
        formLayout_4->setObjectName("formLayout_4");
        Von_4 = new QLabel(Hotel);
        Von_4->setObjectName("Von_4");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, Von_4);

        lineEditHotel = new QLineEdit(Hotel);
        lineEditHotel->setObjectName("lineEditHotel");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEditHotel);

        Bis_4 = new QLabel(Hotel);
        Bis_4->setObjectName("Bis_4");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, Bis_4);

        lineEditTown = new QLineEdit(Hotel);
        lineEditTown->setObjectName("lineEditTown");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEditTown);

        label_21 = new QLabel(Hotel);
        label_21->setObjectName("label_21");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_21);

        lineEditZimmertyp = new QLineEdit(Hotel);
        lineEditZimmertyp->setObjectName("lineEditZimmertyp");

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEditZimmertyp);

        tabWidget->addTab(Hotel, QString());
        Car = new QWidget();
        Car->setObjectName("Car");
        formLayout_5 = new QFormLayout(Car);
        formLayout_5->setObjectName("formLayout_5");
        Von_5 = new QLabel(Car);
        Von_5->setObjectName("Von_5");

        formLayout_5->setWidget(0, QFormLayout::LabelRole, Von_5);

        lineEditPickup = new QLineEdit(Car);
        lineEditPickup->setObjectName("lineEditPickup");

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineEditPickup);

        Bis_5 = new QLabel(Car);
        Bis_5->setObjectName("Bis_5");

        formLayout_5->setWidget(1, QFormLayout::LabelRole, Bis_5);

        lineEditReturn = new QLineEdit(Car);
        lineEditReturn->setObjectName("lineEditReturn");

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineEditReturn);

        label_23 = new QLabel(Car);
        label_23->setObjectName("label_23");

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_23);

        lineEditCartyp = new QLineEdit(Car);
        lineEditCartyp->setObjectName("lineEditCartyp");

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lineEditCartyp);

        label = new QLabel(Car);
        label->setObjectName("label");

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label);

        lineEditComany = new QLineEdit(Car);
        lineEditComany->setObjectName("lineEditComany");

        formLayout_5->setWidget(3, QFormLayout::FieldRole, lineEditComany);

        tabWidget->addTab(Car, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(BuchungsFenster);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BuchungsFenster);
    } // setupUi

    void retranslateUi(QWidget *BuchungsFenster)
    {
        BuchungsFenster->setWindowTitle(QCoreApplication::translate("BuchungsFenster", "Form", nullptr));
        label_10->setText(QCoreApplication::translate("BuchungsFenster", "ID", nullptr));
        label_6->setText(QCoreApplication::translate("BuchungsFenster", "Von", nullptr));
        dateEditVon->setDisplayFormat(QCoreApplication::translate("BuchungsFenster", "dd/MMMM/yyyy", nullptr));
        label_5->setText(QCoreApplication::translate("BuchungsFenster", "Bis", nullptr));
        dateEdit_2->setDisplayFormat(QCoreApplication::translate("BuchungsFenster", "dd/MMMM/yyyy", nullptr));
        label_8->setText(QCoreApplication::translate("BuchungsFenster", "Preis", nullptr));
        Von_2->setText(QCoreApplication::translate("BuchungsFenster", "Von", nullptr));
        label_7->setText(QCoreApplication::translate("BuchungsFenster", "Abfahrt", nullptr));
        timeEditAbfahrt->setDisplayFormat(QCoreApplication::translate("BuchungsFenster", "hh:mm AP", nullptr));
        Bis_2->setText(QCoreApplication::translate("BuchungsFenster", "Nach", nullptr));
        label_11->setText(QCoreApplication::translate("BuchungsFenster", "Ankunft", nullptr));
        label_3->setText(QCoreApplication::translate("BuchungsFenster", "Zugklasse", nullptr));
        label_9->setText(QCoreApplication::translate("BuchungsFenster", "\303\234ber", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetZ->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BuchungsFenster", "1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Zug), QCoreApplication::translate("BuchungsFenster", "Zug", nullptr));
        Von_3->setText(QCoreApplication::translate("BuchungsFenster", "From Dest", nullptr));
        label_12->setText(QCoreApplication::translate("BuchungsFenster", "from Dest(N)", nullptr));
        Bis_3->setText(QCoreApplication::translate("BuchungsFenster", "To Dest", nullptr));
        label_13->setText(QCoreApplication::translate("BuchungsFenster", "To Dest(N)", nullptr));
        label_4->setText(QCoreApplication::translate("BuchungsFenster", "KLasse", nullptr));
        label_2->setText(QCoreApplication::translate("BuchungsFenster", "Airline", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Flug), QCoreApplication::translate("BuchungsFenster", "Flug", nullptr));
        Von_4->setText(QCoreApplication::translate("BuchungsFenster", "Hotel", nullptr));
        Bis_4->setText(QCoreApplication::translate("BuchungsFenster", "Town", nullptr));
        label_21->setText(QCoreApplication::translate("BuchungsFenster", "Zimmertyp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Hotel), QCoreApplication::translate("BuchungsFenster", "Hotel", nullptr));
        Von_5->setText(QCoreApplication::translate("BuchungsFenster", "Pickup Loc", nullptr));
        Bis_5->setText(QCoreApplication::translate("BuchungsFenster", "Return Loc", nullptr));
        label_23->setText(QCoreApplication::translate("BuchungsFenster", "Cartyp", nullptr));
        label->setText(QCoreApplication::translate("BuchungsFenster", "Company", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Car), QCoreApplication::translate("BuchungsFenster", "Car", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuchungsFenster: public Ui_BuchungsFenster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCHUNGSFENSTER_H
