using Newtonsoft.Json;
using System.IO;

namespace TradeBot.FileIO
{
    public static class PropertySerializer
    {
        public static TProp Deserialize<TProp>(string path)
        {
            return JsonConvert.DeserializeObject<TProp>(File.ReadAllText(path));
        }

        public static void Serialize<TProp>(TProp propertyClass, string path)
        {
            File.WriteAllText(path, JsonConvert.SerializeObject(propertyClass));
        }
    }
}
