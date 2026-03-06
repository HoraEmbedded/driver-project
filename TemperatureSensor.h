#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "DeviceDriver.h"
#include <string>
#include <iostream>

class TemperatureSensor : public DeviceDriver 
{
private:
   float currentTemperature; // Current temperature reading
   std::string unit; // Unit of temperature (e.g., Celsius, Fahrenheit)
public:
    TemperatureSensor(const std::string& name, const std::string& tempUnit) : DeviceDriver(name), currentTemperature(0.0), unit(tempUnit) {} // Constructor to initialize temperature sensor with device name and temperature unit
    
    void read() override {
         if (is_initialized) {
              std::cout << "Reading temperature from sensor: " << deviceName << ", Current Temperature: " << currentTemperature << " " << unit << std::endl; // Print reading message with current temperature
         } else {
              std::cout << "Cannot read from uninitialized device: " << deviceName << std::endl; // Print error message if device is not initialized
         }
    }
    
    void write(const std::string& data) override {
         std::cout << "Temperature sensor does not support writing data." << std::endl; // Print message indicating that writing is not supported for temperature sensor
    }
    
    void updateTemperature(float newTemp) {
         currentTemperature = newTemp; // Update the current temperature reading
         std::cout << "Updated temperature for sensor: " << deviceName << ", New Temperature: " << currentTemperature << " " << unit << std::endl; // Print updated temperature message
    }
    
    void displayStatus() const override {
         std::cout << "Temperature Sensor: " << deviceName << ", Current Temperature: " << currentTemperature << " " << unit << ", Status: " << (is_initialized ? "Initialized" : "Not Initialized") << std::endl; // Print temperature sensor status with current temperature
    }
    };

#endif // TEMPERATURE_SENSOR_H