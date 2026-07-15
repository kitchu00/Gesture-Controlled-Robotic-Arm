import cv2
import mediapipe as mp
import serial
import time

# Initialize
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.7)
mp_draw = mp.solutions.drawing_utils

# Change 'COM3' to your Arduino port (check in Arduino IDE)
ser = serial.Serial('COM3', 9600, timeout=1)
time.sleep(2)  # Wait for connection

cap = cv2.VideoCapture(0)
print("Gesture Control Started...")

while True:
    success, frame = cap.read()
    if not success:
        break

    frame = cv2.flip(frame, 1)
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hands.process(rgb)

    if results.multi_hand_landmarks:
        for hand in results.multi_hand_landmarks:
            mp_draw.draw_landmarks(frame, hand, mp_hands.HAND_CONNECTIONS)
            
            # Example: Get wrist position (landmark 0)
            wrist = hand.landmark[0]
            x = int(wrist.x * 100)   # Base rotation
            y = int(wrist.y * 100)   # Shoulder
            
            # Simple mapping (we will improve this)
            base_angle = max(0, min(180, x))
            shoulder_angle = max(0, min(180, y))
            
            # Send to Arduino
            data = f"{base_angle},{shoulder_angle},90,90,90\n"
            ser.write(data.encode())
            print(f"Sent: {data.strip()}")

    cv2.imshow("Gesture Control", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
ser.close()
cv2.destroyAllWindows()
