import serial
import pydirectinput
pydirectinput.PAUSE = 0
pydirectinput.FAILSAFE = False
# Configuration
PORT = 'COM4'  # Update this to match your Arduino COM port
BAUD = 115200

# Key Mapping: Map the serial tags to your preferred keyboard keys
KEY_MAP = {
    'G': 'a',  # Green Fret
    'R': 's',  # Red Fret
    'Y': 'j',  # Yellow Fret
    'B': 'k',  # Blue Fret
    'O': 'l',  # Orange Fret
    'U': 'up',  # Strum Up
    'D': 'down',  # Strum Down
    'S': 'space',  # Star Power / Select
    'X': 'enter'  # Start / Menu
}

try:
    # Initialize Serial connection with a very low timeout for minimal lag
    ser = serial.Serial(PORT, BAUD, timeout=0.001)
    print(f"Bridge Active. Connected to {PORT}")
    print("Listening for 9 buttons...")

    while True:
        # Käytetään while-silmukkaa if-lauseen sijasta, jotta luetaan KAIKKI viestit puskurista
        while ser.in_waiting > 0:
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            if len(line) >= 2:
                tag = line[0]
                state = line[1]
                if tag in KEY_MAP:
                    key = KEY_MAP[tag]
                    if state == '1':
                        pydirectinput.keyDown(key)
                    elif state == '0':
                        pydirectinput.keyUp(key)

except KeyboardInterrupt:
    print("\nScript stopped by user.")
except Exception as e:
    print(f"Error: {e}")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print("Serial connection closed.")