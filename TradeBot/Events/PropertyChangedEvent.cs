namespace TradeBot.Events
{
    public delegate void PropertyChangedEventHandler(object sender, PropertyChangedEventArgs e);

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
