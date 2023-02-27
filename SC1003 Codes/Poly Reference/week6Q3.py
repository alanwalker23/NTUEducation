from sense_hat import SenseHat
from Stick import SenseStick

sense = SenseHat()
stick = SenseStick()
sense.clear()
a = 0
b = 7
r = 0
g = 0
b1 = 204
sense.set_pixel(a,b,r,g,b1)
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
            sense.clear()
            if d[event.key] == 'up':
                # DO SOMETHING
                if b == 0:
                    b = 7
                else:
                    b-=1
                    b1 =255

            #if joystick is moved down
            elif d[event.key] == 'down':
                # DO SOMETHING
                if b == 7:
                    b = 0
                else:
                    b+=1
                    r =51
                    g =51
                    b1 =255

            #if joystick is moved left
            elif d[event.key] == 'left':
                # DO SOMETHING
                if a == 0:
                    a = 7
                else:
                    a-=1
                    r =102
                    g =102
                    b1 =255

            #if joystick is moved right
            elif d[event.key] == 'right':
                # DO SOMETHING
                if a == 7:
                    a = 0
                else:
                    a+=1
                    r =153
                    g =153
                    b1 =255           

            #if joystick is pushed
            elif d[event.key] == 'push':
                # DO SOMETHING
                sense.show_message("",back_colour=[0,255,255])
            sense.clear()    
            sense.set_pixel(a,b,r,g,b1)
