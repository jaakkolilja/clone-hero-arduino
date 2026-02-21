# Clone Hero Arduino Controller (Nano Every)

This project allows an **Arduino Nano Every** to function as a guitar controller for Clone Hero. Since the Nano Every lacks native HID (keyboard) support, this setup uses a **Python bridge** to read serial data and simulate keyboard inputs with minimal latency.

## Hardware Requirements
* **Arduino Nano Every**
* **2 Buttons** (e.g., Green and Red)
* **2 10k Ohm Resistors** (for Pull-down configuration)

## Wiring
* **Green Button:** Connected between **3.3V** and Pin **D2**.
* **Red Button:** Connected between **3.3V** and Pin **D3**.
* **Pull-down resistors:** Connect a 10k resistor from each input pin (**D2** and **D3**) to **GND** to ensure a stable signal.

## Software Setup

1. **Arduino:**
   - Upload the code from the `arduino-code/` folder to your Nano Every.
   - The baud rate is set to `115200` to ensure the lowest possible input lag.

2. **Python Environment:**
   - Install the required libraries using your terminal:
     ```bash
     pip install pyserial pydirectinput
     ```
   - Open `guitar.py` and ensure the `PORT` variable matches your Arduino's COM port (e.g., `'COM3'`).

## How to Use
1. Plug in your Arduino.
2. Run the Python script: `python guitar.py`.
3. **Keep the script running** in the background.
4. Open **Clone Hero** and press **Space** to enter the **Controller Settings**.
5. Map your physical buttons to the in-game frets.