//Mode Selector

int M=39;

//line follower direction

int N=38;

//Motors DECLARATION

int Motor_frontRight_Enable = 7 ;

int Motor_frontRight_forward = 27 ;

int Motor_frontRight_backward = 26 ;


int Motor_frontLeft_Enable = 9;

int Motor_frontLeft_forward = 29;

int Motor_frontLeft_backward = 28;


int Motor_backRight_Enable = 8 ;

int Motor_backRight_forward = 25;

int Motor_backRight_backward = 24 ;


int Motor_backLeft_Enable = 10;

int Motor_backLeft_forward = 23;

int Motor_backLeft_backward = 22;


int Speed =60;                             

int velocity =90;                         


//line follower 


int sensorleft=44;;

int sensorcenter=45;

int sensorright=46;


int l1;

int l2;

int l3;


//Bluetooth

char input;

 

//LEDS

int ledred1 = 12;

int ledred2 = 11;

//int ledyellow = 32;*/

int j=0,i=0;


//ULTASONIC

int echo = 34;

int trig = 32;

int duration;

int distance;


//Flame sensor and Buzzer

int sensorPin = A15; // select the input pin for the LDR.

int sensorValue = 0; // variable to store the value coming from the senso

int buzzer = 6; // Output pin for Buzzer


void setup()

{

   

  Serial.begin(9600);


  //RIGHT Motors

  pinMode(Motor_frontRight_Enable, OUTPUT);

  pinMode(Motor_backRight_Enable, OUTPUT);

  

  pinMode(Motor_frontRight_forward, OUTPUT);

  pinMode(Motor_frontRight_backward, OUTPUT);

  pinMode(Motor_backRight_forward, OUTPUT);

  pinMode(Motor_backRight_backward, OUTPUT);



  //LEFTMotors

  pinMode(Motor_frontLeft_Enable, OUTPUT);

  pinMode(Motor_backLeft_Enable, OUTPUT);

  

  pinMode(Motor_frontLeft_forward, OUTPUT);

  pinMode(Motor_frontLeft_backward, OUTPUT);

  pinMode(Motor_backLeft_forward, OUTPUT);

  pinMode(Motor_backLeft_backward, OUTPUT);



  //LEDS

  pinMode(ledred1, OUTPUT);

  pinMode(ledred2, OUTPUT);

 // pinMode(ledyellow, OUTPUT);


//Ultrasonic

 pinMode(trig,OUTPUT);

 pinMode(echo,INPUT);

 

 //line follower

 pinMode(sensorleft,INPUT);

 pinMode(sensorcenter,INPUT);

 pinMode(sensorright,INPUT);

 

 //Mode selector

 pinMode(M,OUTPUT);


 //Buzzer

 pinMode(buzzer,OUTPUT);

}


void loop()

{

 int S=digitalRead(M);

  Serial.println(S);

  int k=digitalRead(N);

  Serial.println(k);

  if(S==0)

  {

  //phase 1

   char input = Serial.read();

   Serial.println(input);

    i=1;

    switch (input)

    {

      case 'F':

       forward();

       led_off();

       j=0;

       break;   


      case 'B':

        backward();

        j=1;

        break;

        

      case 'R':

        right();

        led_off();

        j=0;

        break;


      case 'L':

        left();

        led_off();

        j=0;

        break;


      case 'S':

        STOP();

        led_on();

        j=0;

        break;


       case '+':

        incSpeed();

        j=0;

        break; 

      

      case '-':

        decSpeed();

         j=0;

        break;


     case 'r':

       led_off();

      RightForward();

       j=0;

      break;


     case'l':

      led_off();

      LeftForward();

      j=0;

      break;

    }

    Serial.println(input);

    Serial.println(Speed);

    if(i==1)

    {

    distance=Distance();  

    if (distance<=40&&distance>0 )

       {

        STOP();

        delay(500);

        backward();

        delay(500);

        RightForward();

        delayMicroseconds(20);

       }


       //Flame detection

 sensorValue = analogRead(sensorPin);

Serial.println( sensorValue);

if (sensorValue < 300)

{

Serial.println("Fire Detected");

analogWrite(buzzer,255);

delay(1000);

analogWrite(buzzer,0);

}

                                        //end of flame detection

    }

    Serial.print("dis ");

    Serial.println(distance);

    if (j==1)

       Blink();     

  }

                                              //phase 2

                     //Black-->1 ,any color-->0

else if(S==1)

{

l1=digitalRead(sensorleft);

l2=digitalRead(sensorcenter);

l3=digitalRead(sensorright);

Serial.println(l1);

Serial.println(l2);

Serial.println(l3);


if(l1==0&&l3==1)                                                 //right turn

{

  while(true)

  {

    right();

    l1=digitalRead(sensorleft);

    l2=digitalRead(sensorcenter);

    l3=digitalRead(sensorright);

    if(l2==1) break;

    }

}

else if((l1==1&&l3==0))                            //left turn

{

  while(true)

  {

    left();

    l1=digitalRead(sensorleft);

    l2=digitalRead(sensorcenter);

    l3=digitalRead(sensorright);

      if(l2==1) break;

    }  

}

else if((l1==0&&l2==1&&l3==0)||(l1==1&&l2==1&&l3==1))                        

{

  forward();

   l1=digitalRead(sensorleft);

   l2=digitalRead(sensorcenter);

   l3=digitalRead(sensorright);

}

else if((l1==0&&l2==0&&l3==0))             

{

  forward();

} 


else if(l1==1&&l2==1&&l3==1)

{

  forward();

}

 distance=Distance();  

    if (distance<=30&&distance>0&&k==1 )                //When the track is clock wise direction 

       {

        STOP();

        delay(500);

        backward();

        delay(500);

        RightForward2();

        delayMicroseconds(20);

       }

       

            //Flame detection        

sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue < 300)

{

Serial.println("Fire Detected");

analogWrite(buzzer,255);

delay(1000);

analogWrite(buzzer,0);

}

//end of flame detection


   else if (distance<=25&&distance>0&&k==0 )          // When the track is anti-clock wise

       {

        STOP();

        delay(500);

        backward();

        delay(500);

        LeftForward2();

        delayMicroseconds(20);

       }

}

  

                                           //Flame detection (Bonus)

sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue < 300)

{

Serial.println("Fire Detected");

analogWrite(buzzer,255);

delay(1000);

analogWrite(buzzer,0);

}                                                       //end of flame detection

}



// FUNCTIONS


//FORWARD FUNCTION


void forward()

{

  analogWrite(Motor_frontRight_Enable , Speed);         

  analogWrite(Motor_backRight_Enable , Speed);

  analogWrite(Motor_frontLeft_Enable , Speed);

  analogWrite(Motor_backLeft_Enable , Speed);

  

  digitalWrite(Motor_frontRight_forward , HIGH);

  digitalWrite(Motor_frontRight_backward , LOW);

  digitalWrite(Motor_backRight_forward , HIGH);

  digitalWrite(Motor_backRight_backward , LOW);

  

  digitalWrite(Motor_frontLeft_forward , HIGH);

  digitalWrite(Motor_frontLeft_backward , LOW);

  digitalWrite(Motor_backLeft_forward , HIGH);

  digitalWrite(Motor_backLeft_backward , LOW);

}


//BACKWARD FUNCTION WITH BUZZER


void backward()

{

  analogWrite(Motor_frontRight_Enable ,velocity );

  analogWrite(Motor_backRight_Enable,velocity );

  analogWrite(Motor_frontLeft_Enable ,velocity );

  analogWrite(Motor_backLeft_Enable , velocity);

  

  digitalWrite(Motor_frontRight_forward , LOW);

  digitalWrite(Motor_frontRight_backward , HIGH);

  digitalWrite(Motor_backRight_forward , LOW);

  digitalWrite(Motor_backRight_backward , HIGH);

  

  digitalWrite(Motor_frontLeft_forward , LOW);

  digitalWrite(Motor_frontLeft_backward , HIGH);

  digitalWrite(Motor_backLeft_forward , LOW);

  digitalWrite(Motor_backLeft_backward , HIGH);


     analogWrite(buzzer,255);

     delay(10);

     analogWrite(buzzer,0);

}


//left FUNCTION


void left()

{

  analogWrite(Motor_frontRight_Enable , velocity);

  analogWrite(Motor_backRight_Enable, velocity);

  analogWrite(Motor_frontLeft_Enable ,velocity*0.25);                   

  analogWrite(Motor_backLeft_Enable ,velocity*0.25);                     

  

  digitalWrite(Motor_frontRight_forward , HIGH);

  digitalWrite(Motor_frontRight_backward , LOW);

  digitalWrite(Motor_backRight_forward , HIGH);

  digitalWrite(Motor_backRight_backward , LOW);

  

  digitalWrite(Motor_frontLeft_forward , LOW);

  digitalWrite(Motor_frontLeft_backward , HIGH);

  digitalWrite(Motor_backLeft_forward , LOW);

  digitalWrite(Motor_backLeft_backward , HIGH);

}


//right FUNCTION


void right()

{

  analogWrite(Motor_frontRight_Enable , velocity*0.25);       

  analogWrite(Motor_backRight_Enable, velocity*0.25);       

  analogWrite(Motor_frontLeft_Enable , velocity);     

  analogWrite(Motor_backLeft_Enable , velocity);      

  

  digitalWrite(Motor_frontRight_forward , LOW);

  digitalWrite(Motor_frontRight_backward , HIGH);

  digitalWrite(Motor_backRight_forward , LOW);

  digitalWrite(Motor_backRight_backward , HIGH);

  

  digitalWrite(Motor_frontLeft_forward , HIGH);

  digitalWrite(Motor_frontLeft_backward , LOW);

  digitalWrite(Motor_backLeft_forward , HIGH);

  digitalWrite(Motor_backLeft_backward , LOW);


}

//RIGHT FORWARD

 void RightForward()

 {

  right();

  delay(1200);

  forward();

 }

 void RightForward2()

 {

  right();

  delay(500);

  forward();

 }


//LEFT FORWARD

 void LeftForward()

  {

    left();

    delay(1200);

    forward();

  }

//LEFT FORWARD 2

 void LeftForward2()

  {

    left();

    delay(650);

    forward();

  }

//STOP FUNCTION


void STOP()

{

  analogWrite(Motor_frontRight_Enable , 0);

  analogWrite(Motor_backRight_Enable, 0);

  analogWrite(Motor_frontLeft_Enable , 0);

  analogWrite(Motor_backLeft_Enable , 0);

  

  digitalWrite(Motor_frontRight_forward , LOW);

  digitalWrite(Motor_frontRight_backward , LOW);

  digitalWrite(Motor_backRight_forward , LOW);

  digitalWrite(Motor_backRight_backward , LOW);

  

  digitalWrite(Motor_frontLeft_forward , LOW);

  digitalWrite(Motor_frontLeft_backward , LOW);

  digitalWrite(Motor_backLeft_forward , LOW);

  digitalWrite(Motor_backLeft_backward , LOW);

}


//DECREASE

void decSpeed ()

{

  if (Speed<=255&&Speed>0)

  {

  Speed=Speed-5;

  }

  }


//INCREASE

  void incSpeed ()

{

  if (Speed<255&&Speed>=0)

 {

  Speed=Speed+5;

 } 

  }


//Distance 

int Distance()

{

 digitalWrite(trig,LOW);

  delayMicroseconds(2);

  digitalWrite(trig,HIGH);

  delayMicroseconds(10);

  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);

  //distance=duration*0.034/2;

  distance=(duration/2)/29.1;

    return distance;


}


//LED Blink

void Blink()

{


  

  digitalWrite(ledred1, HIGH);   

  digitalWrite(ledred2, HIGH);                    

  delay(500); 

                        

  digitalWrite(ledred1, LOW);                   

  digitalWrite(ledred2, LOW);    

  delay(500);                    

}



//LED ON

void led_on()

{

  digitalWrite(ledred1, HIGH);   

  digitalWrite(ledred2, HIGH);                            

  }



//LED OFF

void led_off()

{

   digitalWrite(ledred1, LOW);                   

  digitalWrite(ledred2, LOW);                              

  }
