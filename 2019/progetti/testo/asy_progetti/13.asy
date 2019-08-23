unitsize(0.7cm);
import math;
import roundedpath;
settings.tex = "pdflatex";

path rrect(pair p, pair q, real r=0.1) {
    return roundedpath(p -- (p.x, q.y) -- q -- (q.x, p.y) -- cycle, r);
}

int LEN = 4;

for (int i=0; i<LEN;++i) {
    draw(box((i,0), (i+1, 1)), black+2);
}

void disegna(int pos, int pos_fine, pen col1, pen col2) {
    filldraw(rrect((pos, 0), (pos_fine, 1)), col1, col2);
}

disegna(0, 1, palered, deepred);
disegna(1, 4, palegreen, deepgreen);

