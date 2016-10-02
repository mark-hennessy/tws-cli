using System.Linq;

namespace TradeBot.Core.FileIO
{
    public static class StringExtensions
    {
        /// <summary>
        /// Surrounds the given string with quotation marks.
        /// This is useful when writting key/value properties to files.
        /// 
        /// Quotes make cases where the value starts with an equal sign easier to read.
        /// Example: key="====" vs key=====
        /// 
        /// Quotes also make it easy to spot whitespace.
        /// Example: key=", " vs key=,
        /// </summary>
        /// <param name="value">the string instance to act on</param>
        /// <returns>the resulting string</returns>
        public static string SurroundWithQuotes(this string value)
        {
            return $"\"{value}\"";
        }

        /// <summary>
        /// Uppercases the first character of the string.
        /// </summary>
        /// <param name="value">the string instance to act on</param>
        /// <returns>the resulting string</returns>
        public static string TitleCase(this string value)
        {
            if (string.IsNullOrEmpty(value))
            {
                return value;
            }

            return value.First().ToString().ToUpper() + value.Substring(1);
        }

        /// <summary>
        /// Lowercases the first character of the string.
        /// </summary>
        /// <param name="value">the string instance to act on</param>
        /// <returns>the resulting string</returns>
        public static string ReverseTitleCase(this string value)
        {
            if (string.IsNullOrEmpty(value))
            {
                return value;
            }

            return value.First().ToString().ToLower() + value.Substring(1);
        }

        /// <summary>
        /// Uppercases all characters of the string and replaces periods with underscores.
        /// </summary>
        /// <param name="value">the string instance to act on</param>
        /// <returns>the resulting string</returns>
        public static string ToUpperForCode(this string value)
        {
            return value.Replace('.', '_').ToUpper();
        }

        /// <summary>
        /// Lowercases all characters of the string and replaces underscores with periods.
        /// </summary>
        /// <param name="value">the string instance to act on</param>
        /// <returns>the resulting string</returns>
        public static string ToLowerForFile(this string value)
        {
            return value.Replace('_', '.').ToLower();
        }

        /// <summary>
        /// Pascal cases the string and replaces periods with underscores.
        /// Periods denote word boundaries.
        /// </summary>
        /// <param name="value">the string instance to act on</param>
        /// <returns>the resulting string</returns>
        public static string PascalCaseForCode(this string value)
        {
            var words = value.Split('.').Select(s => s.TitleCase());
            return string.Join("_", words);
        }

        /// <summary>
        /// camelCases the string and replaces underscores with periods.
        /// Underscores denote word boundaries.
        /// </summary>
        /// <param name="value">the string instance to act on</param>
        /// <returns>the resulting string</returns>
        public static string camelCaseForFile(this string value)
        {
            var words = value.Split('_').Select(s => s.ReverseTitleCase());
            return string.Join(".", words);
        }
    }
}
