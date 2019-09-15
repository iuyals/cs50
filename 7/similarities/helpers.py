from nltk.tokenize import sent_tokenize, word_tokenize

def lines(a, b):
    """
    a: a str
    b: a str

    Return: lines in both a and b
    """
    samels=[]
    lista=a.splitlines()
    listb=b.splitlines()
    lista=rmdup(lista)
    listb=rmdup(listb)
    for linea in lista:
        for lineb in listb:
            if linea==lineb:
                samels.append(linea)
    # TODO
    return samels


def sentences(a, b):
    """Return sentences in both a and b"""
    sames=[]
    lista=sent_tokenize(a)
    listb=sent_tokenize(b)
    lista=rmdup(lista)
    listb=rmdup(listb)
    for linea in lista:
        for lineb in listb:
            if linea==lineb:
                sames.append(linea)
    # TODO
    return sames


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    subsa=strtolist(a,n)
    subsb=strtolist(b,n)
    subsa=rmdup(subsa)
    subsb=rmdup(subsb)
    samestr=[]
    for substra in subsa:
       for substrb in subsb:
          if substra==substrb:
             samestr.append(substra)
    # TODO
    return samestr


def strtolist(str,length):
   """
      str: str need to be split
      length:int,length of a elemnt substr in result list
      return:a list contain equal lenght substr
   """
   substrs=[]
   for i in range(0,len(str)-length+1):
      asubstr=''
      for j in range(length):
         asubstr+=str[i+j]
      substrs.append(asubstr)
   return substrs

def rmdup(alist):
   """
      alist: list need to be remove dunplicate elements
      return refined list
   """
   newlist = list(dict.fromkeys(alist))
   return newlist



file1=open("1","r")
file2=open("2","r")


str1=file1.read()
str2=file2.read()


print(lines(str1,str2))
print(sentences(str1,str2))
print(substrings(str1,str2,4))

