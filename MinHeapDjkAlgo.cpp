#include "MinHeapDjkAlgo.h"
#include <iostream>
using namespace std;

//Constructor
MinHeapDjkAlgo::MinHeapDjkAlgo(int capacity)
{
     this->capacity = capacity;
     this->heapSize = 0;
     this->arr = new minHeapNodeAjkAlgo[this->capacity];
}

//A method to insert a node and that also maintain min heap property
void MinHeapDjkAlgo::insertNode(minHeapNodeAjkAlgo k)
{
     //Speacial Case Handling
     if (this->heapSize == this->capacity) {
          cout << "OVERFLOW" << endl;
          cout << endl;
     }

     this->heapSize++;
     int i = this->heapSize - 1;
     arr[i] = k;

     //Let's maintain min heap property
     while (i != 0 && arr[parent(i)].cost > arr[i].cost)
     {
          Swap(arr[i], arr[parent(i)]);
          i = parent(i);
     }
}

//Recursive Approach
//Assuming the subtree is already balanced
void MinHeapDjkAlgo::minHeapify(int index)
{
     int l = left(index);//Left ChildIndex
     int r = right(index);//Right ChildIndex
     int smallest = index;

     if (l < this->heapSize && arr[smallest].cost > arr[l].cost) {
          smallest = l;
     }
     if (r < this->heapSize && arr[smallest].cost > arr[r].cost) {
          smallest = r;
     }

     //Base Case
     if (smallest != index) {
          Swap(arr[index], arr[smallest]);
          minHeapify(smallest);//Recursive call
     }

}

//A method which will return the root node as well as will delete the root node
minHeapNodeAjkAlgo MinHeapDjkAlgo::extractMin()
{
     //Speacial Case
     if (this->heapSize == 0) {
          minHeapNodeAjkAlgo emptyNode;
          emptyNode.cost = NULL;
          emptyNode.vertexNum = NULL;
          return emptyNode;
     }

     //Another Speacial Case
     if (this->heapSize == 1) {
          this->heapSize--;
          return arr[0];
     }

     minHeapNodeAjkAlgo root = arr[0];//Savinf the minimum cost node
     arr[0] = arr[this->heapSize - 1];//Bringing the last node to first place
     this->heapSize--;//Reducing the size 
     minHeapify(0);//Maintaining min heap property
     return root;//Retturing the root node
}

//The new cost of the node at index "index"
//Also, It is assumed that the new node cost will always be less than current node cost
void MinHeapDjkAlgo::decrease(int index, int newCost)
{
     arr[index].cost = newCost;
     while (index != 0 && arr[index].cost < arr[parent(index)].cost)
     {
          swap(arr[index], arr[parent(index)]);
          index = parent(index);
     }
}

// A method that will swap two nodes
void MinHeapDjkAlgo::Swap(minHeapNodeAjkAlgo& x, minHeapNodeAjkAlgo& y)
{
     minHeapNodeAjkAlgo temp = x;
     x = y;
     y = temp;
}

//Will return true if min Heap is empty
bool MinHeapDjkAlgo::isEmpty()
{
     return (this->heapSize == 0);
}


//Return the index number of a particular node at 
int MinHeapDjkAlgo::getIndex(int vertexNum)
{
     for (int i = 0; i < this->heapSize; i++)
     {
          if (arr[i].vertexNum == vertexNum) {
               return i;//Oh! It's found. Let's return the index number
          }
     }
     return -1;//Will return -1 as an invalid index
}


//that will return the cost of particular node which has a given vertexNum
int MinHeapDjkAlgo::getCost(int vertexNum)
{
     for (int i = 0; i < this->heapSize; i++) {
          if (arr[i].vertexNum == vertexNum) {
               return arr[i].cost;
          }
     }
     return INT_MIN;//invalid
}


//A method that will return true if a partivular node exists! Otherwise will return Flase
bool MinHeapDjkAlgo::isAvailable(int vertexNum)
{
     for (int i = 0; i < this->heapSize; i++)
     {
          if (arr[i].vertexNum == vertexNum) {
               return true;//Yes. it's found
          }
     }
     return false;//It's not found!
}


//A method that updates the parent property of a particular node of type minHeapNodeAjkAlgo in the min heap array
void MinHeapDjkAlgo::setParent(int index, string parent)
{
     arr[index].parent = arr[index].parent + "" + parent;
}
