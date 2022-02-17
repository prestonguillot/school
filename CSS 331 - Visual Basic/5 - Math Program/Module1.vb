'Preston Guillot
'Assignment 5 - Math Program

Imports System.Windows.Forms

Module Module1

    Sub Main()

        Dim rand As Random = New Random
        Dim problemType, rand1, rand2, numProblems, numCorrect, answer As Integer
        Dim totAdd, corAdd, totSub, corSub, totMult, corMult, totDiv, corDiv As Integer
        Dim output As String

        Do
            problemType = 1 + rand.Next(4)
            rand1 = 1 + rand.Next(9)
            rand2 = 1 + rand.Next(9)

            Select Case problemType

                Case 1

                    totAdd += 1
                    Console.Write("What is " & rand1 & " + " & rand2 & "? : ")
                    answer = Console.ReadLine()
                    If (answer = (rand1 + rand2)) Then
                        Console.WriteLine("You are correct!")
                        numCorrect += 1
                        corAdd += 1
                    Else
                        Console.WriteLine("Sorry, the correct answer is " & rand1 + rand2)
                    End If

                Case 2

                    totMult += 1
                    Console.Write("What is " & rand1 & " * " & rand2 & "? : ")
                    answer = Console.ReadLine()
                    If (answer = (rand1 * rand2)) Then
                        Console.WriteLine("You are correct!")
                        numCorrect += 1
                        corMult += 1
                    Else
                        Console.WriteLine("Sorry, the correct answer is " & rand1 * rand2)
                    End If

                Case 3

                    totSub += 1
                    Console.Write("What is " & rand1 + rand2 & " - " & rand1 & "? : ")
                    answer = Console.ReadLine()
                    If (answer = rand2) Then
                        Console.WriteLine("You are correct!")
                        numCorrect += 1
                        corSub += 1
                    Else
                        Console.WriteLine("Sorry, the correct answer is " & rand2)
                    End If

                Case 4

                    totDiv += 1
                    Console.Write("What is " & rand1 * rand2 & " / " & rand1 & "? : ")
                    answer = Console.ReadLine()
                    If (answer = rand2) Then
                        Console.WriteLine("You are correct!")
                        numCorrect += 1
                        corDiv += 1
                    Else
                        Console.WriteLine("Sorry, the correct answer is " & rand2)
                    End If

            End Select
        Loop While numCorrect < 5

        output = "Type" & vbTab & vbTab & "Total" & vbTab & "Correct" & vbCrLf & vbCrLf
        output &= "Addition" & vbTab & vbTab & totAdd & vbTab & corAdd & vbCrLf
        output &= "Subtratction" & vbTab & totSub & vbTab & corSub & vbCrLf
        output &= "Multiplication" & vbTab & totMult & vbTab & totMult & vbCrLf
        output &= "Division" & vbTab & vbTab & totDiv & vbTab & corDiv & vbCrLf
        MessageBox.Show(output, "Program Summary")

    End Sub

End Module
