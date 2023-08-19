// Define durations for dot and dash signals in milliseconds
const int dotDuration = 200;
const int dashDuration = 600;

// Define the pin number for the LED and your name
const int ledPin = 13;
const String myName = "aryan";

// Define Morse code patterns for each lowercase letter
const char *MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Declare variables
volatile int currentIndex = 0;
volatile bool isBlinking = true;  // Start blinking automatically

void setup() {
    pinMode(ledPin, OUTPUT);  // Set LED pin as output
    Serial.begin(9600);       // Initialize serial communication
}

void loop() {
    if (isBlinking) {
        Serial.println(myName);  // Print your name to serial monitor
        blinkName();             // Blink your name in Morse code
        delay(3000);             // Wait for 3 seconds before blinking again
    }
}

// Function to blink a dot
void blinkDot() {
    digitalWrite(ledPin, HIGH);
    delay(dotDuration);
    digitalWrite(ledPin, LOW);
    delay(dotDuration);
}

// Function to blink a dash
void blinkDash() {
    digitalWrite(ledPin, HIGH);
    delay(dashDuration);
    digitalWrite(ledPin, LOW);
    delay(dotDuration);
}

// Function to blink a character using Morse code
void blinkCharacter(char characterToBlink) {
    int index = characterToBlink - 'a';
    if (index >= 0 && index < 26) {
        const char *pattern = MORSE_CODE[index];
        for (int i = 0; pattern[i]; i++) {
            if (pattern[i] == '.') {
                blinkDot();
            } else if (pattern[i] == '-') {
                blinkDash();
            }
            if (pattern[i + 1]) {
                delay(dotDuration);
            }
        }
    }
}

// Function to blink the entire name in Morse code
void blinkName() {
    for (int i = 0; i < myName.length(); i++) {
        blinkCharacter(tolower(myName[i]));
        if (i < myName.length() - 1) {
            delay(700);  // Delay between characters
        }
    }
}
