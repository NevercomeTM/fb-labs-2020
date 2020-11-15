file = open("crypted.txt")
text = file.read()
##text = text.lower()
output = open("open1.txt", 'w')
text=text.replace('\n', '')

def frec(text):
    fr=[0]*32
    for l in text:
        if(l!='\n'):
            fr[ord(l)-ord('а')]+=1
    n = fr.index(max(fr))
    return n

Dr=[0]*30
for k in range(2,31):
    for i in range(0, len(text)-k):
        if text[i]==text[i+k]:
            Dr[k-2]+=1
    print((f'{k}'+ " = " + f'{Dr[k-2]}'))
klen = Dr.index(max(Dr))+2
print("suggested key length: "+str(klen))
print("input key length")
klen=int(input())
##klen=8
t=['']*klen
key = ''
for i in range(0, len(text)):
    t[i%klen]+=text[i]
for k in range(0, klen):
    y=frec(t[k])
    x=ord('о')-ord('а')
    d = y-x
    if d<0:
        d+=32
    d=chr(d+ord('а'))
    key+=d
##print(Dr.index(max(Dr))+2)
##print(frec(text))
print(key)

from decoder import decode
decode(text, key)
output.close()
##m=0
##while m!=-1:
##    decoded = open("decoded text.txt").read()
##    print("\n")
##    print(text[:24])
##    print(decoded[:24])
##    print("\n")
##    print(text[24:48])
##    print(decoded[25:49])
##    print("\n")
##    print(text[48:72])
##    print(decoded[50:74])

##    y=input()
##    x=input()
##    y=ord(y)-ord('а')
##    x=ord(x)-ord('а')
##    d = y-x
##    if d<0:
##        d+=32
##    d=chr(d+ord('а'))
##    print(d)
key = input()
decode(text, key)
##while 1==1:
##    l = input()
##    l = int(l)
##    if l > klen:
##        print("error")
##    else:
##        if l==-1:
##            nkey=key
##        else:
##            y=frec(t[l-1])
##            x=ord('а')-ord('а')
##            d = y-x
##            if d<0:
##                d+=32
##            d=chr(d+ord('а'))
##            print(d)
##            nkey.replace(nkey[l-1], d)
##            ##nkey[l-1]=d
##            print(nkey)

output.close()
print("done")
