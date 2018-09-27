# Inverted Pendulum Controls
Arduino code for controlling an inverted pendulum on a fixed pin with torque from an electric motor. This is done with accelerometer feedback and state space representation.

## InvertedPendulum.ino
Because the arduino compiler is quirky the compiled file needs to be in a folder of the same name. This means that main.ino isn't a viable file name and so instead we get this.

## Accelerometer.h
A header that develops an Accelerometer class with a few functions, ReadX, ReadY, ReadZ, and GetTheta, all for getting data from the sensor, as well as Debug() which prints raw values for X and Y.
