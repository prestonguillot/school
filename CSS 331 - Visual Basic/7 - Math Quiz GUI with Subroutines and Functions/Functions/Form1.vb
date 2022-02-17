Public Class Form1
    Inherits System.Windows.Forms.Form

    Dim numCorrect As Integer = 0
    Dim problemFlag As Integer = 0

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents txtAnswer As System.Windows.Forms.TextBox
    Friend WithEvents checkButton As System.Windows.Forms.Button
    Friend WithEvents txtOperand1 As System.Windows.Forms.TextBox
    Friend WithEvents txtOperator As System.Windows.Forms.TextBox
    Friend WithEvents txtOperand2 As System.Windows.Forms.TextBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Public WithEvents txtMessage As System.Windows.Forms.TextBox
    Friend WithEvents txtStatus As System.Windows.Forms.TextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.txtMessage = New System.Windows.Forms.TextBox
        Me.txtAnswer = New System.Windows.Forms.TextBox
        Me.checkButton = New System.Windows.Forms.Button
        Me.txtOperand1 = New System.Windows.Forms.TextBox
        Me.txtOperator = New System.Windows.Forms.TextBox
        Me.txtOperand2 = New System.Windows.Forms.TextBox
        Me.Button1 = New System.Windows.Forms.Button
        Me.txtStatus = New System.Windows.Forms.TextBox
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.BackColor = System.Drawing.Color.Gray
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(32, 48)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(520, 24)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Program to Generate Arithmetic Problems"
        '
        'Label2
        '
        Me.Label2.BackColor = System.Drawing.Color.Gray
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(32, 72)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(520, 24)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Click the Next Button to Generate a Problem"
        '
        'txtMessage
        '
        Me.txtMessage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.txtMessage.Cursor = System.Windows.Forms.Cursors.Default
        Me.txtMessage.Location = New System.Drawing.Point(16, 400)
        Me.txtMessage.Name = "txtMessage"
        Me.txtMessage.ReadOnly = True
        Me.txtMessage.Size = New System.Drawing.Size(552, 20)
        Me.txtMessage.TabIndex = 2
        Me.txtMessage.Text = ""
        Me.txtMessage.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtAnswer
        '
        Me.txtAnswer.Location = New System.Drawing.Point(216, 256)
        Me.txtAnswer.Name = "txtAnswer"
        Me.txtAnswer.Size = New System.Drawing.Size(152, 20)
        Me.txtAnswer.TabIndex = 3
        Me.txtAnswer.Text = ""
        '
        'checkButton
        '
        Me.checkButton.Location = New System.Drawing.Point(200, 296)
        Me.checkButton.Name = "checkButton"
        Me.checkButton.Size = New System.Drawing.Size(192, 72)
        Me.checkButton.TabIndex = 4
        Me.checkButton.Text = "Enter Answer and Click to Check"
        '
        'txtOperand1
        '
        Me.txtOperand1.Location = New System.Drawing.Point(240, 120)
        Me.txtOperand1.Name = "txtOperand1"
        Me.txtOperand1.ReadOnly = True
        Me.txtOperand1.Size = New System.Drawing.Size(32, 20)
        Me.txtOperand1.TabIndex = 5
        Me.txtOperand1.Text = ""
        Me.txtOperand1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtOperator
        '
        Me.txtOperator.Location = New System.Drawing.Point(280, 120)
        Me.txtOperator.Name = "txtOperator"
        Me.txtOperator.ReadOnly = True
        Me.txtOperator.Size = New System.Drawing.Size(32, 20)
        Me.txtOperator.TabIndex = 6
        Me.txtOperator.Text = ""
        Me.txtOperator.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtOperand2
        '
        Me.txtOperand2.Location = New System.Drawing.Point(320, 120)
        Me.txtOperand2.Name = "txtOperand2"
        Me.txtOperand2.ReadOnly = True
        Me.txtOperand2.Size = New System.Drawing.Size(32, 20)
        Me.txtOperand2.TabIndex = 7
        Me.txtOperand2.Text = ""
        Me.txtOperand2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(224, 144)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(136, 24)
        Me.Button1.TabIndex = 8
        Me.Button1.Text = "Next Problem"
        '
        'txtStatus
        '
        Me.txtStatus.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.txtStatus.Location = New System.Drawing.Point(16, 424)
        Me.txtStatus.Name = "txtStatus"
        Me.txtStatus.ReadOnly = True
        Me.txtStatus.Size = New System.Drawing.Size(552, 20)
        Me.txtStatus.TabIndex = 9
        Me.txtStatus.Text = "You have worked 0 problems correctly. There are 5 problems left to work."
        Me.txtStatus.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(584, 446)
        Me.Controls.Add(Me.txtStatus)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.txtOperand2)
        Me.Controls.Add(Me.txtOperator)
        Me.Controls.Add(Me.txtOperand1)
        Me.Controls.Add(Me.checkButton)
        Me.Controls.Add(Me.txtAnswer)
        Me.Controls.Add(Me.txtMessage)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "CSS331 Arithmetic Quiz"
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        If (problemFlag = 1) Then

            txtMessage.Text() = "Please attempt the current problem before generating a new one."

        ElseIf (numCorrect < 5) Then

            problemFlag = 1

            Dim rand As Random = New Random
            Dim problemType, rand1, rand2 As Integer

            problemType = 1 + rand.Next(4)
            rand1 = 1 + rand.Next(9)
            rand2 = 1 + rand.Next(9)

            Select Case problemType

                Case 1

                    txtOperand1.Text() = rand1
                    txtOperand2.Text() = rand2
                    txtOperator.Text() = "+"

                Case 2

                    txtOperand1.Text() = rand1
                    txtOperand2.Text() = rand2
                    txtOperator.Text() = "*"

                Case 3

                    rand1 += rand2
                    txtOperand1.Text() = rand1
                    txtOperand2.Text() = rand2
                    txtOperator.Text() = "-"

                Case 4

                    rand1 *= rand2
                    txtOperand1.Text() = rand1
                    txtOperand2.Text() = rand2
                    txtOperator.Text() = "/"

            End Select

        Else
            txtStatus.Text() = "You have worked all five problems correctly already."
        End If

    End Sub

    Private Sub checkButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles checkButton.Click

        If (problemFlag = 2) Then

            txtMessage.Text() = "Click the Next Problem button to generate a new problem."

        ElseIf (numCorrect < 5) Then

            problemFlag = 2

            Dim operator As String
            Dim operand1, operand2, correct As Integer

            operator = txtOperator.Text()
            operand1 = txtOperand1.Text()
            operand2 = txtOperand2.Text()

            Select Case operator

                Case "+"

                    numCorrect += add(operand1, operand2)

                Case "-"

                    numCorrect += subtract(operand1, operand2)

                Case "*"

                    numCorrect += multiply(operand1, operand2)

                Case "/"

                    numCorrect += divide(operand1, operand2)

            End Select

            txtStatus.Text() = "You have worked " & numCorrect & " problems correctly. There are " & (5 - numCorrect) & " problems left to work."

        Else
            txtStatus.Text() = "You have worked all five problems correctly already."
        End If

    End Sub

    Private Function add(ByVal operand1 As Integer, ByVal operand2 As Integer) As Integer

        If (txtAnswer.Text() = (operand1 + operand2)) Then
            txtMessage.Text() = "Correct!"
            Return 1
        Else
            txtMessage.Text() = "Sorry, the correct answer is " & (operand1 + operand2)
            Return 0
        End If

    End Function

    Private Function subtract(ByVal operand1 As Integer, ByVal operand2 As Integer) As Integer

        If (txtAnswer.Text() = (operand1 - operand2)) Then
            txtMessage.Text() = "Correct!"
            Return 1
        Else
            txtMessage.Text() = "Sorry, the correct answer is " & (operand1 - operand2)
            Return 0
        End If

    End Function

    Private Function multiply(ByVal operand1 As Integer, ByVal operand2 As Integer) As Integer

        If (txtAnswer.Text() = (operand1 * operand2)) Then
            txtMessage.Text() = "Correct!"
            Return 1
        Else
            txtMessage.Text() = "Sorry, the correct answer is " & (operand1 * operand2)
            Return 0
        End If

    End Function

    Private Function divide(ByVal operand1 As Integer, ByVal operand2 As Integer) As Integer

        If (txtAnswer.Text() = (operand1 / operand2)) Then
            txtMessage.Text() = "Correct!"
            Return 1
        Else
            txtMessage.Text() = "Sorry, the correct answer is " & (operand1 / operand2)
            Return 0
        End If

    End Function

End Class
