This project implements a state machine and different specifications for it - see ProjectSpecification file.

Everything in the project worked fine. However, note that when starting the program, a warning expression will show.
This is fine, the code still works regardless.

Note that the user must seperate the command arguments and capitalize all state characters.
This is because the UI is built in a way to accomodate the space character i.e. typing 'c0C' will not work and 'c 0 C' will work.
And that typing 'c 0 c' will not work and 'c 0 C' will work.

For the general description of how I implemented this FSM, I first made a State struct which in essence is a "node/states" to which
I will now be calling the State struct either as node/state or node/state objects. I realized that when creating the nodes, it was not possible
to initialize each node under a stuct State array. Therefore, I implemented a pointer array instead that points to each of the states,
so that I could initialize the values for each state. In addition, I have a currentState pointer that will point to the pointer array in order
to traverse the configuration.

The functions I implemented are straight-forward. The hardest part was passing pointers to a function, especially, when deleting and changing nodes
due to the extra layer of pointers on top of the states that also have pointers. In addition, the garbage function, is a recursive function that
works by traversing the last and next nodes where every recursive call will increment a stateNode integer that signifies that it has already been
in that node. This is to prevent an endless recursive call along with other logics that I implemented so that the function is efficient as possible.

