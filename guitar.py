import serial
import pydirectinput

PORT = 'COM4'  # Tarkista portti!
BAUD = 115200

try:
    ser = serial.Serial(PORT, BAUD, timeout=0.001)  # Erittäin nopea luku
    print("Skripti aktiivinen. Pitkät nuotit toimivat nyt!")

    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()

            # VIHREÄ NAPPI (A-näppäin)
            if line == "G1":
                pydirectinput.keyDown('a')
            elif line == "G0":
                pydirectinput.keyUp('a')

            # PUNAINEN NAPPI (S-näppäin)
            elif line == "R1":
                pydirectinput.keyDown('s')
            elif line == "R0":
                pydirectinput.keyUp('s')

except Exception as e:
    print(f"Virhe: {e}")
finally:
    if 'ser' in locals():
        ser.close()