using System.ComponentModel;

namespace TradeBot.Events
{
    public class PropertyValueChangedEventArgs<T> : PropertyChangedEventArgs
    {
        public PropertyValueChangedEventArgs(string propertyName, T oldValue, T newValue)
            : base(propertyName)
        {
            OldValue = oldValue;
            NewValue = newValue;
        }

        public T OldValue { get; }

        public T NewValue { get; }
    }
}
