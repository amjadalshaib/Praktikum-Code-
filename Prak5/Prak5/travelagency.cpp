#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "json.hpp"
#include "rentalcarreservation.h"
#include "trainticket.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QDate>
#include "json.hpp"
//QString Issue = "Wenn Sie die Datei bereits korrigiert haben, wählen Sie'Retry'. Wählen Sie 'Discard', um alle Buchungen zu löschenund 'Cancel', um die vorhandenen Buchungenstehenzulassen und diesen Dialog zu verlassen.";
using namespace std;
using json = nlohmann::json;
using namespace nlohmann;
const vector<shared_ptr<Booking>> &TravelAgency::getBookings() const
{
    return allBookings;
}

const vector<shared_ptr<Travel> > &TravelAgency::getAllTravels() const
{
    return allTravels;
}

void TravelAgency::setAllBookings(QDate from, QString id)
{
    shared_ptr<Booking> b = findBooking(id);
    if (b != nullptr) {
        b->setFromDate(from);
    }

}

vector<shared_ptr<Customer> > TravelAgency::getAllCustomer() const
{
    return allCustomer;
}

TravelAgency::TravelAgency()
    : flightBookingsCount(0), hotelBookingsCount(0), rentalCarBookingsCount(0), trainBookingsCount(0),
      totalFlightValue(0), totalHotelValue(0), totalRentalCarValue(0), totalTrainValue(0) {
}

TravelAgency::~TravelAgency()
{
    deleteVector();
}
void TravelAgency::readFile(QString fileName, QString &message) {


#include "json.hpp"
    using namespace nlohmann;
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        message = "Datei konnte nicht geoeffnet werden";
        return;
    }
    QByteArray fileData = file.readAll();
    file.close();


    std::string jsonData = fileData.toStdString();

    json data = json::parse(jsonData);

    int zeile{};
    bool Problem = false;
    for (const auto& JData : data) {
        zeile++;
        try{
            // Check if the Price attribute is a valid numeric value
            if (!JData["price"].is_number()) {
                throw std::invalid_argument("Price must be a valid numeric value.");
            }
            long customerID = JData["customerId"];
            std::string firstName1 = JData["customerFirstName"];
            std::string lastName1 = JData["customerLastName"];
            QString firstName = QString::fromStdString(firstName1);
            QString lastName = QString::fromStdString(lastName1);
            long travelID = JData["travelId"];

           shared_ptr<Customer> customer = findCustomer(customerID);

            if (customer == nullptr) {
                // Create a new customer if not found
                customer = make_shared<Customer>(customerID, lastName, firstName);

                allCustomer.push_back(customer);
            }

            // Check if a Travel with the given travelID already exists for the customer

            std::string type = JData.value("type", "");
            std::string id1 = JData.value("id", "");
            double price = JData.value("price", 0.0);
            std::string fromDate1 = JData.value("fromDate", "");
            std::string toDate1 = JData.value("toDate", "");

            QString id = QString::fromStdString(id1);
            QString fromDate2 = QString::fromStdString(fromDate1);
            QString toDate2 = QString::fromStdString(toDate1);
            QDate fromDate = QDate::fromString(fromDate2, "yyyyMMdd");
            QDate toDate = QDate::fromString(toDate2, "yyyyMMdd");
            shared_ptr<Travel> travel = findTravel(travelID);

            string predecessor1str = JData.value("predecessor1","");
             string predecessor2str = JData.value("predecessor2","");

            QString predecessor1 = QString::fromStdString(predecessor1str);
            QString predecessor2 = QString::fromStdString(predecessor2str);

            if (!JData["type"].is_string()) {
                throw std::invalid_argument("Type must be a valid string value.");
            }

            if (travel == nullptr ) {
                // If not, create a new Travel
                travel = make_shared<Travel>(travelID, customerID,id);
                customer->addTravel(travel);

            }
            allTravels.push_back(travel);
            // Now, add the booking to the appropriate customer and travel

            if (id1.empty() || fromDate1.empty() || toDate1.empty()) {
                throw std::invalid_argument("Empty attributes are not allowed.");
            }
            if (!JData["price"].is_number()) {
                throw std::invalid_argument("Price must be a valid numeric value.");
            }
            shared_ptr<Booking> newBooking = nullptr;
            bool ok;
            if (type == "Flight")
            {

                flightBookingsCount++;
                totalFlightValue += price;
                std::string fromDestination1 = JData.value("fromDest", "");
                std::string toDestination1 = JData.value("toDest", "");
                std::string airline1 = JData.value("airline", "");
                QString fromDestination = QString::fromStdString(fromDestination1);
                QString toDestination = QString::fromStdString(toDestination1);
                QString airline = QString::fromStdString(airline1);
                string reservationTyp1 = JData["bookingClass"];
                QString reservationTyp= QString::fromStdString(reservationTyp1);

                std::string fromDestLatitudeStr = JData.value("fromDestLatitude", "");
                QString fromDestLatitudeStr1 = QString::fromStdString(fromDestLatitudeStr);
                double fromDestLatitude = fromDestLatitudeStr1.toDouble(&ok);

                std::string fromDestLongitudeStr = JData.value("fromDestLongitude", "");
                QString fromDestLongitudeStr1 = QString::fromStdString(fromDestLongitudeStr);
                double fromDestLongitude = fromDestLongitudeStr1.toDouble(&ok);

                std::string toDestLatitudeStr = JData.value("toDestLatitude", "");
                QString toDestLatitudeStr1 = QString::fromStdString(toDestLatitudeStr);
                double toDestLatitude = toDestLatitudeStr1.toDouble(&ok);

                std::string toDestLongitudeStr = JData.value("toDestLongitude", "");
                 QString toDestLongitudeStr1 = QString::fromStdString(toDestLongitudeStr);
                double toDestLongitude = toDestLongitudeStr1.toDouble(&ok);

                if (type == "Flight" && (fromDestination1.length() != 3 || toDestination1.length() != 3)) {
                    throw std::invalid_argument("Airport codes must consist of three characters.");
                }
                newBooking = make_shared<FlightBooking>(travelID, id, price, fromDate, toDate,predecessor1,predecessor2, fromDestination, toDestination, airline,
                                                        reservationTyp, fromDestLatitude, fromDestLongitude, toDestLatitude, toDestLongitude);
                qDebug() << "fromDestLatitude: " << fromDestLatitude << " - fromDestLongitude: " << fromDestLongitude;
            } else if (type == "Hotel") {
                hotelBookingsCount++;
                totalHotelValue += price;
                std::string hotel1 = JData["hotel"];
                std::string town1 = JData["town"];
                string zimmerTyp1 =JData[ "roomType"];
                QString zimmerTyp = QString::fromStdString(zimmerTyp1);
                QString hotel = QString::fromStdString(hotel1);
                QString town = QString::fromStdString(town1);

                string hotelLatitudeStr = JData["hotelLatitude"];
                QString hotellat= QString::fromStdString(hotelLatitudeStr);
                double hotelLatitude = hotellat.toDouble(&ok);

                string hotelLongitudeStr = JData["hotelLongitude"];
                QString hotellong= QString::fromStdString(hotelLongitudeStr);
                double hotelLongitude = hotellong.toDouble(&ok);
                if (type == "Hotel" && (hotel1.empty() || town1.empty())) {
                    throw std::invalid_argument(&"Empty attributes are not allowed in 'hotel' or 'town' for Hotel booking."[zeile]);
                }
                newBooking= make_shared<HotelBooking>(travelID,id, price, fromDate, toDate,predecessor1,predecessor2, hotel, town, zimmerTyp,hotelLatitude,hotelLongitude);


            } else if (type == "RentalCar") {
                rentalCarBookingsCount++;
                totalRentalCarValue += price;
                std::string pickupLocation = JData["pickupLocation"];
                std::string returnLocation = JData["returnLocation"];
                std::string company = JData["company"];
                string Fahrzeugtypen1 = JData["vehicleClass"];
                QString Fahrzeugtypen= QString::fromStdString(Fahrzeugtypen1);
                QString pick = QString::fromStdString(pickupLocation);
                QString ret = QString::fromStdString(returnLocation);
                QString com = QString::fromStdString(company);

                string pickupLatitudestr = JData.value("pickupLatitude", "");
                QString pickupplat = QString::fromStdString(pickupLatitudestr);
                double pickupLatitude = pickupplat.toDouble(&ok);


                string pickupLongitudestr = JData.value("pickupLongitude", "");
                QString pickuplong = QString::fromStdString(pickupLongitudestr);
                double pickupLongitude = pickuplong.toDouble(&ok);

                string returnLatitudeStr = JData.value("returnLatitude", "");
                QString returnlat = QString::fromStdString(returnLatitudeStr);
                double returnLatitude = returnlat.toDouble(&ok);

                string returnLongitudeStr = JData.value("returnLongitude", "");
                QString returnlong = QString::fromStdString(returnLongitudeStr);
                double returnLongitude = returnlong.toDouble(&ok);
                if (type == "RentalCar" && (pickupLocation.empty() || returnLocation.empty() || company.empty())) {
                    throw std::invalid_argument("Empty attributes are not allowed in 'pickupLocation', 'returnLocation', or 'company' for Rental Car booking.");
                }
                newBooking= make_shared<RentalCarReservation>(travelID,id, price, fromDate, toDate,predecessor1,predecessor2, pick, ret, com, Fahrzeugtypen,
                                                    pickupLatitude,pickupLongitude,returnLatitude,returnLongitude);

            } else if (type == "Train") {
                trainBookingsCount++;
                totalTrainValue += price;
                std::string fromDestination1 = JData["fromStation"];
                std::string toDestination1 = JData["toStation"];
                std::string departureTime1 = JData["departureTime"];
                std::string arrivalTime1 = JData["arrivalTime"];

                string sittingKlasse1 = JData["ticketType"];
                QString sittingKlasse=QString::fromStdString(sittingKlasse1);
                QString fromDestination = QString::fromStdString(fromDestination1);
                QString toDestination = QString::fromStdString(toDestination1);
                QString departureTime = QString::fromStdString(departureTime1);
                QString arrivalTime = QString::fromStdString(arrivalTime1);
                double fromStationLatitude = JData.value("fromStationLatitude", 0.0);
                double fromStationLongitude = JData.value("fromStationLongitude", 0.0);
                double toStationLatitude = JData.value("toStationLatitude", 0.0);
                double toStationLongitude = JData.value("toStationLongitude", 0.0);
                json connectionsArray = JData["connectingStations"];

                // Vector to store Connections objects
                std::vector<Connections*> connectingStations;

                // Loop through the array and extract values
                for (const auto& connection : connectionsArray) {
                    double latitude = connection["latitude"];
                    double longitude = connection["longitude"];
                    std::string stationName1 = connection["stationName"];
                    QString stationName=QString::fromStdString(stationName1);
                    // Create a new Connections object and add it to the vector
                    connectingStations.push_back(new Connections(latitude, longitude, stationName));
                }
                if (type == "Train" && (fromDestination1.empty() || toDestination1.empty() || departureTime1.empty() || arrivalTime1.empty())) {
                    throw std::invalid_argument(&"Empty attributes are not allowed in 'fromStation', 'toStation', 'departureTime', or 'arrivalTime' for Train booking." [ zeile]);
                }
                newBooking= make_shared<TrainTicket>(travelID,id, price, fromDate, toDate,predecessor1,predecessor2, fromDestination, toDestination,
                                           departureTime, arrivalTime, connectingStations,sittingKlasse, fromStationLatitude,
                                           fromStationLongitude, toStationLatitude, toStationLongitude);
            }


            allBookings.push_back(newBooking);
            findTravel(travelID)->addBooking(newBooking);


        } catch (const std::exception& e) {
            message = QString("Error reading JSON file at Array %1: %2").arg(zeile).arg(e.what());
            Problem=true;
        }
        if(Problem){
            return;
        }
    }
    data.clear();

}

void TravelAgency::readISO()
{

    QFile file(":/read/iatacodes.json");

      if (!file.open(QIODevice::ReadOnly)) {
         qDebug()<< "File could not be opened";
          return;
      }

      QByteArray fileData = file.readAll();
      file.close();

      json data = json::parse(fileData.toStdString());

      for (const auto& entry : data) {


              QString name = QString::fromStdString(entry["name"]);
              QString iso_country= QString::fromStdString(entry["iso_country"]);
              QString municipality = QString::fromStdString(entry["municipality"]);
              QString iata_code = QString::fromStdString(entry["iata_code"]);

            shared_ptr<Airport> air = make_shared<Airport>(name,iso_country, municipality,iata_code );
              myMap.insert(pair<QString, shared_ptr<Airport>>(iata_code,air));

      }

}

QString TravelAgency::showBookingStatsJ() const {
    QString stats;
    int totalBookingsForCustomer1 = 0;
    int bookingsForTravel17 = 0;


    // Count bookings for travel with ID 17
    for(auto c: allCustomer){
        if(c->getId() == 1)
            totalBookingsForCustomer1 = c->getTravelList().size();
    }
    for(auto t: allTravels){
        if(t->getTravelID()==17)
            bookingsForTravel17 = t->getTravelBookings().size();
    }



    // Display the booking statistics
    stats += "Flight Bookings: " + QString::number(flightBookingsCount) + " in the total value of " + QString::number(totalFlightValue) + " Euro\n";
    stats += "Hotel Bookings: " + QString::number(hotelBookingsCount) + " in the total value of " + QString::number(totalHotelValue) + " Euro\n";
    stats += "Rental Car Bookings: " + QString::number(rentalCarBookingsCount) + " in the total value of " + QString::number(totalRentalCarValue) + " Euro\n";
    stats += "Train Bookings: " + QString::number(trainBookingsCount) + " in the total value of " + QString::number(totalTrainValue) + " Euro\n";
    stats += "Der Kunde mit der ID 1 hat "+ QString::number(totalBookingsForCustomer1) +" Reisen gebucht. Zur Reise mit der ID 17 gehören "+ QString::number(bookingsForTravel17) +" Buchungen.";
    return stats;
}

void TravelAgency::deleteVector(){

    allBookings.clear();
    allCustomer.clear();
    allTravels.clear();
}
void TravelAgency::resteData() {
    flightBookingsCount = 0;
    hotelBookingsCount = 0;
    rentalCarBookingsCount = 0;
    trainBookingsCount = 0;
    totalFlightValue = 0;
    totalHotelValue = 0;
    totalRentalCarValue = 0;
    totalTrainValue = 0;
    allBookings.clear();
    allTravels.clear();
    allCustomer.clear();
}

QString TravelAgency::printALL()
{
    QString s;
    for(auto b:allBookings){
        s+=b->showDetails() + '\n';

    }
    return s;
}

shared_ptr<Booking> TravelAgency::findBooking(QString id)
{

    for (auto b : allBookings) {
        if (b->getId() == id) {
            return b;
        }
    }
    return nullptr;
}
shared_ptr<Travel> TravelAgency::findBookint(QString id)
{

    for (auto b : allTravels) {
        if (b->getID() == id) {
            return b;
        }
    }
    return nullptr;
}

QString TravelAgency::findmyMAp(QString searchCode)
{

auto it = myMap.find(searchCode);

// Check if the key (IATA code) exists in the map
if (it != myMap.end()) {
    // The key exists, access the shared_ptr<Airport> and get the name
    QString airportName = (*it).second->getName();

    return airportName;
} else {
    // The key does not exist in the map
    qDebug() << "Airport with IATA code " << searchCode << " not found.";
    QString error ="Not found" ;
    return error;
}
}

shared_ptr<Travel> TravelAgency::findTravel(long id) const
{

    for (auto travel : allTravels) {
        if(travel->getTravelID() == id){
            return travel;
        }
    }
    return nullptr;
}

shared_ptr<Customer> TravelAgency::findCustomer(long id)
{
    for (auto customer : allCustomer) {
        if (customer->getId() == id) {
            return customer;
        }
    }
    return nullptr;
}


shared_ptr<Booking> TravelAgency::find(int id)
{
    int num = 0;
    for (auto b : allBookings)
    {
        if (num == id)
            return b;
        num++;
    }
    // Return nullptr if not found
    return nullptr;
}

using namespace nlohmann;
void TravelAgency::writeToFile(QString fileName, QString &message) {
    // Create a JSON array to hold all bookings
    nlohmann::json allBookingsJson = nlohmann::json::array();

    // Iterate through all travels and create JSON objects for each booking
    for (auto &booking : allBookings) {


        nlohmann::json bookingJson;

        // Retrieve customer information
        shared_ptr<Travel> t =  findTravel(booking->getTravelid());
        shared_ptr<Customer> customer = findCustomer(t->getCustomerID());

        // Add travel-specific attributes
        bookingJson["travelId"] = t->getTravelID();
        bookingJson["customerId"] = t->getCustomerID();
        bookingJson["customerFirstname"] = customer->getFirstName().toStdString();
        bookingJson["customerLastname"] = customer->getLastName().toStdString();

        // Find the corresponding booking

        // Add booking-specific attributes
        bookingJson["id"] = booking->getId().toStdString();
        bookingJson["price"] = booking->getPrice();
        bookingJson["fromDate"] = booking->getFromDate().toString("yyyyMMdd").toStdString();
        bookingJson["toDate"] = booking->getToDate().toString("yyyyMMdd").toStdString();

        // Add type-specific attributes
        if (auto flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking)) {
            bookingJson["type"] = "Flight";
            bookingJson["fromDest"] = flightBooking->getFromDestination().toStdString();
            bookingJson["toDest"] = flightBooking->getToDestination().toStdString();
            bookingJson["airline"] = flightBooking->getAirline().toStdString();
            bookingJson["bookingClass"] = flightBooking->getReservationTypCode(flightBooking->getReservationTyp()).toStdString();
            bookingJson["fromDestLatitude"] = flightBooking->getFromDestLatitude();
            bookingJson["fromDestLongitude"]  = flightBooking->getFromDestLongitude();
            bookingJson["toDestLatitude"]  = flightBooking->getToDestLatitude();
            bookingJson["toDestLongitude"]  = flightBooking->getToDestLongitude();
        } else if (auto hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {
            bookingJson["type"] = "Hotel";
            bookingJson["hotel"] = hotelBooking->getHotel().toStdString();
            bookingJson["town"] = hotelBooking->getTown().toStdString();
            bookingJson["roomType"] = hotelBooking->getZimmerTypCode(hotelBooking->getZimmerTyp()).toStdString();
            bookingJson["hotelLatitude"] = hotelBooking->getHotelLatitude();
            bookingJson["hotelLongitude"] = hotelBooking->getHotelLongitude();
        } else if (auto rentalCarBooking =std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
            bookingJson["type"] = "RentalCar";
            bookingJson["pickupLocation"] = rentalCarBooking->getPickupLocation().toStdString();
            bookingJson["returnLocation"] = rentalCarBooking->getReturnLocation().toStdString();
            bookingJson["company"] = rentalCarBooking->getCompany().toStdString();
            bookingJson["vehicleClass"] = rentalCarBooking->getFahrzeugtypen().toStdString();
            bookingJson["pickupLatitude"] = rentalCarBooking->getPickupLatitude();
            bookingJson["pickupLongitude"] = rentalCarBooking->getPickupLongitude();
            bookingJson["returnLatitude"] = rentalCarBooking->getReturnLatitude();
            bookingJson["returnLongitude"] = rentalCarBooking->getReturnLongitude();
        } else if (auto trainTicket = std::dynamic_pointer_cast<TrainTicket>(booking)) {
            bookingJson["type"] = "Train";
            bookingJson["fromStation"] = trainTicket->getFromDestination().toStdString();
            bookingJson["toStation"] = trainTicket->getToDestination().toStdString();
            bookingJson["departureTime"] = trainTicket->getDepartureTime().toStdString();
            bookingJson["arrivalTime"] = trainTicket->getArrivalTime().toStdString();
            bookingJson["ticketType"] = trainTicket->getSittingKlasseCode(trainTicket->getSittingKlasse()).toStdString();
            bookingJson["fromStationLatitude"] = trainTicket->getFromStationLatitude();
            bookingJson["fromStationLongitude"] = trainTicket->getFromStationLongitude();
            bookingJson["toStationLatitude"] = trainTicket->getToStationLatitude();
            bookingJson["toStationLongitude"] = trainTicket->getToStationLongitude();
            const std::vector<Connections*>& connectingStations = trainTicket->getConnectingStation();
            nlohmann::json connectionsArray = nlohmann::json::array();

            for (const auto& station : connectingStations) {
                // Create a JSON object for each connection
                nlohmann::json connectionJson;
                connectionJson["latitude"] = station->latitude;
                connectionJson["longitude"] = station->longitudel;
                connectionJson["stationName"] = station->stationName.toStdString();

                // Push the JSON object into the array
                connectionsArray.push_back(connectionJson);
            }

            // Assign the JSON array to the connectingStations field in the main JSON object
            bookingJson["connectingStations"] = connectionsArray;
        }
        // Add the booking JSON to the array
        allBookingsJson.push_back(bookingJson);

    }
    //deleteVector();
    // Write the JSON array to the file
    std::ofstream outputFile(fileName.toStdString(), std::ios::out | std::ios::trunc);
    /*  if (!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        message = "Datei konnte nicht geoeffnet werden";
        return;
    }
    */
    if (!outputFile.is_open()) {
        message = "Datei konnte nicht geoeffnet werden";
        return;
    }

    outputFile << std::setw(4) << allBookingsJson; // Pretty print with indentation
    outputFile.close();

    message = "Data written to " + fileName;
}

