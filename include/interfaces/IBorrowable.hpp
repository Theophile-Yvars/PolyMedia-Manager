#pragma once   
#include <chrono>

class IBorrowable
{
public:
    virtual ~IBorrowable() = default;
    virtual void borrow() = 0;
    virtual void returnItem() = 0;
    virtual bool isBorrowed() const = 0;
    virtual std::chrono::system_clock::time_point getBorrowDate() const = 0;
};