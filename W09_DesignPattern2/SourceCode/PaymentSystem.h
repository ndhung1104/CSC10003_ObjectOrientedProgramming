#include <string>
#include <vector>
#include <iostream>


class Product
{
private:
    std::string code;
    std::string name;
    double price;
    int count;

public:
    Product(const std::string code, const std::string name, double price, int count);
    double getPrice();
};


class PaymentMethod
{
public:
    virtual void pay(double money) = 0;
};

class CashPayment : public PaymentMethod
{
public:
    void pay(double money);
};

class ATMPayment : public PaymentMethod
{
public:
    void pay(double money);
};

class MomoPayment : public PaymentMethod
{
public:
    void pay(double money);
};

class ZalopayPayment : public PaymentMethod
{
public:
    void pay(double money);
};

class Order
{
private:
    std::string code;
    std::string customerName;
    std::string phoneNumber;
    std::string address;
    std::vector<Product> productList;
    PaymentMethod* paymentMethod;
    double getOrderPrice();
public:
    Order(const std::string& code, const std::string& customerName, const std::string& phoneNumber, const std::string& address, const std::vector<Product>& productList, PaymentMethod* paymentMethod);
    void setPaymentMethod(PaymentMethod* paymentMethod);
    void pay();
};
