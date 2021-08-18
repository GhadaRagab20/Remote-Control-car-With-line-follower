# Remote-Control-car-With-line-follower
 RC car controlled by Bluetooth using a mobile application that allows its motion Forward, Backward, Left, Right and rotation around itself left & right, and avoid obstacles using an Ultrasonic sensor, so when the ultrasonic detects an obstacle within a distance of 25 cm. or less , the car stops, moves backward then turns right.
RC car following a track It is controlled by three line followers that emit light and sense if the light bounces back to it or not and give either 0,1 output with a bit of code this can be used to make the car follow a black track that absorbs all the light incoming on it When the car sees a wall it turns and follows the wall until it can see the track again.

## Components:
  #### * Arduino Mega 2560 :
  ![Arduino Mega 2560](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/Arduino%20Mega%202560.jpg)
  
        The Arduino Mega 2560 is a microcontroller board based on the ATmega2560. It has 54 digital input/output pins (of which 14 can be used as PWM outputs), 16 analog inputs, 4               UARTs(hardware serial ports), a 16 MHz crystal oscillator, a USB connection, a power jack, an ICSP header, and a reset button.
        The Arduino Mega 2560 contains everything needed to support the microcontroller; simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter or                 battery to get started. The Arduino Mega is compatible with most shields designed for the Arduino Duemilanove or Diecimila.
        * Arduino Mega 2560 Features:
          * Microcontroller ATmega2560
          * Operating Voltage 5V
          * Input Voltage (recommended) 7-12V
          * Input Voltage (limits) 6-20V
          * Digital I/O Pins 54 (of which 14 provide PWM output)
          * Analog Input Pins 16
          
   #### * L298N Driver
   ![ L298N Driver](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/L298N%20Driver.jpg)

          we use 2 H-bridge.
          The L298N is a dual H-Bridge motor driver Which allows speed and direction control of two DC motors at the same time.
          The module can drive DC motors that have voltage between 5 and 12 v ,with a peak current up to 2A.
          
   #### * DC Motors
   ![ DC Motors](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/DC%20Motors.jpg)
    
       4 Gearbox Motors. 
         * Operating Voltage: 3 , 4.5 , 5 & 12 Vdc
         * No Load Speed: 90 RPM
         * No Load Current: 190mA (250mA max)
         * Max. Torque: 800 gf.cm
         * Gear Ratio: 48:1
       
  #### * HC-05
   ![ HC-05](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/HC-05.jpg)
   
       Very simple Bluetooth module (Based on BC417 Chip) to connect it with your microcontroller , Arduino , Raspberry Pi , or any MCU board using the TTL UART interface. 
 
 #### * Ultrasonic Sensor
  ![Ultrasonic Sensor](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/L298N%20Driver.jpg)
  
       Distance measurement sensor is a low cost full functionality solution for distance measurement applications. 
       The module is based on the measurement of time flight of ultrasonic pulse, which is reflected by an object. 
       The distance to be measured mainly depends on the speed of ultrasonic waves in space or air –which is a constant- and the flight time of the pulse.
       The module performs these calculations and outputs a pulse width depends on the measured distance, this pulse is easily interfaced to any microcontroller. 

 #### * Line follower:
  ![Line follower](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/line%20follower.png)
  
       The Line Follower sensor is an add-on for the RC car that gives it the ability to detect lines or nearby objects. 
       The sensor works by detecting reflected light coming from its own infrared LED. 
       The sensor has a 3-pin header which connects directly to the Arduino Main board via female to female jumper wires.
       
 #### * Flame sensor
  ![Flame sensor](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/Flame%20Sensor.jpg)
  
       The flame sensor can detect flame and infrared light sources with wavelengths ranging from 760 nm to 1100 nm. It uses the LM393 comparator chip, which gives a clean, stable
       digital output signal and driving ability of 15 mA.
       This flame detector that can be  used in fire alarms and other fire detecting devices 
       
 #### * Buzzer
  ![ Buzzer](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/Buzzer.png)
  
        A buzzer or beeper is an audio signalling device, which may be mechanical, electromechanical, or piezoelectric. Typical uses of buzzers and beepers include alarm devices, 
        timers, and confirmation of user input such as a mouse click or keystroke.
        
 #### * Car Chassis
  ![Car Chassis](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/Car%20Chassis.jpg)
  
        Made from acrylic. 
        All of the car components are mounted on it.

#### * Battery Holder
 ![Battery Holder](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/Battery%20Holder.jpg)
 
#### * Lithium Battery
 ![Lithium Battery](https://github.com/GhadaRagab20/Romot-Control-car-With-line-follower/blob/master/images/Lithium%20Battery.png)
 
       3 Rechargeable Lithium ion Battery
       3.7v 5000mah 



