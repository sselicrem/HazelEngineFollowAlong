using System;

namespace Hazel
{

    public class Main
    {
        public float FloatVar { get; set; }

        public Main()
        {
            Console.WriteLine("Main Constructor!");
        }

        public void PrintMessage()
        {
            Console.WriteLine("HELLO WORLD FROM C#!");
        }

        public void PrintInt(int i)
        {
            Console.WriteLine($"C# SAYS: {i}");
        }

        public void PrintInts(int value1, int value2)
        {
            Console.WriteLine($"C# SAYS: {value1} and {value2}");
        }

        public void PrintCustomMessage(string message)
        {
            Console.WriteLine($"C# SAYS: {message}");
        }

    }
}