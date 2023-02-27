from sense_hat import SenseHat
from Stick import SenseStick

sense = SenseHat()
stick = SenseStick()
sense.clear()

d ={
    stick.KEY_UP: 'up',
    stick.KEY_DOWN: 'down',
    stick.KEY_LEFT: 'left',
    stick.KEY_RIGHT: 'right',
    stick.KEY_ENTER: 'push',
    }

while True:
    for event in stick:
        if event.state == stick.STATE_PRESS:
            #if joystick is moved up
            if d[event.key] == 'up':
                # DO SOMETHING 

            #if joystick is moved down
            elif d[event.key] == 'down':
                # DO SOMETHING

            #if joystick is moved left
            elif d[event.key] == 'left':
                # DO SOMETHING

            #if joystick is moved right
            elif d[event.key] == 'right':
                # DO SOMETHING

            #if joystick is pushed
            elif d[event.key] == 'push':
                # DO SOMETHING

                break

    break
