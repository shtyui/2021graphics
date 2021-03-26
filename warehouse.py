# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
class WareHouse:
    def __init__(self,name,good1,good2,good3):
        self.name=name
        self.g1_name=good1
        self.g2_name=good2
        self.g3_name=good3
        self.balance_g1=0
        self.balance_g2=0
        self.balance_g3=0
    def stock(self,good_name,amount):
        if amount<=0:
            raise ValueError("must be positive")
        if good_name==self.g1_name:
            self.balance_g1 += amount
            print("Stock "+good_name+"　: ",amount)
            print("Current "+good_name+" account amount:",self.balance_g1)
            if self.balance_g1>100:
                print("Current "+good_name+" is too much!")
                
        if good_name==self.g2_name:
            self.balance_g2+=amount
            print("Stock "+good_name+"　: ",amount)
            print("Current "+good_name+" account amount:",self.balance_g2)
            if self.balance_g2>100:
                print("Current"+good_name+"is too much!")
                
        if good_name==self.g3_name:
            self.balance_g3+=amount
            print("Stock "+good_name+"　: ",amount)
            print("Current "+good_name+" account amount:",self.balance_g3)
            if self.balance_g3>100:
                print("Current"+good_name+"is too much!")
                
                
    def ship(self,good_name,amount):
        if good_name==self.g1_name:
            if amount<=self.balance_g1:
                self.balance_g1-=amount
                print("Ship "+good_name+" : ",amount)
                print("Current "+good_name+" account amount:",self.balance_g1)
                if self.balance_g1<10:
                    print("Current "+good_name+" need to stock!")
            else:
                print('amount not enough')
                
        if good_name==self.g2_name:
            if amount<=self.balance_g2:
                self.balance_g2-=amount
                print("Ship "+good_name+" : ",amount)
                print("Current "+good_name+" account amount:",self.balance_g2)
                if self.balance_g2<10:
                    print("Current "+good_name+" need to stock!")
            else:
                print('amount not enough')
                
        if good_name==self.g3_name:
            if amount<=self.balance_g3:
                self.balance_g3-=amount
                print("Ship "+good_name+" : ",amount)
                print("Current "+good_name+" account amount:",self.balance_g3)
                if self.balance_g3<10:
                    print("Current "+good_name+" need to stock!")
            else:
                print('amount not enough')
                
                
    def retrival(self,good_name):
        if good_name==self.g1_name:
            print("Current "+good_name+" account amount:",self.balance_g1)
            
        if good_name==self.g2_name:
            print("Current "+good_name+" account amount:",self.balance_g2)
            
        if good_name==self.g3_name:
            print("Current "+good_name+" account amount:",self.balance_g3)

w1=WareHouse('MCU','Apple','Orange','Watermelon')
run=1
while run==1:
    command=input("Enter the operation: 1: Stock ,2: Ship ,3:Retrival ,4: End:")
    if command=="1":
        name=input("The item name:")
        num=(int)(input("The item number:"))
        w1.stock(name,num)
    if command=="2":
        name=input("The item name:")
        num=(int)(input("The item number:"))
        w1.ship(name,num)
    if command=='3':
        name=input("The item name:")
        w1.retrival(name)
    if command=='4':
        print("The End")
        run=0
        break
                
                
                
                
                
                
                
                
                
                
                
                