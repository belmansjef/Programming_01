// 1DAE21N - Belmans Jef

#include "pch.h"

#define _USE_MATH_DEFINES

#include <iostream>
using namespace std;

// Note: I've used classes just to start experimenting with them.
// Implementation is not how it should be, I am keen to learn the best design paterns

class Color4f

{
    int r{ 255 };
    int g{ 255 };
    int b{ 255 };
    int a{ 255 };

    float rConverted{ r / 255.0f };
    float gConverted{ g / 255.0f };
    float bConverted{ b / 255.0f };
    float aConverted{ a / 255.0f };

public:
    void SetColor()
    {
        cout << "RGBA in [0, 255]? ";
        cin >> r >> g >> b >> a;
    }

    void ConvertRange()
    {
        rConverted = r / 255.0f;
        gConverted = g / 255.0f;
        bConverted = b / 255.0f;
        aConverted = a / 255.0f;
    }

    void PrintConvertedRange()
    {
        cout << "RGBA in [0.0f, 1.0f]:\n";
        cout << rConverted << endl << gConverted << endl << bConverted << endl << aConverted << endl;
    }
};

class Distance 
{
    float kilometers{ 2.5f };
    float meters{ kilometers * 1000.0f };
    float centimeters{ kilometers * 100000.0f };

public:
    void SetKilometers()
    {
        cout << "Distance in KM? ";
        cin >> kilometers;
    }

    void ConvertDistance()
    {
        meters = kilometers * 1000.0f;
        centimeters = kilometers * 100000.0f;
    }

    void PrintConvertedDistance()
    {
        cout << meters << " meters. " << centimeters << " centimeters.\n";
    } 
};

class Angle
{
    float aRad{ 0.785398f };
    float aDeg{ 45.0f };

public:

    void SetRadian()
    {
        cout << "Angle in radians? ";
        cin >> aRad;
    }

    void SetDegree()
    {
        cout << "Angle in degrees? ";
        cin >> aDeg;
    }

    void ConvertToRadians()
    {
        aRad = aDeg * (( 2.0f * static_cast<float>(M_PI) ) / 360.0f);
    }

    void ConvertToDegrees()
    {
        aDeg = aRad * ( 360.0f / ( 2.0f * static_cast<float>(M_PI) ));
    }

    void PrintRadians()
    {
        cout << aRad << " radians\n";
    }

    void PrintDegrees()
    {
        cout << aDeg << " degrees\n";
    }
};

class AngularVelocity
{
    float rotationTime{ 3.0f };
    float angularVelocity{ 120.0f };

public:

    void SetRotationTime()
    {
        cout << "Seconds of one rotation? ";
        cin >> rotationTime;
    }

    void CalculateAngularVelocity()
    {
        angularVelocity = 360.0f / rotationTime;
    }

    void PrintAngularVelocity()
    {
        cout << angularVelocity << " degrees/second\n";
    }
};

class Speed
{
    float speed{ 3 };
    float elapsedTimeMinutes{ 30 };
    float distance{ 1500 };

public:

    void SetSpeed()
    {
        cout << "Speed (km/h)? ";
        cin >> speed;
    }

    void SetElapsedTime()
    {
        cout << "Elapsed time (minutes)? ";
        cin >> elapsedTimeMinutes;
    }

    void CalculateDistance()
    {
        float convertedSpeed{ speed / 3.6f };
        float convertedTime{ elapsedTimeMinutes * 60.0f };

        distance = convertedSpeed * convertedTime;
    }

    void PrintDistance()
    {
        cout << distance << " meters\n";
    }

};

class Velocity
{
    float elapsedTime{ 4 };
    float velocity{ 39.2f };
    float gravity{ 9.81f };

public:

    void SetDeltaTime()
    {
        cout << "Calculate velocity: seconds? ";
        cin >> elapsedTime;
    }

    void CalculateVelocity()
    {
        velocity = elapsedTime * gravity;
    }

    void PrintVelocity()
    {
        cout << "Velocity " << velocity << " m/sec\n";
    }
};

class Circle
{
    float radius{ 10.0f };
    float circumference{ 62.8319f };
    float area{ 314.159f };

public:

    void SetRadius()
    {
        cout << "Radius of circle? ";
        cin >> radius;
    }

    void CalculateCircumference()
    {
        circumference = 2 * static_cast<float>(M_PI) * radius;
    }

    void CalculateArea()
    {
        area = static_cast<float>(M_PI) * powf(radius, 2);
    }

    void PrintCircumference()
    {
        cout << "Circumference: " << circumference << endl;
    }

    void PrintArea()
    {
        cout << "Area: " << area << endl;
    }
};

class Rectangle
{
    float width{ 10.0f };
    float height{ 4.0f };
    float circumference{ 28.0f };
    float area{ 40.0f };

public:

    void SetWidthAndHeight()
    {
        cout << "Width and height? ";
        cin >> width >> height;
    }

    void CalculateCircumference()
    {
        circumference = (2 * width) + (2 * height);
    }

    void CalculateArea()
    {
        area = width * height;
    }

    void PrintCircumference()
    {
        cout << "Circumference: " << circumference << endl;
    }

    void PrintArea()
    {
        cout << "Area: " << area << endl;
    }
};

class Triangle
{
    float base{ 10.0f };
    float height{ 6.0f };
    float area{ 30.0f };

public:

    void SetBaseAndHeight()
    {
        cout << "Base and height? ";
        cin >> base >> height;
    }

    void CalculateArea()
    {
        area = (base * height) / 2.0f;
    }

    void PrintArea()
    {
        cout << "Area: " << area << endl;
    }
};

int main()
{
    #pragma region Variables

    Color4f primaryColor{};
    Distance primaryDistance{};
    Angle primaryAngle{};
    AngularVelocity primaryAngularVelocity{};
    Speed primarySpeed{};
    Velocity primaryVelocity{};
    Circle primaryCircle{};
    Rectangle primaryRectangle{};
    Triangle primaryTriangle{};

    #pragma endregion

    #pragma region Function calls

    primaryColor.SetColor();
    primaryColor.ConvertRange();
    primaryColor.PrintConvertedRange();

    primaryDistance.SetKilometers();
    primaryDistance.ConvertDistance();
    primaryDistance.PrintConvertedDistance();

    primaryAngle.SetRadian();
    primaryAngle.ConvertToDegrees();
    primaryAngle.PrintDegrees();

    primaryAngle.SetDegree();
    primaryAngle.ConvertToRadians();
    primaryAngle.PrintRadians();

    primaryAngularVelocity.SetRotationTime();
    primaryAngularVelocity.CalculateAngularVelocity();
    primaryAngularVelocity.PrintAngularVelocity();

    primarySpeed.SetSpeed();
    primarySpeed.SetElapsedTime();
    primarySpeed.CalculateDistance();
    primarySpeed.PrintDistance();

    primaryVelocity.SetDeltaTime();
    primaryVelocity.CalculateVelocity();
    primaryVelocity.PrintVelocity();

    primaryCircle.SetRadius();
    primaryCircle.CalculateCircumference();
    primaryCircle.CalculateArea();
    primaryCircle.PrintCircumference();
    primaryCircle.PrintArea();

    primaryRectangle.SetWidthAndHeight();
    primaryRectangle.CalculateCircumference();
    primaryRectangle.CalculateArea();
    primaryRectangle.PrintCircumference();
    primaryRectangle.PrintArea();

    primaryTriangle.SetBaseAndHeight();
    primaryTriangle.CalculateArea();
    primaryTriangle.PrintArea();

    #pragma endregion

    return 0;
}