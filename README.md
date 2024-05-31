# ESP8266 Wi-Fi Signal Strength Indicator

This project uses an ESP8266 to connect to a Wi-Fi network and indicates the signal strength using three LEDs. The LED1, LED2, and LED3 correspond to weak, moderate, and strong Wi-Fi signals, respectively.

## Features

- **LED Indication**:
  - **Weak Signal**: LED1 blinks.
  - **Moderate Signal**: LED1 and LED2 are constantly on.
  - **Strong Signal**: LED1, LED2, and LED3 are constantly on.
- **Serial Monitor**: Prints the RSSI (Received Signal Strength Indicator) value to the serial monitor.

## Components

- ESP8266 module
- Three LEDs
- Resistors for LEDs
- Breadboard and jumper wires
- 9V battery and voltage regulator for power (if not using USB)

## Circuit Diagram

- **LED1** connected to pin D1
- **LED2** connected to pin D2
- **LED3** connected to pin D3
- Common ground for all LEDs

## Wiring

1. **Connect the LEDs**:
   - LED1 anode to D1, cathode to GND (via resistor).
   - LED2 anode to D2, cathode to GND (via resistor).
   - LED3 anode to D3, cathode to GND (via resistor).
2. **Power Supply**:
   - Connect a 9V battery to a voltage regulator to provide 3.3V to the ESP8266.

## Future Plans

- Speed Test Integration: Implement functionality to measure and log download and upload speeds using a speed test API.
- Data Logging: Store signal strength and speed test data for further analysis.
- Machine Learning: Use the collected data to predict network performance.
