#include <iostream>

class LED {
private:
    bool is_on; // true for ON, false for OFF
public:
    LED() : is_on(false) {} // Constructor initializes LED to OFF

    void turnOn() {
        is_on = true;
        std::cout << "LED is ON" << std::endl;
    }

    void turnOff() {
        is_on = false;
        std::cout << "LED is OFF" << std::endl;
    }

    bool getState() const {
        std::cout << "LED state: " << (is_on ? "ON" : "OFF") << std::endl;
        return is_on;
    }
};

int main() {
    LED myLED; // Create an instance of LED

    myLED.getState(); // Check initial state (should be OFF)
    
    myLED.turnOn(); // Turn the LED ON
    myLED.getState(); // Check state (should be ON)

    myLED.turnOff(); // Turn the LED OFF
    myLED.getState(); // Check state (should be OFF)

    return 0;
}