using System;
using System.Threading;

/// <summary>
/// Esempi di varie Race condition e come evitare che possano accadere:
/// 1) Semplice lettura del risultato. Il processo più lento setta la variabile
/// 2) Qualcosa di strano accade .... La variabile cambia il valore
/// 3) Si prova a sistemare la situazione
/// </summary>
namespace RaceCondition
{
    public class SharedMemoryV1
    {
        public int result = 0;
        public void Work1() { result = 1; }
        public void Work2() { result = 2; }
        public void Work3() { result = 3; }
    }

    public class SharedMemoryV2
    {
        int sleepTime = 2;
        public int result;
        public void Work1()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("Trovo {0} ma io Sono Gino settero a 1", result);
                result = 1;
                Thread.Sleep(sleepTime);
            }
        }
        public void Work2()
        {
            for (int i = 0; i < 5; i++)
            {

                Console.WriteLine("Trovo {0} ma io Sono Maria settero a 2", result);
                result = 2;
                Thread.Sleep(sleepTime);
            }
        }
        public void Work3()
        {
            for (int i = 0; i < 5; i++)
            {

                Console.WriteLine("Trovo {0} ma io Sono Pasquale settero a 3", result);
                result = 3;
                Thread.Sleep(sleepTime);
            }
        }
    }

    public class SharedMemoryV3
    {
        int sleepTime = 2;
        object __lockObj = new object();

        private int _result;
        public int result
        {
            get => _result;
            set
            {
                Console.WriteLine("[Ero {0} ora sono {1}]\n", _result, value);
                _result = value;
            }
        }
        public void Work1()
        {
            for (int i = 0; i < 5; i++)
            {
                lock (__lockObj)
                {
                    Console.WriteLine("Trovo {0} ma io Sono Gino settero a 1", result);
                    result = 1;
                }
                Thread.Sleep(sleepTime);
            }
        }
        public void Work2()
        {
            for (int i = 0; i < 5; i++)
            {
                lock (__lockObj)
                {
                    Console.WriteLine("Trovo {0} ma io Sono Maria settero a 2", result);
                    result = 2;
                }
                Thread.Sleep(sleepTime);
            }
        }
        public void Work3()
        {
            for (int i = 0; i < 5; i++)
            {
                lock (__lockObj)
                {
                    Console.WriteLine("Trovo {0} ma io Sono Pasquale settero a 3", result);
                    result = 3;
                }
                Thread.Sleep(sleepTime);
            }
        }
    }

    public class App
    {
        static void Main(string[] args)
        {   
            for (int i = 0; i < 5; i++)
            {
                var a = new SharedMemoryV2();
                Thread worker1 = new Thread(a.Work1);
                Thread worker2 = new Thread(a.Work2);
                Thread worker3 = new Thread(a.Work3);
                worker1.Start();
                worker2.Start();
                worker3.Start();
                Thread.Sleep(200); //will sleep for x sec
                Console.WriteLine("Il risultato è {0}\n", a.result);
            }
            Console.Read();
        }
    }

}
