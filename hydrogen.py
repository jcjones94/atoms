import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time

dr = 1e-11
Me = 9.109383e-31
Q = 1.602176e-19
E = -2.1427e-18
h = 1.058571e-34
perm = 8.98755e9
wave = [0, 1]
position = [0]
dr2 = dr*dr
fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)
def animate(i):
	E = -2.14e-18 + i*Q/10
	wave = [0, 1]
	position = [0]
	for i in range(1, 80):
		r = dr*i
		wave.append((2 - 2*dr2*Me*perm*Q*Q/(h*h*r) - dr2*E*2*Me/(h*h))*wave[i] - wave[i-1])
		position.append(i)
	position.append(r*80)
	time.sleep(0.1)
	print len(position)
	print len(wave)

	ax1.clear()
	ax1.plot(position, wave)
for n in range(0,10):
	ani = animation.FuncAnimation(fig, animate, interval= 1000)	
	plt.show()
