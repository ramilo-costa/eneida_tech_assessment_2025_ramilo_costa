# Explain how your code handles circular wrap-around behavior

On push function the line cb->head = (cb->head + 1) % BUFFER_SIZE
This guarantees that my head will always count from 0 to Buffer size because it uses mod division. 
This means everytime will reach the end (BUFFER_SIZE) the division will return 0 and then 1, 2, and so forth