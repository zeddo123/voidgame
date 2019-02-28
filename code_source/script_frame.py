import sys
import os
import re

f = open(sys.argv[1]+"/frames.txt","w");

regex = re.compile(r"png$")

for i in sorted(os.listdir(sys.argv[1])):
	if regex.search(i):
		f.write(sys.argv[1]+"/"+i+'\n')

f.close()