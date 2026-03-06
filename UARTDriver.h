#ifndef UART_DRIVER_H
#define UART_DRIVER_H
#include "DeviceDriver.h"
#include <string>
#include <iostream>

class UARTDriver : public DeviceDriver {
    private:
        int baudRate; // Baud rate for UART communication
    public:
        UARTDriver(const std::string& name, int rate) : DeviceDriver(name), baudRate(rate) {} // Constructor to initialize UART driver with device name and baud rate

        void read() override {
            if (is_initialized) {
                std::cout << "Reading data from UART device: " << deviceName << std::endl; // Print reading message
            } else {
                std::cout << "Cannot read from uninitialized device: " << deviceName << std::endl; // Print error message if device is not initialized
            }
        }

        void write(const std::string& data) override {
            if (is_initialized) {
                std::cout << "Writing data to UART device: " << deviceName << ", Data: " << data << std::endl; // Print writing message with data
            } else {
                std::cout << "Cannot write to uninitialized device: " << deviceName << std::endl; // Print error message if device is not initialized
            }
        }

        void  initialize() override {
            DeviceDriver::initialize(); // Call base class initialize method
            std::cout << "Setting baud rate to: " << baudRate << std::endl; // Print baud rate setting message
        }

        void displayStatus() const override {
            DeviceDriver::displayStatus(); // Call base class displayStatus method
            std::cout << "UART Device: " << deviceName << ", Baud Rate: " << baudRate << std::endl; // Print UART device status with baud rate
        }


};

#endif // UART_DRIVER_H