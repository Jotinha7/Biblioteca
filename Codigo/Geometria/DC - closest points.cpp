// Divide and Conquer -> Find the distance of the two closest points inside a set of points O(n * (logn) ^ 2)
// Idea: Make a line in the middle of the set and search recursively for the closest points there
// after that you'd have the closest points from the left and from the right, now you need to find
// if some point that goes from left to right can have a smaller distance

struct point {
  ld x, y;
  point() { x = y = 0.0; }
  point(const ld& X, const ld& Y) { x = X, y = Y; }
};
ld dist(const point& a, const point& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmpx(const point& a, const point& b){
  if(fabs(a.x - b.x) > eps) return a.x < b.x;
  return a.y < b.y;
}
bool cmpy(const point& a, const point& b){
  if(fabs(a.y - b.y) > eps) return a.y < b.y;
  return a.x < b.x;
}
ld naive(const vector<point>& pts, int qnt) {
  ld d = 1e18;
  for(int i = 0; i < qnt; i++) {
    for(int j = i + 1; j < qnt; j++) {
      d = min(d, dist(pts[i], pts[j]));
    }
  }
  return d;
}
ld f(vector<point> pts, int qnt) {
  if(qnt <= 3) return naive(pts, qnt); // base case -> just brute force through it

  int mid = qnt / 2;
  point val = pts[mid];

  ld left = f(vector<point>(pts.begin(), pts.begin() + mid), mid); // left part of pts
  ld right = f(vector<point>(pts.begin() + mid, pts.end()), qnt - mid);// right part of pts

  ld d = min(left, right);

  vector<point> strip; // make a strip to reduce the number of points used to find the minimum distance
  for(int i = 0; i < qnt; i++) { 
    if(fabs(pts[i].x - val.x) < d) strip.pb(pts[i]);
  }

  sort(all(strip), cmpy);

  ld closest_strip = 1e18;
  for(int i = 0; i < sz(strip); i++) {
    for(int j = i + 1; j < sz(strip); j++) {
      closest_strip = min(closest_strip, dist(strip[i], strip[j]));
    }
  }

  return min(d, closest_strip);
}
