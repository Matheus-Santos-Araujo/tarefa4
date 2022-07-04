import numpy as np
from delaunay2D import Delaunay2D

if __name__ == '__main__':

    numSeeds = 24
    radius = 100
    seeds = [[1, 3], [2, 5], [3,2], [4,5], [5,3], [2,3]]
    print("seeds:\n", seeds)
    print("BBox Min:", np.amin(seeds, axis=0),
          "Bbox Max: ", np.amax(seeds, axis=0))

    center = np.mean(seeds, axis=0)
    dt = Delaunay2D(center, 50 * radius)
    
    for s in seeds:
        dt.addPoint(s)

    print (len(dt.exportTriangles()), "Delaunay triangles")
   
    import matplotlib.pyplot as plt
    import matplotlib.tri
    import matplotlib.collections

    fig, ax = plt.subplots()
    ax.margins(0.1)
    ax.set_aspect('equal')
    plt.axis([-1, radius+1, -1, radius+1])

    cx, cy = zip(*seeds)
    dt_tris = dt.exportTriangles()
    ax.triplot(matplotlib.tri.Triangulation(cx, cy, dt_tris), 'bo--')
            
    vc, vr = dt.exportVoronoiRegions()
    
    for r in vr:
        polygon = [vc[i] for i in vr[r]]       # Build polygon for each region
        plt.plot(*zip(*polygon), color="red")  # Plot polygon edges in red
    
    plt.savefig('output-delaunay2D.png', dpi=96)

    plt.show()