#pragma once
#include <utility>
#include <cmath>
//DO NOT INCLUDE MAPITERATOR


//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111)
class MapIterator;

struct Node{
    TKey key;
    TValue val;
    Node* next = nullptr;
};
/*
struct HashTable {
    int p = 4;
    int m = (1 << p) - 1; //15
    Node **T = new Node*;
    int h(TKey key) const{
        return key % m;
    };
    float alpha = 0.8;
    int numelems = 0;
    bool needs_rehash() const { //check if correct
        return ( alpha < ((numelems * 1.0) / (m * 1.0)));
    }
    ~HashTable(){
        for ( int i = 0; i < m; i ++){
            Node* currNode = T[i];
            while (currNode != nullptr){
                Node* next = currNode->next;
                delete currNode;
                currNode = next;
            }
        }
        delete[] T;
    }
};
*/
class Map {
	//DO NOT CHANGE THIS PART
	friend class MapIterator;

	private:
		//TODO - Representation

        int p = 4;
        int m = (1 << p) - 1; //15
        Node **T = new Node*;

        float alpha = 0.8;
        int numelems = 0;

        int h(TKey key) const{ return key % m; }; // Complexity: Th(1)

        bool needs_rehash() const { return ( alpha < ((numelems * 1.0) / (m * 1.0))); }

        //HashTable* ht;

        void rehash();
	public:

	// implicit constructor
	Map();

	// adds a pair (key,value) to the map
	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	//if the key does not exist, a new pair is added and the value null is returned
	TValue add(TKey c, TValue v);

	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	TValue search(TKey c) const;

	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
	TValue remove(TKey c);

	//returns the number of pairs (key,value) from the map
	int size() const;

	//checks whether the map is empty or not
	bool isEmpty() const;

	//returns an iterator for the map
	MapIterator iterator() const;

	// destructor
	~Map();

};



