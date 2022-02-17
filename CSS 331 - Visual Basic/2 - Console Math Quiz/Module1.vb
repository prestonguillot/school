Module Module1

    Sub Main()

        'variable declarations
        Dim name, input1, input2 As String
        Dim number1, number2, answer As Single

        'get input from user
        Console.Write("Please enter your name: ")
        name = Console.ReadLine()
        Console.WriteLine()
        Console.WriteLine("Nice to be working with you {0}.", name)
        Console.WriteLine()
        Console.Write("Please enter an integer number: ")
        input1 = Console.ReadLine()
        Console.WriteLine()
        Console.Write("Please enter a second integer number: ")
        input2 = Console.ReadLine()
        Console.WriteLine()

        'convert input to numbers
        number1 = input1
        number2 = input2

        'start math quiz thing
        Console.Write("What is {0} * {1}? ", input1, input2)
        answer = Console.ReadLine()
        Console.WriteLine()
        If (answer = (number1 * number2)) Then
            Console.WriteLine("Good job {0}!", name)
            Console.WriteLine()
        Else
            Console.WriteLine("You're dumb, the answer is {0}", (number1 * number2))
            Console.WriteLine()
        End If

        Console.Write("What is {0} ^ {1}? ", input1, input2)
        answer = Console.ReadLine()
        Console.WriteLine()
        If (answer = (number1 ^ number2)) Then
            Console.WriteLine("Good job {0}!", name)
            Console.WriteLine()
        Else
            Console.WriteLine("You're dumb, the answer is {0}", (number1 ^ number2))
            Console.WriteLine()
        End If

        Console.Write("What is {0} / {1}? ", input1, input2)
        answer = Console.ReadLine()
        Console.WriteLine()
        If (Math.Abs(answer - (number1 / number2)) < 0.0001) Then
            Console.WriteLine("Good job {0}!", name)
            Console.WriteLine()
        Else
            Console.WriteLine("You're dumb, the answer is {0}", (number1 / number2))
            Console.WriteLine()
        End If

        Console.Write("What is {0} \ {1}? ", input1, input2)
        answer = Console.ReadLine()
        Console.WriteLine()
        If (answer = (number1 \ number2)) Then
            Console.WriteLine("Good job {0}!", name)
            Console.WriteLine()
        Else
            Console.WriteLine("You're dumb, the answer is {0}", (number1 \ number2))
            Console.WriteLine()
        End If

        Console.Write("What is {0} Mod {1}? ", input1, input2)
        answer = Console.ReadLine()
        Console.WriteLine()
        If (answer = (number1 Mod number2)) Then
            Console.WriteLine("Good job {0}!", name)
            Console.WriteLine()
        Else
            Console.WriteLine("You're dumb, the answer is {0}", (number1 Mod number2))
            Console.WriteLine()
        End If

    End Sub

End Module
