using System.Collections.Generic;
using System.Linq;

namespace TradeBot.Extensions
{
    public static class CollectionExtensions
    {
        // <summary>
        /// Determines whether the collection is null or contains no elements.
        /// </summary>
        /// <typeparam name="T">The IEnumerable type.</typeparam>
        /// <param name="enumerable">The enumerable, which may be null or empty.</param>
        /// <returns>
        ///     <c>true</c> if the IEnumerable is null or empty; otherwise, <c>false</c>.
        /// </returns>
        public static bool IsNullOrEmpty<T>(this IEnumerable<T> enumerable)
        {
            if (enumerable == null)
            {
                return true;
            }

            var collection = enumerable as ICollection<T>;
            return collection?.IsEmpty() ?? enumerable.IsEmpty();
        }

        public static bool IsEmpty<T>(this ICollection<T> enumerable)
        {
            // Use the Count property for efficiency. 
            // The Count property is O(1) while IEnumerable.Count() is O(N). 
            return enumerable.Count == 0;
        }

        public static bool IsEmpty<T>(this IEnumerable<T> enumerable)
        {
            return !enumerable.Any();
        }

        public static int LastIndex<T>(this IEnumerable<T> enumerable)
        {
            return enumerable.Count() - 1;
        }
    }
}
