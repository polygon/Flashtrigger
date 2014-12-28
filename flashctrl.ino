// External pins
const int STATUSLED=13; // Status indicator
const int SIGIN=2;      // Sense signal input
const int FLASH=7;      // Flash XSENSE output

// Flash fire delay
const unsigned long DELAY=1900;

// Flash XSYNC low time
const unsigned long FLASHPULSE_TIME=2500;

// State
volatile byte armed = 1;
volatile unsigned long i;

// Flash ISR
void fire()
{ 
  noInterrupts();

  // Delay flash by defined amount
  for (i=0; i < DELAY; i++)
  {
    // Debounce input, sync to last SENSE event
    // Comment this out to sync to first SENSE event
    if (digitalRead(SIGIN) == true)
      i = 0;
  }   
  
  // Pull XSYNC low, fire flash
  if (armed != 0)
    pinMode(FLASH, OUTPUT);
    
  // After delay, pull XSYNC high
  for (i=0; i < FLASHPULSE_TIME; i++) {}
  pinMode(FLASH, INPUT);
  
  // Trigger disarmed, status LED off
  armed = 0;
  digitalWrite(STATUSLED, LOW);
}

void setup()
{ 
  noInterrupts();

  // System armed, turn on status LED
  pinMode(STATUSLED, OUTPUT);
  digitalWrite(STATUSLED, HIGH);

  // Configure sense pin as input 
  pinMode(SIGIN, INPUT); // INPUT_PULLUP

  // Configure flash pin as input (High Impedance)
  pinMode(FLASH, INPUT);
  digitalWrite(FLASH, LOW);

  // Trigger interrupt on falling edge on sense pin
  attachInterrupt(0, fire, FALLING);
  interrupts();
}

// No main loop
void loop()
{}
