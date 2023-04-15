#include "lib_hash.h"

HashTable::HashTable(int c){
  this->capacity = c;
  this->size = 0;
  this->t = new int[c];
  
  for(int i = 0; i < c; i++){
    t[i] = 0;
  }
}

bool HashTable::empty(){
	if (size == 0)
		return true;
	else
		return false;
}

bool HashTable::full(){
	if (size == capacity)
		return true;
	else
		return false;
}

int HashTable::hashFunction(int x){
  return x % capacity;
}

int HashTable::insert(int x){
  if(!full()){
    int hash = hashFunction(x);
    int i=0;
    while(t[(hash + i)%capacity] != 0 && t[(hash + i)%capacity] != -1){
      i++;
    }
    size++;
    t[(hash + i)%capacity] = x;
    return i;
  }
}

void HashTable::del(int x){
  if(!empty()){
    int hash = hashFunction(x);
    int i=0;
    while(t[(hash + i)%capacity] != 0 && i<capacity){
      if(t[(hash + i)%capacity] == x){
        t[(hash + i)%capacity] = -1;
        size--;
        break;
      } 
      i++;
    }
  }
}

int HashTable::search(int x){
  if(!empty()){
    int hash = hashFunction(x);
    int i=0;
    while(t[(hash + i)%capacity] != 0 && i<capacity){
      if(t[(hash + i)%capacity] == x){
        return i;
        //return x;
      }
      i++;
    }
  }
}