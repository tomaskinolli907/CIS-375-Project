#pragma once
#include <string>
using namespace std;

//This node will be speacificaly used for min heap
class minHeapNodeAjkAlgo
{
public:
     int vertexNum;
     int cost;
     string parent = "";// i assume it will be a character. but letter i figured out iactually hsoul be a string
};

class MinHeapDjkAlgo
{
private:
     minHeapNodeAjkAlgo* arr;//A dynamic array of type minHeapNodeAjkAlgo
     int capacity;//Maximum possible size of the dynamic array
     int heapSize;//Current size of the dynamic array

public:
     MinHeapDjkAlgo(int capacity);//Constructor

     //A method to insert node
     void insertNode(minHeapNodeAjkAlgo k);

     //to heapify a subtree with the root at given index
     void minHeapify(int index);

     //Return the parent of a gievn node at index "index"
     int parent(int index) {
          return ((index - 1) / 2);
     }

     //To get the left child of a node at given index
     int left(int index) {
          return ((2 * index) + 1);
     }

     //To get the right child of a node at a given index
     int right(int index) {
          return ((2 * index) + 2);
     }

     //A method which will return the root (minimum) and it will delete the value as well
     minHeapNodeAjkAlgo extractMin();

     //Update the cost property of the node at given index
     void decrease(int index, int newCost);

     //A method which will swap two nodes in the dynamic array
     void Swap(minHeapNodeAjkAlgo& x, minHeapNodeAjkAlgo& y);

     //A method to check whether a min heap is empty or not
     bool isEmpty();

     //Given the vertex Number of node, return the index
     int getIndex(int vertexNum);

     //Given the vertex Number of a node, return the cost associated with the vertex
     int getCost(int vertexNum);

     //Given the vertex number property of a node, return whether that node exist or not in min Heap Array
     bool isAvailable(int vertexNum);

     void setParent(int index, string parent);

     ~MinHeapDjkAlgo() {
          delete[]arr;
     }
};

