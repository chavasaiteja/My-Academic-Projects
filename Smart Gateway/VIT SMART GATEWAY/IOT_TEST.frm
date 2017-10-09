VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Object = "{00028C01-0000-0000-0000-000000000046}#1.0#0"; "DBGRID32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.TextBox Text5 
      Height          =   615
      Left            =   10920
      TabIndex        =   13
      Top             =   3960
      Width           =   2295
   End
   Begin MSCommLib.MSComm MSComm2 
      Left            =   840
      Top             =   3720
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      CommPort        =   10
      DTREnable       =   -1  'True
   End
   Begin VB.TextBox Text4 
      Height          =   615
      Left            =   5520
      TabIndex        =   10
      Top             =   3720
      Width           =   2295
   End
   Begin VB.TextBox Text3 
      Height          =   615
      Left            =   5520
      TabIndex        =   9
      Top             =   2640
      Width           =   2295
   End
   Begin VB.TextBox Text2 
      Height          =   615
      Left            =   5520
      TabIndex        =   8
      Top             =   1560
      Width           =   2295
   End
   Begin MSDBGrid.DBGrid DBGrid1 
      Bindings        =   "IOT_TEST.frx":0000
      Height          =   1095
      Left            =   4680
      OleObjectBlob   =   "IOT_TEST.frx":0014
      TabIndex        =   4
      Top             =   7200
      Width           =   6615
   End
   Begin VB.Data Data1 
      Caption         =   "Data1"
      Connect         =   "Access"
      DatabaseName    =   "D:\VIT SMART GATEWAY\DETAILS.mdb"
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   375
      Left            =   6120
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   "DETAILS"
      Top             =   6360
      Width           =   3375
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   720
      Top             =   2400
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      CommPort        =   2
      DTREnable       =   -1  'True
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   2160
      Top             =   2640
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Left            =   10920
      TabIndex        =   2
      Top             =   2040
      Width           =   2295
   End
   Begin VB.CommandButton Command1 
      Caption         =   "E&XIT"
      Height          =   615
      Left            =   13320
      TabIndex        =   1
      Top             =   6840
      Width           =   1935
   End
   Begin VB.Label Label8 
      AutoSize        =   -1  'True
      Caption         =   "RFID"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   11520
      TabIndex        =   14
      Top             =   3240
      Width           =   825
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   10920
      TabIndex        =   12
      Top             =   5280
      Width           =   90
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "SMART GATE WAY"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   4800
      TabIndex        =   11
      Top             =   360
      Width           =   3435
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "BP"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   4680
      TabIndex        =   7
      Top             =   3840
      Width           =   480
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "HB"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   4680
      TabIndex        =   6
      Top             =   2760
      Width           =   495
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "TEMP"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   4200
      TabIndex        =   5
      Top             =   1680
      Width           =   1020
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Label2"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   1800
      TabIndex        =   3
      Top             =   600
      Width           =   1095
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "IOT TEST"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      Left            =   11160
      TabIndex        =   0
      Top             =   1320
      Width           =   1665
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
Dim Rstr, Rstr1, temp, hb, bp, Rstr2, Rstr3, prs As Variant
Private Sub Command1_Click()
End
End Sub
Private Sub Form_Load()
MSComm1.PortOpen = True
Sleep (20)
MSComm1.Output = "~"
Label1.Caption = "~"
Sleep (20)

temp = 32
hb = 60
bp = 120


MSComm2.PortOpen = True
Sleep (20)
End Sub


Private Sub Timer1_Timer()
Rstr2 = MSComm2.Input
Sleep (20)
Label1.Caption = Rstr2

If Rstr2 <> "" Then
Rstr3 = Rstr2
End If
Text5.Text = Rstr3

Rstr = MSComm1.Input
Sleep (20)
If Rstr <> "" Then
Rstr1 = Rstr
End If

Text1.Text = Rstr1

If Text1.Text = "T" Then
MSComm1.Output = temp & Chr$(13)
Label1.Caption = temp
Sleep (20)
End If

If Text1.Text = "H" Then
MSComm1.Output = hb & Chr$(13)
Label1.Caption = hb
Sleep (20)
End If

If Text1.Text = "B" Then
MSComm1.Output = bp & Chr$(13)
Label1.Caption = bp
Sleep (20)
End If



If Text1.Text = "A" Then
'Label7.Caption = " "
MSComm1.Output = "~"
Label1.Caption = "~"
Sleep (1000)
Text1.Text = ""
End If

If Text1.Text = "D" Then
prs = "Take paracetamol"
Sleep (100)
MSComm1.Output = "~"
Label1.Caption = "~"
ElseIf Text1.Text = "C" Then
Sleep (100)
prs = "Take Dolo"
MSComm1.Output = "~"
Label1.Caption = "~"
End If

Data1.Recordset.MoveFirst
While Not Data1.Recordset.EOF
If Text5.Text = Data1.Recordset.Fields(3) Then
Text2.Text = Data1.Recordset.Fields(0)
Text3.Text = Data1.Recordset.Fields(1)
Text4.Text = Data1.Recordset.Fields(2)
Label7.Caption = prs
GoTo l1
End If
Data1.Recordset.MoveNext
Wend

'Label2.Caption = prs

l1:
End Sub
