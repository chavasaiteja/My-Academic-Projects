import cv2
ca = cv2.VideoCapture(0)
detector=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

Id=raw_input('enter your id')
num=0
while(True):
ret, im = ca.read()
gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
face = detector.detectMultiScale(gray, 1.3, 5)
for (x,y,w,h) in face:
cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)


num=num+1
cv2.imwrite("dataSet/User."+Id +'.'+ str(num) + ".jpg", gray[y:y+h,x:x+w])

cv2.imshow('frame',im)
    #wait for 100 miliseconds
if cv2.waitKey(100) & 0xFF == ord('q'):
break
    # break if the sample number is morethan 20
elifsampleNum>20:
break
cam.release()
