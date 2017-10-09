import sys
importdlib
import cv2
importopenface
predictor_model = "shape_predictor_68_face_landmarks.dat"
file = sys.argv[1]
detector = dlib.get_frontal_face_detector()
pose_predictor = dlib.shape_predictor(predictor_model)
aligner = openface.AlignDlib(predictor_model)
# Load the image
image = cv2.imread(file)
# Run the HOG face detector on the image data
detected_faces = detector(image, 1)
print("Found {} faces in the image file {}".format(len(detected_faces), file))
# Loop through each face we found in the image
fori, rect in enumerate(detected_faces):

	# Detected faces are returned as an object with the coordinates 
	# of the top, left, right and bottom edges
	print("- Face #{} found at Left: {} Top: {} Right: {} Bottom: {}".format(i, face_rect.left(), face_rect.top(), face_rect.right(), face_rect.bottom()))

	# Get the the face's pose
	landmarks = pose_predictor(image, face_rect)

	# Use openface to calculate and perform the face alignment
	alignedFace = aligner.align(534, image, face_rect, landmarkIndices=openface.AlignDlib.OUTER_EYES_AND_NOSE)

	# Save the aligned image to a file
	cv2.imwrite("aligned_face_{}.jpg".format(i), alignedFace)
