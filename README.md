# AthenaMT
## Asynchronous, MultiThreaded, Shardable Ragnarok Online Emulator
AthenaMT is a private Ragnarok Online emulator which relies on asynchronous and multithreading technologies to improve the performance and scalability of Ragnarok Online servers.
Also AthenaMT comes with a completely new scripting language, called ChaiScript, which is inspired by ECMAScript. This should lead to more script developers, since the syntax of the language is very easy to learn.

## Powered by C++ and Boost
AthenaMT is relying on C++11 and the boost libraries, which helps us to develop the emulator faster and keep the source codes understandable. There is only one other dependency: MongoDB C++ Driver.

## Redis and MongoDB
Unlike other Ragnarok Online emulators, AthenaMT is using MongoDB as storage for all server related data and redis in order to synchronize all region servers. Since the data is cached in a central location, there are only a few things which needs to be transferred between the servers themselves.

## Support AthenaMT
AthenaMT has it's own IRC Channel. Come and join our community!

>IRC Server: irc.rizon.net:6667

>IRC Channel: #AthenaMT
