unitsize(.8cm);

void draw_node(pair pos, string text) {
	path c = circle(pos, .5);
	fill(c, white);
	draw(c, black);
	label(text, pos);
}

void draw_edge(path edge, string text, align al = NoAlign, bool active = false) {
	pair a = relpoint(edge, 0);
	pair b = relpoint(edge, 1);

	real time_a = intersect(edge, circle(a, .5))[0];
	real time_b = intersect(edge, circle(b, .5))[0];

	path sub = subpath(edge, time_a, time_b);
	pair mid = midpoint(sub);
	
	label(scale(.7) * text, mid, al);

	if (active)
		draw(edge, rgb(.8,.8,1) + linewidth(5));
	//draw(sub, arrow = EndArrow(TeXHead, size = 1.5));
	draw(sub, dashed);
}

pair n0 = (1,3);
pair n1 = (3,3);
pair n2 = (5,3);
pair n3 = (3,1);

draw_edge(n0 .. n1, "2", N, true);
draw_edge(n1 .. n2, "2", N, true);
draw_edge(n1 .. n3, "1", W, false);

draw_node(n0, "4");
draw_node(n1, "2");
draw_node(n2, "3");
draw_node(n3, "1");
