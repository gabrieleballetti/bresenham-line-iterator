# bresenham-line-iterator
A compact and storage-less C++ implementation of a Bresenham line iterator.

Given two arbitrary integer points on the plane, returns the Bresenham line from the first (included) to the second (excluded). It works on all octants!

It allows iterations over range-based loops.

```c++
    for (auto& pt : BresenhamLineIterator(start, end))
    {
        // do fabulous things
    }
```

All the heavy lifting is done by the constructor and the prefix increment operator, all the rest is just structural.

```c++
    BresenhamLineIterator(Point2D& p, Point2D& q) :
        firstPoint(p),
        lastPoint(q),
        point(p),
        delta(Point2D(q[0] - p[0], q[1] - p[1]))
    {
        id = abs(delta[0]) >= abs(delta[1]) ? 0 : 1;
        increment[id] = delta[id] >= 0 ? 1 : -1;
        increment[1 - id] = delta[1 - id] >= 0 ? 1 : -1;
        delta = Point2D(delta[0] * increment[0], delta[1] * increment[1]);
        error = 2 * delta[1 - id] - delta[id];
    }
```

```c++
    BresenhamLineIterator operator++()
    {
        point[id] += increment[id];
        if (error > 0)
        {
            point[1 - id] += increment[1 - id];
            error -= 2 * delta[id];
        }
        error += 2 * delta[1 - id];
        return *this;
    }
```