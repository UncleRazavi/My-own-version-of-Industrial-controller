# Industrial Control System Structure & Functionality

## 1. Core Logic & Processing Layer (The Brain)
- **MCU:** STM32 Series F103 family
- **Function:** a
    - Manages concurrent tasks (Sensing, Display, Logging).
    - Decodes user inputs and drives actuator logic.
    - Handles communication protocols (UART, USB, SPI).

## 2. Sensing & Acquisition Layer (The Inputs)
- **Analog Domain:** 
    - **Temperature (LM35-style):** High-precision analog-to-voltage conversion.
    - **Gas/Smoke (MQ-series):** Detects atmospheric hazards via voltage level changes.
- **Digital Domain:**
    - **Temp/Humidity (DHT-style):** Single-wire digital protocol for environment monitoring.
- **User Interface Inputs:**
    - **Control Keys:** 5 tactile buttons for mode switching and setpoint adjustments.

## 3. Power & Signal Integrity Layer (The Foundation)
- **Power Management:**
    - **Main Regulation:** Converts input to system-level rails (3.3V/5V).
    - **Isolation/Filtering:** Dedicated block for "Analog and Digital Power Filter" to keep high-frequency digital noise out of sensitive ADC readings.
- **Signal Protection:**
    - Pull-up/down networks and decoupling capacitors near the MCU to ensure signal stability.

## 4. Actuation & Interface Layer (The Outputs)
- **Power Switching (The Relays):** 
    - 3-Channel Relay output with transistor drivers and flyback diodes.
    - Used for driving heavy AC/DC loads like Heaters, Coolers, and Gas Solenoids.
- **Visual & Audible Alerts:**
    - **LCD 16x2:** Local status display (Temps, Modes, Alarms).
    - **Piezo Buzzers:** Dual buzzers for critical audio warnings.
    - **Status LEDs:** Fast visual confirmation of system states.
- **Data & Connectivity:**
    - **SD Card:** Local data persistence (Blackbox logging).
    - **USB-to-Serial:** PC interface for debugging, monitoring, and field calibration.
    - **Programmer (SWD):** Low-level debug and firmware update interface.

---

###  Operational Logic (System Flow)
1. **Acquisition:** Read sensors (ADC & Digital) every 100-500ms.
2. **Filtering:** Digital filtering of analog values to prevent jitter.
3. **Logic Execution:** Compare real-time values against Setpoints (saved in RAM/EEPROM).
4. **Safety Check:** If Gas > Limit or Temp > Safety_Limit, override all relays to SAFE state and trigger Buzzers.
5. **Human Interaction:** Update LCD and poll buttons for user overrides or menu navigation.
6. **Persistence:** Log any state change or alarm event to the SD Card.
