#ifndef BUCHUNGSFENSTER_H
#define BUCHUNGSFENSTER_H
#include "booking.h"
#include "qtablewidget.h"
#include "travelagency.h"
#include <QWidget>
#include "travel.h"
#include "check.h"
#include "travelagencyui.h"
namespace Ui {
class BuchungsFenster;
}

class BuchungsFenster : public QWidget
{
    Q_OBJECT

public:
    explicit BuchungsFenster(shared_ptr<Booking> b, shared_ptr<TravelAgency> travelAgency, QWidget *parent = nullptr, Qt::WindowFlags flag = Qt::Window);
    ~BuchungsFenster();

private slots:
    void on_lineEditAirline_textEdited(const QString &arg1);
    void on_lineEditAbfahrtF_textEdited(const QString &arg1);
    void on_lineEditAnkunftF_textEdited(const QString &arg1);
    void on_lineEditFlugKlasse_textEdited(const QString &arg1);


    //  void on_lineEditAnkunftZ_textChanged(const QString &arg1);
    void on_lineEditZugklasse_textEdited(const QString &arg1);


    void on_lineEditHotel_textEdited(const QString &arg1);
    void on_lineEditTown_textEdited(const QString &arg1);
    void on_lineEditZimmertyp_textEdited(const QString &arg1);

    void on_lineEditPickup_textEdited(const QString &arg1);
    void on_lineEditReturn_textEdited(const QString &arg1);
    void on_lineEditCartyp_textEdited(const QString &arg1);
    void on_lineEditComany_textEdited(const QString &arg1);



    void on_dateEditVon_dateChanged(const QDate &date);
    void on_dateEdit_2_dateChanged(const QDate &date);
    void on_doubleSpinBoxPreis_valueChanged(double arg1);
    void on_timeEditAbfahrt_timeChanged(const QTime &time);
    void on_timeEditAnkunft_timeChanged(const QTime &time);
    void on_lineEditAbfahrtZ_textEdited(const QString &arg1);
    void on_lineEditAnkunftZ_textEdited(const QString &arg1);
    void on_tableWidgetZ_itemChanged(QTableWidgetItem *item);

signals:
    void dateChangedSignalvon(const QDate& date);
    void dateChangedSignalbis(const QDate& date);
private:
    Ui::BuchungsFenster *ui;
    shared_ptr<TravelAgency> T;
    shared_ptr<Booking> booking;
    TravelAgencyUI* trav;

};

#endif // BUCHUNGSFENSTER_H
