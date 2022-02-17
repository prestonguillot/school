'Preston Guillot
'Assignment 4 - Die Simulation

Imports System.Windows.Forms

Module Module1

    Sub Main()

        Dim rand As Random = New Random
        Dim input, roll, counter, i, percentage As Integer
        Dim numRolls As Integer() = New Integer() {0, 0, 0, 0, 0, 0}
        Dim avg As Double

        'Get input from user.
        Console.Write("Input the number of times for the die to be tossed: ")
        input = Console.ReadLine

        'Make die rolls and keep track of number of rolls of each.
        counter = 0
        avg = 0
        While counter < input
            roll = 1 + rand.Next(6)
            numRolls(roll - 1) += 1
            avg += roll
            counter += 1
            'Console.WriteLine(roll)
        End While

        'Print graph showing percentage with which each outcome occurs.
        For i = 0 To 5
            counter = 0
            percentage = numRolls(i) / input * 100
            Console.Write(i + 1 & ": ")
            Do Until counter >= percentage
                Console.Write("*")
                counter += 1
            Loop
            Console.WriteLine(" (" & percentage & ")")
        Next

        'Print the average of all rolls in a message box.
        avg /= input
        MessageBox.Show("Average = " & avg, "Die Simulation")

    End Sub

End Module
