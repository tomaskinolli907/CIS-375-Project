#pragma once
#include "FlightRecommendation.h"
#include <fstream>
class Trip : public FlightRecommendation {
private:
	ofstream bill;
	double cost;
	string ReturnCity;
	void OneWay();
	void RoundTrip();
public:
	Trip();
	~Trip();
	void TripPrompt();
};