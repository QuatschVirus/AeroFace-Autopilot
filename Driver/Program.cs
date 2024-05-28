using Solid.Arduino;

namespace Driver
{
    public class Program
    {
        static ArduinoSession s;
        static void Main(string[] args)
        {
            using (s = new(new SerialConnection("COM6", SerialBaudRate.Bps_115200)))
            {
                Console.WriteLine(s.ReadLine());
                s.StringReceived += Process;
                s.SendStringData("0\n" + FormatForDisplay("Welcome to AeroFace!", "Autopilot Module", "Connected!"));
                Console.ReadKey(true);
            }
        }

        private static void Process(object sender, StringEventArgs eventArgs)
        {
            Console.WriteLine(eventArgs.Text.Length);
        }

        public static string FormatForDisplay(params string[] lines)
        {
            string output = "";
            foreach (string line in lines) {
                if (line.Length > 20) continue;
                string padding = string.Concat(Enumerable.Repeat(' ', (20 - line.Length) / 2));
                output += padding + line + padding + "\n";
            }
            return output.TrimEnd('\n');
        }
    }
}
