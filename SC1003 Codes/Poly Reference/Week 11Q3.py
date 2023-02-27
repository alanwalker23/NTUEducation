from sense_hat import SenseHat
sense=SenseHat()
sense.show_message('',back_colour=[0,0,255])
for i in range(9):
    for j in range(i):
        sense.set_pixel(j,j,255,0,0)
        
        
