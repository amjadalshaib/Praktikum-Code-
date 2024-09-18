/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelAgencyUI
{
public:
    QAction *actionDatei_Anlegen;
    QAction *actionSearch;
    QAction *actionSpeichern;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditID;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidgetReisen;
    QGroupBox *groupBoxReise;
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditReiseID;
    QLabel *label_5;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TravelAgencyUI)
    {
        if (TravelAgencyUI->objectName().isEmpty())
            TravelAgencyUI->setObjectName("TravelAgencyUI");
        TravelAgencyUI->resize(949, 781);
        actionDatei_Anlegen = new QAction(TravelAgencyUI);
        actionDatei_Anlegen->setObjectName("actionDatei_Anlegen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/import_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDatei_Anlegen->setIcon(icon);
        actionSearch = new QAction(TravelAgencyUI);
        actionSearch->setObjectName("actionSearch");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch->setIcon(icon1);
        actionSpeichern = new QAction(TravelAgencyUI);
        actionSpeichern->setObjectName("actionSpeichern");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/pngtree-vector-save-icon-png-image_322173.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSpeichern->setIcon(icon2);
        centralwidget = new QWidget(TravelAgencyUI);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 611, 361));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditID = new QLineEdit(groupBox);
        lineEditID->setObjectName("lineEditID");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditID);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        tableWidgetReisen = new QTableWidget(groupBox);
        if (tableWidgetReisen->columnCount() < 3)
            tableWidgetReisen->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetReisen->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetReisen->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetReisen->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidgetReisen->setObjectName("tableWidgetReisen");
        tableWidgetReisen->setMinimumSize(QSize(0, 0));
        tableWidgetReisen->setLineWidth(0);
        tableWidgetReisen->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetReisen->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetReisen->setIconSize(QSize(10, 10));

        horizontalLayout->addWidget(tableWidgetReisen);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout);

        groupBoxReise = new QGroupBox(centralwidget);
        groupBoxReise->setObjectName("groupBoxReise");
        groupBoxReise->setGeometry(QRect(10, 370, 611, 311));
        layoutWidget = new QWidget(groupBoxReise);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 591, 261));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditReiseID = new QLineEdit(layoutWidget);
        lineEditReiseID->setObjectName("lineEditReiseID");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditReiseID);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        tableWidget = new QTableWidget(layoutWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, tableWidget);

        TravelAgencyUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TravelAgencyUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 949, 25));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        TravelAgencyUI->setMenuBar(menubar);
        statusbar = new QStatusBar(TravelAgencyUI);
        statusbar->setObjectName("statusbar");
        TravelAgencyUI->setStatusBar(statusbar);
        toolBar = new QToolBar(TravelAgencyUI);
        toolBar->setObjectName("toolBar");
        TravelAgencyUI->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuDatei->menuAction());
        menuDatei->addAction(actionDatei_Anlegen);
        menuDatei->addAction(actionSearch);
        menuDatei->addAction(actionSpeichern);
        toolBar->addAction(actionDatei_Anlegen);
        toolBar->addAction(actionSearch);
        toolBar->addAction(actionSpeichern);

        retranslateUi(TravelAgencyUI);

        QMetaObject::connectSlotsByName(TravelAgencyUI);
    } // setupUi

    void retranslateUi(QMainWindow *TravelAgencyUI)
    {
        TravelAgencyUI->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "TravelAgencyUI", nullptr));
        actionDatei_Anlegen->setText(QCoreApplication::translate("TravelAgencyUI", "Datei Anlegen", nullptr));
        actionSearch->setText(QCoreApplication::translate("TravelAgencyUI", "Search", nullptr));
        actionSpeichern->setText(QCoreApplication::translate("TravelAgencyUI", "Speichern", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TravelAgencyUI", "Kund*in", nullptr));
        label->setText(QCoreApplication::translate("TravelAgencyUI", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("TravelAgencyUI", "Name ", nullptr));
        label_4->setText(QCoreApplication::translate("TravelAgencyUI", "Reisen", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetReisen->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TravelAgencyUI", "Reise-ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetReisen->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TravelAgencyUI", "Beginn der Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetReisen->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TravelAgencyUI", "Ende der Reise", nullptr));
        groupBoxReise->setTitle(QCoreApplication::translate("TravelAgencyUI", "Reise", nullptr));
        label_3->setText(QCoreApplication::translate("TravelAgencyUI", "Reise-ID", nullptr));
        label_5->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungen", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungstyp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TravelAgencyUI", "Start", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TravelAgencyUI", "Ende", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TravelAgencyUI", "Preis", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("TravelAgencyUI", "Datei", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelAgencyUI: public Ui_TravelAgencyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H
