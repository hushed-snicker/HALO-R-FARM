/* HALO:R FARM
  This sketch is made to farm credits with a modified 360 controller
*/

// Config for Setup
const int A_TOGGLE = 1; // A toggle pin
const int START_TOGGLE = 4; // START toggle pin
const int D_UP_TOGGLE = 7; // D-Pad UP toggle pin

const int A_TEST = 2; //A test pin
const int START_TEST = 5; // START test pin
const int D_UP_TEST = 8; // D-Pad UP test pin

const int PRESS_TIME = 2; // Button Press time in seconds (Multiply by 1000 in delay() use for seconds instead of miliseconds)

// Config for Debug
const int BAUD_RATE = 9600; // serial communications baud rate
const int STABILITY_DELAY = 1;

// Other variables used in sketch
int buttonStateStart = 0;
int buttonStateA = 0;
int buttonStateDUp = 0;
int buttonStateAll = 0;

//First Part ran by arduino
void setup() {
  
  // Start serial output
  Serial.begin(BAUD_RATE);
  
  // Initialize output pins
  pinMode(A_TOGGLE, OUTPUT);
  pinMode(START_TOGGLE, OUTPUT);
  pinMode(UP_TOGGLE, OUTPUT);
  
}

//main loop decleration for arduino
void loop() {
  
  //Press START
  Serial.write('[INFO] Pressing Start');
  press_start();
  
  //Press A
  Serial.write('[INFO] Pressing A');
  press_a();
  
  //press D-Pad UP
  Serial.write('[INFO] Pressing Up');
  press_d_up();
  
  //Press A
  Serial.write('[INFO] Pressing A');
  press_a();
  
}

//Press START
void press_start() {
  
  //debug info
  Serial.write('[DEBUG]Checking all button states');
  
  //Checks the state of the buttons
  check_button_state_all();
  
  if (buttonStateAll = 0) {
    
    //debug info
    Serial.write('[DEBUG] Simulating Press');
    
    //Press start
    digitalWrite(START_TOGGLE, HIGH);
    delay(PRESS_TIME * 1000);
    digitalWrite(START_TOGGLE, LOW);
    delay(STABILITY_DELAY);
    
  }
  
  else {
    
    //debug info
    Serial.write('[ERROR] Failed pressing Start!');
    
  }
  
  
}

//Press A
void press_a() {
  
  //debug info
  Serial.write('[DEBUG] Checking all button states');
  
  // Check button states
  check_button_state_all();
  
  if (buttonStateAll = 0) {
    
    //debug info
    Serial.write('[DEBUG] Simulating Press');
    
    //Press A
    digitalWrite(A_TOGGLE, HIGH);
    delay(PRESS_TIME * 1000);
    digitalWrite(A_TOGGLE, LOW);
    delay(STABILITY_DELAY);
    
  }
  
  else {
    
    //debug info
    Serial.write('[ERROR] Failed pressing A!');
  }
  
}

//Press D-Pad UP
void press_d_up() {
  
  //debug info
  Serial.write('[DEBUG] Checking all button states');
  
  // Check button states
  check_button_state_all();
  
  if (buttonStateAll = 0) {
    
    //debug info
    Serial.write('[DEBUG] Simulating Press');
    
    //Press A
    digitalWrite(D_UP_TOGGLE, HIGH);
    delay(PRESS_TIME * 1000);
    digitalWrite(D_UP_TOGGLE, LOW);
    delay(STABILITY_DELAY);
    
  }
  
  else {
    
    //debug info
    Serial.write('[ERROR] Failed pressing D-Pad Up!');
  }
  
}

//Checks the button state of all the buttons
//Changes global var buttonStateAll to:
//  0: All buttons off
//  1: At least one button on
void check_button_state_all() {
  
  //Debug info
  Serial.write('[DEBUG] Checking Button States');
  
  //Checks all the button states
  check_button_state_start();
  check_button_state_a();
  check_button_state_d_up();
  
  if (buttonStateStart + buttonStateA + buttonStateDUp > 0) {
    
    //Toggle Global var and print some info
    Serial.write('[INFO] A button is being pressed');
    buttonStateAll = 1;
    
  }
  
  else {
    
    //Toggle Global Var and print some info
    Serial.write('[INFO] No buttons are being pressed');
    buttonStateAll = 0;
    
  }
  
  delay(STABILITY_DELAY);  //delay for stability
  
}

// Check START button state function
void check_button_state_start() {
  
  if (START_TEST = LOW) { //if test pin is low
    
    buttonStateStart = 0; //set state to 0 (off)
    
  }
  
  else if (START_TEST = HIGH) {
    
    buttonStateStart = 1;
    
  }
  else {
    
    //debug info
    Serial.write('[ERROR] Start State Test Error');
    
  }
  
}

//Check A button state function
void check_button_state_a() {
  
  if (A_TEST = LOW) {
    
    buttonStateA = 0;
    
  }
  
  else if (A_TEST = HIGH) {
    
    buttonStateA = 1;
    
  }
  
  else {
    
    //debug info
    Serial.write('[ERROR] A State Test Error');
    
  }
  
}

//Check D-Pad UP button state function
void check_button_state_d_up() {
  
  if (D_UP_TEST = LOW) {
    
    buttonStateDUp = 0;
    
  }
  
  else if (D_UP_TEST = HIGH) {
    
    buttonStateDUp = 1;
    
  }
  
  else {
    
    //debug info
    Serial.write('[ERROR] D-Pad Up State Test Error');
    
  }
  
}
