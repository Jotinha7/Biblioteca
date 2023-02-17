#include <bits/stdc++.h>

using namespace std;

//template de geometria - ricaxov v0.2.0 

//Circunferencia de um circulo que possui um triangulo inscrito -> a * b * c / (4 * area)

typedef long double ld;

const ld eps = 1e-9;
const ld pi = acos(-1.0);
const int maxn = 2 * 1e5;

struct point {
  ld x, y;
  point() { x = y = 0.0; }
  point(ld X, ld Y) { x = X, y = Y; }
  bool operator < (const point& other) const { // para ordenar os pontos
		if(fabs(x - other.x) > eps) {
			return x < other.x;
		}
		return y < other.y;
	}
	bool operator == (const point& other) const { // para verificar se dois pontos sao iguais
		return (fabs(x - other.x) < eps) && (fabs(y - other.y) < eps);
	}
};
ld dist(const point& a, const point& b) { // distancia entre dois pontos
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ld deg_to_rad(ld deg) { // converter pra rad
  return deg * pi / 180.0; 
}
ld rad_to_deg(ld rad) { // converter pra graus
  return rad * 180.0 / pi;
}
ld area(const vector<point>& points) { //area de poligono convexo, utilizando matrix cruzada
  ld ans = 0.0;
  int n = (int)points.size();
  for(int i = 0; i + 1 < n; i++) {
		ans += (points[i].x * points[i + 1].y - points[i + 1].x * points[i].y);
	}
  return fabs(ans) / 2.0;
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

ld dist(const point& p, const line& l) { // distancia minima entre um ponto e uma linha ponto para uma reta
  return fabs((l.a * p.x) + (l.b * p.y) + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

void slope_to_line(const point& p, ld slope, line& l) { // converte do tipo slope (y = ax + b) para o tipo standard (ax + by = c)
  l = {-slope, 1.0, -slope * p.x + p.y};
}

bool parallel(const line& l1, const line& l2) { // check parallel
  return (fabs(l1.a - l2.a) < eps) && (fabs(l1.b - l2.b) < eps);
}
bool same(const line& l1, const line& l2) { // check same line
  return parallel(l1, l2) && (fabs(l1.c - l2.c) < eps);
}

bool intersect(const line& l1, const line& l2, point& p) { // return 1 se as retas se intersectao => intersection at point p
  if(parallel(l1, l2)) {
    return 0;
  }
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if(fabs(l1.b) > eps) {
    p.y = -(l1.a * p.x + l1.c);
  }
  else {
    p.y = -(l2.a * p.x + l2.c);
  }
  return 1;
}

struct vec {
  ld x, y;
  vec(){ x = y = 0.0; }
  vec(ld X, ld Y) { x = X, y = Y; }
  vec(point A, point B) {
    x = B.x - A.x;
    y = B.y - A.y;
  }
};


/* Depois precisa dar uma olhada melhor nisso aqui
vec scale(const vec &v, double s) { // s = [<1..1..>1]
  return vec(v.x*s, v.y*s); // shorter/eq/longer
} // return a new vec
point translate(const point &p, const vec &v) { // translate p
  return point(p.x+v.x, p.y+v.y); // according to v
} // return a new point
*/

/* uva - 10263
double distToLineSegment(point p, point a, point b, point &c) {
vec ap = toVec(a, p), ab = toVec(a, b);
double u = dot(ap, ab) / norm_sq(ab);
if (u < 0.0) { // closer to a
c = point(a.x, a.y);
return dist(p, a); // dist p to a
}
if (u > 1.0) { // closer to b
c = point(b.x, b.y);
return dist(p, b); // dist p to b
}
return distToLine(p, a, b, c); // use distToLine
}
*/
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
}
