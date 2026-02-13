#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override
    {
        return width * height;
    }

    double perimeter() const override
    {
        return 2 * (width + height);
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }
};

int main()
{
    Rectangle rectangle(5, 3);

    // Create a pointer to "Rectangle". 
    Rectangle *rectPtr = &rectangle;

    // Declare a "shapePtr" and initialize it by statically upcasting "rectPtr".
    Shape *shapePtr = static_cast<Shape *>(rectPtr);


    // Dynamically check if "shapePtr" can be downcasted to a Circle*
    if( 
    dynamic_cast<Circle *>(shapePtr) != nullptr
    ) {
        cout << "shapePtr points to a Circle\n";
    } else {
        cout << "shapePtr does not point to a Circle\n";
    }

    // Remove the const qualifier from the "const Rectangle" pointed to by rectPtr.
    const Circle circle(10);
    const Circle *ptr = &circle;
    rectPtr = const_cast<Rectangle *>(rectPtr);

    int x = 97;
    int* p = &x;
    // Declare a "char c" and initialize it with the value 'a' by performing a reinterpret cast on "p"
    char c = *reinterpret_cast<char *>(p);

}