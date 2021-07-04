//
// Created by LENOVO on 3/07/2021.
//

#ifndef GRAPHS_DSARRAY_H
#define GRAPHS_DSARRAY_H
#include <vector>
using namespace std;


template <typename T>
class DisjoinSet{

private:
    int *rank;
    int *padre;
    int set;
    int tam;
    vector<T>data;
public:

    DisjoinSet(vector<T> data){
        rank=new int[tam];
        padre=new int[tam];
        tam = data.size();
        set=tam;
        this->data=data;
        MakeSet();
    }

    ~DisjoinSet()=default;

    void MakeSet(int x){
        padre[x]=x;
        rank[x]=0;
    }

    void MakeSet(){
        for(int i=0;i<tam;i++){
            MakeSet(i);
        }
    }

    int Find(int x){
        if(padre[x]==x)return x;
        return Find(padre[x]);
    }

    void Union(int x, int y){
        T xroot = Find(x);
        T yroot = Find(y);
        if (xroot==yroot) return ;
        if (rank[xroot]<rank[yroot]){
            padre[xroot]= yroot;
            set--;
        }
        else if (rank[xroot]>rank[yroot]){
            padre[yroot]= xroot;
            set--;
        }
        else{
            padre[yroot]=xroot;
            rank[xroot]= rank[xroot]+1;
            set--;
        }

    }

    int size(int x){
        int cx=0;
        for(int i=0;i<tam;i++){
            if(Find(i)==Find(x)){
                cx++;
            }
        }
        return cx;
    }




};


#endif //GRAPHS_DSARRAY_H
