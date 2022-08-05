/*
 * Created by Evan Poon (StewartChicken)
 * 2022-07-28
 * 
 * This sketch will control the mechanisms of a toy 
 * foam dart mini gun. The turret will be operated 
 * with a joy stick. When the joy stick is pressed 'up',
 * the turret will power up and prepare to fire. When 
 * pressed 'down', the turret will power down. When the 
 * joy stick itself is pushed down (like a button), 
 * the turret fires (if it is powered up).
 * There will also be a push-button toggle to switch
 * between manual control mode and sentry mode.
 * In sentry mode, the turret will simply rotate
 * back and forth as if it is scanning/guarding
 * its environment. This sketch will also include 
 * the program to control a stepper motor (turret rotation)
 * as well as the DC motors built into the toy gun.
 */


// Pin assignment
int y = A1;
int x = A0;

int dirPin = 2;
int pulPin = 3;

int powerUpPin = 8;

int buttonReadPin = 7;

int gatSpeedPin = 5;
int gatDir1 = 4;
int gatDir2 = 6;
int mSpeed = 255;

boolean dir = HIGH;

int sentryPulseDelay = 20;
int sentryTurretPauseTime = 3300; 
int sentryTurnRadius = 130;
int manualPulseDelay = 2000;

boolean sentryMode = false;

// Read values from pins
int yVal;
int xVal;

// If in manual mode, is the turret powered up/ready to fire
boolean poweredUp;

int buttonNew;
int buttonOld = 1;

void setup() {

  poweredUp = false;
  
  pinMode(dirPin, OUTPUT);
  pinMode(pulPin, OUTPUT);

  pinMode(y, INPUT);
  pinMode(x, INPUT);

  pinMode(powerUpPin, OUTPUT);

  pinMode(buttonReadPin, INPUT);

  pinMode(12, OUTPUT);

  pinMode(gatSpeedPin, OUTPUT);
  pinMode(gatDir1, OUTPUT);
  pinMode(gatDir2, OUTPUT);

  Serial.begin(115200);

}

void loop() {

  buttonNew = digitalRead(buttonReadPin);
  Serial.println(buttonNew);
  if(buttonOld == 0 && buttonNew == 1){
    switchMode();
  }
  
  buttonOld = buttonNew;

  if(sentryMode){
    digitalWrite(dirPin, dir);
    digitalWrite(powerUpPin, LOW);
    digitalWrite(gatSpeedPin, LOW);
  
    for(int i = 0; i < sentryTurnRadius; i ++){
      digitalWrite(pulPin, LOW);
      digitalWrite(pulPin, HIGH);
      delay(sentryPulseDelay);
    }

    switchDir();
    delay(sentryTurretPauseTime);
  
  }
  
  if(!sentryMode){
    swVal = digitalRead(sw);
    xVal = analogRead(x);
    yVal = analogRead(y);

    if(poweredUp){
      digitalWrite(powerUpPin, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(gatDir1, HIGH);
      digitalWrite(gatDir2, LOW);
      analogWrite(gatSpeedPin, mSpeed);
    }else{
      digitalWrite(powerUpPin, LOW);
      digitalWrite(12, LOW);
      digitalWrite(gatDir1, LOW);
      digitalWrite(gatDir2, HIGH);
      analogWrite(gatSpeedPin, 0);
    }
    
    if(yVal < 100){
      poweredUp = true;
    }
    if(yVal > 900){
      poweredUp = false;
    }

    if(xVal > 600){
      float proportion = float(xVal) / 1023.;
      
      dir = HIGH;
      digitalWrite(dirPin, dir);
      digitalWrite(pulPin, LOW);
      digitalWrite(pulPin, HIGH);
      delayMicroseconds(int((1. / proportion) * float(manualPulseDelay)));

    }else if(xVal < 400){
      float proportion = float(1023 - xVal) / 1023.;
      
      dir = LOW;
      digitalWrite(dirPin, dir);
      digitalWrite(pulPin, LOW);
      digitalWrite(pulPin, HIGH);

      if(xVal == 0){
        delayMicroseconds(manualPulseDelay);
      }else{
        delayMicroseconds(int((1. / proportion) * float(manualPulseDelay)));
      }
      
    }
  }
}

void switchDir(){
  dir = !dir;
}

void switchMode(){
  sentryMode = !sentryMode; 
}
