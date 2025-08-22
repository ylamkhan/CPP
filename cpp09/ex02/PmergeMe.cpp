#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string arg)
{
    startTimeData = clock();
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (isdigit(arg[i]))
        {
            std::string ch;
            while (i<arg.size() && isdigit(arg[i]))
            {
                ch.push_back(arg[i]);
                i++;
            }
            double d = std::stod(ch);
            if(d > INT_MAX)
            {
                std::cerr<<"Error: Sup INT_MAX\n";
                exit(EXIT_FAILURE);
            }
            nub1.push_back((int)d);
            nub2.push_back((int)d);
        }
    }
    endTimeData = clock();
}

PmergeMe &PmergeMe::operator=(const PmergeMe &o)
{
    if(this != &o)
    {
        res             =   o.res;
        deq             =   o.deq;
        startTimeVec    =   o.startTimeVec;
        endTimeVec      =   o.endTimeVec;
        startTimeDeq    =   o.startTimeDeq;
        endTimeDeq      =   o.endTimeDeq;
        nub1            =   o.nub1;
        nub2            =   o.nub2;
        startTimeData   =   o.startTimeData;
        endTimeData     =   o.endTimeData;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &o)
{
    *this = o;
}
PmergeMe::~PmergeMe()
{

}



void PmergeMe::swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

/*------------------------------------------------------------------------------------*/
/*----------------------------Using the Ford-Johnson algorithm.-----------------------*/
/*------------------------------------------------------------------------------------*/

std::vector<int> PmergeMe::PmergeInsertVec(std::vector<int> &vec)
{
    
    if(vec.empty() || vec.size() < 1)
        return vec;
    /*--------------------------------------------------------------------------------*/
    /*------------------Step 1: Group elements into pairs-----------------------------*/
    /*--------------------------------------------------------------------------------*/
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i+=2)
    {
        std::pair<int, int> pair;
        pair.first = vec[i];
        if(i+1<vec.size())
            pair.second = vec[i+1];
        else
            pair.second = -1;
        pairs.push_back(pair);
    }
    /*--------------------------------------------------------------------------------*/
    /*------------------Step 2: Perform comparisons and merge pairs-------------------*/
    /*--------------------------------------------------------------------------------*/
    std::vector<int> resultVec;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if(pairs[i].first > pairs[i].second)
            resultVec.push_back(pairs[i].first);
        else
        {
            resultVec.push_back(pairs[i].second);
            swap(pairs[i].first,pairs[i].second);
        }
    }
    /*--------------------------------------------------------------------------------*/
    /*---------Step 3: Recursively sort the [n/2]larger elements from each pair-------*/
    /*--------------------------------------------------------------------------------*/
    if(resultVec.size()>1)
        resultVec =  PmergeMe::PmergeInsertVec(resultVec);
    /*--------------------------------------------------------------------------------*/
    /*------------------Step 4: Insert the remaining elements-------------------------*/
    /*--------------------------------------------------------------------------------*/
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(resultVec.begin(),resultVec.end(),pairs[i].second);
        if(pairs[i].second>=0)
            resultVec.insert(it,pairs[i].second);
    }
    return resultVec;
}


std::deque<int> PmergeMe::PmergeInsertDeq(std::deque<int> &Deq)
{
    if(Deq.empty() || Deq.size()<1)
        return Deq;
    /*--------------------------------------------------------------------------------*/
    /*------------------Step 1: Group elements into pairs-----------------------------*/
    /*--------------------------------------------------------------------------------*/
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < Deq.size(); i+=2)
    {
        std::pair<int, int> pair;
        pair.first = Deq[i];
        if (i+1<Deq.size())
            pair.second = Deq[i+1];
        else
            pair.second = -1;
        pairs.push_back(pair);
    }
    /*--------------------------------------------------------------------------------*/
    /*------------------Step 2: Perform comparisons and merge pairs-------------------*/
    /*--------------------------------------------------------------------------------*/
    std::deque<int> resultDeq;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if(pairs[i].first>pairs[i].second)
            resultDeq.push_back(pairs[i].first);
        else
        {
            resultDeq.push_back(pairs[i].second);
            swap(pairs[i].first,pairs[i].second);
        }
    }
    /*--------------------------------------------------------------------------------*/
    /*---------Step 3: Recursively sort the [n/2]larger elements from each pair-------*/
    /*--------------------------------------------------------------------------------*/
    if(resultDeq.size()>1)
        resultDeq =  PmergeMe::PmergeInsertDeq(resultDeq);
    /*--------------------------------------------------------------------------------*/
    /*------------------Step 4: Insert the remaining elements-------------------------*/
    /*--------------------------------------------------------------------------------*/
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(resultDeq.begin(),resultDeq.end(),pairs[i].second);
        if(pairs[i].second>=0)
            resultDeq.insert(it,pairs[i].second);
    }
    return resultDeq;
}

void PmergeMe::run()
{
    startTimeVec = clock();
    res =  PmergeInsertVec(nub1);
    endTimeVec = clock();
    startTimeDeq = clock();
    deq =  PmergeInsertDeq(nub2);
    endTimeDeq = clock();
}

void PmergeMe::diysplay()
{
    if(nub1.empty())
        return;
    std::cout<<"Before: ";
    for (size_t i = 0; i < nub1.size(); i++)
    {
        std::cout<<nub1[i];
        if(i+1<nub1.size())
            std::cout<<" ";
    }
    std::cout<<"\n";
    std::cout<<"After: ";
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout<<res[i];
        if(i+1<res.size())
            std::cout<<" ";
    }
    std::cout<<"\n";
    std::cout<<"Time to process a range of "<<nub1.size()<<" elements with std::vector<int> : "<< std::fixed << std::setprecision(5)<<(double)((endTimeData - startTimeData)+(endTimeVec - startTimeVec))<<" us\n";
    std::cout<<"Time to process a range of "<<nub1.size()<<" elements with std::Deque<int> : "<< std::fixed << std::setprecision(5)<<(double)((endTimeData - startTimeData)+(endTimeDeq - startTimeDeq))<<" us\n";
}