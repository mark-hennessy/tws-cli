using Newtonsoft.Json;
using System.IO;

namespace TradeBot.FileIO
{
    public static class PropertySerializer
    {
        public static T Deserialize<T>(string path)
        {
            return JsonConvert.DeserializeObject<T>(File.ReadAllText(path));
        }

        public static void Serialize<T>(T propertyClass, string path)
        {
            File.WriteAllText(path, JsonConvert.SerializeObject(propertyClass));
        }
    }
}
