#include "Trip.h"

Trip::Trip() {
	this->cost = 0;
	this->bill.open("Bill.txt");
	bill << "----------TRIP BILL----------\n";
	bill << "Name: " << this->getFirstName() << " " << this->getLastName() << endl;
	bill << "Card number: ";
	for (int i = 0; i < this->getCardNumber().size(); i++) {
		if (i > getCardNumber().size() - 4) {
			bill << getCardNumber().at(i);
		}
		else {
			bill << "X";
		}
	}
	bill << endl << endl;

}
Trip::~Trip() {
	bill << "TOTAL: $" << cost;
	bill.close();
}
void Trip::OneWay() {
	system("cls");
	cout << "ONEWAY FLIGHT: \n";
	bill << "ONEWAY FLIGHT\n";
	string city;
	this->printCities();
	cin.ignore();
	getline(cin, city);
	this->setSourceCity(city);
	system("cls");
	this->printCities();
	//cin.ignore();
	getline(cin, city);
	this->setDestinationCity(city);
	system("cls");
	cout << "How would you like to select your flight?\n 1) Based on price. \n 2) Based on distance. \n";
	char filter;
	do {
		cin.clear();
		cin >> filter;
	} while (filter != '1' && filter != '2');
	system("cls");

	if (filter == '1') {
		this->cost = (double)this->flightPathRecommenderBasedOnCost();
	}
	else {
		this->cost = (double)this->pathRecommendationBasedOnDistance() * 0.5;
	}
	bill << "*" << this->getSourceCity() << " -> " << this->getDestinationCity() << " Price: $" << cost << endl;
	cout << this->getSourceCity() << " -> " << this->getDestinationCity() << " Price: $" << cost << endl;
	
}
void Trip::RoundTrip() {
	system("cls");
	cout << "ROUND TRIP FLIGHT: \n";
	bill << "ROUND TRIP FLIGHT: \n";
	string city;
	this->printCities();
	cin.ignore();
	getline(cin, city);
	this->setSourceCity(city);
	system("cls");
	this->printCities();
	//cin.ignore();
	getline(cin, city);
	this->setDestinationCity(city);
	system("cls");
	cout << "How would you like to select your flight?\n 1) Based on price. \n 2) Based on distance. \n";
	char filter;
	do {
		cin.clear();
		cin >> filter;
	} while (filter != '1' && filter != '2');
	system("cls");
	
	if (filter == '1') {
		this->cost = (double)this->flightPathRecommenderBasedOnCost() * 2;
	}
	else {
		this->cost = ((double)this->pathRecommendationBasedOnDistance() * 0.5) * 2;
	}
	cout << this->getSourceCity() << "->" << this->getDestinationCity() << " Price: $" << cost / 2 << endl;
	cout << this->getDestinationCity() << "->" << this->getSourceCity() << " Price: $" << cost / 2 << endl;
	bill << this->getSourceCity() << "->" << this->getDestinationCity() << this->getSourceCity() << " Price: $" << cost / 2;
	
	

}
void Trip::TripPrompt() {
	cout << "Is this trip one way or round trip?\n1) One Way.\n2) Round Trip.\n";
	char tripType;
	do {
		cin >> tripType;
	} while (tripType != '1' && tripType != '2');
	if (tripType == '1') {
		this->OneWay();
	}
	else {
		this->RoundTrip();
	}

}