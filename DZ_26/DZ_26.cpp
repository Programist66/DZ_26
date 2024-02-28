#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;
class Triangle {
private:
    int side1;
    int side2;
    int side3;

public:
    Triangle(int s1, int s2, int s3) : side1(s1), side2(s2), side3(s3) {
        if (!isValid()) {
            throw invalid_argument("Invalid triangle sides");
        }
    }

    double getPerimeter() const {
        return side1 + side2 + side3;
    }

    double getArea() const {
        double p = getPerimeter() / 2.0;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

private:
    bool isValid() const {
        return side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1;
    }
};

int main() {
    Triangle t1(3, 4, 5);
    Triangle t2(6, 8, 10);
    Triangle t3(5, 12, 13);

    auto compareByPerimeter = [](const Triangle& t1, const Triangle& t2) {
        return t1.getPerimeter() < t2.getPerimeter();
        };

    auto compareByArea = [](const Triangle& t1, const Triangle& t2) {
        return t1.getArea() < t2.getArea();
        };

    cout << "Perimeter Comparison:" << endl;
    cout << "t1 < t2: " << boolalpha << compareByPerimeter(t1, t2) << endl;
    cout << "t1 > t3: " << boolalpha << compareByPerimeter(t1, t3) << endl;
    cout << "t2 > t3: " << boolalpha << compareByPerimeter(t2, t3) << endl;

    cout << "Area Comparison:" << endl;
    cout << "t1 < t2: " << boolalpha << compareByArea(t1, t2) << endl;
    cout << "t1 > t3: " << boolalpha << compareByArea(t1, t3) << endl;
    cout << "t2 > t3: " << boolalpha << compareByArea(t2, t3) << endl;

    return 0;
}