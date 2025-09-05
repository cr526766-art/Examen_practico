program ARBOLBIN;
uses crt;
type
PNodo = ^Node;
Nodo = record
valor: integer;
izq,der: PNodo;
end;

var
raiz: PNodo;
function CrearNodo(x: integer): PNodo;
var
nuevo: PNodo;
begin
new(nuevo);
nuevo^.valor :=x;
nuevo^.izq := nil;
nuevo^.der :=nil;
CrearNodo := nuevo;
end;

function Insertar(nodo: PNodo; x: integer): PNodo;
begin
if nodo= nil then
Insertar := CrearNodo(x)
else
begin
if x < nodo^.valor then
nodo^.izq := Insertar(nodo^.izq, x)
else
nodo^.der := Insertar(nodo^.der, x)
Insertar := nodo;
end;
end;

procedure Preorden(nodo: PNodo);
begin
if nodo <> nil then
begin
write(nodo^.valor, '');
Preorden(nodo^.izq);
Preorden(nodo^.der);
end;
end;

procedure Inorden(nodo: PNodo);
begin
 if nodo <> nil then
 begin
 Inorden(nodo^.izq);
 write(nodo^.valor,'');
 Inorden(nodo^.der);
 end;
 end;

procedure Postorden(nodo: PNodo);
begin
if nodo <> nil then
begin
Postorden(nodo^.izq);
Postorden(nodo^.der);
write(nodo^.valor,'');
end;
end;

begin
clrscr;
raiz := nil;

raiz := Insertar(raiz, 10);
Insertar(raiz,8);
Insertar(raiz,13);
Insertar(raiz,5);
Insertar(raiz,9);
Insertar(raiz,12);
Insertar(raiz,20)

writeln('PREORDEN:');
Preorden(raiz);

writeln(#13#10, 'INORDEN:');
Inorden(raiz);

writeln(#13#10,'POSTORDEN:');
Postorden(raiz);

readln;
end.






