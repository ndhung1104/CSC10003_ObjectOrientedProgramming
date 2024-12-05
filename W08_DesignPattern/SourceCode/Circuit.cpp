#include "Circuit.h"

SingleCircuit::SingleCircuit(double resistance)
{
    this->resistance = resistance;
}

double SingleCircuit::calResistance()
{
    return this->resistance;
}

CompositeCircuit::CompositeCircuit() : components(std::vector<Circuit*>()) {};

CompositeCircuit::~CompositeCircuit()
{
    for (Circuit* component : components)
        delete component;
}

void CompositeCircuit::addComponent(Circuit* component)
{
    components.push_back(component);
}

void CompositeCircuit::removeComponent(Circuit* component)
{
    auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end())
        components.erase(it);
}


double SerialCircuit::calResistance()
{
    double res = 0;
    for (Circuit* c : components)
        res += c->calResistance();
    return res;
}

double ParallelCircuit::calResistance()
{
    double res = 0;
    for (Circuit* c : components)
        res += 1 / c->calResistance();
    return 1 / res;
}

