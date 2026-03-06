#include <iostream>
#include <string>

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
