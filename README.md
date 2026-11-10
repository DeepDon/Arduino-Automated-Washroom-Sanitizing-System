# Arduino-Based Automated Washroom Sanitizing and Monitoring System

An automated, IoT-enabled public washroom sanitization, air quality monitoring, and COVID-19 statistics tracking system. Designed to eliminate unhygienic conditions in public restrooms, reduce human contact with hazardous environments, and automate floor cleaning, handwashing, and ventilation alerts.

---

## 🛠 System Architecture & Block Diagram

The system is structured into three integrated functional modules:

+-----------------------------------------------------------------------+
|                              PART A: MONITORING & SANITATION          |
|                                                                       |
|   +-------------------+                     +---------------------+   |
|   |    PIR Sensor     | ==================> |                     |   |
|   +-------------------+                     |     Arduino Uno     |   |
|   |    Gas Sensor     | > |    Microcontroller  |   |
|   |    (MQ-135)       |                     |     (ATmega328P)    |   |
|   +-------------------+                     +----------+----------+   |
|                                                        |              |
|                                                        v              |
|   +-------------------+                     +---------------------+   |
|   |   LCD Display     | < |   Relay & Pressure  |   |
|   |   & Buzzer        |                     |   Pump / Sprayer    |   |
|   +-------------------+                     +---------------------+   |
+-----------------------------------------------------------------------+

+-----------------------------------------------------------------------+
|                        PART B: AUTOMATED HANDWASH                     |
|                                                                       |
|   [ Proximity Sensor ] ===> [ Transistor Driver ] ===> [ DC Pump ]    |
+-----------------------------------------------------------------------+

+-----------------------------------------------------------------------+
|                        PART C: IOT MONITORING UNIT                    |
|                                                                       |
|   [ NodeMCU (ESP8266) ] ===> [ Display Unit (Global COVID Cases) ]    |
+-----------------------------------------------------------------------+
