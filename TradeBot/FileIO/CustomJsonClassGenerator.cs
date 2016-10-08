using System.IO;
using Xamasoft.JsonClassGenerator;

namespace TradeBot.FileIO
{
    public class CustomJsonClassGenerator
    {
        public static void Main(string[] args)
        {
            string pathToJson = args[0];
            string pathToClass = args[1];
            string namespaceName = args[2];

            string json = File.ReadAllText(pathToJson);
            string folderPath = Path.GetDirectoryName(pathToClass);
            string className = Path.GetFileNameWithoutExtension(pathToClass);

            JsonClassGenerator generator = new JsonClassGenerator();
            generator.Example = json;
            generator.TargetFolder = folderPath;
            generator.MainClass = className;
            generator.Namespace = namespaceName;
            generator.SingleFile = true;
            // Set UseNestedClasses to false because it doesn't work... 
            generator.UseNestedClasses = false;
            generator.UseProperties = true;
            generator.UsePascalCase = true;
            generator.AlwaysUseNullableValues = true;
            generator.GenerateClasses();
        }
    }
}
