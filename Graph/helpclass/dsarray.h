//
// Created by LENOVO on 3/07/2021.
//

#ifndef GRAPHS_DSARRAY_H
#define GRAPHS_DSARRAY_H
#include <vector>
using namespace std;

template <typename T>
class DisjoinSetArray
{
private:
    // define the structures
    T *data;
    int *parent;
    int *rank;
    int capacity;
    int size_;
    int sets_;
public:
    DisjoinSetArray() {};

    DisjoinSetArray(vector<T> data){
        int ind = 0;
        size_ = data.size();
        capacity = size_;
        this->data = new T[capacity];
        parent = new int[capacity];
        rank = new int[capacity];
        sets_ = size_;
        for (auto ite:data){
            this->data[ind] = data[ind];
        }
        MakeSet();
    };
    ~DisjoinSetArray() {
        delete data;
        data = nullptr;
        delete parent;
        parent = nullptr;
        delete rank;
        rank = nullptr;
    }
    // implement all functions
    void MakeSet(int x) ;
    //MakseSet all elements
    void MakeSet() ;
    //Find the root of x (with optimization)
    int Find(int x) ;
    //Union two sets represented by x and y (apply rank)
    void Union(int x, int y) ;

    //check whether there is a path between x and y
    bool isConnected(int x, int y) ;
    //total number of elements
    int size()  { return size_;};
    //number of sets
    int sets()  { return sets_;};
    //total number of elements that belong to the set of x
    int size(int x) ;
    //add the element to the set of x
    void add(T element, int x) ;
    //return all elements that belong to the set of x
    vector<T> getElementsSet(int x) ;

    void resize_plus();
};

template <typename T>
void DisjoinSetArray<T>::MakeSet(int x) {
    parent[x] = x;
    rank[x] = 0;
}

template <typename T>
void DisjoinSetArray<T>::MakeSet() {
    for (int i=0; i<size_; i++){
        MakeSet(i);
    }
}

template<typename T>
int DisjoinSetArray<T>::Find(int x) {
    int parent_ = parent[x];
    while (parent_ != parent[parent_]){
        parent_ = parent[parent_];
    }
    return parent_;
}

template<typename T>
void DisjoinSetArray<T>::Union(int x, int y) {
    sets_--;
    int xRoot =Find(x);
    int yRoot =Find(y);
    if (xRoot==yRoot) return;
    //Ya que no están en el
    //mismo conjunto,se unen.
    int xrank = rank[xRoot];
    int yrank = rank[yRoot];
    if (xrank<yrank) parent[xRoot] = yRoot;
    else if (xrank>yrank) parent[yRoot] = xRoot;
    else{
        parent[yRoot] =xRoot;
        rank[xRoot] = xrank+1;
    }
}

template<typename T>
bool DisjoinSetArray<T>::isConnected(int x, int y) {
    return  Find(x) == Find(y);
}

template<typename T>
vector<T> DisjoinSetArray<T>::getElementsSet(int x) {
    vector<T> r_vec;
    for (int i=0; i<size_;i++){
        if (Find(i)==Find(x)){
            r_vec.push_back(data[i]);
        }
    }
    return r_vec;
}

template<typename T>
int DisjoinSetArray<T>::size(int x) {
    int siz = 0;
    for (int i=0; i<size_;i++){
        if (Find(i)==Find(x)){
            siz++;
        }
    }
    return siz;
}

template<typename T>
void DisjoinSetArray<T>::resize_plus(){
    T *temp_c = new T[capacity*2];
    capacity = capacity*2;
    for (int i=0; i<size_; i++) temp_c[i] = data[i];
    delete [] data;
    data = temp_c;
    int *temp = new int[capacity*2];
    for (int i=0; i<size_; i++) temp[i] = parent[i];
    delete [] parent;
    parent = temp;
    for (int i=0; i<size_; i++) temp[i] = rank[i];
    delete [] rank;
    rank = temp;
}

template<typename T>
void DisjoinSetArray<T>::add(T element, int x) {
    if (size_ == capacity) resize_plus();
    data[size_] = element;
    MakeSet(size_);
    Union(x, size_);
    size_++;
}


#endif //GRAPHS_DSARRAY_H
