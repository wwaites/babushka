# babushka

This program takes packets receive over the network by UDP to
the broadcast address and copies them to the serial port for 
controlling a Dimension Engineering Sabertooth 2x60 motor 
controller.

Customisation should be done in `src/project.h` and there is a
template version in the distribution.

## Building

Building needs platformio for the build and several libraries:

    - EspSoftwareSerial

which can be installed with "platformio lib install foo"

There is a Makefile that will wrap calls to platformio because
I can never remember them. So "make", "make upload" should work.
Also "make IPADDR=192.0.2.1 ota" should work for updating the
firmware over the network.

