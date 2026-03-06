#include <iostream>

class Shape {
protected:
    std::string name; // Name of the shape
public:
    Shape(const std::string& shapeName) : name(shapeName) {} // Constructor to initialize shape name    
    
    void describe() const {
        std::cout << "I'm a shape named : " << name << "." << std::endl;
    }
    virtual double area() = 0; // Pure virtual function to calculate area, making Shape an abstract class
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
    Shape* s = new Circle(5.0); // Create a shape pointer to a Circle instance with radius 5.0
    s->describe(); // Describe the shape (should describe it as a Circle)
    std::cout << "Area of the shape: " << s->area() << std::endl; // Calculate and display area of the shape (should calculate area of the circle)
    delete s; // Clean up memory
    
    Circle myCircle(5.0); // Create an instance of Circle with radius 5.0
    myCircle.describe(); // Describe the circle
    std::cout << "Area of the circle: " << myCircle.area() << std::endl; // Calculate and display area of the circle

    return 0;
}