/*
   Juniper Robotics - Grow Tower Controller 
*/

//define constants
#define pump_on_time 1                       //on time in seconds
#define pump_off_time 3                      //off time in seconds

//define varaibles
long currentTime = 0, lastTime = 0, secondsCount = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);              //configure LED on circuit board
}

void loop () {
  currentTime = millis();                    //store current millis timer value into currentTime variable
  if (currentTime - lastTime >= 1000) {      //check if it has been 1000ms or more since the pump ran last
    lastTime = currentTime;                  //store current time as last time ran
    if (secondsCount >= pump_off_time) {     //check if pump has been off for the required amount of time (pump_off_time)
      secondsCount = 0;                      //reset minute count to restart pump
    }
    if (secondsCount < pump_on_time) {       //check if pump has been on less than the desired time (pump_on_time)
      digitalWrite(LED_BUILTIN, HIGH);       //turn pump on
    }
    else {  
      digitalWrite(LED_BUILTIN, LOW);        //turn pump off
    }
    secondsCount++;
  }
}
