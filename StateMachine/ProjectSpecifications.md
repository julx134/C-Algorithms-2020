No Commands:
Before any commands are issued to the program, it prints out the starting state.

One/Zero Commands:
These commands (a '0' or a '1' on a line by itself) prints to stdout the name of the next state given the supplied input, and update the current state.

Change command:
The change command is invoked by the letter 'c' followed by a '1' or a '0' followed by the name of a state (i.e. a single letter in the range A–H). This command modifies the state machine such that the '0' (or '1') command applied to the current state will cause the machine to change to the named state and that this change is the state machine configuration will continue. This command produces no output.

Print command:
The print command is invoked with the single letter 'p'. It prints to stdout the state machine configuration as currently specified (i.e. including changes that may have been made with change commands) in the same format the state machine was specified with.

Garbage Identify command:
This command is invoked with the single letter 'g'. It should identify all states that are reachable or unreachable from the current state. It always produces output to stdout.
If all states are reachable, it should output No garbage. 

Delete command:
This command is invoked with 'd', optionally followed by the name of a state to delete. When the ‘d’ command is invoked without the optional argument, it deletes (i.e. mark as “deleted”) all un-deleted states that are unreachable. If there are no such unreachable un-deleted states, it prints no states deleted.