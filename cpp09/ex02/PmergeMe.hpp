#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <cctype>
#include <ctime>
#include <iomanip>
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------Merge-insertion sort Algorithm----------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*on an input X of n elements:--------------------------------------------------------------------------------------------------------------------*/
/*----1- Group the elements of X into [n/2] pais of elements. if nub of X odd one element is unpaired.--------------------------------------------*/
/*----2- Perform [n/2] comparisons, one per pair, to determine the large of the two elements in each pair.----------------------------------------*/
/*----3-Recursively sort the [n/2] larger elements from each pair , creating a sorted sequence S of [n/2] the input elements, in ascending order.-*/
/*----4-Insert at the start of S the element that was paired with the first and smallest element of S.--------------------------------------------*/
/*----Insert the remaining [n/2] elements of S into S, one at a time, with a specially chosen insertion ordering described below.------------------
------Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.-------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------*/




class PmergeMe
{
    public:

        PmergeMe(std::string arg);
        ~PmergeMe();
        void diysplay();
        std::vector<int> PmergeInsertVec(std::vector<int> &vec);
        std::deque<int> PmergeInsertDeq(std::deque<int> &Deq);
        void run();

    private:
        std::vector<int>    res;
        std::deque<int>     deq;
        clock_t             startTimeVec;
        clock_t             endTimeVec;
        clock_t             startTimeDeq;
        clock_t             endTimeDeq;
        std::vector<int>    nub1;
        std::deque<int>     nub2;
        clock_t             startTimeData;
        clock_t             endTimeData;

        void swap(int &a, int &b);
        PmergeMe &operator=(const PmergeMe &o);
        PmergeMe(const PmergeMe &o);
};

#endif