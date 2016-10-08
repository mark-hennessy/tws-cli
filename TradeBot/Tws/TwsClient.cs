using IBApi;
using static TradeBot.Resources;

namespace TradeBot.Tws
{
    public class TwsClient : EClientSocket
    {
        public TwsClient(TwsResponseHandler handler)
            : base(handler)
        {
        }

        public void eConnect()
        {
            eConnect(
                Preferences.ClientUrl,
                Preferences.ClientPort.Value,
                Preferences.ClientId.Value);
        }
    }
}
