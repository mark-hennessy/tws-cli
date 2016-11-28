using System;
using System.Threading.Tasks;

namespace TradeBot.Extensions
{
    public static class TaskExtensions
    {
        public static async Task TimeoutAfter(this Task task, int millisecondsTimeout)
        {
            Task timer = Task.Delay(millisecondsTimeout);
            if (task == await Task.WhenAny(task, timer).ConfigureAwait(false))
            {
                // Task completed within timeout.
                // Consider that the task may have faulted or been canceled.
                // We re-await the task so that any exceptions/cancellation is rethrown.
                await task.ConfigureAwait(false);
            }
            else
            {
                throw new TimeoutException();
            }
        }

    }
}
