#define left_f_pwm 2
#define left_f_DIR 22
#define right_f_pwm 3
#define right_f_DIR 23
#define left_b_pwm 4
#define left_b_DIR 24
#define right_b_pwm 5
#define right_b_DIR 25
#define pwmActuator_1 6
#define pwmActuator_2 7
#define dirActuator_1 26
#define dirActuator_2 27
#define dirDiggingEffector 8
#define pwmDiggingEffector 28
#define pwmArmRotation 10
#define dirArmRotation 30
#define pwmCameraGimbal_1 9
#define dirCameraGimbal_1 29
#define pwmCameraGimbal_2 11
#define dirCameraGimbal_2 31


int speed=10;
int pww=150;
int pew=0;
int speedLimit = 250;
int speedActuators =0;
int speedActuatorsLimit =220;
int speedGimble = 75;
int armSpeed =180;
// int speedActuatorsLimit = 150;
// int speedGimbleLimit = 150;
int DIR;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(left_f_pwm,OUTPUT);
  pinMode(left_f_DIR,OUTPUT);
  pinMode(right_f_pwm,OUTPUT);
  pinMode(right_f_DIR,OUTPUT);
  pinMode(left_b_pwm,OUTPUT);
  pinMode(left_b_DIR,OUTPUT);
  pinMode(right_b_pwm,OUTPUT);
  pinMode(right_b_DIR,OUTPUT);
  analogWrite(left_f_pwm,0);
  analogWrite(right_f_pwm,0);
  analogWrite(left_b_pwm,0);
  analogWrite(right_b_pwm,0);
  analogWrite(pwmActuator_1,0);
  analogWrite(pwmActuator_2,0);
  analogWrite(pwmDiggingEffector,0);
  analogWrite(pwmArmRotation,0);
  analogWrite(pwmCameraGimbal_1,0);
  analogWrite(pwmCameraGimbal_2,0);
   
}
void speedUpWheels(){
  if(speed<speedLimit){
    speed++;
  }
    analogWrite(left_f_pwm,speed);
    analogWrite(right_f_pwm,speed);
    analogWrite(left_b_pwm,speed);
    analogWrite(right_b_pwm,speed);
    delay(12);
}
void speedUpActuators(){
  if(speedActuators<speedActuatorsLimit){
    speedActuators++;
  }
    analogWrite(left_f_pwm,speedActuators);
    analogWrite(right_f_pwm,speedActuators);
    analogWrite(left_b_pwm,speedActuators);
    analogWrite(right_b_pwm,speedActuators);
    delay(1000);
}
void speedDownWheels(){
  if(speed>0){
    speed--;
  }
  analogWrite(left_f_pwm,speed);
  analogWrite(right_f_pwm,speed);
  analogWrite(left_b_pwm,speed);
  analogWrite(right_b_pwm,speed);
  delay(12);
}

void speedDownActuators(){
  if(speedActuators>0){
    speedActuators--;
  }
    analogWrite(left_f_pwm,speedActuators);
    analogWrite(right_f_pwm,speedActuators);
    analogWrite(left_b_pwm,speedActuators);
    analogWrite(right_b_pwm,speedActuators);
    delay(1000);
}
void movement(int DIR)
{
  if(DIR == 119)
    {
      digitalWrite(left_f_DIR,HIGH);
      digitalWrite(right_f_DIR,LOW);
      digitalWrite(left_b_DIR,HIGH);
      digitalWrite(right_b_DIR,LOW);
      
//      analogWrite(left_f_pwm,speed);
//      analogWrite(right_f_pwm,speed);
//      analogWrite(left_b_pwm,speed);
//      analogWrite(right_b_pwm,speed);
      Serial.println("Forward");
      speedUpWheels();

    }
     else if(DIR==115)
    {
      digitalWrite(left_f_DIR,LOW);
      digitalWrite(right_f_DIR,HIGH);
      digitalWrite(left_b_DIR,LOW);
      digitalWrite(right_b_DIR,HIGH);
//      analogWrite(left_f_pwm,speed);
//      analogWrite(right_f_pwm,speed);
//      analogWrite(left_b_pwm,speed);
//      analogWrite(right_b_pwm,speed);
      Serial.println("Backward");
      speedUpWheels();
    }
    else if(DIR==100)
    {
      digitalWrite(left_f_DIR,HIGH);
      digitalWrite(right_f_DIR,HIGH);
      digitalWrite(left_b_DIR,HIGH);
      digitalWrite(right_b_DIR,HIGH);
      Serial.println("RIGHT");
//      analogWrite(left_f_pwm,speed);
//      analogWrite(right_f_pwm,speed);
//      analogWrite(left_b_pwm,speed);
//      analogWrite(right_b_pwm,speed);
      
      speedUpWheels();
    }
    else if(DIR==97)
    {
      digitalWrite(left_f_DIR,LOW);
      digitalWrite(right_f_DIR,LOW);
      digitalWrite(left_b_DIR,LOW);
      digitalWrite(right_b_DIR,LOW);
      Serial.println("LEFT");
      speedUpWheels();
      
    }
    else if(DIR==105){
      digitalWrite(dirActuator_1,LOW);
      speedUpActuators();
    }
    else if(DIR==121){
      digitalWrite(dirActuator_1,HIGH);
      speedUpActuators();
    }
    else if(DIR==117){
      digitalWrite(dirActuator_2,LOW);
      speedUpActuators();
    }
    else if(DIR==111){
      digitalWrite(dirActuator_2,HIGH);
      speedUpActuators();
    }
    else if(DIR==114){
      digitalWrite(dirArmRotation,HIGH);
      analogWrite(pwmArmRotation,armSpeed);
    }
    else if(DIR==116){
      digitalWrite(dirArmRotation,LOW);
      analogWrite(pwmArmRotation,armSpeed);
    }
    else if(DIR==102){
      digitalWrite(dirCameraGimbal_1,LOW);
      analogWrite(pwmCameraGimbal_1,speedGimble);
    }
    else if(DIR==103){
      digitalWrite(dirCameraGimbal_1,HIGH);
      analogWrite(pwmCameraGimbal_1,speedGimble);
    }
    else if(DIR==109){
      digitalWrite(dirDiggingEffector,HIGH);
      analogWrite(pwmDiggingEffector,75);
    
    }
    else if(DIR==108){
      digitalWrite(dirDiggingEffector,LOW);
      analogWrite(pwmDiggingEffector,75);
    }
    else if(DIR==122){
      analogWrite(left_f_pwm,0);
      analogWrite(right_f_pwm,0);
      analogWrite(left_b_pwm,0);
      analogWrite(right_b_pwm,0);
      analogWrite(pwmActuator_1,0);
      analogWrite(pwmActuator_2,0);
      analogWrite(pwmDiggingEffector,0);
      analogWrite(pwmArmRotation,0);
      analogWrite(pwmCameraGimbal_1,0);
    }
    else if (DIR==113){
        analogWrite(left_f_pwm, pww);
        analogWrite(right_f_pwm, pww);
        analogWrite(left_b_pwm, pww);
        analogWrite(right_b_pwm, pww);
        }


    
    else if(DIR==98){
        analogWrite(left_f_pwm, pew);
        analogWrite(right_f_pwm, pew);
        analogWrite(left_b_pwm, pew);
        analogWrite(right_b_pwm, pew);
        }
    //   speedDownWheels();
    //   // speedDownGimble();
    //   // speedDownActuators();
      
    // }

    return;
  
}



void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
  DIR=Serial.read();
  movement(DIR);
  }
  // else{
  //   speedDownWheels();
  //   speedDownActuators();
  //   analogWrite(left_f_pwm,0);
  //   analogWrite(pwmDiggingEffector,0);
  //   analogWrite(pwmArmRotation,0);
  //   analogWrite(pwmCameraGimbal_1,0);


  // }

}