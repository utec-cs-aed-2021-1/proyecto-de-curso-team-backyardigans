#ifndef GRAPHS_PRIORITYQUEUE_H
#define GRAPHS_PRIORITYQUEUE_H
#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
class priority_{
private:
    int capacity = 10;
    int n_pairs = 0;
    pair <T,string>* pairs = new pair <T,string>[capacity];
    unordered_map<string , T> position;
    int Parent(int i){
        return (i - 1) / 2;
    }

    int Left(int i){
        return (2 * i + 1);
    }

    int Right(int i){
        return (2 * i + 2);
    }

    void heapify_down(int i ){
        auto child_r = Right(i);
        auto child_l = Left(i);

        if (size()-1 < child_l) return;

        if (size()-1 == child_l){
            if (pairs[i].first <= pairs[child_l].first) return;
            else{
                auto temp = pairs[i];
                pairs[i] = pairs[child_l];
                pairs[child_l] = temp;
                position[pairs[child_l].second] = child_l;
                position[pairs[i].second] = i;
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
                    position[pairs[child_l].second] = child_l;
                    position[pairs[i].second] = i;
                    heapify_down(child_l);
                }
                else{
                    pairs[i] = pairs[child_r];
                    pairs[child_r] = temp;
                    position[pairs[child_r].second] = child_r;
                    position[pairs[i].second] = i;
                    heapify_down(child_r);
                }
            }
        }
    }

    void heapify_up(int i){
        auto parent = Parent(i);
        if (i == 0) return;

        if (pairs[i].first >= pairs[parent].first) return;

        auto temp = pairs[i];
        pairs[i] = pairs[parent];
        pairs[parent] = temp;
        position[pairs[parent].second]=parent;
        position[pairs[i].second]=i;
        heapify_up(parent);
    }
public:
    priority_(){};
    ~priority_(){
        delete [] pairs;
    }

    int size(){
        return n_pairs;
    }

    bool is_empty(){
        if (n_pairs==0) return true;
        return false;
    }

    void push(pair<T, string> vertex){
        if(n_pairs==capacity){
            auto* pairs2 = new pair <T,string>[capacity*2];
            for(int i=0;i<n_pairs;i++){
                pairs2[i]=pairs[i];
            }
            delete[] pairs;
            pairs = pairs2;
            capacity = capacity*2;
        }

        pairs[n_pairs] = vertex;
        position[vertex.second] = n_pairs;
        heapify_up(n_pairs);
        n_pairs = n_pairs+1;
    }
    void push(const string& vertex){
        if(n_pairs==capacity){
            auto* pairs2 = new pair <T,string>[capacity*2];
            for(int i=0;i<n_pairs;i++){
                pairs2[i]=pairs[i];
            }
            delete[] pairs;
            pairs = pairs2;
            capacity = capacity*2;
        }
        pairs[n_pairs] = {(int)INFINITY, vertex};
        position[vertex] = n_pairs;
        heapify_up(n_pairs);
        n_pairs = n_pairs+1;
    }

    void pop(){
        position.erase(pairs[0].second);
        auto temp = pairs[0];
        pairs[0]=pairs[n_pairs-1];
        n_pairs = n_pairs-1;
        position[pairs[0].second] = 0;
        heapify_down(0);
    }

    pair<T,string> top(){
        return pairs[0];
    }

    bool find(string str){
        if (position.find(str) == position.end()) return false;
        return true;
    }

    void actualizar(string str, T vertex){
        auto temp = pairs[position[str]];
        auto temp2 = pairs[n_pairs-1];
        pairs[position[str]] = pairs[n_pairs-1];
        n_pairs = n_pairs-1;
        position[temp2.second] = position[str];
        position.erase(str);
        heapify_down(position[temp2.second]);
        push({vertex, str});
    }

    pair<T,string>& operator[](string str){
        return pairs[position[str]];
    }




};
#endif //GRAPHS_PRIORITYQUEUE_H
