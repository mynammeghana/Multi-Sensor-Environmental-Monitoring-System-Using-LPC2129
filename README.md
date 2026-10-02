#Multi-Sensor Environmental Monitoring System


##The Multi-Sensor Environmental Monitoring System is an embedded system project developed using the ARM7 LPC2129 microcontroller. The system collects and processes environmental data from multiple sensors, including the LM35 temperature sensor, LDR sensor, soil moisture sensor, and water sensor.

The LPC2129 reads sensor values through its ADC (Analog-to-Digital Converter) and determines the corresponding environmental conditions. The monitored information is displayed on a 16×2 LCD, while LED indicators provide visual status information. The sensor data and system status are also transmitted to a PC/Laptop through UART communication.

The system can identify conditions such as normal temperature, high temperature, low light, dry soil, and water detection.

#Features
- Temperature Monitoring – Measures temperature using the LM35 temperature sensor through the LPC2129 ADC.
- Light Level Monitoring – Uses an LDR sensor to monitor the surrounding light intensity.
- Soil Moisture Monitoring – Measures soil moisture and identifies dry soil conditions.
- Water Detection – Detects the presence of water using a water sensor.
- 16×2 LCD Display – Displays temperature, light level, soil moisture, water sensor status, and overall system status.
- UART Communication – Transmits sensor information and system status to a PC/Laptop terminal.
- LED Indication – Uses Green, Yellow, and Red LEDs to indicate different system conditions.
- Multi-Sensor Integration – Integrates multiple analog and digital sensors with the LPC2129 microcontroller.
- ADC-Based Monitoring – Uses the LPC2129 ADC to read analog outputs from the connected sensors.
