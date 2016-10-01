namespace TradeBot.Core.FileIO
{
    /// <summary>
    /// A utility program for sorting resource properties in ascending order.
    /// </summary>
    public class ResourcePropertySorter
    {
        public static void Main(string[] args)
        {
            string resourcePath = args[0];

            Properties properties = new Properties();
            properties.Load(resourcePath);
            // Properties are sorted by key in ascending order when saved to a file. 
            properties.Save(resourcePath);
        }
    }
}
