We are developing a Windows class in an abstracted way. 

We are using GLFW. GLFW is an OpenGl extensions that add support for creating windows. 

GLFW does not support DirectX so at some point we will have to replace it. 
In anticipation of this, we will implement a window class per platform. 

Each platform (Windows, Mac, Linux) will have their own separate folder.