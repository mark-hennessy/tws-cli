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
        /// Appends a new line, declares a namespace, and opens a new scope for it.
        /// </summary>
        /// <param name="namespaceName">the name of the namespace</param>
        public void AppendNamespace(string namespaceName)
        {
            AppendNewLine($"namespace {namespaceName}");
            OpenNewScope();
        }

        /// <summary>
        /// Appends a new line, declares a static class, and opens a new scope for it.
        /// </summary>
        /// <param name="className">the name of the class</param>
        public void AppendStaticClass(string className)
        {
            AppendNewLine($"public static class {className}");
            OpenNewScope();
        }

        /// <summary>
        /// Appends a string constant for each key in the given properties object. 
        /// Properties are sorted by key in ascending order.
        /// </summary>
        /// <param name="properties">the properties object for which to append constants</param>
        public void AppendKeyConstants(Properties properties)
        {
            properties.Keys
                .OrderBy(k => k)
                .ToList()
                .ForEach(AppendKeyConstant);
        }

        /// <summary>
        /// Appends a string constant for the given key.
        /// </summary>
        /// <param name="key">the key for which to append a constant</param>
        public void AppendKeyConstant(string key)
        {
            AppendConstant(DataType.STRING, GetConstantVariableName(key), key);
        }

        /// <summary>
        /// Appends a constant for each value in the given properties object.
        /// Data types are derived from the values.
        /// Properties are sorted by key in ascending order.
        /// </summary>
        /// <param name="properties">the properties object for which to append constants</param>
        public void AppendValueConstants(Properties properties)
        {
            properties
                .OrderBy(kvp => kvp.Key)
                .ToList()
                .ForEach(kvp => AppendValueConstant(kvp.Key, kvp.Value));
        }

        /// <summary>
        /// Appends a constant for the given value.
        /// The data type is derived from the value.
        /// </summary>
        /// <param name="key">the key for the value</param>
        /// <param name="value">the value for which to append a constant</param>
        public void AppendValueConstant(string key, string value)
        {
            AppendConstant(DataTypeParser.ParseDataType(value), GetConstantVariableName(key), value);
        }

        /// <summary>
        ///  Appends a constant field.
        /// </summary>
        /// <param name="dataType">the const data type</param>
        /// <param name="name">the const name</param>
        /// <param name="value">the const value</param>
        public void AppendConstant(DataType dataType, string name, string value)
        {
            if (dataType.Equals(DataType.STRING))
            {
                // Add quotation marks around the string.
                value = $"\"{value}\"";
            }

            AppendNewLine($"public const {dataType.AsString()} {name} = {value};");
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

        private string GetConstantVariableName(string key)
        {
            return key.Replace('.', '_').ToUpper();
        }
    }
}
