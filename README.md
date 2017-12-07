# multihop-comm-M3-nodes
An example to show how multihop communication between nodes in a Wireless Sensor Network works.

The 3 c scripts available here are scripts written to be flashed on m3 nodes.
To use m3 node on your computer, first follow this tutorial: https://gist.github.com/vandaele/d77c54020575b805a7d03268f99d9552

Then, while your m3 node is connected to your computer via USB; open a termianl an go to:

	$ cd /iot-lab/parts/openlab/build.m3
Then run:

	$ sudo make flash_send_lightX 
With X = 1, 2 or 3.


Explanation:

These 3 scripts illustrate how multihop communication between nodes works.
- A 1st node captures the luminous intensity with its sensor and sends the value in broadcast via a radio packet.
- A 2nd node recieves the 1st node's packet and just transferts it via an other packet sent in broadcast.
- A 3rd node connected to a pc recieves the 2nd node's packet (or both packets if the 3rd node is within range of 1st node). 

Even if the 1st and the 3rd nodes are to far one to each other (about 30 metres), the message will still be sent thanks to the 2nd node wich is located between the 1st and the 3rd.
