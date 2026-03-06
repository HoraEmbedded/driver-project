
#include "UARTDriver.h"
#include "TemperatureSensor.h"

int main() {
    DeviceDriver* drivers[2]; // Array of pointers to DeviceDriver
    drivers[0] = new UARTDriver("UART1", 9600); // Create a UART driver instance with name "UART1" and baud rate 9600
    drivers[1] = new TemperatureSensor("TempSensor1", "Celsius"); // Create a temperature sensor instance with name "TempSensor1" and unit "Celsius"
    for (int i = 0; i < 2; ++i) {
        drivers[i] ->initialize(); // Check initialization status of each device driver
        drivers[i]->displayStatus(); // Display status of each device driver
        drivers[i]->write("Hello, UART!"); // Write data to each device driver (note that TemperatureSensor will indicate that writing is not supported)
        drivers[i]->read(); // Read from each device driver
    }

    TemperatureSensor* tempSensor = dynamic_cast<TemperatureSensor*>(drivers[1]); // Attempt to cast the second driver to a TemperatureSensor
    if (tempSensor) {
        tempSensor->updateTemperature(25.5); // Update the temperature reading for the temperature sensor
        tempSensor->displayStatus(); // Display the updated status of the temperature sensor
    }
    
    for (int i = 0; i < 2; ++i) {
        delete drivers[i]; // Clean up memory for each device driver
    }
    return 0;
}