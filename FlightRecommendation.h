#pragma once
#include "Payment.h"
#include <string>
#include <vector>

class adjListNode
{
public:
    //city will be demonstrated as number
    int destination; // if (0,3) is an edge, then 0 is the source and 3 is the destination
    int weight; //weight of each edge
    adjListNode* next;  //pointer to the next edge of an adjacency list

    //Constructor
    adjListNode(int destination, int weight) {
        this->destination = destination;
        this->weight = weight;
        this->next = NULL;
    }
};




//FlightRecommendation class dierctly gets inherited from Payment class
//Payment class gets inherited from Account class
//So,FlightRecommendation have access to all the public and protected members and methods of Account and Payment classes
class FlightRecommendation :public Payment
{
private:

    //it is for representing the cities
    vector <adjListNode*> adjList; //Just Declraing it now. will get the size later

    vector <string> city;
    string sourceCity;
    string destinationCity;
    //0 is no flight path selected, 1 if path selected on cost, 2 if path selected on distance

    //generate shortest path based on distance
    //int foundShortestPathBasedOnDistance(int source, int destination);
    //generate cheapest path based on distance
    int findBestFlight(int source, int destination);
    //will connect two cities in our map
    void addEdges(int source, int destination, int weight);
    //print the map
    void printAdjList();

public:
    //constructor
    FlightRecommendation();

    int getFlightPathFilter();

    //setter for destination city
    void setDestinationCity(string);

    //prints cities
    void printCities();

    //getter for destination city
    string getDestinationCity();

    //setter for source city
    void setSourceCity(string);

    //getter for source city
    string getSourceCity();


    //call foundShortestPathBasedOnDistance method with source and destination value 
    int pathRecommendationBasedOnDistance();

    int flightPathRecommenderBasedOnCost();


};



