using IBApi;
using static TradeBot.GlobalProperties;

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
                Preferences.ClientPort,
                Preferences.ClientId);
        }
    }
}
