import time
start = time.time()
import sys
importargparse
import cv2
import os
import pickle
import numpy as np
importopenface
importMySQLdb
db=MySQLdb.connect("localhost","root","raspberry","attdd")
c=db.cursor()
conn=sqlite3.connect('attd.db')

curs=conn.cursor()
fileDir = os.path.dirname(os.path.realpath(__file__))
modelDir = os.path.join(fileDir, '..', 'models')
dlibModelDir = os.path.join(modelDir, 'dlib')
openfaceModelDir = ('/home/pi')


defgetRep(img, multiple=False):
start = time.time()
bgr = cv2.imread(img)
ifbgr is None:
raise Exception("Unable to load image: {}".format(img))

rgb = cv2.cvtColor(bgrImg, cv2.COLOR_BGR2RGB)

ifargs.verbose:
print("  + Original size: {}".format(rgb.shape))
ifargs.verbose:
print("Loading the image took {} seconds.".format(time.time() - start))

start = time.time()

if multiple:
bbs = align.getAllFaceBoundingBoxes(rgb)
else:
        bb1 = align.getLargestFaceBoundingBox(rgb)
bbs = [bb1]
iflen(bbs) == 0 or (not multiple and bb1 is None):
raise Exception("Unable to find a face: {}".format(img))
ifargs.verbose:
print("Face detection took {} seconds.".format(time.time() - start))

reps = []
for bb in bbs:
start = time.time()
alignedFace = align.align(
args.imgDim,
rgbImg,
bb,
landmarkIndices=openface.AlignDlib.OUTER_EYES_AND_NOSE)
ifalignedFace is None:
raise Exception("Unable to align image: {}".format(img))
ifargs.verbose:
print("Alignment took {} seconds.".format(time.time() - start))
print("This bbox is centered at {}, {}".format(bb.center().x, bb.center().y))

start = time.time()
rep = net.forward(alignedFace)
ifargs.verbose:
print("Neural network forward pass took {} seconds.".format(
time.time() - start))
reps.append((bb.center().x, rep))
sreps = sorted(reps, key=lambda x: x[0])
returnsreps

defadd_attd(per):
print 'uploaded'
curs.execute("""INSERT INTO attd
VALUES (date('now'), (?))""",(per,))
c.execute("""INSERT INTO atend
VALUES (%s,CURRENT_DATE(),%s,NOW())""",(per,cid))
conn.commit()

def train(args):
print("Loading embeddings.")
fname = "{}/labels.csv".format(args.workDir)
labels = pd.read_csv(fname, header=None).as_matrix()[:, 1]
labels = map(itemgetter(1),
map(os.path.split,
map(os.path.dirname, labels)))  # Get the directory.
fname = "{}/reps.csv".format(args.workDir)
embeddings = pd.read_csv(fname, header=None).as_matrix()
le = LabelEncoder().fit(labels)
labelsNum = le.transform(labels)
nClasses = len(le.classes_)
print("Training for {} classes.".format(nClasses))

ifargs.classifier == 'LinearSvm':
clf = SVC(C=1, kernel='linear', probability=True)
elifargs.classifier == 'GridSearchSvm':
print("""
        Warning:
.
        """)
param_grid = [
            {'C': [1, 10, 100, 1000],
             'kernel': ['linear']},
            {'C': [1, 10, 100, 1000],
             'gamma': [0.001, 0.0001],
             'kernel': ['rbf']}
        ]
clf = GridSearchCV(SVC(C=1, probability=True), param_grid, cv=5)
elifargs.classifier == 'GMM':  # Doesn't work best
clf = GMM(n_components=nClasses)


elifargs.classifier == 'RadialSvm':  # Radial Basis Function kernel
        # works better with C = 1 and gamma = 2
clf = SVC(C=1, kernel='rbf', probability=True, gamma=2)
elifargs.classifier == 'DecisionTree':  # Doesn't work best
clf = DecisionTreeClassifier(max_depth=20)
elifargs.classifier == 'GaussianNB':
clf = GaussianNB()


elifargs.classifier == 'DBN':
fromnolearn.dbn import DBN
clf = DBN([embeddings.shape[1], 500, labelsNum[-1:][0] + 1
learn_rate_decays=0.9,
epochs=300, 

ifargs.ldaDim> 0:
clf_final = clf
clf = Pipeline([('lda', LDA(n_components=args.ldaDim)),
('clf', clf_final)])

clf.fit(embeddings, labelsNum)

fName = "{}/classifier.pkl".format(args.workDir)
print("Saving classifier to '{}'".format(fName))
with open(fName, 'w') as f:
pickle.dump((le, clf), f)


def infer(args, multiple=False):
with open(args.classifierModel, 'r') as f:
        (le, clf) = pickle.load(f)


forimg in args.imgs:             

print("\n=== {} ===".format(img))
reps = getRep(img, multiple)
iflen(reps) > 1:
print("List of faces in image from left to right")
for r in reps:
rep = r[1].reshape(1, -1)
bbx = r[0]
start = time.time()
predictions = clf.predict_proba(rep).ravel()
maxI = np.argmax(predictions)
person = le.inverse_transform(maxI)
confidence = predictions[maxI]
ifargs.verbose:
print("Prediction took {} seconds.".format(time.time() - start))
if multiple:
var=person
                # print person
print 'multiple'
printvar
                # print("Predict {} @ x={} with {:.2f} .".format(person, bbx,confidence))
                #print("prdeictedperson".format(person))
                #add(var)
add_attd(var)


else:
var=person
print 'single'
printvar
                # curs.execute("INSERT INTO attd(name,currentdate) VALUES('var',date('now'))")
add_attd(var)
#  print("Predict {} with {:.2f} ".format(person,confidence))
                #print("prdeictedperson".format(person))

ifisinstance(clf, GMM):
dist = np.linalg.norm(rep - clf.means_[maxI])
print("  + Distance from the mean: {}".format(dist))
