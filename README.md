# CS 370 - Development Project

The goal of this project is to utilize a small, IoT device to signal whether or not a cat's (or cats') litter box is above a certain capacity. This will increase the cleanliness of the litter box by informing the owner (either via text or an LED) that the box is too full and needs to be cleaned.

## Current Progress

- All parts have been purchased, including tools and an empty litter box
- The connections are all soldered and verified to be working
- The board can accept new code and has some basic weight sensing code already on-board

## Next Steps

1. Shore up the logic on when something is on the scale or not
2. Use the [WiFi library](https://github.com/arduino-libraries/ArduinoHttpClient) to hook the board into a network
3. Decide whether to use IoT Hub or a Lambda/Function to send notifications
    - Probably will end up being whichever is free or cheaper
4. Hook up logic to either [send a message to IoT Hub](https://github.com/arduino/ArduinoCloudProviderExamples) or [send an HTTP request to a Function/Lambda](https://github.com/arduino-libraries/ArduinoHttpClient)
5. _Bonus_: Utilize the [on-board LED (e.g. `LED_BUILTIN`)](https://www.arduino.cc/reference/en/language/variables/constants/constants/) or the purchased LED screen
    - Purchased screen will require additional connectors, apparently, so this may not be the simplest option

## Useful Links

- [Original Guide](https://learn.sparkfun.com/tutorials/load-cell-amplifier-hx711-breakout-hookup-guide#hardware-hookup-)
- [HX711 GitHub Repo](https://github.com/RobTillaart/HX711)
- [Guide to hooking up to IoT hubs in the Cloud](https://github.com/arduino/ArduinoCloudProviderExamples)
- [Library for connecting to WiFi](https://www.arduino.cc/reference/en/libraries/wifi/)
- [Library for making HTTP calls](https://github.com/arduino-libraries/ArduinoHttpClient)
- [Arduino Uno WiFi Rev2 Pinout](https://content.arduino.cc/assets/Pinout-UNOwifirev2_latest.pdf)
- [Load Cell Amazon Link](https://www.amazon.com/dp/B07B4DNJ2L)
- [Load Cell Amplifier Amazon Link](https://www.amazon.com/dp/B079LVMC6X)
- [Arduino Uno Amazon Link](https://www.amazon.com/dp/B07MK598QV)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
