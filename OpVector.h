//
//  OpVector.h
//  GProject
//
//  Created by DFTL on 4/20/18.
//  Copyright © 2018 DFXTL. All rights reserved.
//

#ifndef OpVector_h
#define OpVector_h

//includes
//#include 

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
//uml
//vector template class type Type
template<class Type>
class OpVector{
private:
    
    int numElemSize;    //number of elements in vecList
    int maxSize;        //max number of elements that vecList can Hold
    Type *vecList;      //vecList
    void Reserve(); 
    
public:
    //Default constructor
    OpVector();
    
    //Non Default constructor for maxSize
    OpVector(int pmaxSize);
    
    //Non default constructor
    OpVector(int numElemSize, int maxSize, const Type & initial);
    
    //Copy constructor
    OpVector(const OpVector<Type> & copyOpVector);
    
    //destructor
    ~OpVector();
    
    typedef Type *traverse;               //pointer Type
    
    //Operators   0
    Type & operator[] (int index);        //get reference of indexed element (what element do we want to return)
    OpVector<Type> & operator = (const OpVector<Type> & rhs);
    //OpVector& operator += (const OpVector<Type> & rhs);
    
    //Setters
    void PushBack(const Type & value);       //add new element
                             //update maxsize = elemesize * 2
    //void Resize(int numElemSize);            //update new elements size
    
    //Getters
    int NumElemSize() const;                 //get number of elements
    int MaxSize() const;                     //get maxsize
    bool IsEmpty() const;                    //check if v is empty
    Type elemAt(int index)const;                  //return element at specific index
    void clear();                            //clear list
    
    traverse Begin();                        //get pointer to the first element
    traverse End();                          //get pointer to the last element
    Type & Front();                          //get a reference of first element
    Type & Back();                           //get a reference of last element
};//End class declarations

//******** OpVector Implementations ****************************************************************

//Default constructor
template<class Type>
OpVector<Type>::OpVector(){
    numElemSize = 0;
    maxSize = 5;      //by defaul max capacity is 4
    vecList = new Type[maxSize];
}

//Non Default Constructor for maxSize
template <class Type>
OpVector<Type>::OpVector(int pmaxSize){
    numElemSize = 0;
    maxSize = pmaxSize;
    vecList = new Type[maxSize];
}

//Non default constructor
template<class Type>
OpVector<Type>::OpVector(int numElemSize, int maxSize, const Type & initial):
numElemSize(numElemSize),
maxSize(maxSize){
    
    if(maxSize < 0){
        cout << "negative size vector..." << endl;
    }else{
        vecList = new Type[maxSize];
        for(int index = 0; index < numElemSize; index++){
            vecList[index] = initial;
        }
    }
}

//Destructor
template<class Type>
OpVector<Type>::~OpVector(){
    delete[] vecList;
}

//Copy constructor
template<class Type>
OpVector<Type>::OpVector(const OpVector<Type> & copyOpVector){
    numElemSize = copyOpVector.numElemSize;
    maxSize = copyOpVector.maxSize;
    vecList = new Type[copyOpVector.maxSize];
    for(int index = 0; index < copyOpVector.numElemSize; index++){
        vecList[index] = copyOpVector.vecList[index];
    }
}

//subscription
template <class Type>
Type& OpVector<Type>::operator[](int index){
    return vecList[index];
}

//clear();
template<class Type>
void OpVector<Type>::clear(){
    delete[] vecList;
    numElemSize = 0;
    maxSize = 5;
    vecList = new Type[maxSize];
}

template <class Type>
OpVector<Type> & OpVector<Type>::operator=(const OpVector<Type> & rhs){
    if(this!=&rhs){
        numElemSize = rhs.numElemSize;
        maxSize = rhs.maxSize;
        delete[] vecList;
        vecList = new Type[maxSize];
        for(int index = 0; index < rhs.numElemSize; index++){
            vecList[index] =rhs.vecList[index];
        }
    }
    return *this;
}

//template <class Type>
//OpVector<Type> & OpVector<Type>::operator+=(const OpVector<Type> & rhs){
//    this->PushBack(rhs);
//    return *this;
//}


//PushBack
template<class Type>
void OpVector<Type>::PushBack(const Type & addElement){
    if(numElemSize >= maxSize){
        Reserve();
        vecList[numElemSize++] = addElement; //Add element after reserve
    }else{
        vecList[numElemSize++] = addElement;
    }
}

//Reserve memory if maxvec is full
template<class Type>//needs work
void OpVector<Type>::Reserve(){
    maxSize = numElemSize * 2; //duplicate space
    Type *tempList = new Type[maxSize]; //we create a new list
    //now we need to copy all elements and delete old list
    for(int index = 0; index < numElemSize; index++){
        tempList[index] = vecList[index];   //copy all elements
    }
    delete[] vecList;     //dealloc
    vecList = tempList;   //assign with updated size
}

//**********
//Getters
//get numElemSize
template<class Type>
int OpVector<Type>::NumElemSize()const{
    return numElemSize;
}

//get maxSize
template<class Type>
int OpVector<Type>::MaxSize()const{
    return maxSize;
}

//IsEmpty
template<class Type>
bool OpVector<Type>::IsEmpty()const{
    return numElemSize == 0;
}

//Type elemAt(int index);                  //return element at specific index
template <class Type>
Type OpVector<Type>::elemAt(int index)const{
    return vecList[index];
}

//Begin returns address of first element in case..
template<class Type>
typename OpVector<Type>::traverse OpVector<Type>::Begin(){
    return vecList;
}

//End return address of last element
template<class Type>
typename OpVector<Type>::traverse OpVector<Type>::End(){
    return vecList + numElemSize -1;
}

//Front
template<class Type>
Type& OpVector<Type>::Front(){
    if(!(IsEmpty()))
        return vecList[0];
    throw *this; //add scpecific exception
}

//Back
template<class Type>
Type& OpVector<Type>::Back(){
    return vecList[NumElemSize() - 1];
}
//
#endif /* OpVector_h */
