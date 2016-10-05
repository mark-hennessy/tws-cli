using System;

namespace TradeBot.Extensions
{
    public static class ArrayExtensions
    {
        public static int LastIndex(this Array array)
        {
            return array.Length - 1;
        }
    }
}
