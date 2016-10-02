using System;

namespace TradeBot.Core.FileIO
{
    /// <summary>
    /// A utility program for generating C# constants for resource property keys.
    /// </summary>
    public class ResourceKeyClassGenerator
    {
        public static void Main(string[] args)
        {
            string thisNamespace = ResourceFiles.NAMESPACE;
            string className = args[0];
            Properties properties = new Properties();
            for (int i = 1; i < args.Length; i++)
            {
                string resourcePath = args[i];
                properties.Load(resourcePath);
            }

            ClassBuilder classBuilder = new ClassBuilder();
            classBuilder.AppendNamespace(thisNamespace);
            classBuilder.AppendStaticClass(className);
            classBuilder.AppendConstFieldsForPropertyKeys(properties);
            Console.Write(classBuilder);
        }
    }
}
