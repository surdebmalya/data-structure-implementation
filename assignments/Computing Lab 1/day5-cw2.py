import numpy as np


def f(x, y):
    return x ** 2 + y ** 2 - x * y + 2 * x + 4 * y + 3


c1 = c2 = 1.5
w = 0.729

n_particles = 5
np.random.seed(100)
X = np.random.rand(2, n_particles) * 5
V = np.random.randn(2, n_particles) * 0.1

# Initialize data
pbest = X
pbest_obj = f(X[0], X[1])
gbest = pbest[:, pbest_obj.argmin()]
gbest_obj = pbest_obj.min()


def update(itr: int = 1):
    global V, X, pbest, pbest_obj, gbest, gbest_obj
    # Update params
    r1, r2 = np.random.rand(2)
    V = w * V + c1*r1*(pbest - X) + c2*r2*(gbest.reshape(-1, 1)-X)
    X = X + V
    if(itr % 10 == 0):
        print("\n--------------------- Position -------------------------")
        tempX = X
        tempX = tempX.transpose()
        print(tempX)
        print()
        print("-------------------- Veclocity --------------------------")
        tempV = V
        tempV = tempV.transpose()
        print(tempV)
    obj = f(X[0], X[1])
    pbest[:, (pbest_obj >= obj)] = X[:, (pbest_obj >= obj)]
    pbest_obj = np.array([pbest_obj, obj]).min(axis=0)
    gbest = pbest[:, pbest_obj.argmin()]
    gbest_obj = pbest_obj.min()


for i in range(20):
    update(i)

print("PSO found solution at f({})={}".format(gbest, gbest_obj))
