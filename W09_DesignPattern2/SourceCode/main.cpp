#include "PaymentSystem.h"
#include "Dragon.h"

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


    std::cout << "\nBai 2.................\n";

    Dragon ABC("ABC", 50, 30, 100, 5);
    std::cout << "\nInitialized dragon ABC with 50 damage, 30 defense, 100 hp, and level 5\n\n";
    ABC.setState(new NormalState());
    ABC.calculateCombatPower();
    ABC.attack();
    ABC.move();

    std::cout << "\n";

    ABC.setState(new RageState());
    ABC.calculateCombatPower();
    ABC.attack();
    ABC.move();

    std::cout << "\n";

    ABC.setState(new DefensiveState());
    ABC.calculateCombatPower();
    ABC.attack();
    ABC.move();

    return 0;
}