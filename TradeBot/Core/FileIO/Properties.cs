using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace TradeBot.Core.FileIO
{
    public class Properties : IEnumerable<KeyValuePair<string, string>>
    {
        private Dictionary<string, string> propertyMap;

        public Properties()
        {
            propertyMap = new Dictionary<string, string>();
        }

        public IEnumerable<string> Keys
        {
            get
            {
                return propertyMap.Keys.AsEnumerable();
            }
        }

        public string GetString(string key)
        {
            return propertyMap.ContainsKey(key) ? propertyMap[key] : null;
        }

        public int GetInt(string key)
        {
            return GetExoticType(key, int.Parse);
        }

        public double GetDouble(string key)
        {
            return GetExoticType(key, double.Parse);
        }

        public bool GetBool(string key)
        {
            return GetExoticType(key, bool.Parse);
        }

        public T GetExoticType<T>(string key, Func<string, T> parser)
        {
            string valueAsString = GetString(key);
            return valueAsString != null ? parser(valueAsString) : default(T);
        }

        public void Set(string key, object value)
        {
            if (propertyMap.ContainsKey(key))
            {
                propertyMap[key] = value.ToString();
            }
            else
            {
                propertyMap.Add(key, value.ToString());
            }
        }

        /// <summary>
        /// Saves the properties to a file. 
        /// Properties are sorted by key in ascending order to ensure order is always consistent.
        /// Note that overwriting an existing file will remove comments, empty lines, 
        /// white-space formatting etc.
        /// </summary>
        /// <param name="path">the file to save the properties to</param>
        public void Save(string path)
        {
            File.WriteAllText(path, ToString());
        }

        /// <summary>
        /// Loads properties from a file.
        /// This method can be called multiple times to load properties from multiple files.
        /// Property values from the new file will overwrite values from the previous file.
        /// </summary>
        /// <param name="path">the path to the file from which to load properties</param>
        public void Load(string path)
        {
            if (!File.Exists(path))
            {
                return;
            }

            foreach (string line in File.ReadAllLines(path))
            {
                if (!string.IsNullOrEmpty(line)
                    && line.Contains("=")
                    // Ignore comments
                    && !line.StartsWith(";")
                    && !line.StartsWith("#")
                    && !line.StartsWith("'"))
                {
                    int equalSignIndex = line.IndexOf("=");
                    string key = line.Substring(0, equalSignIndex).Trim();
                    string value = string.Empty;
                    int valueStartIndex = equalSignIndex + 1;
                    if (valueStartIndex < line.Length)
                    {
                        // Don't trim the value like we do for the key.
                        // The value may have leading or trailing white space on purpose.
                        value = line.Substring(valueStartIndex);
                    }

                    // Remove leading and trailing quotation marks from the value if present.
                    string doubleQuote = "\"";
                    string singleQuote = "'";
                    if ((value.StartsWith(doubleQuote) && value.EndsWith(doubleQuote)) ||
                        (value.StartsWith(singleQuote) && value.EndsWith(singleQuote)))
                    {
                        value = value.Substring(1, value.Length - 2);
                    }

                    Set(key, value);
                }
            }
        }

        /// <summary>
        /// Clears all properties from memory.
        /// Note that the actual properties file will not be cleared unless the Save method is called.
        /// </summary>
        public void ClearAll()
        {
            propertyMap.Clear();
        }

        public IEnumerator<KeyValuePair<string, string>> GetEnumerator()
        {
            return propertyMap.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return propertyMap.GetEnumerator();
        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            // Order of keys in a dictionary is not guaranteed.
            // Sort properties by key in ascending order to ensure property order is always consistent.
            foreach (string key in Keys.OrderBy(k => k))
            {
                string format;
                string value = propertyMap[key] ?? string.Empty;
                if (DataTypeParser.ParseDataType(value).Equals(DataType.STRING))
                {
                    // Surround the string value with quotation marks.
                    // This makes cases where the value starts with an equal sign easier to read.
                    // Example: key="====" vs key=====
                    // This also makes it easy to spot whitespace
                    // Example: key=", " vs key=, 
                    format = "{0}=\"{1}\"";
                }
                else
                {
                    format = "{0}={1}";
                }
                stringBuilder.AppendFormat(format, key, value);
                stringBuilder.AppendLine();
            }
            return stringBuilder.ToString();
        }
    }
}
