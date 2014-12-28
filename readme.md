# Arduino Flash Trigger

Arduino based flash trigger for high speed photography.

## Building

1. Open as a sketch in Arduino IDE (tested with arduino-1.0.5.)
2. Change pin definitions of STATUSLED, SIGIN and FLASH to match hardware setup
3. Set DELAY to desired value
4. Enable or disable debouncing by enabling or commenting the code section
5. Build and flash

## Usage

When starting, the STATUSLED will be "on" indicating that the system is armed. When the system sees a falling edge on the SENSE input, the "fire"-ISR is triggered. The flash is delayed by the amount defined in DELAY and the SENSE-input is debounced if desired. The flash is then fired and the trigger is disarmed. Press the RESET button to arm the trigger for another shot.

Change parameters by changing the code.
