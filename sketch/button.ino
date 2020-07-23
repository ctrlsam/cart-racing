const int button = 2;

void setup_button() {                
  pinMode(button, OUTPUT); 
}

bool isButtonPress(){
    return digitalRead(button) == 1;
}