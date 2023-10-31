/// @brief Header File for Window
/// @file Window.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef WINDOW_H
#define WINDOW_H

#include "ListQueue.h"
#include "Customer.h"
using namespace std;
#include <string>
#include <cstdlib>

class Window{
    public:
        Window();
        virtual ~Window();
        void nextCustomer();
        void addCustomer(Customer* c);
        int lineSize(); 

    protected:
        ListQueue<Customer*>* queueAtWindow;

};



#endif