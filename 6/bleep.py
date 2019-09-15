# -*- coding: utf-8 -*-
"""
Created on Sat Sep 14 19:27:58 2019

@author: cyl
"""

import sys

def main():
   """ program entry"""
   lenargv=len(sys.argv)
   if not lenargv==2:
      return 1

   try:
      fbanned=open(sys.argv[1])
   except IOError:
      print("cant open",sys.argv[1])
   listbanned=[]
   for line in fbanned:
      line=line.rstrip("\n")
      listbanned.append(line)
#      for word in line.split(" "):
#         listbanned.append(word)
   #pytho will strip newline auto
   userinput=input("What message would you like to censor?\n")
   listinput=userinput.split(" ")
   for word in listinput:
      if word in listbanned:
         for i in range(len(word)):
            print("*",end="")
         print(" ",end="")
      else:
         print(word,end=" ")

main()