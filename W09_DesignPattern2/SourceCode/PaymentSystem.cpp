#include "PaymentSystem.h"

Product::Product(const std::string code, const std::string name, double price, int count) : code(code), name(name), price(price), count(count) {};

void CashPayment::pay(double money)
{
    std::cout << "Pay " << money << " by cash!\n";
}

void ATMPayment::pay(double money)
{
    std::cout << "Pay " << money << " by ATM!\n";
}

void MomoPayment::pay(double money)
{
    std::cout << "Pay " << money << " by Momo!\n";
}

void ZalopayPayment::pay(double money)
{
    std::cout << "Pay " << money << " by Zalo!\n";
}

double Product::getPrice()
{
    return price;
}


Order::Order(const std::string& code, const std::string& customerName, const std::string& phoneNumber, const std::string& address, const std::vector<Product>& productList, PaymentMethod* paymentMethod) 
: code(code), customerName(customerName), phoneNumber(phoneNumber), address(address), productList(productList), paymentMethod(paymentMethod) {};

void Order::setPaymentMethod(PaymentMethod* paymentMethod)
{
    this->paymentMethod = paymentMethod;
}


double Order::getOrderPrice()
{
    double total = 0;
    for (Product i : productList)
        total += i.getPrice();
    
    return total;
}

void Order::pay()
{
    paymentMethod->pay(this->getOrderPrice());
}