#include <iostream>
#include <cstdlib>
using namespace std;

int ERROR = 2147483647;

// typedef unsigned long size_t; // unsingn long long
struct vector_t
{
    int *data; ///масив, указател към първия му елемент
    size_t size;
    size_t capacity;
} typedef Vector;

Vector *initVector();

/**
 * @brief Adds the number in the back of the vector
 *
 * @param v
 * @param number
 */
void pushBack(Vector *v, int number);

/**
 * @brief Resizes the vector
 *
 * @param v
 */
void resize(Vector *v);


/**
 * @brief Prints the vector in the specified format
 *
 */

// Vector's size:
// Vector's capacity:
// Vector's data:
void print(Vector *v);

/**
 * @brief Returns the element at the provided index
 *
 * @param v
 * @param index
 * @return int
 */
int at(Vector *v, int index);

/**
 * @brief Pops the last element of the vector
 *
 * @param v
 * @return int if successful, ERROR - if not
 */
int pop(Vector *v);

/**
 * @brief Frees the memory allocated by the vector
 *
 * @param v
 */
void destroy(Vector *v);

///int main()
///{
   /// struct vector_t *v = initVector();
   /// cout << v->size << endl;
   /// v->data[v->size] = 1;

   /// for (unsigned i = 0; i < v->size; i++)
    ///{
     ///   cout << v->data[i];
    ///}

   /// delete[] v->data; // *(v).data
   /// delete v;
   /// return 0;
///}

Vector *initVector()
{
    Vector *v = new struct vector_t;
    v->size = 0;
    v->capacity = 2;
    v->data = new int[v->capacity];
    return v;
}

void pushBack(Vector *v, int number){
    if(v->size == v->capacity){
        resize(v);
    }
    v->data[v->size]=number;
    v->size++;
}

void resize(Vector *v){
   size_t newCapacity = v->capacity*2;
   int *newData= new int[newCapacity];
   for(size_t i=0; i< v->size; ++i) {
        newData[i]=v->data[i];
   }
   delete [] v->data;
   v->data=newData;
   v->capacity = newCapacity;
}

void print(Vector *v){
    cout<< "Vector's size: "<< v->size<< endl;
    cout<< "Vector's capacity: "<< v->capacity<< endl;
    cout<< "Vector's data: [";
    for(unsigned i=0; i<v->size; i++){
        cout<< v->data[i];
        if(i<v->size-1){
            cout<< " ";
        }
    }
    cout<< "]"<< endl;
}

int at(Vector *v, int index){
    if(index<0 || index>=v->size){
        return ERROR;
    }
    else{
        return v->data[index];
    }
}

int pop(Vector *v){
    if(v->size==0){
        return ERROR;
    }
    v->size--;
    return v->data[v->size];
}

void destroy(Vector *v){
    delete [] v->data;
    delete v;
}
vector.cpp
Displaying vector.cpp.