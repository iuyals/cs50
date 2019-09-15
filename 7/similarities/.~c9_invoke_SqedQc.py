

def lines(a, b):
    """Return lines in both a and b"""
    result=[]
    i=0;
    for linea in a:
        lineb=b[i]
        i+=1
        if linea==lineb:
            result.append(linea)
    # TODO
    return result


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    return []


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    return []

file1=open("1","r")
file2=open("2","r")

print(lines(file1,file2))

file1.close()
file2.close()