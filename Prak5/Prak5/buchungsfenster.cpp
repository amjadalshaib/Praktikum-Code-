#include "buchungsfenster.h"
#include "flightbooking.h"
#include "ui_buchungsfenster.h"
#include "travelagency.h"  // Include the header file for TravelAgency
#include "trainticket.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "trainticket.h"
#include <QDate>
#include <QInputDialog>
#include <QFileDialog>
#include <vector>
#include <QString>
#include "travelagency.h"
#include <QLabel>
#include <QPalette>
#include "check.h"

BuchungsFenster::BuchungsFenster(shared_ptr<Booking> b, shared_ptr<TravelAgency> travelAgency, QWidget *parent, Qt::WindowFlags flag) :
    QWidget(parent, flag),
    ui(new Ui::BuchungsFenster),
    T(travelAgency),booking(b)  // Use the member T to reference the TravelAgency instance
{
    trav = new TravelAgencyUI(T,parent);
//connect(this, SIGNAL(dateChangedSignalvon(QDate)),trav, SLOT(check1()));
 //connect(this, SIGNAL(dateChangedSignalbis(QDate)),trav, SLOT(check1()));

    ui->setupUi(this);
    // Check if the booking is not null before accessing its properties
    QTableWidgetItem* headerItem = new QTableWidgetItem("Über");
    ui->tableWidgetZ->setHorizontalHeaderItem(0, headerItem);

    if (b) {

        if (shared_ptr<FlightBooking> flight = std::dynamic_pointer_cast<FlightBooking>(b)) {
            ui->tabWidget->setCurrentWidget(ui->Flug);
            ui->lineEditID->setText(flight->getId());
            ui->dateEditVon->setDate(flight->getFromDate());
            ui->dateEdit_2->setDate(flight->getToDate());
            ui->doubleSpinBoxPreis->setValue(flight->getPrice());
            ui->lineEditAbfahrtF->setText(flight->getFromDestination());
            ui->lineEditAnkunftF->setText(flight->getToDestination());
            ui->lineEditAirline->setText(flight->getAirline());
            ui->lineEditFlugKlasse->setText(flight->getReservationTyp());
            ui->lineEditFDestcode->setText(T->findmyMAp(flight->getFromDestination()));
            ui->lineEdittoDestCode->setText(T->findmyMAp(flight->getToDestination()));

        } else if (shared_ptr<HotelBooking> hotel = std::dynamic_pointer_cast<HotelBooking>(b)) {
            ui->tabWidget->setCurrentWidget(ui->Hotel);
            ui->lineEditID->setText(hotel->getId());
            ui->dateEditVon->setDate(hotel->getFromDate());
            ui->dateEdit_2->setDate(hotel->getToDate());
            ui->doubleSpinBoxPreis->setValue(hotel->getPrice());
            ui->lineEditHotel->setText(hotel->getHotel());
            ui->lineEditTown->setText(hotel->getTown());
            ui->lineEditZimmertyp->setText(hotel->getZimmerTyp());
        } else if (shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(b)) {
            ui->tabWidget->setCurrentWidget(ui->Car);
            ui->lineEditID->setText(rentalCar->getId());
            ui->dateEditVon->setDate(rentalCar->getFromDate());
            ui->dateEdit_2->setDate(rentalCar->getToDate());
            ui->doubleSpinBoxPreis->setValue(rentalCar->getPrice());
            ui->lineEditPickup->setText(rentalCar->getPickupLocation());
            ui->lineEditReturn->setText(rentalCar->getReturnLocation());
            ui->lineEditComany->setText(rentalCar->getCompany());
            ui->lineEditCartyp->setText(rentalCar->getFahrzeugtypen());
        } else if (shared_ptr<TrainTicket> train = std::dynamic_pointer_cast<TrainTicket>(b)) {
            ui->timeEditAbfahrt->setDisplayFormat("HH:mm");
            ui->timeEditAnkunft->setDisplayFormat("HH:mm");

            ui->tabWidget->setCurrentWidget(ui->Zug);
            ui->lineEditID->setText(train->getId());
            ui->dateEditVon->setDate(train->getFromDate());
            ui->dateEdit_2->setDate(train->getToDate());
            ui->doubleSpinBoxPreis->setValue(train->getPrice());
            ui->lineEditAbfahrtZ->setText(train->getFromDestination());
            ui->lineEditAnkunftZ->setText(train->getToDestination());
            ui->lineEditZugklasse->setText(train->getSittingKlasse());
            ui->timeEditAbfahrt->setTime(train->getQTimeDeparture());
            ui->timeEditAnkunft->setTime(train->getQTimeArrival());
            const vector<Connections*> belegungen = train->getConnectingStation();
            int numRows = belegungen.size();

            ui->tableWidgetZ->setRowCount(numRows);  // Set the number of rows in the table

            for (int row = 0; row < numRows; ++row) {
                QTableWidgetItem* item = new QTableWidgetItem(belegungen[row]->stationName);
                ui->tableWidgetZ->setItem(row, 0, item);
            }

        }
    } else {
        // Handle the case where the booking is null
        ui->lineEditID->setText("Invalid Booking");
    }
}

BuchungsFenster::~BuchungsFenster()
{
    delete ui;
}



void BuchungsFenster::on_lineEditAirline_textEdited(const QString &arg1) //F
{
    shared_ptr<FlightBooking> flightbooking = std::dynamic_pointer_cast<FlightBooking>(booking);
    flightbooking->setAirline(arg1);
}
void BuchungsFenster::on_lineEditAbfahrtF_textEdited(const QString &arg1)
{
    shared_ptr<FlightBooking> flightbooking = std::dynamic_pointer_cast<FlightBooking>(booking);
    if(T->findmyMAp(arg1)=="Not found"){
        QString text = "Ungültiger Iata-Code";
        // Set text color using style sheet
        ui->lineEditFDestcode->setStyleSheet("color: red;");
        ui->lineEditFDestcode->setText(text);
    }else{
        flightbooking->setFromDestination(arg1);
        ui->lineEditFDestcode->setStyleSheet("");
        ui->lineEditFDestcode->setText(T->findmyMAp(arg1));
    }
}
void BuchungsFenster::on_lineEditAnkunftF_textEdited(const QString &arg1)
{
    shared_ptr<FlightBooking> flightbooking = std::dynamic_pointer_cast<FlightBooking>(booking);
    if(T->findmyMAp(arg1)=="Not found"){
        QString text = "Ungültiger Iata-Code";
        // Set text color using style sheet
        ui->lineEdittoDestCode->setStyleSheet("color: red;");
        ui->lineEdittoDestCode->setText(text);
    }else{
        flightbooking->setToDestination(arg1);
        ui->lineEdittoDestCode->setStyleSheet("");
        ui->lineEdittoDestCode->setText(T->findmyMAp(arg1));
    }

}
void BuchungsFenster::on_lineEditFlugKlasse_textEdited(const QString &arg1)
{
    shared_ptr<FlightBooking> flightbooking = std::dynamic_pointer_cast<FlightBooking>(booking);
    flightbooking->setReservationTyp(arg1);
}


void BuchungsFenster::on_lineEditZugklasse_textEdited(const QString &arg1)//Z
{
    shared_ptr<TrainTicket> train =  std::dynamic_pointer_cast<TrainTicket>(booking);
    train->setSittingKlasse(arg1);
}


void BuchungsFenster::on_timeEditAbfahrt_timeChanged(const QTime &time)
{
    shared_ptr<TrainTicket> train =  std::dynamic_pointer_cast<TrainTicket>(booking);
    train->setQTimeDeparture(time);
}


void BuchungsFenster::on_timeEditAnkunft_timeChanged(const QTime &time)
{
    shared_ptr<TrainTicket> train =  std::dynamic_pointer_cast<TrainTicket>(booking);
    train->setQTimeArrival(time);
}

void BuchungsFenster::on_lineEditHotel_textEdited(const QString &arg1)//H
{
    shared_ptr<HotelBooking> hotel = std::dynamic_pointer_cast<HotelBooking>(booking);
    hotel->setHotel(arg1);
}
void BuchungsFenster::on_lineEditTown_textEdited(const QString &arg1)
{
    shared_ptr<HotelBooking> hotel = std::dynamic_pointer_cast<HotelBooking>(booking);
    hotel->setTown(arg1);
}
void BuchungsFenster::on_lineEditZimmertyp_textEdited(const QString &arg1)
{
    shared_ptr<HotelBooking> hotel = std::dynamic_pointer_cast<HotelBooking>(booking);
    hotel->setZimmerTyp(arg1);
}

void BuchungsFenster::on_lineEditPickup_textEdited(const QString &arg1) //C
{
    shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(booking);
    rentalCar->setPickupLocation(arg1);
}
void BuchungsFenster::on_lineEditReturn_textEdited(const QString &arg1)
{
    shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(booking);
    rentalCar->setReturnLocation(arg1);
}
void BuchungsFenster::on_lineEditCartyp_textEdited(const QString &arg1)
{
    shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(booking);
    rentalCar->setFahrzeugtypen(arg1);
}
void BuchungsFenster::on_lineEditComany_textEdited(const QString &arg1)
{
    shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(booking);
    rentalCar->setCompany(arg1);
}


void BuchungsFenster::on_dateEditVon_dateChanged(const QDate &date)//Booking
{
    if (shared_ptr<FlightBooking> flight = std::dynamic_pointer_cast<FlightBooking>(booking)) {
        flight->setFromDate(date);
    } else if (shared_ptr<HotelBooking> hotel = std::dynamic_pointer_cast<HotelBooking>(booking)) {
        hotel->setFromDate(date);

    } else if ( shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
        rentalCar->setFromDate(date);
    } else if (shared_ptr<TrainTicket> train = std::dynamic_pointer_cast<TrainTicket>(booking)) {
        train->setFromDate(date);
    }
    emit dateChangedSignalvon(date);
   connect(this, SIGNAL(dateChangedSignalvon(QDate)),trav, SLOT(check1()));
}
void BuchungsFenster::on_dateEdit_2_dateChanged(const QDate &date)
{
    booking->setToDate(date);
    emit dateChangedSignalbis(date);
   connect(this, SIGNAL(dateChangedSignalbis(QDate)),trav, SLOT(check1()));
}
void BuchungsFenster::on_doubleSpinBoxPreis_valueChanged(double arg1)
{
    booking->setPrice(arg1);
}



void BuchungsFenster::on_lineEditAbfahrtZ_textEdited(const QString &arg1)
{
    shared_ptr<TrainTicket> train = std::dynamic_pointer_cast<TrainTicket>(booking);
    train->setFromDestination(arg1);
}


void BuchungsFenster::on_lineEditAnkunftZ_textEdited(const QString &arg1)
{
    shared_ptr<TrainTicket> train = std::dynamic_pointer_cast<TrainTicket>(booking);
    train->setToDestination(arg1);
}




void BuchungsFenster::on_tableWidgetZ_itemChanged(QTableWidgetItem *item)
{
    shared_ptr<TrainTicket> train = std::dynamic_pointer_cast<TrainTicket>(booking);
    const vector<Connections*> belegungen = train->getConnectingStation();
    int numRows = belegungen.size();
    vector<Connections*> copy = belegungen;  // Initialize copy with the original values

    int row1 = item->row();

    for (int i = 0; i < numRows; i++) {
        if (row1 == i) {
            QString text = item->text();
            copy[i]->stationName = text;  // Update the specific row
        }
    }

    train->setConnectingStation(copy);
}

