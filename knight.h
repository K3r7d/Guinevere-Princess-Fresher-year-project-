#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void secondmax(int arr[], int size, int& max2_3x, int& max2_3i);
void transformation(int arr[], int size, int after[]);
void find_mountain(int* arr, int size, int& mtx, int& mti);
void findMaxAndMin(int arr[], int len, int& maxIndex, int& minIndex);
void findMaxAndMin2(int arr[], int len, int& maxIndex, int& minIndex);
bool isSubstring(string str, string sub);
int HP_to_Fibonacci(int HP);
void reverseArray(int arr[], int size);
void event13(string file_input, int& HP, int& MAXHP, int mushroom);
void event18(string file_input, int& HP, int& MAXHP);
void event19(string file_input, int& remedy, int& maidenkiss, int& phoenixdown);

#endif // __KNIGHT_H__