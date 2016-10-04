﻿// Generated by Xamasoft JSON Class Generator
// http://www.xamasoft.com/json-class-generator

using System;
using System.Collections.Generic;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace TradeBot.Gen
{

    public class PreferenceProperties
    {

        [JsonProperty("accountLive")]
        public string AccountLive { get; set; }

        [JsonProperty("accountPaper")]
        public string AccountPaper { get; set; }

        [JsonProperty("clientId")]
        public int ClientId { get; set; }

        [JsonProperty("clientPort")]
        public int ClientPort { get; set; }

        [JsonProperty("clientUrl")]
        public string ClientUrl { get; set; }

        [JsonProperty("windowTitle")]
        public string WindowTitle { get; set; }

        [JsonProperty("windowWidth")]
        public int WindowWidth { get; set; }

        [JsonProperty("windowHeight")]
        public int WindowHeight { get; set; }

        [JsonProperty("windowCentered")]
        public bool WindowCentered { get; set; }
    }

}
