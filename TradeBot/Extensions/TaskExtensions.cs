﻿using System.Threading.Tasks;

namespace TradeBot.Extensions
{
    public static class TaskExtensions
    {
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