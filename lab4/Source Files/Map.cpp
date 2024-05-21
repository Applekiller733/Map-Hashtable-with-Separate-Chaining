#include "../Header Files/Map.h"
#include "../Header Files/MapIterator.h"

Map::Map() {
	//TODO - Implementation
    this->T = new Node*[this->m]();
}

Map::~Map() {
	//TODO - Implementation
    delete this->T;
}


void Map::rehash() {

    //Total complexity: O(m * alpha) and since alpha = n/m => O(n)
    //WC:-
    //BC:-

    Node** old_T = this->T;
    int old_m = this->m;

    this->p += 1;
    this->m = (1 << this->p) - 1;

    this->T = new Node*[this->m]();
    this->numelems = 0;

    for (int i = 0; i < old_m; i++){
        Node* currNode = old_T[i];
        while(currNode != nullptr){
            this->add(currNode->key, currNode->val);
            Node* nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        }
    }
    delete[] old_T;

}

TValue Map::add(TKey c, TValue v){

	//Total complexity: O(alpha)
    //WC: O(alpha)
    //BC: Th(1)

    if ( this->needs_rehash() ){
        this->rehash();
    }
    int pos = this->h(c);

    if ( pos < 0 )
        pos = 0 - pos;

    Node* currNode;
    if (this->search(c) != NULL_TVALUE){
        currNode = this->T[pos];
        while (currNode != nullptr && currNode->key != c)
            currNode = currNode->next;
        int old_val = currNode->val;
        currNode->val = v;
        return old_val;
    }
    else
    {
        auto newnode = new Node{c, v, this->T[pos]};
        this->T[pos] = newnode;
        this->numelems+=1;
        return NULL_TVALUE;
    }
}

TValue Map::search(TKey c) const{

    //Total complexity: O(alpha)
    //WC:O(alpha)
    //BC:Th(1)
    int pos = this->h(c);

    if ( pos < 0 )
        pos = 0 - pos;

    auto currnode = this->T[pos];
    while (currnode != nullptr && currnode->key != c){
        currnode = currnode->next;
    }
    if ( currnode != nullptr ){
        return currnode->val;
    }
    else
        return NULL_TVALUE;
}

TValue Map::remove(TKey c){
	//TODO - Implementation

    //Total complexity: O(alpha)
    //BC: Th(1)
    //WC: O(alpha)
    if ( this->search(c) == NULL_TVALUE)
	    return NULL_TVALUE;
    else{
        int pos = this->h(c);

        if (pos < 0 )
            pos = 0 - pos;

        Node* prev = nullptr;
        Node* currNode = this->T[pos];
        while(currNode != nullptr && currNode->key != c){
            prev = currNode;
            currNode = currNode->next;
        }
        if ( currNode->key == c ){
            if (this->T[pos] == currNode){
                this->T[pos] = currNode->next;
            }
            else
                prev->next = currNode->next;

            this->numelems-=1;
            int ret_val = currNode->val;
            delete currNode;
            return ret_val;
        }
    }
}


int Map::size() const {
	return this->numelems;
}

bool Map::isEmpty() const{
	if ( this->size() == 0 )
        return true;
    return false;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}



