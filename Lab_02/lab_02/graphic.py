import matplotlib.pyplot as plt
import numpy as np

SORTED = "sorted"
REVERSED = "reversed"
RANDOMED = "randomed"


# buble
'''
dots = [(100, 0) ,
(200, 0) ,
(300, 0) ,
(400, 0.0002), 
(500, 0) ,
(600, 0) ,
(700, 0) ,
(800, 0) ,
(900, 0) ,
(1000, 0) 
    ]

dots2 = [(100, 0) ,
(200, 0) ,
(300, 0.0004), 
(400, 0.0006) ,
(500, 0.0008) ,
(600, 0.0012) ,
(700, 0.0014) ,
(800, 0.0024) ,
(900, 0.003) ,
(1000, 0.0038) ]


dots1 = [(100, 0) ,
(200, 0.0004) ,
(300, 0.0004) ,
(400, 0.0008) ,
(500, 0.0010) ,
(600, 0.0014) ,
(700, 0.002) ,
(800, 0.0024) ,
(900, 0.0032) ,
(1000, 0.004)  ]
# ======================
'''

# insert
dots = [(100, 0) ,
(200, 0) ,
(300, 0) ,
(400, 0) ,
(500, 0) ,
(600, 0) ,
(700, 0) ,
(800, 0) ,
(900, 0) ,
(1000, 0) ]

dots1 = [(100, 0.0002) ,
(200, 0.0002) ,
(300, 0.0004) ,
(400, 0.0006) ,
(500, 0.0008) ,
(600, 0.001) ,
(700, 0.0014) ,
(800, 0.0016) ,
(900, 0.0022) ,
(1000, 0.0026) ]

dots2 = [(100, 0.0002) ,
(200, 0) ,
(300, 0) ,
(400, 0.0002) ,
(500, 0.0004) ,
(600, 0.0004) ,
(700, 0.0006) ,
(800, 0.0008) ,
(900, 0.001) ,
(1000, 0.0014) ]

'''
# выбор
dots = [(100, 0) ,
(200, 0) ,
(300, 0) ,
(400, 0) ,
(500, 0) ,
(600, 0.0006) ,
(700, 0.0006) ,
(800, 0.0006) ,
(900, 0.001) ,
(1000, 0.0016) ]

dots1 = [(100, 0) ,
(200, 0) ,
(300, 0) ,
(400, 0.0004), 
(500, 0.0003) ,
(600, 0.0008) ,
(700, 0.0008) ,
(800, 0.001) ,
(900, 0.0012) ,
(1000, 0.0014) ]

dots2 = [(100, 0) ,
(200, 0) ,
(300, 0.0002) ,
(400, 0.0002) ,
(500, 0.0002) ,
(600, 0.0006) ,
(700, 0.0006) ,
(800, 0.0008) ,
(900, 0.0012) ,
(1000, 0.0012) ]
'''

x = [dots[i][0] for i in range(len(dots))]
y = [dots[i][1] for i in range(len(dots))]
y1 = [dots1[i][1] for i in range(len(dots1))]
y2 = [dots2[i][1] for i in range(len(dots2))]



fig, ax = plt.subplots()

ax.set_title("Сортировка вставками")

ax.plot(x, y, color = 'r', label=SORTED)
ax.plot(x, y1, color = 'g', label=REVERSED)
ax.plot(x, y2, color = 'b', label=RANDOMED)

plt.grid(True)

ax.set_ylabel('Время, с')
ax.set_xlabel('Длина массива')

ax.legend() 
plt.show()

