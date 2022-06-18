#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2) {
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
   map<int, pair<int, int>> Hash;
   for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if(Hash.find(sum) == Hash.end()) {
                Hash[sum] = make_pair(arr[i], arr[j]);
            }
            else {
                pair1 = Hash[sum];
                pair2 = make_pair(arr[i], arr[j]);
                return true;
            }
        }   
   }
   return false;
}

int foldShift(long long key, int addressSize) {
    string sKey = to_string(key);
    int n = sKey.length();
    if(n <= addressSize || addressSize <= 0) return key;
    int loop = (n % addressSize) ? (n / addressSize + 1) : (n / addressSize);
    int result = 0;
    for(int i = 0; i < loop; i++) {
        string temp = "";
        for(int j = 0; j < addressSize; j++) {
            if(i * addressSize + j < n) {
                temp += sKey[i * addressSize + j];
            }
        }
        result += stoi(temp);
    }
    result = result % int(pow(10, addressSize));
    return result;
}

int rotation(long long key, int addressSize) {
    string temp1 = to_string(key / 10);
    string temp2 = to_string(key % 10);
    long long newKey = stoll(temp2 + temp1);
    return foldShift(newKey, addressSize);
}

long int midSquare(long int seed) {
    long int key = seed * seed;
    key /= 100;
    return key % 10000;
}

long int moduloDivision(long int seed, long int mod) {
    return seed % mod;
}

long int digitExtraction(long int seed,int* extractDigits,int size) {
    string sSeed = to_string(seed);
    string sKey = "";
    for(int i = 0; i < size; i++) {
        sKey += sSeed[extractDigits[i]];
    }
    return stol(sKey);
}

#endif