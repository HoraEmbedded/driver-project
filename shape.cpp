#include <iostream>

class Shape {
protected:
    std::string name; // Name of the shape
public:
    Shape(const std::string& shapeName) : name(shapeName) {} // Constructor to initialize shape name    
    
    void describe() const {
        std::cout << "I'm a shape named : " << name << "." << std::endl;
    }
    virtual double area() 
    {
        std::cout << "Area calculation not implemented for base Shape class." << std::endl;
        return 0.0; // Base class does not have a specific area calculation 
    }
};

class Circle : public Shape {
private:    float radius; // Radius of the circle
public:
    Circle(float r) : Shape("Circle"), radius(r) {} // Constructor initializes shape name and radius

    double area() override {
        return 3.14159 * radius * radius; // Area of a circle: πr²
    }
};

int main() {
    Shape myShape("Shape"); // Create an instance of Shape
    myShape.describe(); // Describe the shape
    myShape.area(); // Attempt to calculate area (not implemented for base class)

    Circle myCircle(5.0); // Create an instance of Circle with radius 5.0
    myCircle.describe(); // Describe the circle
    std::cout << "Area of the circle: " << myCircle.area() << std::endl; // Calculate and display area of the circle

    return 0;
}