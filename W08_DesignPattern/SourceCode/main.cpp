#include "Circuit.h"
#include "BrickBreaker.h"
#include <iostream>

Ball* Ball::instance = nullptr;

int main()
{
    std::cout << "Bai 2..............\n";
    std::cout << "Testing single circuit.\n";
    SingleCircuit sc1(10.0); 
    SingleCircuit sc2(20.0); 

    std::cout << "Single Circuit 1 Resistance: " << sc1.calResistance() << " ohms" << std::endl;
    std::cout << "Single Circuit 2 Resistance: " << sc2.calResistance() << " ohms" << std::endl;

    std::cout << "Testing serial circuit.\n";
    SerialCircuit serialCircuit;
    serialCircuit.addComponent(&sc1);
    serialCircuit.addComponent(&sc2);

    std::cout << "Serial Circuit Resistance: " << serialCircuit.calResistance() << " ohms" << std::endl;

    std::cout << "Testing parallel circuit.\n";
    ParallelCircuit parallelCircuit;
    parallelCircuit.addComponent(&sc1);
    parallelCircuit.addComponent(&sc2);

    std::cout << "Parallel Circuit Resistance: " << parallelCircuit.calResistance() << " ohms" << std::endl;

    std::cout << "Mixing serial and parallel circuit.\n";
    SerialCircuit mixedSerial;
    mixedSerial.addComponent(&parallelCircuit); 
    mixedSerial.addComponent(new SingleCircuit(30.0)); 

    std::cout << "Mixed Serial Circuit Resistance: " << mixedSerial.calResistance() << " ohms" << std::endl;

    return 0;
}
