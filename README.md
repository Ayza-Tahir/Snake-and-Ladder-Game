# Snake-and-Ladder-Game C++ Queue
In this C++ program, we create a Snake and Ladder game using predefined queue functions: push, pop, front, and empty. We utilize three queues to manage user data: one for user names, another for user scores, and a third one to store the game results.

The game board contains specific positions where snakes are located. If a user lands on a snake's position, they are moved downwards on the board. Conversely, certain positions have ladders, enabling users to ascend to higher positions.

Players take turns rolling the dice using the rand function to determine the number of steps they can advance on the board. The program keeps track of their positions using the queue for user scores and updates them accordingly after each roll.

The game continues until a player reaches the end position, and the result queue records the outcomes of each game session.

By incorporating randomness through the rand function, the game offers a dynamic and engaging experience for users, enhancing the excitement of rolling the dice and navigating through the board. It demonstrates the use of queues to manage player data effectively and showcases the classic Snake and Ladder gameplay, where luck and strategy play key roles in achieving victory.
