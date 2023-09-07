const int buttonPin = 2;   
int buttonState = 0;        
int lastButtonState = HIGH; 
bool nameBlinking = false;  
int charIndex = 0;          

char inputName[100];        
int inputIndex = 0;       

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Enter name:");
}

// creating a function blinkdot for blinking name in morse code
void blinkdot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

// creating a function blinkdash for blinking name in morse code
void blinkdash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

// Alphabets in morse code
void morse_encryption(char name) {
  switch (name) {
    case 'a':
      blinkdot();
      blinkdash();
      break;
      
    case 'b':
      blinkdash();
      blinkdot();
      blinkdot();
      blinkdot();
      break;

    case 'c':
      blinkdash();
      blinkdot();
      blinkdash();
      blinkdot();
      break;

    case 'd':
      blinkdash();
      blinkdot();
      blinkdot();
      break;

    case 'e':
      blinkdot();
      break;

    case 'f':
      blinkdot();
      blinkdot();
      blinkdash();
      blinkdot();
      break;

    case 'g':
      blinkdash();
      blinkdash();
      blinkdot();
      break;

    case 'h':
      blinkdot();
      blinkdot();
      blinkdot();
      blinkdot();
      break;

    case 'i':
      blinkdot();
      blinkdot();
      break;

    case 'j':
      blinkdot();
      blinkdash();
      blinkdash();
      blinkdash();
      break;

    case 'k':
      blinkdash();
      blinkdot();
      blinkdash();
      break;

    case 'l':
      blinkdot();
      blinkdash();
      blinkdot();
      blinkdot();
      break;

    case 'm':
      blinkdash();
      blinkdash();
      break;

    case 'n':
      blinkdash();
      blinkdot();
      break;

    case 'o':
      blinkdash();
      blinkdash();
      blinkdash();
      break;

    case 'p':
      blinkdot();
      blinkdash();
      blinkdash();
      blinkdot();
      break;

    case 'q':
      blinkdash();
      blinkdash();
      blinkdot();
      blinkdash();
      break;

    case 'r':
      blinkdot();
      blinkdash();
      blinkdot();
      break;

    case 's':
      blinkdot();
      blinkdot();
      blinkdot();
      break;

    case 't':
      blinkdash();
      break;

    case 'u':
      blinkdot();
      blinkdot();
      blinkdash();
      break;

    case 'v':
      blinkdot();
      blinkdot();
      blinkdot();
      blinkdash();
      break;

    case 'w':
      blinkdot();
      blinkdash();
      blinkdash();
      break;

    case 'x':
      blinkdash();
      blinkdot();
      blinkdot();
      blinkdash();
      break;

    case 'y':
      blinkdash();
      blinkdot();
      blinkdash();
      blinkdash();
      break;

    case 'z':
      blinkdash();
      blinkdash();
      blinkdot();
      blinkdot();
      break;
    default:
      break;
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    nameBlinking = !nameBlinking; 
    charIndex = 0; 
  }

  lastButtonState = buttonState;

  if (nameBlinking) {
    if (inputName[charIndex] != '\0') {
      char y = inputName[charIndex];
      morse_encryption(y);
      delay(1000); 

      charIndex++;
    } else {
      nameBlinking = false; 
    }
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  while (Serial.available() > 0) {
    char incomingChar = Serial.read();
    if (incomingChar == '\n' || inputIndex >= sizeof(inputName) - 1) {
      inputName[inputIndex] = '\0'; 
      inputIndex = 0; 
      Serial.print("name ");
      Serial.print(inputName);
      Serial.print(" blinking");
      nameBlinking = true; 
    } 
    else {
      inputName[inputIndex] = incomingChar;
      inputIndex++;
    }
  }
}