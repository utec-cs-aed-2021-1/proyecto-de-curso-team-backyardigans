//
// Created by LENOVO on 3/07/2021.
//

#ifndef GRAPHS_PRIORITYQUEUE_H

#define GRAPHS_PRIORITYQUEUE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <typename T>
class Heap
{
private:
    T *elements;
    int capacity;
    int n;
    //pair <T,string> p;

public:
    Heap(T *elements, int n) : elements(elements), n(n)
    {
        this->capacity=n;
        for(int i=(n/2) -1;i>=0; --i){
            heapify_down(i);
        }

    }

    Heap(int capacity) : capacity(capacity){
        elements = new T[capacity];
        n=0;

    }

    ~Heap(){
        delete [] elements;
    }

    void buildFromArray(T *arr, int m){
        elements=arr;
        n=m;
        capacity=m;
        for(int i=(n/2) -1;i>=0; --i){
            heapify_down(i);
        }
    }

    int size()
    {
        return n;
    }

    bool is_empty()
    {
        if(n==0) return true;
        return false;
    }

    void push(T value)
    {
        if(n==capacity){


            T* e2 = new int[capacity*2];
            for(int i=0;i<n;i++){
                e2[i]=elements[i];
            }
            delete[] elements;
            elements = e2;
            capacity = capacity*2;
        }

        elements[n]= value;
        heapify_up(n);
        n = n+1 ;
        cout<<value<<endl;



    }

    T pop()
    {
        T temp=elements[0];
        elements[0]=elements[n-1];
        elements[n-1]=temp;
        elements[n-1]= T(NULL);
        heapify_down(0);
        n = n-1 ;
        return temp;

    }

    T top()
    {
        for(int i=0;i<n; i++){
            cout<<elements[i]<<",";
        }
        cout<<endl;
        return elements[0];

    }

    vector<T> extractTheTopK(int k){
        vector<T> v;
        for(int i=0; i<k;i++){
            T temp=top();
            v.push_back(temp);
            pop();
        }
        return v;
    }

    static void sortAsc(T* arr, int m){


        Heap <T>* H1 = new Heap<T>(arr,m, Heap<T>::MAX_HEAP);
        for(int i=0; i<m;i++){
            arr[m-1-i]= H1->pop();
        }

    }

    static void sortDesc(T* arr, int m){
        Heap<T>*H2 = new Heap<T>(arr,m, Heap<T>::MIN_HEAP);
        //for(int i=0; i<m;i++){
        //  arr[m-1-i]= H2->pop();
        //  }/*
        H2->buildFromArray(arr, m);
        cout<<"inicio1"<<endl;
        T min=arr[0];
        while(min==arr[0]){
            T temp=arr[0];

            for(int i=0;i<m;i++) {
                arr[i] = arr[i + 1];
            }
            arr[m]=temp;
        }
        cout<<"des"<<endl;
        for(int i=0;i<m;i++){
            cout<<arr[i]<<",";
        }

    }

private:
    int Parent(int i)
    {
        return (i - 1) / 2;
    }

    int Left(int i)
    {
        return (2 * i + 1);
    }

    int Right(int i)
    {
        return (2 * i + 2);
    }

    void heapify_down(int i)
    {
        if(type==0){
            T imax;
            bool val=true;
            T c_r = Right(i);
            T c_l = Left(i);
            if(c_r >= size()) imax=c_l;
            else if(elements[c_r]> elements[c_l]) imax= c_r;
            else imax=c_l;

            if(Left(i)<size()){
                val=true;
            }
            else{
                val=false;
            }

            if(val==false)return;
            if(elements[i]>=elements[imax])return;

            T t=elements[i];
            elements[i]= elements[imax];
            elements[imax]=t;
            heapify_down(imax);
        }
        else{
            T imin;
            bool val=true;
            T c_r = Right(i);
            T c_l = Left(i);
            if(c_r >= size()) imin=c_l;
            else if(elements[c_r]< elements[c_l]) imin= c_r;
            else imin=c_l;

            if(Left(i)<size()){
                val=true;
            }
            else{
                val=false;
            }

            if(val==false)return;
            if(elements[i]<=elements[imin])return;

            T t=elements[i];
            elements[i]= elements[imin];
            elements[imin]=t;
            heapify_down(imin);
        }

    }

    void heapify_up(int i)
    {
        if(type==0){
            T Pi= Parent(i);
            if(i == 0) return;
            if(elements[i]<= elements[Pi]) return;

            T temp= elements[i];
            elements[i]= elements[Pi];
            elements[Pi]= temp;

            heapify_up(Pi);
        }
        else{
            T Pi= Parent(i);
            if(i == 0) return;
            if(elements[i]>= elements[Pi]) return;

            T temp= elements[i];
            elements[i]= elements[Pi];
            elements[Pi]= temp;

            heapify_up(Pi);
        }

    }


};
#endif //GRAPHS_PRIORITYQUEUE_H
