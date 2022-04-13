// Raju's GATE coaching adventures 

// Raju is preparing for GATE to join liSc. He has joined Mogambo's 
// GATE coaching institute that has given him several chapters of notes to study. 
// The chapters are numbered using integers. There are dependencies between the 
// chapters, expressed as N -> M, which means that chapter number N depends on 
// chapter number M. This dependency means that Raju must first study chapter number 
// M before studying chapter number N. 

// Unfortunately, Mogambo's GATE coaching institute has not done a good job in 
// preparing the chapters. There may be circular dependencies between the chapters, 
// which would mean that Raju cannot study using these notes. 

// Raju wishes to efficiently determine whether there is a circular dependency in 
// the chapters given to him that would prevent him from making use of the notes. 

// Write a program to help Raju make this determination. 

// INPUT: The input to your program will be a set of dependencies between the chapters, 
// with each dependency given on a single line N -> M. on standard input. The chapter 
// numbers need not be in serial order. You should also not expect to see all chapters 
// from 1 onwards, since there may be missing chapters in the set of notes. You should 
// also not make any assumptions that if N -> M is listed as a dependency, then integer 
// M will be numerically smaller than integer N.

// TIME LIMIT: The correctness of your algorithm using 10 test cases. You will receive 
// 1 point for every test case for which your algorithm produces the correct answer. 
// Furthermore. your algorithm must be able to compute the answer to the problem within 
// 5 seconds of wall-clock time on our server for each of these test cases. If your 
// algorithm times-out on our test server for one of our test cases. then you will 
// receive 0 points for that test case.

// OUTPUT: Your program should output 1 if there Is a circular dependency between the 
// chapters. and 0 otherwise. 

// SAMPLE INPUT 1:
// 100 -> 6 
// 99 -> 7 
// 34 -> 55 
// 6 -> 55 
// 7 -> 74 
// 55 -> 16 
// 16 -> 100 
// SAMPLE OUTPUT 1:
// 1

// SAMPLE INPUT 2:
// 100 -> 6 
// 99 -> 7 
// 34 -> 55 
// 6 -> 55 
// 7 -> 74 
// 55 -> 16 
// SAMPLE OUTPUT 2:
// 0

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

    return 0;
}