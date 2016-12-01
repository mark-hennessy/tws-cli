using System.Runtime.CompilerServices;

namespace TradeBot.Events
{
    public delegate void PropertyChangedEventHandler(PropertyChangedEventArgs e);

    public static class PropertyChangedEventHandlerExtensions
    {
        public static void RaiseEvent<T>(this PropertyChangedEventHandler propertyChangedEvent, T value, [CallerMemberName] string propertyName = null)
        {
            propertyChangedEvent?.Invoke(new PropertyValueChangedEventArgs<T>(propertyName, value, value));
        }

        public static void SetPropertyAndRaiseEvent<T>(this PropertyChangedEventHandler propertyChangedEvent, ref T field, T newValue, [CallerMemberName] string propertyName = null)
        {
            T oldValue = field;
            if (!Equals(oldValue, newValue))
            {
                field = newValue;
                propertyChangedEvent?.Invoke(new PropertyValueChangedEventArgs<T>(propertyName, oldValue, newValue));
            }
        }
    }

    public class PropertyChangedEventArgs
    {
        public PropertyChangedEventArgs(string propertyName)
        {
            PropertyName = propertyName;
        }

        public string PropertyName { get; }
    }

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
