#include "PaymentSystem.h"

int main() {
    std::cout << "Bai 1..................\n";
    Product product1("P001", "Laptop", 1500.0, 2);
    Product product2("P002", "Phone", 700.0, 1);
    std::vector<Product> products = {product1, product2};
    CashPayment cashPayment;
    ATMPayment atmPayment;
    MomoPayment momoPayment;
    ZalopayPayment zalopayPayment;
    Order order("O001", "John Doe", "0123456789", "123 Main St", products, &cashPayment);
    
    std::cout << "Testing Cash Payment:" << std::endl;
    order.setPaymentMethod(&cashPayment);
    order.pay();

    std::cout << "\nTesting ATM Payment:" << std::endl;
    order.setPaymentMethod(&atmPayment);
    order.pay();

    std::cout << "\nTesting Momo Payment:" << std::endl;
    order.setPaymentMethod(&momoPayment);
    order.pay();

    std::cout << "\nTesting Zalopay Payment:" << std::endl;
    order.setPaymentMethod(&zalopayPayment);
    order.pay();

    return 0;
}