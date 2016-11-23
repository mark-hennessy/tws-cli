using System.Collections.Generic;
using System.Linq;

namespace TradeBot.Extensions
{
    public static class CollectionExtensions
    {
        public static bool IsNullOrEmpty<T>(this IEnumerable<T> enumerable)
        {
            return enumerable?.IsEmpty() ?? true;
        }

        public static bool IsEmpty<T>(this IEnumerable<T> enumerable)
        {
            return enumerable.Size() == 0;
        }

        public static int LastIndex<T>(this IEnumerable<T> enumerable)
        {
            return enumerable.Size() - 1;
        }

        private static int Size<T>(this IEnumerable<T> enumerable)
        {
            // The Count property is O(1) while IEnumerable.Count() is O(N)
            var collection = enumerable as ICollection<T>;
            return collection?.Count ?? enumerable.Count();
        }
    }
}
