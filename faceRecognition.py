import cv2
import time
from insightface.app import FaceAnalysis # Ai Detection library

app = FaceAnalysis(name='buffalo_sc', providers=['CPUExecutionProvider'])
app.prepare(ctx_id=0, det_size=(160, 160))  # smaller = faster

cap = cv2.VideoCapture(0) # opens the camera
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
cap.set(cv2.CAP_PROP_FPS, 60)  # request higher FPS from camera

faces = []  # cache faces between frames
frame_count = 0

scale_x, scale_y = 1, 1
frame_count = 0

prev_time = time.time()

while True:
    ret, frame = cap.read()
    if not ret:
        break

    if frame_count % 4 == 0: # runs every 4 frames
        small = cv2.resize(frame, (320, 240))
        faces = app.get(small)
        scale_x = frame.shape[1] / 320
        scale_y = frame.shape[0] / 240

    for face in faces: # draws the boxes on faces
        box = face.bbox.astype(int)
        x1 = int(box[0] * scale_x)
        y1 = int(box[1] * scale_y)
        x2 = int(box[2] * scale_x)
        y2 = int(box[3] * scale_y)
        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
        cv2.putText(frame, f"{face.det_score:.2f}", (x1, y1 - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)

    curr_time = time.time() # fps counter
    fps = 1 / (curr_time - prev_time)
    prev_time = curr_time
    cv2.putText(frame, f"FPS: {fps:.1f}", (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

    cv2.imshow('Face Detector', frame)
    frame_count += 1

    if cv2.waitKey(1) & 0xFF == ord('q'): # click q to exit camera
        break

cap.release()
cv2.destroyAllWindows()