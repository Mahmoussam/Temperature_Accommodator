# Temperature_Accommodator
Atmega16-based Temperature accommodator.

The goal is to:
 * monitor the temperature and humidity values from DHT11 **(using Timer1 to interrupt every 100ms for temperature & 200ms for humidity)**

 * Sends them to the **UART** receiver, and controls the speed of the 12v DC Fan 

 * Uses the L293D driver and **Fast PWM** non-inverted **(Timer0 and OC0 for generating PWM)**.
## Components:
- Atmega16
- DHT11
- 12V DC FAN
- L293D
## Schematic
![alt text](https://github.com/Mahmoussam/Temperature_Accommodator/blob/master/Screenshot%202024-08-09%20200301.png)
