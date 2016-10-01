namespace TradeBot.Core.FileIO
{
    public static class DataTypeParser
    {
        public static DataType ParseDataType(string value)
        {
            bool boolResult;
            if (bool.TryParse(value, out boolResult))
            {
                return DataType.BOOL;
            }

            // Check if the value is a int before checking if it is a double
            // because an int can be parsed to a double but a double cannot be parsed to an int.
            int intResult;
            if (int.TryParse(value, out intResult))
            {
                return DataType.INT;
            }

            double doubleResult;
            if (double.TryParse(value, out doubleResult))
            {
                return DataType.DOUBLE;
            }

            return DataType.STRING;
        }
    }

    public enum DataType { BOOL, INT, DOUBLE, STRING }

    public static class DataTypeExtensions
    {
        public static string AsString(this DataType dataType)
        {
            return dataType.ToString().ToLower();
        }
    }
}
