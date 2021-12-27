/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
#include <list>
#include <vector>
#include <iostream>
using namespace std;

class HashTable{
private:
  list<int> *table;
  int total_elements;

  // Hash function to calculate hash for a value:
  int getHash(int key){
    return key % total_elements;
  }

public:
  // Constructor to create a hash table with 'n' indices:
  HashTable(int n){
    total_elements = n;
    table = new list<int>[total_elements];
  }

  // Insert data in the hash table:
  void insertElement(int key){
    table[getHash(key)].push_back(key);
  }

  // Remove data from the hash table:
  void removeElement(int key){
    int x = getHash(key);

    list<int>::iterator i; 
    for (i = table[x].begin(); i != table[x].end(); i++) { 
      // Check if the iterator points to the required item:
      if (*i == key) 
        break;
    }

    // If the item was found in the list, then delete it:
    if (i != table[x].end()) 
      table[x].erase(i);
  }

  bool peek(int key){
    int x = getHash(key);
    list<int>::iterator i; 
    for (i = table[x].begin(); i != table[x].end(); i++) { 
      // Check if the iterator points to the required item:
      if (*i == key) 
        return true;
    }
    return false;
  }

  void printAll(){
    // Traverse each index:
    for(int i = 0; i < total_elements; i++){
      cout << "Index " << i << ": ";
      // Traverse the list at current index:
      for(int j : table[i])
        cout << j << " => ";

      cout << endl;
    }
  }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> final;
        int ind1, ind2;
        HashTable H(nums.size());
        for (int i = 0; i < nums.size(); i++)  // Insert the elements of the nums vector into HashTable.
        {
            H.insertElement(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(H.peek(target-nums[i]))  ind1 = i;  // target - curr InHash?
        }
        for (int i = ind1+1; i < nums.size(); i++)
        {
            if(nums[i] == target-nums[ind1])  ind2 = i;  // Finding target - curr's index
        }

        final.push_back(ind1); final.push_back(ind2);
        return final;
    }
};