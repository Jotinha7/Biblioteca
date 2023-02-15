//template de geometria - ricaxov v0.1
typedef long double ld;

const ld eps = 1e-9;
const ld pi = acos(-1.0);
const int maxn = 2 * 1e5;

struct point {
  ld x, y;
  point() { x = y = 0.0; }
  point(ld X, ld Y) { x = X, y = Y; }
};
ld dist(point a, point b) { // distancia euclidiana
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ld convertRad(ld deg) { //converter pra rad
  return deg * pi / 180.0; 
}
ld convertDeg(ld rad) { // converter pra graus
  return rad * 180.0 / pi;
}
ld matrix[maxn + 1][2];
ld getArea(vector<point>& points) { // area de poligono convexo
  int n = (int)points.size();
  for(int i = 0; i < n; i++) {
    matrix[i][0] = points[i].x;
    matrix[i][1] = points[i].y;
  }
  matrix[n][0] = points[0].x;
  matrix[n][1] = points[0].y;
  
  ld x = 0.0, y = 0.0;
  for(int i = 0; i < n; i++) {
    x += matrix[i][0] * matrix[i + 1][1];
    y += matrix[i][1] * matrix[i + 1][0];
  }
  
  return abs(x - y) / 2.0;
}

struct line {
  ld a, b, c;
  line(){ a = b = c = 0.0; }
  line(ld A, ld B, ld C) { a = A, b = B, c = C; }
  line(point A, point B) {
    a = B.y - A.y;
    b = A.x - B.x;
    c = A.y * B.x - A.x * B.y;
  }
};
ld dist(point& p, line& l) { // distancia minima de um ponto para uma linha
  return fabs((l.a * p.x) + (l.b * p.y) + l.c) / sqrt(l.a * l.a + l.b * l.b);
}
