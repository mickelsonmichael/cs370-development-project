#include <HX711.h>

/*
 These two variables define which pin the clock and data out point to.
 When wired "properly", the clock should be green and the data should be blue (to avoid confusion).
 The DAT wire is an input and the CLK wire is an output.

 These should be digital pins, not analog.
*/
#define CLK 6          // green
#define DAT 5          // blue
#define THRESHOLD 20.0 // pounds of litter + waste

// Initialize an instance of the library
HX711 scale;

float previous;
float current;
float delta;

void setup()
{
    Serial.begin(9600);

    // Configure the in/out pins
    scale.begin(DAT, CLK);

    wait("\nEmpty the scale, press a key to tare");
    scale.tare(); // must tare (zero) the scale with nothing on it

    read_weight();

    wait("Place 10 lbs onto the scale, press any key to calibrate");
    // place a 10-lbs weight onto the scale before pressing enter
    // if you do not have a 10 pound weight, change the first parameter of this function
    scale.calibrate_scale(
        10, // the weight of the calibration object
        10  // the number of samples to take
    );

    previous = read_weight();
}

// This is performed repeatedly by the Arduino device
void loop()
{
    current = read_weight();

    if (current - previous > 5) // could probably afford to do an abs() call here
    {
        delay(5000); // wait five seconds

        return; // if more than five pounds has entered the scale since the last reading, then a cat is on it
    }

    if (current > THRESHOLD)
    {
        // do something about the limit being reached
        // e.g. send a request to an API or something
    }

    delay(1000); // Wait a second before continuing

    previous = current
}

// Reads the current weight on the scale
// `get_units` takes in an integer which represents the number of samples to take
// e.g. 10 = take 10 readings and average them
float read_weight()
{
    float value = scale.get_units(10);

    Serial.print("READ: ");
    Serial.println(value);

    return value;
}

// Prints a message to the monitor and waits for user input
void wait(const char *msg)
{
    Serial.println(msg);

    while (!Serial.available())
        ;
    while (Serial.available())
        Serial.read();
}
