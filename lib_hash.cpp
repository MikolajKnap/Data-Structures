#include "lib_hash.h"

HashTable::hashTable(int c){
  capacity = c;
  size = 0;
  t = new int[c];
  
  for(int i = 0; i < c; i++){
    t[i] = 0;
  }
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