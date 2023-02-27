from sense_hat import SenseHat
sense=SenseHat()
sense.show_message('',back_colour=[0,0,255])
for y in range(8):
    for x in range(8):
        if y%2==0 and x%2==0:
            sense.set_pixel(x,y,255,0,0)
        elif y%2==1 and x%2==1:
            sense.set_pixel(x,y,255,0,0)
        else:
            sense.set_pixel(x,y,0,0,255)
            
    
