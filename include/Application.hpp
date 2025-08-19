#include <SimuCore/SimuCoreApplication.hpp>
#include <iostream>

// Example components
class Sensor : public Component {
public:
    Signal<int> outValue;

    Sensor(Component* parent = nullptr) : Component(parent) {}

    void update() override {
        static int counter = 0;
        outValue.value = ++counter;
        std::cout << "[Sensor] value = " << outValue.value << "\n";
    }
};

class Controller : public Component {
public:
    Signal<int> inValue;
    Signal<int> outCommand;

    Controller(Component* parent = nullptr) : Component(parent) {}

    void update() override {
        outCommand.value = inValue.value;
        std::cout << "[Controller] outCommand = " << outCommand.value << "\n";
    }
};

class Actuator : public Component {
public:
    Signal<int> inCommand;

    Actuator(Component* parent = nullptr) : Component(parent) {}

    void update() override {
        std::cout << "[Actuator] received = " << inCommand.value << "\n";
    }
};

class Application : public SimuCoreApplication {
public:
    Application() : 
        SimuCoreApplication(),
        sensor(this),
        controller(this),
        actuator(this)
    {
       
    }
    ~Application(){}

    void init() {
        controller.bind(sensor.outValue, controller.inValue);
        actuator.bind(controller.outCommand, actuator.inCommand);
    }

public:
    Sensor sensor;
    Controller controller;
    Actuator actuator;
};