The res folder contains key/value property files. The app reads user preferences, localized messages, and persisted application state from these files.

Properties are stored in plain text format for convenience so that property values can be edited by hand when the app is not running.

state
==
The app persists its state to this file before closing. State is stored in plain text key/value pairs.

Modification by hand is allowed, but should be done with caution.

message
==
This file defines the messages used by the app. 

Changes to messages will take effect the next time the app is launched.

default.prefs
==
This file defines which preferences are available and assigns a default value to them. 

This file should not be modified by users.

user.prefs
==
This file allows users to set custom preference values which will overwrite the default values.