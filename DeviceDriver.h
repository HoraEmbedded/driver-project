#ifndef DEVICE_DRIVER_H
#define DEVICE_DRIVER_H
#include <string>
#include <iostream>

class DeviceDriver {
    protected:
        std::string deviceName; // Name of the device
        bool is_initialized; // Flag to indicate if the device is initialized
    public: 
        DeviceDriver(const std::string& name) : deviceName(name), is_initialized(false) {} // Constructor to initialize device name and set initialized flag to false

        virtual void initialize() {
            is_initialized = true; // Set initialized flag to true
            std::cout << "Initializing device: " << deviceName << std::endl; // Print initialization message
        }

        virtual void shutdown() {
            is_initialized = false; // Set initialized flag to false
            std::cout << "Shutting down device: " << deviceName << std::endl; // Print shutdown message
        }

        bool getInitializationStatus() const {
            std::cout << "Device " << deviceName << " initialization status: " << (is_initialized ? "Initialized" : "Not Initialized") << std::endl; // Print initialization status
            return is_initialized; // Return the initialization status
        }

        virtual ~DeviceDriver() {
            std::cout << "Destroying device driver: " << deviceName << std::endl; // Print destruction message
        } // Virtual destructor for proper cleanup in derived classes

        virtual void read() = 0; 
        virtual void write(const std::string& data) = 0;

        virtual void displayStatus() const {
            std::cout << "Device: " << deviceName << ", Status: " << (is_initialized ?"Initialized" : "Not Initialized") << std::endl; // Print device status
        }   
        
};

#endif // DEVICE_DRIVER_H