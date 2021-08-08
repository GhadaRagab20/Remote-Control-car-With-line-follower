# Remote-Control-car-With-line-follower
 RC car controlled by Bluetooth using a mobile application that allows its motion Forward, Backward, Left, Right and rotation around itself left & right, and avoid obstacles using an Ultrasonic sensor, so when the ultrasonic detects an obstacle within a distance of 25 cm. or less , the car stops, moves backward then turns right.
RC car following a track It is controlled by three line followers that emit light and sense if the light bounces back to it or not and give either 0,1 output with a bit of code this can be used to make the car follow a black track that absorbs all the light incoming on it When the car sees a wall it turns and follows the wall until it can see the track again.

Components:
  - Arduino Mega 2560 : 
        The Arduino Mega 2560 is a microcontroller board based on the ATmega2560. It has 54 digital input/output pins (of which 14 can be used as PWM outputs), 16 analog inputs, 4           UARTs(hardware serial ports), a 16 MHz crystal oscillator, a USB connection, a power jack, an ICSP header, and a reset button.
        The Arduino Mega 2560 contains everything needed to support the microcontroller; simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter or               battery to get started. The Arduino Mega is compatible with most shields designed for the Arduino Duemilanove or Diecimila.
        *Arduino Mega 2560 Features:
          -Microcontroller ATmega2560
          -Operating Voltage 5V
          -Input Voltage (recommended) 7-12V
          -Input Voltage (limits) 6-20V
          -Digital I/O Pins 54 (of which 14 provide PWM output)
           -Analog Input Pins 16
   - L298N Driver
          we use 2 H-bridge.
          The L298N is a dual H-Bridge motor driver Which allows speed and direction control of two DC motors at the same time .The module can drive DC motors that have voltage                 between 5 and 12 v ,with a peak current up to 2A.
   - DC Motors
       4 Gearbox Motors. 
       -Operating Voltage: 3 , 4.5 , 5 & 12 Vdc
       -No Load Speed: 90 RPM
       -No Load Current: 190mA (250mA max)
       -Max. Torque: 800 gf.cm
       -Gear Ratio: 48:1
   - 
     



