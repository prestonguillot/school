'Preston Guillot
'CSS 331
'Assignment #3 - Minimum Number of Coins Problem
'Value - 15 Points
'10/12/05

Imports System.Windows.Forms

Module Module1

    Sub Main()

        Dim fifty, quarter, dime, nickel, input, total As Integer

        fifty = 0
        quarter = 0
        dime = 0
        nickel = 0
        total = 0

        Console.Write("Enter an integer between 1 and 99: ")
        input = Console.ReadLine

        If (input >= 50) Then
            fifty = 1
            total += 1
            input -= 50
        End If

        If (input >= 25) Then
            quarter = 1
            total += 1
            input -= 25
        End If

        If (input >= 10) Then
            dime = 1
            total += 1
            input -= 10
        End If

        If (input >= 5) Then
            nickel = 1
            total += 1
            input -= 5
        End If

        total += input

        Console.WriteLine("The minimum number of coins = {0}", total)

        MessageBox.Show("Minimum number of coins consists of " & fifty & " half-dollars " & quarter & " quarters " _
                         & dime & " dimes " & nickel & " nickels " & input & " pennies.", "Minimum Number of Conis Problem")



    End Sub

End Module
