#ifndef DRIVE_H
#define DRIVE_H
 





class OmniWheelDrive
{
private:

    double wheelRadius;
    double wheelSeparation;
    double wheelAngle;

public:
    OmniWheelDrive(double radius, double separation)
    {
        wheelRadius = radius;
        wheelSeparation = separation;
        wheelAngle = 120.0 * (PI / 180.0);
    }

    void calculateWheelSpeeds(double xVel, double yVel, double zAngular, double wheelSpeeds[3])
    {
        wheelSpeeds[0] = (-xVel - (wheelSeparation / 2.0) * zAngular) / wheelRadius;
        wheelSpeeds[1] = (-xVel * cos(wheelAngle) + yVel * sin(wheelAngle) - (wheelSeparation / 2.0) * zAngular) / wheelRadius;
        wheelSpeeds[2] = (-xVel * cos(wheelAngle) - yVel * sin(wheelAngle) - (wheelSeparation / 2.0) * zAngular) / wheelRadius;
    }
};
#endif 