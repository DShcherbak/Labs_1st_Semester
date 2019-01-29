uses GraphABC;

var
  x, y, z: real;
  t, r, j: integer;
  coordinates : array [1..1000000] of Point;

BEGIN
  lockDrawing();
  setWindowSize(1200, 1200);
  read(r);
  for t := 1 to 1000000 do
  begin
    clearWindow();
    line(0, 320, 1200, 320);
    z := t / r;
    circle(t ,320-r,r);
    // println(z);
    x := r * z - r * sin(z);
    y := r - r * cos(z);
    //   println(x,y);
    setPenColor(clRed);
    setBrushColor(clRed);
    coordinates[t]:=(round(x), 320 - round(y));
    for j:=1 to t do
    begin
      circle(coordinates[j].X,coordinates[j].Y, 3);
    end;
    circle(round(x), 320 - round(y), 5);
    setPenColor(clBlack);
    setBrushColor(clWhite);
    Redraw();
  end;
end.