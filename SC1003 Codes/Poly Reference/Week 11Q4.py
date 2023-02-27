from sense_hat import SenseHat
sense=SenseHat()
sense.show_message('',back_colour=[0,0,255])
a=0
for i in range(4):
    for j in range (8):
        sense.set_pixel(j,a,255,0,0)
    a+=2
