using IBApi;
using static TradeBot.Resources;

namespace TradeBot.Tws
{
    public class TwsClient : EClientSocket
    {
        public TwsClient() : base(new TwsResponseHandler())
        {
        }

        public void eConnect()
        {
            eConnect(
                Preferences.TwsClientInfo.Url,
                Preferences.TwsClientInfo.Port,
                Preferences.TwsClientInfo.Id);
        }
    }
}
