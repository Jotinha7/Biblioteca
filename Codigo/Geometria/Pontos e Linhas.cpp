#include <bits/stdc++.h>

using namespace std;

//template de geometria - ricaxov v0.1.3 

//upd:
//const &, sobrecargas, papai ta chatinho

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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
}
