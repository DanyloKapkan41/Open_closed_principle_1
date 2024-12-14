#include <iostream>
#include <vector>
#include <memory>
using namespace std;
// ������� ���� ��� ��� �����
class Shape {
public:
    virtual double area() const = 0; // ����� ��������� �������
    virtual ~Shape() = default;     // ³��������� ����������
};

// ���� ��� ������������
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// ���� ��� ��������
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

// ����������� ����
class AreaCalculator {
public:
    double calculate(const vector<shared_ptr<Shape>>& shapes) const {
        double totalArea = 0.0;
        for (const auto& shape : shapes) {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main() {
    vector<shared_ptr<Shape>> shapes = {
        make_shared<Rectangle>(4.0, 5.0),
        make_shared<Square>(3.0)
    };

    AreaCalculator calculator;
    cout << "Total Area: " << calculator.calculate(shapes) << endl;
    return 0;
}
/*
��� ���������� OCP:
� ����� ������� ����� ���� ������ ������������� ���� ��������� ����:

#include <iostream>
#include <vector>
#include <string>

class Shape {
public:
    std::string type;
    double width, height;

    Shape(const std::string& t, double w, double h) : type(t), width(w), height(h) {}
};

class AreaCalculator {
public:
    double calculate(const std::vector<Shape>& shapes) {
        double totalArea = 0.0;
        for (const auto& shape : shapes) {
            if (shape.type == "rectangle") {
                totalArea += shape.width * shape.height;
            } else if (shape.type == "square") {
                totalArea += shape.width * shape.width;
            }
            // ��������� ���� ������ ������� ������� ����� ����
        }
        return totalArea;
    }
};

int main() {
    std::vector<Shape> shapes = {{"rectangle", 4.0, 5.0}, {"square", 3.0, 0.0}};
    AreaCalculator calculator;
    std::cout << "Total Area: " << calculator.calculate(shapes) << std::endl;
    return 0;
}*/