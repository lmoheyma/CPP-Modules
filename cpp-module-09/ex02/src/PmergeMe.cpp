/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:45:09 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/03/15 16:35:53 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe::~PmergeMe()
{

}

static void printVector(std::vector<int> vector)
{
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
}

static void printList(std::list<int> list)
{
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
        std::cout << *it << " ";
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return (*this);
}

static std::vector<int> mergeVector(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> res;
    int i = 0;
    int j = 0;
    int left_size = left.size();
    int right_size = right.size();

    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            res.push_back(left[i]);
            i++;
        }
        else
        {
            res.push_back(right[j]);
            j++;
        }
    }
    
    while (i < left_size)
        res.push_back(left[i++]);
    while (j < right_size)
        res.push_back(right[j++]);
    return (res);
}

static std::vector<int> mergeInsertVector(std::vector<int> vector)
{
    if (vector.size() <= 1)
        return (vector);
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int>::iterator middleIt(vector.begin() + vector.size() / 2);

    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        if (std::distance(it, middleIt) > 0)
            left.push_back(*it);
        else
            right.push_back(*it);
    }
    left = mergeInsertVector(left);
    right = mergeInsertVector(right);

    return (mergeVector(left, right));
    
}

void PmergeMe::sortVector(int argc, char **argv)
{
    std::vector<int> vector;
    std::vector<int> sortedVector;
    std::clock_t start;
    double duration;

    for (int i = 1; i < argc; i++)
        vector.push_back(std::atoi(argv[i]));
    std::cout << "\033[1m\033[35mBefore: \033[1m\033[37m";
    printVector(vector);
    std::cout << std::endl;

    start = std::clock();

    sortedVector = mergeInsertVector(vector);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\033[1m\033[35mAfter:  \033[1m\033[37m";
    printVector(sortedVector);
    std::cout << std::endl << "\033[1m\033[36mTime to process a range of " << vector.size() << " elements with std::vector<int> : " << duration << "s\033[0m" << std::endl;
}

static std::list<int> mergeList(std::list<int> left, std::list<int> right)
{
    std::list<int> res;
    std::list<int>::iterator itLeft = left.begin();
    std::list<int>::iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft < *itRight)
        {
            res.push_back(*itLeft);
            itLeft++;
        }
        else
        {
            res.push_back(*itRight);
            itRight++;
        }
    }
    
    while (itLeft != left.end())
    {
        res.push_back(*itLeft);
        itLeft++;
    }
    while (itRight != right.end())
    {
        res.push_back(*itRight);
        itRight++;
    }
    return (res);
}

static std::list<int> mergeInsertList(std::list<int> list)
{
    if (list.size() <= 1)
        return (list);
    std::list<int> left;
    std::list<int> right;
    std::list<int>::iterator it1 = list.begin();
    
    for (size_t i = 0; i < list.size() / 2; i++)
        it1++;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        if (std::distance(it, it1) > 0)
            left.push_back(*it);
        else
            right.push_back(*it);
    }
    left = mergeInsertList(left);
    right = mergeInsertList(right);

    return (mergeList(left, right));
}

void PmergeMe::sortList(int argc, char **argv)
{
    std::list<int> list;
    std::list<int> sortedList;
    std::clock_t start;
    double duration;

    for (int i = 1; i < argc; i++)
        list.push_back(std::atoi(argv[i]));
    std::cout << "\033[1m\033[35mBefore: \033[1m\033[37m";
    printList(list);
    std::cout << std::endl;

    start = std::clock();

    sortedList = mergeInsertList(list);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\033[1m\033[35mAfter:  \033[1m\033[37m";
    printList(sortedList);
    std::cout << std::endl << "\033[1m\033[36mTime to process a range of " << list.size() << " elements with std::list<int> : " << duration << "s\033[0m" << std::endl;
}