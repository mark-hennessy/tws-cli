using System;
using System.Threading.Tasks;

namespace TradeBot.Extensions
{
    public static class TaskExtensions
    {
        public static async Task TimeoutAfter(this Task task, int millisecondsTimeout)
        {
            if (task == await Task.WhenAny(task, Task.Delay(millisecondsTimeout)).ConfigureAwait(false))
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

        /// <summary>
        /// Sets the result on the task completion source if the task has not already been completed.
        /// </summary>
        /// <typeparam name="T">the result type</typeparam>
        /// <param name="tcs">the subject</param>
        /// <param name="result">the task result</param>
        public static void SafelySetResult<T>(this TaskCompletionSource<T> tcs, T result)
        {
            if (tcs.Task.IsCompleted)
            {
                return;
            }

            tcs.SetResult(result);
        }
    }
}
