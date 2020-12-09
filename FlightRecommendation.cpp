#include "FlightRecommendation.h"
#include <string>
#include <queue>
#include <vector>
#include <sstream> 
#include <list>
#include "MinHeapDjkAlgo.h"



//Constructor
FlightRecommendation::FlightRecommendation() {

     //since 10 cities
     adjList.resize(10, NULL);

     //All the possible departuare and arrival city
     this->city.push_back("Beijing");
     this->city.push_back("New York");
     this->city.push_back("London");
     this->city.push_back("Moscow");
     this->city.push_back("Dubai");
     this->city.push_back("Paris");
     this->city.push_back("Los Angeles");
     this->city.push_back("Toronto");
     this->city.push_back("Singapore");
     this->city.push_back("Tokyo");

     //since 10 cities
     adjList.resize(10, NULL);

     //0 will represent Beijing
     //1 will represent New York
     //2 will represent London
     //3 will represent Moscow
     //4 will represent Dubai
     //5 will represent Paris
     //6 will represent Los Angeles
     //7 will represent Toronto
     //8 will represent Singapore
     //9 will represent Tokyo

     //Distance between Beijing and New York 6844 miles
     //Distance between New York and London 3459 miles
     //Distance between London and Los Angeles 5448 miles
     //Distance between Los Angeles and paris 5669 miles
     //Distance between paris and Dubai 3259 miles
     //Distance between Dubai and Moscow 2700 miles
     //Distance between Beijing and Moscow 3618 miles
     //Distance between Moscow and Toronto 4560 miles
     //Distance between Toronto and Singapore 9324 miles
     //Distance between Singapore and Tokyo 5481 miles
     //Distance between Tokyo and Los Angeles 5479 miles
     //let's add these to our travel map 

     addEdges(0, 1, 6844);
     addEdges(1, 2, 3459);
     addEdges(2, 6, 5448);
     addEdges(6, 5, 5669);
     addEdges(5, 4, 3259);
     addEdges(4, 3, 2700);
     addEdges(0, 3, 3618);
     addEdges(3, 7, 4560);
     addEdges(7, 8, 9324);
     addEdges(8, 9, 5481);
     addEdges(9, 6, 5479);
     

     this->sourceCity = "";//initialy NULL
     this->destinationCity = "";//initially NULL
}

//setter for destination city
void FlightRecommendation::setDestinationCity(string userOpinion) {
     stringstream userOpinioonInString(userOpinion);
     int userOpinioonInInt;
     userOpinioonInString >> userOpinioonInInt;

     while (userOpinioonInInt < 0 || userOpinioonInInt > 9) {
          cout << "You have chosen invalid Destination City" << endl;
          cout << "Choose The Destination city Again: " << endl;
          for (int i = 0; i < this->city.size(); i++) {
               cout << i + 1 << " => " << this->city[i] << endl;
          }
          getline(cin, userOpinion);
          stringstream userOpinioonInString(userOpinion);
          userOpinioonInString >> userOpinioonInInt;
     }

     this->destinationCity = this->city[userOpinioonInInt ];
}

//getter for destination city
string FlightRecommendation::getDestinationCity() {
     return this->destinationCity;
}

void FlightRecommendation::printCities() {
     cout << "Choose The Source city: " << endl;
     for (int i = 0; i < this->city.size(); i++) {
          cout << i  << " => " << this->city[i] << endl;
     }
}

//setter for source city
void FlightRecommendation::setSourceCity(string userOpinion) {
     stringstream userOpinioonInString(userOpinion);
     int userOpinioonInInt;
     userOpinioonInString >> userOpinioonInInt;

     while (userOpinioonInInt < 0 || userOpinioonInInt > 9 || this->destinationCity == this->city[userOpinioonInInt ]) {
          cout << "You have chosen invalid Destination City" << endl;
          cout << "Choose The Destination city Again: " << endl;
          for (int i = 0; i < this->city.size(); i++) {
               cout << i + 1 << " => " << this->city[i] << endl;
          }
          getline(cin, userOpinion);
          stringstream userOpinioonInString(userOpinion);
          userOpinioonInString >> userOpinioonInInt;
     }

     this->sourceCity = this->city[userOpinioonInInt ];
}

//getter for source city
string FlightRecommendation::getSourceCity() {
     return this->sourceCity;
}

void FlightRecommendation::addEdges(int source, int destination, int weight)
{
    
     //let's add first edge
     adjListNode* newNodeOne = new adjListNode(destination, weight);
     newNodeOne->next = adjList[source];
     adjList[source] = newNodeOne;

     //Swapping two values
     int temp = destination;
     destination = source;
     source = temp;

     //since undirected so I have to add one more edge
     adjListNode* newNodeTwo = new adjListNode(destination, weight);
     newNodeTwo->next = adjList[source];
     adjList[source] = newNodeTwo;
}

//A method to print the graph as adjacency list
void FlightRecommendation::printAdjList()
{
     int i = 0;
     while (i < 10)
     {
          cout << "adj" << "[" << i << "]" << "----->";
          adjListNode* temp = adjList[i];
          while (temp) {
               cout << "(" << temp->destination << ", " << temp->weight << ")" << " ";
               temp = temp->next;
          }
          cout << endl;
          i++;
     }
}


// A method to find out the shortest path between two nodes(front source to destination)
//int FlightRecommendation::foundShortestPathBasedOnDistance(int source, int destination)
//{
//     //let's first initialize all of them
//     minHeapNodeAjkAlgo* heapNodeArr = new minHeapNodeAjkAlgo[10];
//     const int INF = INT_MAX;
//     for (int i = 0; i < 10; i++) {
//          heapNodeArr[i].cost = INF;
//          heapNodeArr[i].vertexNum = i;
//          heapNodeArr[i].parent = "";
//     }
//     //Initialization Done!
//
//     //Let's initialize the source cost to 0 since distance from source to sourece is 0
//     heapNodeArr[source].cost = 0;
//     heapNodeArr[source].parent = "";
//
//     //Let's declare the the min Heap that is going to be used to determine shortest path
//     MinHeapDjkAlgo myHeap(10);
//
//     //let's insert node to the min Heap (myHeap)
//     for (int i = 0; i < 10; i++) {
//          myHeap.insertNode(heapNodeArr[i]);
//     }
//
//     //let's declare a vector which will store each node and the minimum cost required to visit that node from the source
//     vector < minHeapNodeAjkAlgo> myVec;//Instead of vector I could have used set data structure
//
//     minHeapNodeAjkAlgo nextMin;
//     //let's get to the meat of the shortest path algorithm
//
//     cout << endl << endl;
//    
//
//     //so, let's show the shortest path building procedure when the total number of vertices is less than or equal to 10
//     if (true) {
//          cout << "Shortest Path Building Procedure based on Distance: " << endl << endl;
//     }
//
//     while (!myHeap.isEmpty())
//     {
//          minHeapNodeAjkAlgo front = myHeap.extractMin();
//          myVec.push_back(front);
//
//          //let's print the building procedure step by step
//
//          if (true) {
//               for (int i = 0; i < myVec.size(); i++) {
//                    int vertexNumber = 0;
//                    while (vertexNumber < 10) {
//                         if (myVec.at(i).vertexNum == vertexNumber) {
//                              if (myVec.at(i).parent == "")
//                              {
//                                   cout << vertexNumber << "   Total Distance: " << myVec.at(i).cost <<" miles"<< endl;
//                              }
//                              else {
//                                   cout << myVec.at(i).parent << "" << vertexNumber << "   Total Distance: " << myVec.at(i).cost <<" miles"<< endl;
//                              }
//                         }
//                         vertexNumber++;
//                    }
//               }
//               cout << endl;
//          }
//
//
//          //Now let's do the relaxing
//
//          int sourceTwo = front.vertexNum;
//          adjListNode* temp = adjList[sourceTwo];
//
//          while (temp)//if temp exists
//          {
//               if (myHeap.isAvailable(temp->destination))
//               {
//                    int index = myHeap.getIndex(temp->destination);
//                    if (myHeap.getCost(temp->destination) > (front.cost + temp->weight))
//                    {
//                         myHeap.decrease(index, (front.cost + temp->weight));
//                         //here i have gotta do something
//                         int i = front.vertexNum;
//                         string str = to_string(i);
//                         if (front.parent != "")//that is where i was in trouble
//                         {
//                              str = front.parent + "" + str;//That is where I was in trouble
//                         }
//                         str = str + "-->";
//                         int index = myHeap.getIndex(temp->destination);//
//                         myHeap.setParent(index, str);
//
//
//                    }
//               }
//               temp = temp->next;
//          }
//          delete temp;//taking care of the dynamic memory
//     }
//
//     cout << endl << endl;
//
//     cout << "Shortest Path and Shortest Path Distance Between " << this->city[source] << " and " << this->city[destination] << ": " << endl;
//
//
//     cout << endl;
//     int dist;
//     for (int i = 0; i < myVec.size(); i++) {
//          if (myVec.at(i).vertexNum == destination) {
//               if (myVec.at(i).parent == "") {
//                    cout << this->city[destination] << "   Total Distance: " << myVec.at(i).cost <<" miles"<< endl;
//               }
//               else {
//
//                    int startingVerTexIndex = 0;
//                    char c = (char)source;
//
//
//                    
//                    int lengthOfPathString = myVec.at(i).parent.length();
//                    while (true) {
//                         if (myVec.at(i).parent.at(lengthOfPathString - 1) - '0' == source) {
//                              break;
//                         }
//                         lengthOfPathString--;
//                        
//                    }
//
//                    startingVerTexIndex = lengthOfPathString-1;
//
//
//
//                    for (int j = startingVerTexIndex; j < myVec.at(i).parent.length(); j++) {
//                         if (isdigit(myVec.at(i).parent.at(j))) {
//                              char digit = myVec.at(i).parent.at(j);
//                              int x = digit - '0';
//                              cout << this->city[x];
//                         }
//                         else {
//                              cout << myVec.at(i).parent.at(j);
//                         }
//                    }
//
//                    cout << myVec.at(i).parent << "" << destination << "   Total Distance: " << myVec.at(i).cost << " miles" << endl;
//                    cout << this->city[destination] << "   Total Distance: " << myVec.at(i).cost <<" miles"<< endl;
//
//               }
//          }
//     }
//
//     cout << endl << endl;
//
//     // delete[]temp;
//}

int FlightRecommendation::pathRecommendationBasedOnDistance() {
     
     int source = -1;
     int destination = -1;

     for (int i = 0; i < this->city.size(); i++) {
          if (this->city[i] == this->sourceCity) {
               source = i;
          }
     }
     for (int i = 0; i < this->city.size(); i++) {
          if (this->city[i] == this->destinationCity) {
               destination = i;
          }
     }

     if (source != -1 && destination != -1) {
         return findBestFlight(source, destination);
          
     }


}


// A method to find out the shortest path between two nodes(front source to destination)
int FlightRecommendation::findBestFlight(int source, int destination)
{
     //let's first initialize all of them
     minHeapNodeAjkAlgo* heapNodeArr = new minHeapNodeAjkAlgo[10];
     const int INF = INT_MAX;
     for (int i = 0; i < 10; i++) {
          heapNodeArr[i].cost = INF;
          heapNodeArr[i].vertexNum = i;
          heapNodeArr[i].parent = "";
     }
     //Initialization Done!

     //Let's initialize the source cost to 0 since distance from source to sourece is 0
     heapNodeArr[source].cost = 0;
     heapNodeArr[source].parent = "";

     //Let's declare the the min Heap that is going to be used to determine shortest path
     MinHeapDjkAlgo myHeap(10);

     //let's insert node to the min Heap (myHeap)
     for (int i = 0; i < 10; i++) {
          myHeap.insertNode(heapNodeArr[i]);
     }

     //let's declare a vector which will store each node and the minimum cost required to visit that node from the source
     vector < minHeapNodeAjkAlgo> myVec;//Instead of vector I could have used set data structure

     minHeapNodeAjkAlgo nextMin;
     //let's get to the meat of the shortest path algorithm

     //cout << endl << endl;


     //so, let's show the shortest path building procedure when the total number of vertices is less than or equal to 10
     if (true) {
          //cout << "Shortest Path Building Procedure: " << endl << endl;
     }

     while (!myHeap.isEmpty())
     {
          minHeapNodeAjkAlgo front = myHeap.extractMin();
          myVec.push_back(front);

          //let's print the building procedure step by step

          //if (true) {
          //     for (int i = 0; i < myVec.size(); i++) {
          //          int vertexNumber = 0;
          //          while (vertexNumber < 10) {
          //               if (myVec.at(i).vertexNum == vertexNumber) {
          //                    if (myVec.at(i).parent == "")
          //                    {
          //                         cout << vertexNumber << "   Total Cost: " << myVec.at(i).cost << " Dollars" << endl;
          //                    }
          //                    else {
          //                         cout << myVec.at(i).parent << "" << vertexNumber << "   Total Cost: " << myVec.at(i).cost << " Dollars" << endl;
          //                    }
          //               }
          //               vertexNumber++;
          //          }
          //     }
          //     cout << endl;
          //}


          //Now let's do the relaxing

          int sourceTwo = front.vertexNum;
          adjListNode* temp = adjList[sourceTwo];

          while (temp)//if temp exists
          {
               if (myHeap.isAvailable(temp->destination))
               {
                    int index = myHeap.getIndex(temp->destination);
                    if (myHeap.getCost(temp->destination) > (front.cost + temp->weight))
                    {
                         myHeap.decrease(index, (front.cost + temp->weight));
                         //here i have gotta do something
                         int i = front.vertexNum;
                         string str = to_string(i);
                         if (front.parent != "")//that is where i was in trouble
                         {
                              str = front.parent + "" + str;//That is where I was in trouble
                         }
                         str = str + "-->";
                         int index = myHeap.getIndex(temp->destination);//
                         myHeap.setParent(index, str);


                    }
               }
               temp = temp->next;
          }
          delete temp;//taking care of the dynamic memory
     }

     //cout << endl << endl;

     //cout << "Chpeast cost path between " << this->sourceCity << " and " << this->destinationCity << ": " << endl;


     //cout << endl;
     int cost;
     for (int i = 0; i < myVec.size(); i++) {
          if (myVec.at(i).vertexNum == destination) {
               if (myVec.at(i).parent == "") {
                    cout << this->city[destination] << " Total Cost: " << myVec.at(i).cost << " Dollars" << endl;
               }
               else {

                    int startingVerTexIndex = 0;
                    char c = (char)source;



                    int lengthOfPathString = myVec.at(i).parent.length();
                    while (true) {
                         if (myVec.at(i).parent.at(lengthOfPathString - 1) - '0' == source) {
                              break;
                         }
                         lengthOfPathString--;

                    }

                    startingVerTexIndex = lengthOfPathString - 1;



                    for (int j = startingVerTexIndex; j < myVec.at(i).parent.length(); j++) {
                         if (isdigit(myVec.at(i).parent.at(j))) {
                              char digit = myVec.at(i).parent.at(j);
                              int x = digit - '0';
                              //cout << this->city[x];
                         }
                         else {
                              //cout << myVec.at(i).parent.at(j);
                         }
                    }

                    //cout << this->city[i] << " --> " << this->city[destination] << "   Total Distance: " << adjList[destination]->weight << " miles" << endl;
                    cost = i;
                    //cout << this->sourceCity << " --> " << this->destinationCity << "   Total Cost: " << myVec.at(i).cost << " Dollars" << endl;
                    //cout << endl;
               }
          }
     }
     return myVec.at(cost).cost;
     //cout << endl << endl;

     // delete[]temp;
}


int FlightRecommendation::flightPathRecommenderBasedOnCost() {
     //let's first set the to null
     adjList.clear();
     adjList.resize(10, NULL);

    //0 will represent Beijing
    //1 will represent New York
    //2 will represent London
    //3 will represent Moscow
    //4 will represent Dubai
    //5 will represent Paris
    //6 will represent Los Angeles
    //7 will represent Toronto
    //8 will represent Singapore
    //9 will represent Tokyo

    //third parameter is the price which is calculated by distance/2

     addEdges(0, 1, 3422);
     addEdges(1, 2, 1730);
     addEdges(2, 6, 2724);
     addEdges(6, 5, 2835);
     addEdges(5, 4, 1630);
     addEdges(4, 3, 1350);
     addEdges(0, 3, 1809);
     addEdges(3, 7, 2280);
     addEdges(7, 8, 4662);
     addEdges(8, 9, 2741);
     addEdges(9, 6, 2740);

     //printAdjList();

     int source = -1;
     int destination = -1;


     for (int i = 0; i < this->city.size(); i++) {
          if (this->city[i] == this->sourceCity) {
               source = i;
          }
          else if (this->city[i] == this->destinationCity) {
               destination = i;
          }
     }
     return findBestFlight(source, destination);
}
