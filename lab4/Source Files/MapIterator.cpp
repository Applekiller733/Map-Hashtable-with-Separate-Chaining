#include "../Header Files/Map.h"
#include "../Header Files/MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{

    this->currentPos = 0;
    while (this->currentPos < this->map.m && this->map.T[this->currentPos] == nullptr){
        this->currentPos += 1;
    }
    if ( this->currentPos < this->map.m){
        this->currNode = this->map.T[this->currentPos];
    }
    else
        this->currNode = nullptr;
    this->firstPos = this->currentPos;
}


void MapIterator::first() {
	//TODO - Implementation
    this->currentPos = this->firstPos;
    this->currNode = this->map.T[this->currentPos];
}


void MapIterator::next() {
	//Total complexity:
    //BC:
    //WC:
    if ( this->valid() ){
        if ( this->currNode->next != nullptr){
            this->currNode = this->currNode->next;
        }
        else
        {
            currentPos+=1;
            while ( this->currentPos < this->map.m && this->map.T[this->currentPos] == nullptr){
                this->currentPos += 1;
            }
            if ( this->currentPos < this->map.m )
            {
                this->currNode = this->map.T[this->currentPos];
            }
            else
                this->currNode = nullptr;
        }
    }
    else
        throw std::exception();
}

void MapIterator::previous() {
    if (!this->valid())
        throw std::exception();

    Node* prev = this->map.T[this->currentPos];
    if (prev != this->currNode) {
        while (prev->next != this->currNode) {
            prev = prev->next;
        }

    }
    else {
        this->currentPos--;
        while (this->currentPos >= 0 && this->map.T[currentPos] == nullptr)
            this->currentPos--;
        if (this->currentPos < 0) {
            this->currNode = nullptr;
            return;
        }

        prev = this->map.T[this->currentPos];
        while (prev->next != nullptr)
            prev = prev->next;
    }
    this->currNode = prev;
}


TElem MapIterator::getCurrent(){

    if (this->valid()) {
        TElem elem;
        elem.first = this->currNode->key;
        elem.second = this->currNode->val;
        return elem;
    }
    else
        throw std::exception();
}


bool MapIterator::valid() const {

    if ( this->currNode == nullptr || this->map.isEmpty() )
        return false;
    return true;
}



