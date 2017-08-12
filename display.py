import matplotlib.pyplot as plt
i = 2
position = []
with open("data.txt") as f:
	floats = map(float, f)

while (i < floats[1]):
	position.append(floats[0]*1E-10*i)
	i = i + 1
position.append(floats[0]*1E-10*i)
del floats[0:4]
print len(floats)
print len(position)
#plt.ylim([0, 1])
plt.plot(position,floats)
plt.show();
