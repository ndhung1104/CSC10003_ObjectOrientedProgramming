#include <vector>
#include <algorithm>

class Circuit
{
protected:
    double resistance;
public:
    virtual double calResistance() = 0;
};

class SingleCircuit : public Circuit
{

public:
    SingleCircuit(double resistance);
    double calResistance();
};

class CompositeCircuit : public Circuit
{
protected:
    std::vector<Circuit*> components;

public:
    CompositeCircuit();
    ~CompositeCircuit();
    void addComponent(Circuit* component);
    void removeComponent(Circuit* component);
};

class SerialCircuit : public CompositeCircuit
{

public:
    double calResistance();
};

class ParallelCircuit : public CompositeCircuit
{

public:
    double calResistance();
};

