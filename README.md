# labyrinth-solving-robot

With use of two HC-SR04 distance sensors this robot can follow the wall on its right to get out of a labyrinth.
Definitions on the top declares which pins are connected to right motor, left motor and the sensors.
We set pin modes on setup function.
Our main function runs on loop function, idea of the code is if right sensor perceives a wall and front sensor doesn't, the car moves forward until something blocks its 
way or the wall on its right ends. If something comes up infront of the car, it turns to left. If the wall on its right comes to an end, it turns to right. Also there 
are some other regulations. In order not to lose the wall on its right, left motor runs in a little bit higher power. PS: Powers are optimized for my car.
So, if the car gets too close to the wall, right motor gets more power so it doesn't crash.

Functions down below indicates power of motors in order to determine which way will the car go.
