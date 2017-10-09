import cv2, sys, numpy, os
haar = 'haarcascade_frontalface_default.xml'
datasets = 'datasets'  
sub_data = 'Personname'     #These are sub data sets of folder, for my faces I've used my name
path = os.path.join(datasets, sub_data)
if not os.path.isdir(path):
os.mkdir(path)
(width, height) = (130, 100)    
cade = cv2.CascadeClassifier(haar)
cam = cv2.VideoCapture(0) 
# The program loops until it has 30 images of the face.
count = 1
while count < 31: 
    (_, im) = cam.read()
gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
faces = cade.detectMultiScale(gray, 1.3, 4)
for (x,y,w,h) in faces:
cv2.rectangle(im,(x,y),(x+w,y+h),(255,0,0),2)
face = gray[y:y + h, x:x + w]
        face1 = cv2.resize(face, (width, height))
cv2.imwrite('%s/%s.png' % (path,count), face1)
count += 1
key = cv2.waitKey(10)
if key == 27:
	break
