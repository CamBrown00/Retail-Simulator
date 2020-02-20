#include "Store.h"
#include "Isle.h"
#include <vector>
#include <iostream>

//businessDay struct

//Constructors
businessDay::businessDay() : earnings(0.0), customerCount(0), topItem("None"), date(0) {
}

businessDay::businessDay(double earnings, int customerCount, string topItem, int date) : earnings(earnings), customerCount(customerCount), topItem(topItem), date(date) {
}

//Overloaded Operators
ostream& operator << (ostream& outs, const businessDay &bd) {
    outs << "For Day " << bd.date << ": \n" << "Earnings: $" << bd.earnings << "\nCustomer Count: " << bd.customerCount;
    return outs;
}

bool operator == (businessDay &lhs, businessDay &rhs) {
    return (lhs.date == rhs.date);
}

bool operator > (businessDay &lhs, businessDay &rhs) {
    return (lhs.earnings > rhs.earnings);
}

bool operator < (businessDay &lhs, businessDay &rhs) {
    return (lhs.earnings < rhs.earnings);
}

//Store class

//Constructors
Store::Store() : isles({}), businessDays({}), totalEarnings(0), customerCount(0) {
    businessDay b;
    currentBusinessDay = b;
}

Store::Store(vector<Isle> isles) : isles(isles), businessDays({}), totalEarnings(0), customerCount(0) {
    businessDay b;
    currentBusinessDay = b;
}

//Non-trivial methods
void Store::addIsle(Isle is) {
    isles.push_back(is);
}

void Store::logBusinessDay() {
    //Calculate earnings for the current business day based on sum of earnings values stored in each isle object
    for (int i = 0; i < isles.size(); ++i) {
        currentBusinessDay.earnings += isles[i].getIslePrice() - isles[i].getIsleCost();
    }
    //Add current business day data to Store total fields
    customerCount += currentBusinessDay.customerCount;
    totalEarnings += currentBusinessDay.earnings;

    //Reset business day after pushing to vector of business days
    businessDays.push_back(currentBusinessDay);
    businessDay b;
    currentBusinessDay = b;
}

void Store::makeSale(item it) {
    for (int i = 0; i < isles.size(); ++i) {
        isles[i].removeItem(it);
    }
    ++currentBusinessDay.customerCount;
}

void Store::printStore() {

}
