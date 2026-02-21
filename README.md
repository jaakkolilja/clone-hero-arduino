# Clone Hero Arduino Controller (Nano)

This project allows an **Arduino Nano** (or Nano Every) to function as a 9-button guitar controller for Clone Hero. Since the standard Nano does not support native keyboard emulation (HID), this project uses a **Python bridge** to read serial data and simulate keyboard inputs with minimal latency.

## Hardware Requirements
* **Arduino Nano**
* **9 Buttons** (5 Frets, Strum Up/Down, Start, Star Power)
* **9x 10k Ohm Resistors** (for Pull-down configuration)
* **Hookup wire** (approx. 1m for the neck)

## Wiring
* **Common 3.3V Rail:** A single 3.3V wire is daisy-chained to one pin of every button.
* **Signal Lines:** Each button's second pin is connected to an individual digital pin on the Arduino (**D2 through D10**).
* **Pull-down Resistors:** Each signal line (D2-D10) must be connected to **GND** via a 10k ohm resistor. This is crucial for long (1m) wires to prevent electrical noise and "ghost" inputs.

| Component | Arduino Pin |
| :--- | :--- |
| Green Fret | D2 |
| Red Fret | D3 |
| Yellow Fret | D4 |
| Blue Fret | D5 |
| Orange Fret | D6 |
| Strum Up | D7 |
| Strum Down | D8 |
| Star Power | D9 |
| Start / Menu | D10 |

## Software Setup

1. **Arduino:**
   - Upload the provided code to your Arduino.
   - The baud rate is set to `115200` to ensure high-speed communication.

2. **Python Environment:**
   - Install the required libraries using your terminal:
     ```bash
     pip install pyserial pydirectinput
     ```
   - Open `guitar.py` and ensure the `PORT` variable matches your Arduino's COM port (e.g., `'COM4'`).
   - You can customize key bindings in the `KEY_MAP` dictionary within the script.

## How to Use
1. Plug in your Arduino.
2. Run the Python script: `python guitar.py`.
3. Keep the script running in the background.
4. Open **Clone Hero** and press **Space** to enter the **Controller Settings**.
5. Map your physical buttons to the in-game actions.