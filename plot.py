import pandas as pd
import numpy  as np
import os  
import time
import math 
import matplotlib.pyplot as plt
Ln = " 8 "
t = " 1.8 "
option = " 4 "
name = "main.out "
f=" wyniki2"
f31= " opt31"
f32= " opt32"
f33= " opt33"   
b = 0.125
v = 1 
def transform_data(x,y,L):
    T_c = 2.69
    print("x" , x)
    print("y", y)
    print("L", L)
    L_y=math.pow(L, b/v)
    print("L_y", L_y)
    y_n = np.multiply(y,L_y)
    print("y_n" , y_n)
    y_n = [math.log(a) for a in y_n]
    print("y_n" , y_n)
    
    L_x = math.pow(L,v)
    x_n = np.multiply(x, 1/T_c) 
    x_n =  [b-1 for b in x_n] 
    x_n = [abs(a) for a in x_n ]
    x_n = np.multiply(x_n,L_x)  
    return x_n, y_n  

print("STARTING ...")
if(option  == " 3 " ):
    
    #command = "main.out" + t + 5 + option  + ">" + f31 +" "  
    #os.system("./" + command)

    data = pd.read_csv("opt31",sep=' ,',header=None, engine = 'python')
    data = pd.DataFrame(data) 
    
    x = data[0]
    y = data[1]
    plt.figure()
    plt.plot(x, y,"." )# Plot some data on the (implicit) axes.
    data = pd.read_csv("opt32",sep=' ,',header=None, engine = 'python')
    data = pd.DataFrame(data) 
    
    x = data[0]
    y = data[1]
    plt.plot(x, y,"*" )# Plot some data on the (implicit) axes.

    plt.xlabel('T')
    plt.grid(1,'major')
    plt.ylabel('m')
    plt.savefig("L520"+".png")
    os.system("chromium " + "L520" +".png")
    
    command = "main.out" + t + 20 + option  + ">" + f32 +" "  
    os.system("./" + command)
    command = "main.out" + t + 80 + option  + ">" + f33 +" "  
    os.system("./" + command)

if(option == " 4 "):
    
    data = pd.read_csv("opt31",sep=' ,',header=None, engine = 'python')
    data = pd.DataFrame(data) 
    
    x = data[0]
    y = data[1]
    x,y = transform_data(x,y,5)
    plt.figure()
    plt.plot(x, y,"." )# Plot some data on the (implicit) axes.
    data = pd.read_csv("opt32",sep=' ,',header=None, engine = 'python')
    data = pd.DataFrame(data) 
    
    x = data[0]
    y = data[1]
    x,y = transform_data(x,y,20)
    plt.plot(x, y,"*" )# Plot some data on the (implicit) axes.

    plt.xlabel('T')
    plt.grid(1,'major')
    plt.ylabel('m')
    plt.savefig("wykres"+".png")
    os.system("chromium " + "wykres" +".png")
    

if(option  == " 1 "):

    command = "main.out" + t + Ln + option  + ">" + f 
    os.system("make")
    os.system("./" + command)

'''
data = pd.read_csv('wyniki2',sep=' ,',header=None, engine = 'python')
data = pd.DataFrame(data)


x = data[0]
y = data[1]
plt.figure()
plt.plot(x, y,"." )# Plot some data on the (implicit) axes.
plt.xlabel('MCS')
plt.grid(1,'major')
plt.ylabel('m')
plt.title("Flips")
plt.savefig("flips2.png")

os.system("chromium " + "flips2" + ".png")
x = data_fi[0]
y = data_fi[1]
sum(x)
sum(y)

plt.figure()
plt.plot(x, y,'.')
plt.title("Unormowana funkcja falowa odpowiadajaca stanowi podstawowemu")
plt.xlabel("x")
plt.ylabel("phi")
plt.savefig("Fi.png")
plt.show()
file = open("dE","r+")
#
'''
#file.truncate(0)
#file.close()
#file = open(f31[1:],"r+")
#file.truncate(0)
#file.close()

