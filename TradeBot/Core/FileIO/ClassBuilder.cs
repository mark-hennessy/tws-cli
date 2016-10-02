using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace TradeBot.Core.FileIO
{
    /// <summary>
    /// A builder class for generating C# code.
    /// </summary>
    public class ClassBuilder
    {
        private const int INDENT_SIZE = 4;

        private int indentLevel;
        private StringBuilder stringBuilder;

        public ClassBuilder()
        {
            stringBuilder = new StringBuilder();
        }

        /// <summary>
        /// Appends a namespace.
        /// </summary>
        /// <param name="namespaceName">the name of the namespace</param>
        public void AppendNamespace(string namespaceName)
        {
            AppendNewLine($"namespace {namespaceName}");
            OpenNewScope();
        }

        /// <summary>
        /// Appends a static class.
        /// </summary>
        /// <param name="className">the name of the class</param>
        public void AppendStaticClass(string className)
        {
            AppendNewLine($"public static class {className}");
            OpenNewScope();
        }

        /// <summary>
        /// Appends a const field for each key in the given properties object. 
        /// Properties are sorted by key in ascending order.
        /// </summary>
        /// <param name="properties">a properties object</param>
        public void AppendConstFieldsForPropertyKeys(Properties properties)
        {
            properties.Keys
                .OrderBy(k => k)
                .ToList()
                .ForEach(AppendConstFieldForPropertyKey);
        }

        /// <summary>
        /// Appends a const field for the given key.
        /// </summary>
        /// <param name="key">a property key</param>
        public void AppendConstFieldForPropertyKey(string key)
        {
            AppendConstField(
                DataType.STRING,
                key.ToUpperForCode(),
                key);
        }

        /// <summary>
        /// Appends a const field for each value in the given properties object.
        /// Data types are derived from the values.
        /// Properties are sorted by key in ascending order.
        /// </summary>
        /// <param name="properties">a properties object</param>
        public void AppendConstFieldsForPropertyValues(Properties properties)
        {
            properties
                .OrderBy(kvp => kvp.Key)
                .ToList()
                .ForEach(kvp => AppendConstFieldForPropertyValue(kvp.Key, kvp.Value));
        }

        /// <summary>
        /// Appends a const field for the given value.
        /// The data type is derived from the value.
        /// </summary>
        /// <param name="key">the property key</param>
        /// <param name="value">the property value</param>
        public void AppendConstFieldForPropertyValue(string key, string value)
        {
            AppendConstField(
                DataTypeParser.ParseDataType(value),
                key.ToUpperForCode(),
                value);
        }

        /// <summary>
        ///  Appends a const field.
        /// </summary>
        /// <param name="dataType">the field data type</param>
        /// <param name="name">the field name</param>
        /// <param name="value">the field value</param>
        private void AppendConstField(DataType dataType, string name, string value)
        {
            if (dataType.Equals(DataType.STRING))
            {
                value = value.SurroundWithQuotes();
            }

            AppendNewLine($"public const {dataType.AsString()} {name} = {value};");
        }

        /// <summary>
        /// Appends a static property for each value in the given properties object.
        /// Data types are derived from the values.
        /// Properties are sorted by key in ascending order.
        /// </summary>
        /// <param name="properties">a properties object</param>
        public void AppendStaticPropertiesForPropertyValues(Properties properties)
        {
            properties
                .OrderBy(kvp => kvp.Key)
                .ToList()
                .ForEach(kvp => AppendStaticPropertyForPropertyValue(kvp.Key, kvp.Value));
        }

        /// <summary>
        /// Appends a static property for the given value.
        /// The data type is derived from the value.
        /// </summary>
        /// <param name="key">the property key</param>
        /// <param name="value">the property value</param>
        public void AppendStaticPropertyForPropertyValue(string key, string value)
        {
            AppendStaticProperty(
                DataTypeParser.ParseDataType(value),
                key.PascalCaseForCode(),
                value);
        }

        /// <summary>
        ///  Appends a static property.
        /// </summary>
        /// <param name="dataType">the property data type</param>
        /// <param name="name">the property name</param>
        /// <param name="value">the property value</param>
        private void AppendStaticProperty(DataType dataType, string name, string value)
        {
            if (dataType.Equals(DataType.STRING))
            {
                value = value.SurroundWithQuotes();
            }

            AppendNewLine($"public static {dataType.AsString()} {name} {{ get; set; }} = {value};");
        }

        /// <summary>
        /// Appends a new line, appends an opening curly brace, and indents the file.
        /// </summary>
        public void OpenNewScope()
        {
            AppendNewLine("{");
            indentLevel++;
        }

        /// <summary>
        /// Appends a new line, outdents the file, and appends a closing curly brace.
        /// </summary>
        public void CloseCurrentScope()
        {
            indentLevel--;
            AppendNewLine("}");
        }

        /// <summary>
        /// Appends a new line.
        /// </summary>
        /// <param name="optionalText">optional text to indent and append</param>
        public void AppendNewLine([Optional] string optionalText)
        {
            stringBuilder.AppendLine();
            if (!string.IsNullOrEmpty(optionalText))
            {
                stringBuilder.Append(' ', INDENT_SIZE * indentLevel);
                stringBuilder.Append(optionalText);
            }
        }

        /// <summary>
        /// Closes all currently open scopes and converts the value of this instance to a string.
        /// </summary>
        /// <returns>the generated file as a string</returns>
        public override string ToString()
        {
            while (indentLevel > 0)
            {
                CloseCurrentScope();
            }

            return stringBuilder.ToString();
        }
    }
}
