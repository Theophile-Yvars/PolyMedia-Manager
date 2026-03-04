#pragma once   

class IBorrowable
{
public:
    virtual ~IBorrowable() = default;
    virtual void borrow() = 0;
    virtual void returnItem() = 0;
    virtual bool isBorrowed() const = 0;
};