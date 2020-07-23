
bool started = false;       // has countdown started?
const float timer = 120.0f; // countdown time (s)
const int tick = 100;       // update rate (ms)

float timeFromStart;
float timerDecrease;
int lastBeep;

void setup(){
    Serial.begin(9600); // required to print

    setup_buzz();
    //buzz(500);

    timeFromStart = timer;
    timerDecrease = (float) tick/1000;
}

void loop(){

    if (isButtonPress()){
        Serial.println("Started");
        started = true;
    }

    // Countdown
    if (started && timeFromStart >= 0.0){
      
        Serial.println(timeFromStart);
        
        timeFromStart -= timerDecrease;
        const int currentSecond = int(timeFromStart);
        
        // Avoids beep spam
        if (lastBeep != currentSecond){

          // Beep if time to do so...
          if (isBeepTime(currentSecond)) {
            
            lastBeep = currentSecond;
          }
          
        }
        
        
    }

    // Race
    else if (started){
      // GPS Stuff here
    }

    delay(tick); // sleep

}

bool isBeepTime(int now){
    // Check if should beep now
  
    if (now == int(timer/2)){
        buzz(100);
        return true;
    }
    if (now == int(timer/4)){
        buzz(100);
        return true;
    }
    if (now == int(timer/8)){
        buzz(100);
        return true;
    }
    if (now <= 3 && now > 0){
        buzz(100);
        return true;
    }
    if (now <= 0){
        buzz(300);
        return true;
    }
    else{
        return false;
    }

}
