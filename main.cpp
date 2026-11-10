#include <iostream>
#include <cmath>

class Cylinder {
private:
    double m_radius;
    double m_height;
    double m_volume;
public:
    Cylinder() {
        m_radius = 0;
        m_height = 0;
        m_volume = 0;
    }
    Cylinder(double radius, double height) {
        if (radius > 0) {
            m_radius = radius;
        }
        else {
            m_radius = 1;
        }
        if (height > 0) {
            m_height = height;
        }
        else {
            m_height = 1;
        }
    }
    void calcVolume() {
        m_volume = M_PI * pow(m_radius, 2.0) * m_height;
    }
    [[nodiscard]] double getVolume() const {
        return m_volume;
    }
    Cylinder operator+(Cylinder &rightCylinder) {
        Cylinder temp;
        temp.m_volume = this->m_volume += rightCylinder.m_volume; //this uses the object on the left
        temp.m_height = this->m_height += rightCylinder.m_height;
        temp.m_radius = sqrt(temp.m_volume / temp.m_height / M_PI);
        return temp;
    }
    friend std::ostream &operator<<(std::ostream &os, Cylinder &cylinder);
};

std::ostream& operator<<(std::ostream &os, Cylinder &cylinder) { // use friend function when it produces a different data type
    os << "Radius: " << cylinder.m_radius << std::endl;
    os << "Height: " << cylinder.m_height << std::endl;
    os << "Volume: " << cylinder.m_volume << std::endl;
    return os;
}

int main() {
    Cylinder cylinder1(2.45,12.5);
    cylinder1.calcVolume();
    std::cout<<"Cylinder 1 Volume: "<< cylinder1.getVolume() << std::endl;

    Cylinder cylinder2(4.85,9.125);
    cylinder2.calcVolume();
    std::cout<<"Cylinder 2 Volume: "<< cylinder2.getVolume() << std::endl;
    // Cylinder cylinder1.+(cylinder2)
    Cylinder cylinder3 = cylinder1 + cylinder2; // operator overloading

    //std::cout<<"Cylinder 3 Volume: "<< cylinder3.getVolume() << std::endl;
    std::cout << cylinder3 << std::endl;


    return 0;
}