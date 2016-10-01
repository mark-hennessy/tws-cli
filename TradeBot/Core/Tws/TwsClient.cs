using IBApi;
using TradeBot.Core.Resources;

namespace TradeBot.Core.Tws
{
    public class TwsClient : EClientSocket
    {
        public TwsClient() : base(new TwsResponseHandler())
        {
        }

        public void eConnect()
        {
            eConnect(
                Preferences.TWSCLIENT_URL,
                Preferences.TWSCLIENT_PORT,
                Preferences.TWSCLIENT_ID);
        }
    }
}
