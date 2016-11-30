using System;
using System.Threading.Tasks;

namespace TradeBot.Extensions
{
    public static class TaskExtensions
    {
        public static async Task TimeoutAfter(this Task workerTask, int timeoutInMilliseconds)
        {
            Task timerTask = Task.Delay(timeoutInMilliseconds);
            Task firstCompletedTask = await Task.WhenAny(workerTask, timerTask);

            if (workerTask == firstCompletedTask)
            {
                // Re-await the task so that any exceptions/cancellations are rethrown.
                // No need to ConfigureAwait here since the task has already completed.
                await workerTask;
            }
            else
            {
                throw new TimeoutException();
            }
        }

    }
}
