using System;

namespace TradeBot.Core.FileIO
{
    /// <summary>
    /// A utility class for generating C# constants for resource property values.
    /// </summary>
    public class ResourceClassGenerator
    {
        public static void Main(string[] args)
        {
            string thisNamespace = ResourceFiles.NAMESPACE;
            string className = args[0];
            bool constant = bool.Parse(args[1]);
            Properties properties = new Properties();
            for (int i = 2; i < args.Length; i++)
            {
                string resourcePath = args[i];
                properties.Load(resourcePath);
            }

            ClassBuilder classBuilder = new ClassBuilder();
            classBuilder.AppendNamespace(thisNamespace);
            classBuilder.AppendStaticClass(className);

            if (constant)
            {
                classBuilder.AppendConstFieldsForPropertyValues(properties);
            }
            else
            {
                classBuilder.AppendStaticPropertiesForPropertyValues(properties);
            }

            Console.Write(classBuilder);
        }

    }
}
