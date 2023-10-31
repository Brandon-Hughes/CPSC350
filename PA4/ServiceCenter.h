/// @brief Header file for Service Center
/// @file ServiceCenter.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H

#include "Office.h"
#include "Window.h"
#include "ListQueue.h"
#include <cstdlib>
using namespace std;

class ServiceCenter{
    public:
        ServiceCenter(int wRegistrar, int wCashier, int wAid);
        virtual ~ServiceCenter();
        void addCustomer(char c, int window, Customer* c1);
        int shortestLine(char c);
        void nextCustomer(char c, int numWindow);
        int queueSizeS(char c, int numWindow);

    protected:
        Office* registrar;
        Office* cashier;
        Office* financialAid;
};



#endif