#include "travelagencyui.h"
#include "buchungsfenster.h"
#include "flightbooking.h"
#include "trainticket.h"
#include "rentalcarreservation.h"
#include "hotelbooking.h"

#include "qtablewidget.h"
#include <QWidget>
#include "ui_travelagencyui.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QStringListModel>
#include <QStringList>
#include "booking.h"
#include <QIcon>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDesktopServices>
#include <QUrl>
#include <memory>

#include "json.hpp"
//QString Issue = "Wenn Sie die Datei bereits korrigiert haben, wählen Sie'Retry'. Wählen Sie 'Discard', um alle Buchungen zu löschenund 'Cancel', um die vorhandenen Buchungenstehenzulassen und diesen Dialog zu verlassen.";

using namespace std;
using json = nlohmann::json;
using namespace nlohmann;
long Cid;
QString Issue = "Wenn Sie die Datei bereits korrigiert haben, wählen Sie'Retry'. Wählen Sie 'Discard', um alle Buchungen zu löschenund 'Cancel', um die vorhandenen Buchungenstehenzulassen und diesen Dialog zu verlassen.";
TravelAgencyUI::TravelAgencyUI(shared_ptr<TravelAgency> T,QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TravelAgencyUI)
    , T(T)
{
    ui->setupUi(this);
    ui->groupBox->setVisible(false);
    ui->groupBoxReise->setVisible(false);
    ui->tableWidgetReisen->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

     check = std::make_unique<Check>(T);
}

TravelAgencyUI::~TravelAgencyUI()
{
    delete ui;
}

void TravelAgencyUI::updateTextConten(QString atributr, QString Changedto)
{
    QString enteredText = ui->lineEditID->text();
    bool conversionOk;
    int id = enteredText.toInt(&conversionOk);
    if(atributr=="Name"){
        shared_ptr<Customer> c = T->findCustomer(id);
        QStringList nameParts = Changedto.split(" ", Qt::SkipEmptyParts);
        QString firstName, lastName;
        if(nameParts.size()>=2){
            firstName = nameParts[0];
            lastName = nameParts[1];
            c->setFirstName(firstName);
            c->setLastName(lastName);
        }
    }



}
void TravelAgencyUI::on_actionDatei_Anlegen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();

    T->resteData();
    T->deleteVector();  //Delete vector
    QString messages;
    T->readFile(fileName, messages);
    qDebug() << "File read successfully";
    if (messages.isEmpty()==true) {
        QString information = T->showBookingStatsJ();
        QMessageBox::information(this, "Datei erfolgreich eingelesen", information);


    } else {
        QMessageBox messageBox(this);
        messageBox.setText("Fehler beim Einlesen der Buchung");
        messageBox.setWindowTitle("Fehler beim Einlesen der Buchung");
        messageBox.setInformativeText(messages);
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setDetailedText(Issue);


        // Add standard buttons
        messageBox.addButton(QMessageBox::Retry);
        messageBox.addButton(QMessageBox::Discard);
        messageBox.addButton(QMessageBox::Cancel);
        // messageBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Retry | QMessageBox::Discard);
        messageBox.exec();

        // Check which button was clicked
        if (messageBox.result() == QMessageBox::Retry) {
            // Handle the Retry action
            // You can add your code here
            bool check=true;
            while(check){
                T->deleteVector();
                T->resteData();
                messages.clear();
                T->readFile(fileName, messages);
                if (messages.isEmpty()==true) {
                    QString information = T->showBookingStatsJ();
                    QMessageBox::information(this, "Datei erfolgreich eingelesen", information);
                    check=false;
                } else {
                    QMessageBox messageBox(this);
                    messageBox.setText("Fehler beim Einlesen der Buchung");
                    messageBox.setWindowTitle("Fehler beim Einlesen der Buchung");
                    messageBox.setInformativeText(messages);
                    messageBox.setIcon(QMessageBox::Information);
                    messageBox.setDetailedText(Issue);
                    // Add standard buttons
                    messageBox.addButton(QMessageBox::Retry);
                    messageBox.addButton(QMessageBox::Discard);
                    messageBox.addButton(QMessageBox::Cancel);
                    // messageBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Retry | QMessageBox::Discard);
                    messageBox.exec();
                    if (messageBox.result() == QMessageBox::Discard) {
                        // Handle the Discard action
                        // You can add your code here
                        T->deleteVector();
                        T->resteData();
                        return;
                    } else if (messageBox.result() == QMessageBox::Cancel) {
                        // Handle the Cancel action
                        // You can add your code here*/
                        T->deleteVector();
                        T->resteData();
                        return;
                    }}

            }
        } else if (messageBox.result() == QMessageBox::Discard) {
            // Handle the Discard action
            // You can add your code here
            T->deleteVector();
            T->resteData();
            return;
        } else if (messageBox.result() == QMessageBox::Cancel) {
            // Handle the Cancel action
            // You can add your code here*/
            T->deleteVector();
            T->resteData();
            return;
        }
    }
    T->readISO();
    QString messages1;
    bool check1=(*check)(messages1);
    qDebug() << "File read successfully";
   /* if (check1==false) {

        QMessageBox::warning(this, "Datei erfolgreich eingelesen", messages1);


    }*/
    QString messages2;
    check->checkNoMissingHotels(messages2);
    if (!messages2.isEmpty()) {

        QMessageBox::warning(this, "Datei erfolgreich eingelesen", messages2);


    }


}


void TravelAgencyUI::on_actionSearch_triggered()
{

    long customerID = QInputDialog::getInt(this,"Kund*innensuchen","ID");
    Cid=customerID;
    QString Name;
    shared_ptr<Customer> c = T->findCustomer(customerID);
    QTableWidgetItem* headerItem0 = new QTableWidgetItem("Reise-ID");
    ui->tableWidgetReisen->setHorizontalHeaderItem(0, headerItem0);
    QTableWidgetItem* headerItem1 = new QTableWidgetItem("Beginn der Reise");
    ui->tableWidgetReisen->setHorizontalHeaderItem(1, headerItem1);
    QTableWidgetItem* headerItem2 = new QTableWidgetItem("Ende der Reise");
    ui->tableWidgetReisen->setHorizontalHeaderItem(2, headerItem2);
    if(c !=nullptr){
        ui->groupBox->setVisible(true);
        ui->lineEditID->setText(QString::number(customerID));
        Name+= c->getFirstName()+ " ";
        Name+= c->getLastName();
        ui->lineEditName->setText(Name);
        ui->tableWidgetReisen->clear();  // Clear previous content
        ui->tableWidgetReisen->setColumnCount(3);
        QStringList headers;
        headers << "ID" << "Beginn der Reise" << "Ende der Reise";
        ui->tableWidgetReisen->setHorizontalHeaderLabels(headers);

        // Get the list of travels for the customer
        const vector<shared_ptr<Travel>> &travels = c->getTravelList();


        // Set the number of rows in the table
        ui->tableWidgetReisen->setRowCount(travels.size());

        int row = 0;

        for (auto t : travels) {
            // Use the travel ID instead of customer ID
            //   if(t->getCustomerID()==customerID){

            QDate start = t->getstartDatum();
            QDate end= t->getendDatum();

            QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(t->getTravelID()));
            QTableWidgetItem *startdate= new QTableWidgetItem(start.toString("dddd, dd/MMMM/yyyy"));
            QTableWidgetItem *enddate= new QTableWidgetItem(end.toString("dddd, dd/MMMM/yyyy"));
            ui->tableWidgetReisen->setItem(row, 0, idItem);
            ui->tableWidgetReisen->setItem(row,1,startdate);
            ui->tableWidgetReisen->setItem(row,2,enddate);
            row++;

            // }
        }


    } else {
        QMessageBox::warning(this, "ID nicht gefunden", "ID fehlt");
    }


}


void TravelAgencyUI::on_tableWidgetReisen_itemDoubleClicked(QTableWidgetItem *item)
{

    QString text = ui->lineEditID->text();
    bool ok;
    long Customer1 = text.toLong(&ok);
    shared_ptr<Customer> c =  T->findCustomer(Customer1);
    const vector<shared_ptr<Travel>> &travels = c->getTravelList();
    int rows = 0;
    int row1 = item->row();

    shared_ptr<Booking> book;


    for (auto& t3 : travels) {
        if(row1==rows){
            book = T->findBooking(t3->getID());
            if(auto flightBooking =std::dynamic_pointer_cast<FlightBooking>(book)){
                double fromDestLatitude = flightBooking->getFromDestLatitude();
                double fromDestLongitude = flightBooking->getFromDestLongitude() ;
                double toDestLatitude = flightBooking->getToDestLatitude();
                double toDestLongitude = flightBooking->getToDestLongitude();

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(fromDestLongitude) + "," + QString::number(fromDestLatitude) + "],[" + QString::number(toDestLongitude) + "," + QString::number(toDestLatitude) + "]]},\"properties\":{\"name\":\"LineBetweenFromAndTo\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(fromDestLongitude) + "," + QString::number(fromDestLatitude) + "]},\"properties\":{\"from\":\""+ T->findmyMAp(flightBooking->getFromDestination())+"\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(toDestLongitude) + "," + QString::number(toDestLatitude) + "]},\"properties\":{\"to\":\""+ T->findmyMAp(flightBooking->getToDestination()) +"\"}}";
                web += "]}";

                QDesktopServices::openUrl(QUrl(web));
            }
            else if(auto hotel = std::dynamic_pointer_cast<HotelBooking>(book)){
                double hotelLatitude = hotel->getHotelLatitude();
                double hotelLongitude = hotel->getHotelLongitude();

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(hotelLongitude) + "," + QString::number(hotelLatitude) + "]},\"properties\":{\"name\":\""+ hotel->getHotel()+"\"}}";
                web += "]}";
                QDesktopServices::openUrl(QUrl(web));
            }
            else if(auto car = std::dynamic_pointer_cast<RentalCarReservation>(book)){
                double pickupLatitude = car->getPickupLatitude();
                double pickupLongitude = car->getPickupLongitude();
                double returnLatitude = car->getReturnLatitude();
                double returnLongitude = car->getReturnLongitude();

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(pickupLongitude) + "," + QString::number(pickupLatitude) + "],[" + QString::number(returnLongitude) + "," + QString::number(returnLatitude) + "]]},\"properties\":{\"name\":\"LineBetweenPickupAndReturn\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(pickupLongitude) + "," + QString::number(pickupLatitude) + "]},\"properties\":{\"Pick\":\""+car->getPickupLocation()+"\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(returnLongitude) + "," + QString::number(returnLatitude) + "]},\"properties\":{\"name\":\""+car->getReturnLocation()+"\"}}";
                web += "]}";
                QDesktopServices::openUrl(QUrl(web));
            }
            else if(auto trainTicket = std::dynamic_pointer_cast<TrainTicket>(book) ){
                double fromStationLatitude = trainTicket->getFromStationLatitude();
                double fromStationLongitude = trainTicket->getFromStationLongitude();
                double toStationLatitude = trainTicket->getToStationLatitude();
                double toStationLongitude = trainTicket->getToStationLongitude();
                double templat= fromStationLatitude;
                double templong= fromStationLongitude;

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                for(const auto& connection : trainTicket->getConnectingStation()){
                    web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(templong) + "," + QString::number(templat) + "]"+",[" + QString::number(connection->getLongitudel()) + "," + QString::number(connection->getLatitude()) + "]"+ "]},\"properties\":{\"name\":\"LineBetweenFromAndToStation\"}},";
                    templong= connection->getLongitudel();
                    templat=connection->getLatitude();
                }
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(templong) + "," + QString::number(templat) + "]"+ ",[" + QString::number(toStationLongitude) + "," + QString::number(toStationLatitude) + "]"+ "]},\"properties\":{\"name\":\"LineBetweenFromAndToStation\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(fromStationLongitude) + "," + QString::number(fromStationLatitude) + "]},\"properties\":{\"From\":\"" + trainTicket->getFromDestination() + "\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(toStationLongitude) + "," + QString::number(toStationLatitude) + "]},\"properties\":{\"To\":\"" + trainTicket->getToDestination() + "\"}}";

                // Assuming the connecting stations are stored in the vector connectingStation
                for(const auto& connection : trainTicket->getConnectingStation()){
                    web += ",{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(connection->getLongitudel()) + "," + QString::number(connection->getLatitude()) + "]},\"properties\":{\"name\":\"" + connection->getStationName() + "\"}}";
                }

                web += "]}";
                QDesktopServices::openUrl(QUrl(web));

            }
        }

        rows++;
    }



    QString idText = ui->tableWidgetReisen->item(row1, 0)->text();
    bool conversionOk;
    int id = idText.toInt(&conversionOk);
    shared_ptr<Travel> t = T->findTravel(id);

    ui->tableWidget->setRowCount(t->getTravelBookings().size());

    int row = 0;

    for (auto t1 : t->getTravelBookings()) {
        // Use the travel ID instead of customer
        ui->groupBoxReise->setVisible(true);
        ui->lineEditReiseID->setText(QString::number(id));
        QDate start = t1->getFromDate();
        QDate end = t1->getToDate();
        QTableWidgetItem *IconItem = new QTableWidgetItem();
        QTableWidgetItem *startdate= new QTableWidgetItem(start.toString("dddd, dd/MMMM/yyyy"));
        QTableWidgetItem *enddate= new QTableWidgetItem(end.toString("dddd, dd/MMMM/yyyy"));
        QTableWidgetItem *preis= new QTableWidgetItem(QString::number(t1->getPrice()));


        if(std::dynamic_pointer_cast<FlightBooking>(t1) != nullptr){
            IconItem->setIcon(QIcon(":/pic/Flug.png"));
            ui->tableWidget->setItem(row,0, IconItem);

        }

        else if(std::dynamic_pointer_cast<HotelBooking>(t1) != nullptr){
            IconItem->setIcon(QIcon(":/pic/Hotel.png"));
            ui->tableWidget->setItem(row,0, IconItem);
        }
        else if(std::dynamic_pointer_cast<RentalCarReservation>(t1)!=nullptr){
            IconItem->setIcon(QIcon(":/pic/Car.jpeg"));
            ui->tableWidget->setItem(row, 0,  IconItem);
        }
        else if(std::dynamic_pointer_cast<TrainTicket>(t1) != nullptr){
            IconItem->setIcon(QIcon(":/pic/Zug.png"));
            ui->tableWidget->setItem(row, 0,  IconItem);

        }


        ui->tableWidget->setItem(row,1,startdate);
        ui->tableWidget->setItem(row,2,enddate);
        ui->tableWidget->setItem(row,3,preis);



        row++;


    }
}

/*void TravelAgencyUI::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{

    bool b = true;
    long id = item->text().toLong(&b);
    Travel* t = T->findTravel(id);

    Booking* b1 =T->findBooking(t->getID());
    QMessageBox::information(this, "Datei erfolgreich eingelesen", b1->showDetails());
    BuchungsFenster* buchungsFenster = new BuchungsFenster(b1,this,Qt::Window);
    buchungsFenster->setWindowModality(Qt::NonModal);
    buchungsFenster->show();


}*/


void TravelAgencyUI::on_tableWidget_cellDoubleClicked(int row, int column)
{

    QString text =  ui->lineEditReiseID->text();
    bool ok;
    long Customer1 = text.toLong(&ok);

    shared_ptr<Travel> tr =  T->findTravel(Customer1);
    int rows = 0;
    qDebug()<<"join";
    shared_ptr<Booking> book;
    for (auto& t3 : tr->getTravelBookings()) {
        if(row==rows){
            book = T->findBooking(t3->getId());
            if(auto flightBooking =std::dynamic_pointer_cast<FlightBooking>(book)){
                double fromDestLatitude = flightBooking->getFromDestLatitude();
                double fromDestLongitude = flightBooking->getFromDestLongitude() ;
                double toDestLatitude = flightBooking->getToDestLatitude();
                double toDestLongitude = flightBooking->getToDestLongitude();

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(fromDestLongitude) + "," + QString::number(fromDestLatitude) + "],[" + QString::number(toDestLongitude) + "," + QString::number(toDestLatitude) + "]]},\"properties\":{\"name\":\"LineBetweenFromAndTo\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(fromDestLongitude) + "," + QString::number(fromDestLatitude) + "]},\"properties\":{\"from\":\""+ T->findmyMAp(flightBooking->getFromDestination())+"\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(toDestLongitude) + "," + QString::number(toDestLatitude) + "]},\"properties\":{\"to\":\""+ T->findmyMAp(flightBooking->getToDestination()) +"\"}}";
                web += "]}";

                QDesktopServices::openUrl(QUrl(web));
            }
            else if(auto hotel = std::dynamic_pointer_cast<HotelBooking>(book)){
                double hotelLatitude = hotel->getHotelLatitude();
                double hotelLongitude = hotel->getHotelLongitude();

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(hotelLongitude) + "," + QString::number(hotelLatitude) + "]},\"properties\":{\"name\":\""+ hotel->getHotel()+"\"}}";
                web += "]}";
                QDesktopServices::openUrl(QUrl(web));
            }
            else if(auto car = std::dynamic_pointer_cast<RentalCarReservation>(book)){
                double pickupLatitude = car->getPickupLatitude();
                double pickupLongitude = car->getPickupLongitude();
                double returnLatitude = car->getReturnLatitude();
                double returnLongitude = car->getReturnLongitude();

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(pickupLongitude) + "," + QString::number(pickupLatitude) + "],[" + QString::number(returnLongitude) + "," + QString::number(returnLatitude) + "]]},\"properties\":{\"name\":\"LineBetweenPickupAndReturn\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(pickupLongitude) + "," + QString::number(pickupLatitude) + "]},\"properties\":{\"Pick\":\""+car->getPickupLocation()+"\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(returnLongitude) + "," + QString::number(returnLatitude) + "]},\"properties\":{\"name\":\""+car->getReturnLocation()+"\"}}";
                web += "]}";
                QDesktopServices::openUrl(QUrl(web));
            }
            else if(auto trainTicket = std::dynamic_pointer_cast<TrainTicket>(book)){
                double fromStationLatitude = trainTicket->getFromStationLatitude();
                double fromStationLongitude = trainTicket->getFromStationLongitude();
                double toStationLatitude = trainTicket->getToStationLatitude();
                double toStationLongitude = trainTicket->getToStationLongitude();
                double templat= fromStationLatitude;
                double templong= fromStationLongitude;

                QString web = "http://townsendjennings.com/geo/?geojson=";
                web += "{\"type\":\"FeatureCollection\",\"features\":[";
                for(const auto& connection : trainTicket->getConnectingStation()){
                      web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(templong) + "," + QString::number(templat) + "]"+",[" + QString::number(connection->getLongitudel()) + "," + QString::number(connection->getLatitude()) + "]"+ "]},\"properties\":{\"name\":\"LineBetweenFromAndToStation\"}},";
                   templong= connection->getLongitudel();
                    templat=connection->getLatitude();
                }
               web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\",\"coordinates\":[[" + QString::number(templong) + "," + QString::number(templat) + "]"+ ",[" + QString::number(toStationLongitude) + "," + QString::number(toStationLatitude) + "]"+ "]},\"properties\":{\"name\":\"LineBetweenFromAndToStation\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(fromStationLongitude) + "," + QString::number(fromStationLatitude) + "]},\"properties\":{\"From\":\"" + trainTicket->getFromDestination() + "\"}},";
                web += "{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(toStationLongitude) + "," + QString::number(toStationLatitude) + "]},\"properties\":{\"To\":\"" + trainTicket->getToDestination() + "\"}}";

                // Assuming the connecting stations are stored in the vector connectingStation
                for(const auto& connection : trainTicket->getConnectingStation()){
                    web += ",{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\",\"coordinates\":[" + QString::number(connection->getLongitudel()) + "," + QString::number(connection->getLatitude()) + "]},\"properties\":{\"name\":\"" + connection->getStationName() + "\"}}";
                }

                web += "]}";
                QDesktopServices::openUrl(QUrl(web));
            }
        }

        rows++;
    }

    QString enteredText = ui->lineEditReiseID->text();
    bool conversionOk;
    int id = enteredText.toInt(&conversionOk);
    shared_ptr<Travel> t = T->findTravel(id);
    int n=0;

    for(auto t1:t->getTravelBookings()){
        if(n==row){
            shared_ptr<Booking> b1 =T->findBooking(t1->getId());
            BuchungsFenster* buchungsFenster = new BuchungsFenster(b1,T,this,Qt::Window);
            buchungsFenster->setWindowModality(Qt::NonModal);
            buchungsFenster->show();
        }
        n++;
    }
}


void TravelAgencyUI::on_lineEditName_textChanged(const QString &arg1)
{
    updateTextConten("Name",arg1);
}



void TravelAgencyUI::on_actionSpeichern_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    QString messages;
    T->writeToFile(fileName,messages);
    if(messages.isEmpty()==false){
        QMessageBox::information(this, "Datei erfolgreich gesperichert", messages);
    }else{
        QMessageBox::warning(this, "Datei wurde nicht gespeichert", " ");
    }

}

long TravelAgencyUI::getID()
{
    QString text = ui->lineEditID->text();
    qDebug()<<text;
    qDebug()<<text;
    bool ok;
    long Customer1 = text.toLong(&ok);
    return Customer1;
}

void TravelAgencyUI::check1()
{
      qDebug()<<"Check1";
 QString messages1;

      qDebug()<<Cid;

    bool check2=check->Customerc(Cid,messages1);
   qDebug() << "File read successfully";
   //    bool check2=(*check)(messages1);
    if (check2==false) {

        QMessageBox::warning(this, "Datei erfolgreich eingelesen", messages1);


    }
}

