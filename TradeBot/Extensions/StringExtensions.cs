using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TradeBot.Extensions
{
    public static class StringExtensions
    {
        public static int? ToInt(this string str)
        {
            int result;
            bool validInput = int.TryParse(str, out result);
            return validInput ? result : default(int?);
        }

        public static double? ToDouble(this string str)
        {
            double result;
            bool validInput = double.TryParse(str, out result);
            return validInput ? result : default(double?);
        }

        public static string ToCurrencyString(this double currency)
        {
            return string.Format("{0:C}", currency);
        }

        public static string ToCurrencyString(this decimal currency)
        {
            return string.Format("{0:C}", currency);
        }

        public static string ToPrettyString(this object obj, int indentLevel = 0)
        {
            // Formatting is not necessary for strings and value types such as bool, int, double, etc.
            Type type = obj.GetType();
            if (type == typeof(string) || type.IsValueType)
            {
                return obj.ToString();
            }

            var keyValuePairs = obj.GetType()
                .GetProperties()
                // Exclude indexed properties to avoid Parameter Count Mismatch exceptions.
                .Where(p => p.GetIndexParameters().Length == 0)
                .Select(p => new KeyValuePair<string, object>(p.Name, p.GetValue(obj, null)));
            return ToPrettyString(keyValuePairs, indentLevel);
        }

        public static string ToPrettyString(this IEnumerable<KeyValuePair<string, object>> keyValuePairs, int indentLevel = 0)
        {
            if (keyValuePairs.Count() == 0)
            {
                return "{}";
            }

            string indentString = GetIndentString(indentLevel);
            int bodyIndentLevel = indentLevel + 1;
            string bodyIndentString = GetIndentString(bodyIndentLevel);

            StringBuilder builder = new StringBuilder();
            // Don't indent the opening curly brace. Assume it will be inine.
            // e.g. contract: {
            builder.Append("{");
            foreach (var pair in keyValuePairs)
            {
                builder
                    .AppendLine()
                    .Append(bodyIndentString)
                    .AppendFormat("{0} : {1}",
                        pair.Key,
                        pair.Value?.ToPrettyString(bodyIndentLevel));
            }
            builder
                .AppendLine()
                .Append(indentString)
                .Append("}");
            return builder.ToString();
        }

        private static string GetIndentString(int indentLevel)
        {
            return new string(' ', 2 * indentLevel);
        }
    }
}
