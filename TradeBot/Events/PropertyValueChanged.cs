namespace TradeBot.Events
{
    public interface INotifyPropertyValueChanged
    {
        event PropertyValueChangedEventHandler PropertyValueChanged;
    }

    public delegate void PropertyValueChangedEventHandler(object sender, PropertyValueChangedEventArgs eventArgs);

    public class PropertyValueChangedEventArgs
    {
        public PropertyValueChangedEventArgs(string propertyName, object oldValue, object newValue)
        {
            PropertyName = propertyName;
            OldValue = oldValue;
            NewValue = newValue;
        }

        public string PropertyName { get; }

        public object OldValue { get; }

        public object NewValue { get; }
    }
}
