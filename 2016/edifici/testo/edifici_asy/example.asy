unitsize(1cm);

void make_house(pair p, int id, bool special = false) {
	pen bg = black;

    if (special)
        bg = lightblue;

	real delta = .1;
	fill(shift(p - (.28,.28)) * scale(.56, .45) * unitsquare, white);
	path roof = (
		(p.x - .25 - delta, p.y + .1) --
		(p.x, p.y + .3 + delta) --
		(p.x + .25 + delta, p.y + .1) --
		cycle
	);
	fill(shift(p.x, p.y + .2) * scale(1.2, 1.2) * shift(-p.x, -p.y - .2) * roof, white);

	fill(shift(p - (.25,.25)) * scale(.5, .4) * unitsquare, bg);
	fill(roof, bg);
	label("$" + (string)id + "$", p, white);
}

void draw_edge(path p, int L, pair mod = N) {
	draw(p, black + linewidth(1.2));
	label("$" + (string)L + "$", midpoint(p), mod);	
}

real d = 2;
pair n1 = (0, 0);
pair n2 = (2*d, 0);
pair n3 = (d, 0);
pair n4 = (d, d);
pair n5 = (0, d);

draw_edge(n1 -- n3, 2, N);
draw_edge(n1 -- n5, 4, W);
draw_edge(n3 -- n2, 8, N);
draw_edge(n3 -- n4, 5, E);
draw_edge(n3 -- n5, 3, NE);
draw_edge(n4 -- n5, 7, N);

make_house(n1, 1);
make_house(n2, 2);
make_house(n3, 3, true);
make_house(n4, 4);
make_house(n5, 5, true);