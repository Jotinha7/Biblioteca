#include <bits/stdc++.h>

using namespace std;

//G de Geometria - ricaxov v0.5.0 

//Importante ->
//Verificar a correlação entre angulos
//verificar a semelhança entre triangulos
//fixar pontos e encontrar angulos importantes

//Formulas importantes -> (REVISAR PRODUTO VETORIAL E ANGULOS)
//Circunferencia de um circulo que possui um triangulo inscrito -> a * b * c / (4 * area)
//heron theorem ->
//A = sqrt(p * (p − a) * (p − b) * (p − c))
//p = (a + b + c) / 2.0
//goldenratio ->
//g = (1.0 + sqrt(5.0)) / 2.0
//find angle between 2 points, using a third point ->
//oa · ob = |oa| × |ob| × cos(θ) [θ -> angulo aôb]
//distancia de dois pontos na Terra -> 
//formula de haversine

using ll = long long;
using ld = double;

const ld eps = 1e-9; 
const ld pi = acos(-1.0);
const int maxn = 2 * 1e5;

struct point {
  ld x, y;
  point() { x = y = 0.0; }
  point(const ld& X, const ld& Y) { x = X, y = Y; }
  bool operator < (const point& other) const { // para ordenar os pontos
		if(fabs(x - other.x) > eps) { return x < other.x; }
		return y < other.y;
	}
	bool operator == (const point& other) const { // para verificar se dois pontos sao iguais
		return (fabs(x - other.x) < eps) && (fabs(y - other.y) < eps);
	}
};
ld dist(const point& a, const point& b) { // distancia entre dois pontos
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ld deg_to_rad(const ld& deg) { // converter pra rad
  return deg * pi / 180.0; 
}
ld rad_to_deg(const ld& rad) { // converter pra graus
  return rad * 180.0 / pi;
}
point rotate(const point& p, const ld& theta) { // rotaciona anti-horário o ponto p em theta graus em volta do ponto (0, 0)
  ld rad = deg_to_rad(theta);
  return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}
ld area(const vector<point>& points) { // area de poligono convexo, utilizando matriz cruzada
  ld ans = 0.0;
  int n = (int)points.size();
  for(int i = 0; i + 1 < n; i++) { ans += (points[i].x * points[i + 1].y - points[i + 1].x * points[i].y); }
  return fabs(ans) / 2.0;
}

// -----------------------------------------------------------------------------

struct line {
  ld a, b, c;
  line(){ a = b = c = 0.0; }
  line(const ld& A, const ld& B, const ld& C) { a = A, b = B, c = C; }
  line(const point& A, const point& B) {
		if(fabs(A.x - B.x) < eps) { a = 1.0, b = 0.0, c = -A.x; }
		else { a = -(A.y - B.y) / (A.x - B.x); b = 1.0; c = -(a * A.x) - A.y; }
  }
};
line slope_to_line(const point& p, const ld& slope) { // (y = ax + b) -> (ax + by = c) usando um ponto e o gradiente da linha
  return line(-slope, 1.0, -((-slope * p.x) + p.y)); //(SOMENTE LINHAS NÃO VERTICAIS)
}
bool parallel(const line& l1, const line& l2) { // return 1 se duas linhas forem paralelas
  return (fabs(l1.a - l2.a) < eps) && (fabs(l1.b - l2.b) < eps);
}
bool same(const line& l1, const line& l2) { // return 1 se duas linhas forem iguais
  return parallel(l1, l2) && (fabs(l1.c - l2.c) < eps);
}
bool intersect(const line& l1, const line& l2, point& p) { // return 1 se as linhas se intersectao => intersection at point p (NAO SAO SEGMENTOS)
  if(parallel(l1, l2)) { return 0; }
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if(fabs(l1.b) > eps) { p.y = -(l1.a * p.x + l1.c); }
  else { p.y = -(l2.a * p.x + l2.c); }
  return 1;
}
bool contains(const point& a, const point& b, const point& p) {
	return dist(a, p) + dist(p, b) == dist(a, b);
}

// -------------------------------------------------------------------------------

struct vec {
  ld x, y, z;
  vec(){ x = y = 0.0; }
  vec(const ld& X, const ld& Y) { x = X, y = Y; }
  vec(const point& A, const point& B) {
    x = A.y - B.y;
    y = B.x - A.x;
    z = -x * A.x - y * A.y;
    ld Z = sqrt(x * x + y * y);
		if(fabs(Z) > eps) { x /= Z, y /= Z, z /= Z; }
  }
  ld dist(point p) const { return x * p.x + y * p.y + z; }
};
vec scale(const vec& v, const ld& s) { // escalonar um vetor
  return vec(v.x * s, v.y * s);
}
point translate(const point& p, const vec& v) { // desloca um ponto p utilizando um vetor v
  return point(p.x + v.x, p.y + v.y);
}
ld dot(const vec& a, const vec& b) { // dot product (usado pra fazer produto vetorial)
  return a.x * b.x + a.y * b.y;
}
ld norm_sq(const vec& v) { // normal product (usado pra fazer produto vetorial)
  return v.x * v.x + v.y * v.y; 
}
ld angle(const point& a, const point& o, const point& b) { // encontra o angulo aôb usando oa · ob = |oa| × |ob| × cos(θ) [Produto vetorial]
  vec oa(o, a), ob(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); // retorna o angulo em rad
}
ld cross(const vec& a, const vec& b) { // produto cruzado entre vetores (usado pra fazer ccw check e collinear)
  return a.x * b.y - a.y * b.x; 
}
bool ccw(const point& p, const point& q, const point& r) { // retorna 1 se o ponto R estiver a esquerda da reta PQ
  return cross(vec(p, q), vec(p, r)) > eps;
}
bool collinear(const point& p, const point& q, const point& r) { // retorna 1 se o ponto R estiver na mesma linha que a linha PQ
	return fabs(cross(vec(p, q), vec(p, r))) < eps;
}
ld dist(const point& p, const point& a, const point& b, point &c) { // distancia minima entre um ponto P e o vetor A -> B [c guarda o ponto de interseção]
  vec ap(a, p), ab(a, b);
  ld u = dot(ap, ab) / norm_sq(ab); // u é obtido por meio de uma projeção escalar de AP em AB (usando dot product)
  if(u < 0.0) {
    c = a;
    return dist(p, c);
  }
  if(u > 1.0) {
    c = b;
    return dist(p, c);
  }
  c = translate(a, scale(ab, u));// c pode ser visto como um ponto transladado e escalonado por u sobre o vetor A -> B
  return dist(p, c); // c = a + u * AB
}
ld det(ld a, ld b, ld c, ld d){ 
	return a * d - b * c;
}
bool between(ld l, ld r, ld x){
	return (min(l, r) <= x + eps) && (x <= max(l, r) + eps);
}
bool intersect_1d(ld a, ld b, ld c, ld d){
	if (a > b) { swap(a, b); }
	if (c > d) { swap(c, d); }
	return (max(a, c) <= min(b, d) + eps);
}
bool intersect(point a, point b, point c, point d, point& left, point& right){ //intersect de segmentos (a, b) e (c, d) -> intersect at (l, r)
	if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y)) { return 0; }
	vec m(a, b), n(c, d);
	ld zn = det(m.x, m.y, n.x, n.y);
	if(fabs(zn) < eps){
		if (abs(m.dist(c)) > eps || abs(n.dist(a)) > eps) { return 0; }
		if (b < a) { swap(a, b); }
		if (d < c) { swap(c, d); }
		left = max(a, c);
		right = min(b, d);
		return 1;
	}
	else{
		left.x = right.x = -det(m.z, m.y, n.z, n.y) / zn;
		left.y = right.y = -det(m.x, m.z, n.x, n.z) / zn;
		return between(a.x, b.x, left.x) && between(a.y, b.y, left.y) && between(c.x, d.x, left.x) && between(c.y, d.y, left.y);
	}
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
	
}
