Events are a model of stuff happening in games. How we manage these events is called even handling. 

Events are very variable so it would be cool if we could modify functions on the fly and pass them around. 

For our case, we have an application. That application creates a window object. The window generates events from user input, etc... As we don't want the window to contain any application functions, we can pass the window a callback function instead. 

For simplicity we are not going to implement a buffered event system (a queue for events to be done instead at every frame). We are just going to be letting the event execute and pause the rest of our program (blocking event). 

We need to create Application IEventListener, OnEvent class, Event types and debug data.