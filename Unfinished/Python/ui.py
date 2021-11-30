from tkinter import *

root = Tk()

class Test:
    Nums = []
    def Add():
        Test.Nums.append(1)
        print(Test.Nums[0])


#Test.Add()

box = Entry(root)
box.pack()
class SB:
    B = []
    def Click():
        SB.B.append(Button(root,text = box.get(), command = SB.Click))
        length = len(SB.B)-1
        SB.B[length].pack()

#class funct:
#    Button2 = Button(root,text = "I am working so hard")
#    def Click():
#        funct.myLabel.pack()

SB.Click()

#myLabel1 = Label(root,text = "Hello World")
#myLabel2 = Label(root,text = "by Jason Miller")
#Button1  = Button(root,text = "Click Me", command = funct.Click)


#myLabel1.grid(row = 0, column = 0)
#myLabel2.grid(row = 1, column = 1)
#Button1.pack()
root.mainloop()
