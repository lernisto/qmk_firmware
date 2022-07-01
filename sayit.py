from functools import cache
from logging import root
from gtts import gTTS
import os
from pickle import dumps
from hashlib import sha256

class DiskCache():
    def __init__(self,root,*fanout) -> None:
        self.root  = root
        self.fanout=fanout
        os.makedirs(root)

    def split(self,name):
        for c in self.fanout:
            yield name[:c]
            name=name[c:]
        yield name

    def __contains__(self,key):

def memoname(*args,**kw):
    return sha256(dumps((args,kw))).hexdigest()

def say(text):
    cached_name = memoname(text)
    print(cached_name)

say('call me ishmael')
