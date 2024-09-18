#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H

#include "qtablewidget.h"
#include "travelagency.h"
#include <QMainWindow>
#include "check.h"
QT_BEGIN_NAMESPACE
namespace Ui { class TravelAgencyUI; }
QT_END_NAMESPACE

class TravelAgencyUI : public QMainWindow
{
    Q_OBJECT

public:
    TravelAgencyUI(shared_ptr<TravelAgency> T, QWidget *parent = nullptr);
    ~TravelAgencyUI();
    void displayTravelInformation(shared_ptr<Customer> customer);
    void updateTextConten(QString atributr,QString Changedto);
private slots:
    void on_actionDatei_Anlegen_triggered();
    void on_actionSearch_triggered();
    void on_tableWidgetReisen_itemDoubleClicked(QTableWidgetItem *item);
   // void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_lineEditName_textChanged(const QString &arg1);
    void on_actionSpeichern_triggered();
    long getID();
public slots:
    void check1();
private:
    Ui::TravelAgencyUI *ui;
    shared_ptr<TravelAgency> T =nullptr;
      std::unique_ptr<Check> check;
};
#endif // TRAVELAGENCYUI_H
