# chaskey-arduino

## Description
Simple implementation of [8-round](https://mouha.be/wp-content/uploads/chaskey-speed.c) & [12-round](https://mouha.be/wp-content/uploads/chaskey12.c) Chaskey MAC Algorithm based on <http://mouha.be/chaskey/>. This project contains libraries and examples that can be used on microcontrollers such as Arduino UNO, Arduino Mega 2560, and NodeMCU ESP8266 compiled using the Arduino IDE software. Tested on Arduino (Uno, Mega 2560), NodeMCU ESP8266, ESP32 DEVKIT V1 DOIT with Arduino IDE 1.8.7.

## References
The source code reference of the library is taken from [Hutorny](https://github.com/hutorny/chaskey) who made the C++ based Chaskey Algorithm and then modified by [Aaron Lindsay](https://github.com/AerialX/chaskey) in 2017. This project is just an adaptation of what has been made into a simple form that can be compiled and run on a microcontroller using Arduino IDE.

## Usage
Run a vector test function with the following syntax for both Chaskey and Chaskey12:
```C++
test_vector();
```

The first four result for 8-round Chaskey at <chaskey.h>
```
8-Round Chaskey Algorithm Test Vector..

Chaskey: E58F2E79AA87CE75	Test Vector: E58F2E79AA87CE75
Chaskey: 7B30A913892CE650	Test Vector: 7B30A913892CE650
Chaskey: 2289DF5577F57F2C	Test Vector: 2289DF5577F57F2C
Chaskey: 64B2DB1BD88076A0	Test Vector: 64B2DB1BD88076A0
...
```

The first four result for 12-round Chaskey at <chaskey12.h>
```
12-Round Chaskey Algorithm Test Vector..

Chaskey12: DD3E1849D6824555	Test Vector: DD3E1849D6824555
Chaskey12: ED1DA89EC93179CA	Test Vector: ED1DA89EC93179CA
Chaskey12: 98FE20A343CD666F	Test Vector: 98FE20A343CD666F
Chaskey12: F6F418ACDD7D9FA1	Test Vector: F6F418ACDD7D9FA1
...
```
