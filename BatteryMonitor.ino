//analogRead(A16)

//timer interrupt every minute or so ? 

// if battery low, alarm info running red leds once

// if baterry too low , go sleep

// if battery too low and awake, blink leds red and go to sleep // untill charged or plugged

// Timer 1 cant be used with bluetooth or wireless!!! ? ? s


volatile int interruptCounter;
int totalInterruptCounter;
 
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
 
void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
 
}
 
void setupBatMon() {
  
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true); // << this is the timeee to check battery 
  timerAlarmEnable(timer);
 
}
 
void loopBatMon() {
 
  if (interruptCounter > 0) {
 
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
 
    totalInterruptCounter++;
 
    Serial.print("An interrupt as occurred. Total number: ");
    Serial.println(totalInterruptCounter);
    Serial.print("battery level iz : " );
    Serial.println( analogRead(A7) );
    BTprint("battery level iz : " + String(analogRead(A7)) );
  }
}
