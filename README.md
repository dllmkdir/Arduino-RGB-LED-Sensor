# Arduino-RGB-LED-Sensor
This is a little project to control a RGB LED with a RGB sensor.
The RGB sensor was connected as:

* s0=>8;
* s1=>9;
* s2=>10;
* s3=>11;
* out=>12;
* OE=>GND


There are two main programs(both do the same function):
## PWMColor
This program sets RGB values with a user generated PWM signal. In practice, this program performs incredibly well with blue and green detection at a great distance. One of the main disadvantages of this program is that red detection is not so sensitive as the two color previously mentioned. The project was tested in a dark room.
## RGBSensor
This program sets RGB parameters using the AnalogWrite() function for the PWM pins of the Arduino Nano. In practice, this program performed incredibly good with all the colors. The only withdrawal is that the reflective object needs to stay closer to the sensor, but it is more accurrate.
