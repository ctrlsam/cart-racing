const int buzzer = 12;

void setup_buzz(){
    pinMode(buzzer, OUTPUT);
}

void buzz(int length){
    digitalWrite(buzzer, HIGH);
    delay(length);
    digitalWrite(buzzer, LOW);
}
