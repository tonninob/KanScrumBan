This project is trying to provide flexible means to execute scrumming in a team
where traditional partitioning of stories to small tasks is not always 
possible. This should not, however, prevent working in a more traditional
scrumming mode.

Currently there is only a C++ library that provides the basic functionality.
Reason for choosing C++ is simply to refresh the author's memory on the 
langugae.
 
The goal at the moment is to set up a web based system that is scalable (can 
support growing number of users) and one of the possible server side solutions
could include the ZeroMQ framework which provides an easy way to link to this 
C++ library. Nothing is decided yet though. 

Unit tests are written with Google Test.
