import cv2,os
import numpy as np
from PIL import Image

recog = cv2.createLBPHFaceRecognizer()
detect= cv2.CascadeClassifier("haarcascade_frontalface_default.xml");

defgetImagesAndLabels(path):
imagePaths=[os.path.join(path,f) for f in os.listdir(path)] 
faceSamples=[]
    Ids=[]

forimagePath in imagePaths:
pil=Image.open(imagePath).convert('L')
np1=np.array(pil,'uint8')
        Id=int(os.path.split(imagePath)[-1].split(".")[1])
extract the face from the training image sample
fac=detect.detectMultiScale(np1)

for (x,y,w,h) in fac:
fasa.append(imageNp[y:y+h,x:x+w])
Ids.append(Id)
returnfasa,Ids

fasa,Ids = getImagesAndLabels('data')
recog.train(faces, np.array(Ids))
recog.save('trainner.yml')
