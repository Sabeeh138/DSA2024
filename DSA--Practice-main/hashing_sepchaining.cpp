#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Hashtable{
public:
    vector <list<int>> table;
    int bucketcount;

    int hashfunction(int key){
        return key % bucketcount;
    }

    Hashtable(int size){
        bucketcount = size;
        table.resize(bucketcount);
    }

    void insert(int key){
        int index = hashfunction(key);
        table[index].push_back(key);
    }

    void remove(int key){
        int index = hashfunction(key);
        table[index].remove(key);
    }

    bool search(int key){
        int index = hashfunction(key);
        for(int val : table[index]){
            if(val == key){
                return true;
            }
        }
        return false;
    }

    void display(){
        for (int i = 0; i < bucketcount; i++){
            for(int val : table[i]){
                cout<<val<<"->";
            }
            cout<<"NULL ptr"<<endl;
        }
    }
};

