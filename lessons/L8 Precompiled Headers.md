Precompiled headers allow headers that are used often to be precompiled so they don't have to be compiled again whenever a change is made to the source files. When compile times get very long, it is important to use precompiled headers.

Precompiled headers can hide the dependencies of a file. This can hurt the modularity of a file if the dependancies are immediately shown. 