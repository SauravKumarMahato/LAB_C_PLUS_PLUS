/*
qn2.cpp

Write two classes to store distances in meter-centimeter and feet-inch systems
respectively. Write conversions functions so that the program can convert objects of both types.

*/

#include <iostream>
using namespace std;

class feet_inch;
class meter_centimeter
{
    float meter;
    float centimeter;

public:
    meter_centimeter(float m = 0, float c = 0)
    {
        meter = m;
        centimeter = c;
    }
    float get_meter() { return meter; }
    float get_centimeter() { return centimeter; }
    void display()
    {
        cout << "meter: " << meter;
        cout << "centimeter: " << centimeter;
    }

    meter_centimeter(feet_inch fi);
};

class feet_inch
{
    float feet;
    float inches;

public:
    feet_inch(float f = 0, float i = 0)
    {
        feet = f;
        inches = i;
    }
    float get_feet() { return feet; }
    float get_inches() { return inches; }
    void display()
    {
        cout << "feet: " << feet;
        cout << "inches: " << inches;
    }

    feet_inch(meter_centimeter mc)
    {
        feet = mc.get_meter() * 30.48;
        inches = mc.get_centimeter() / 2.54;
    }
};

int main()
{
    feet_inch fi(10, 14), fi1;
    meter_centimeter mc(20, 25), mc1;

    mc1 = fi; // mc1 = meter_centimeter(fi);
    fi1 = mc; // fi1 = feet_inch(mc);

    mc1.display();
    fi1.display();
    return 0;
}

meter_centimeter::meter_centimeter(feet_inch fi)
{
    meter = fi.get_feet() * 0.3048;
    centimeter = fi.get_inches() * 2.54;
}