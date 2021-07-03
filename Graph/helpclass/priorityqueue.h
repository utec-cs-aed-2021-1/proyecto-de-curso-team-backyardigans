//
// Created by LENOVO on 3/07/2021.
//

#ifndef GRAPHS_PRIORITYQUEUE_H

#define GRAPHS_PRIORITYQUEUE_H
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stdexcept>

using namespace std;

template <typename T>
class priority_
{
private:
    pair <T,string>* pairs;
    int n_pairs;
    int capacity = 10;
    unordered_map<string , T> distance;

public:
    ~priority_(){
        delete [] pairs;
    }

    int size()
    {
        return n_pairs;
    }

    bool is_empty()
    {
        if(n_pairs==0) return true;
        return false;
    }

    void push(pair<T, string> vertex)
    {
        if(n_pairs==capacity){
            auto* pairs2 = new pair <T,string>[capacity*2];
            for(int i=0;i<n;i++){
                pairs2[i]=pairs[i];
            }
            delete[] pairs;
            pairs = pairs2;
            capacity = capacity*2;
        }
        pairs[n_pairs] = vertex;
        distance[vertex.second] = n_pairs;
        heapify_up(n_pairs);
        n_pairs = n_pairs+1;
    }

    void pop()
    {
        auto temp = pairs[0];
        pairs[0]=pairs[n_pairs-1];
        pairs[n_pairs-1]=temp;
        pairs[n_pairs-1]= NULL;
        heapify_down(0);
        n_pairs = n_pairs-1;
        distance.erase(temp.second);
    }

    pair <T,string> top(){
        return pairs[0];
    }

    bool find(string str){
        if (distance.find(str) == distance.end()) return false;
        return true;
    }

    pair<T,string>& operator[](string str){
        if (distance.find(str) == distance.end())
            return pairs[distance[str]];
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

    void heapify_down(int i, string str){
        auto child_r = Right(i);
        auto child_l = Left(i);

        if (size()-1 == child_l){
            if (pairs[i].first <= pairs[child_l].first) return;
            else{
                auto temp = pairs[i];
                pairs[i] = pairs[child_l];
                pairs[child_l] = temp;
                return;
            }
        }
        if (size()-1>=child_r){
            if (pairs[i].first <= pairs[child_l].first && pairs[i].first <= pairs[child_r].first) return;

            else{
                auto temp = pairs[i];
                if (pairs[child_l].first < pairs[child_r].first){
                    pairs[i] = pairs[child_l];
                    pairs[child_l] = temp;
                    distance[pairs[child_l].second] = child_l;
                    distance[pairs[i].second] = i;
                    heapify_down(child_l, str);
                }
                else{
                    pairs[i] = pairs[child_r];
                    pairs[child_r] = temp;
                    distance[pairs[child_r].second] = child_r;
                    distance[pairs[i].second] = i;
                    heapify_down(child_r, str);
                }
            }
        }
    }

    void heapify_up(int i, string str){
        auto parent = Parent(i);
        if (i == 0) return;

        if (pairs[i].first >= pairs[parent].first) return;

        auto temp = pairs[i];
        pairs[i] = pairs[parent];
        pairs[parent] = temp;
        distance[pairs[parent].second]=parent;
        distance[pairs[i].second]=i;
        heapify_up(parent, str);
    }
};
#endif //GRAPHS_PRIORITYQUEUE_H
