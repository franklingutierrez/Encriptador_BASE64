# Encryptar texto en BASE64
### 🧡Author: 
***Franklin Hiustong Gutierrez Arizaca***

- ✅Actividad Completada: 
  - Si
- ✅Actividad a Realizar: 
  - Exposición 
  - Programación 
  - Tarea
- ✅Dia Avance: 
  - Lunes - Viernes


Repositorio: https://github.com/guiratec/Encriptador_BASE64

## Codigo

### Funcion convertir un Numero ENTERO a BINARIO

```cpp
//===== Funcion convierte un numero ENTERO a BINARIO =============
inline string base64::int2bin(int n, int bits = 8) {
	string r = string(bits, '0');
	while (n) {
		r.at(--bits) = ((n & 1) + 48);
		n >>= 1;
	}
	return r;
}
```

Esta funcion convierte un numero entero a binario en los bits que pongamos

### Funcion convertir un String Binario a ENTERO

```cpp
//======= Funcion convierte  un String BINARIO a ENTERO ==========
inline int base64::bin2int(string b) {
	int r = 0;
	for (int i = 0; i < b.length(); i++) r += b.at(b.length() - 1 - i) == '1' ? pow(2, i) : 0;
	return r;
}
```

Esta funcion hace lo contrario convierte un String binario a entero

### Funcion Cifrar

```cpp
//===================FUNCION PARA CIFRAR =================================
inline string base64::Cifrar(string t) {
	if (t == "") return "";//si el texto es nulo devolvera nulo

	string b = "", r = "", extra = "";
	for (auto c : t) b += int2bin(c);

	if (t.length() % 3 == 1) {// 3k + 1
		b += "0000";
		extra = "==";
	}
	if (t.length() % 3 == 2) {// 3k - 1
		b += "00";
		extra = "=";
	}
	// recorremos en grupos de 6 todo el texto en binario.
	for (int i = 0; i < b.length(); i += 6) r += BASE64[bin2int(b.substr(i, 6))];
	return r + extra;
}
```

Entonces lo que se tiene que hacer primero es convertir todo el texto a binario, si bien es cierto un texto es un sucesion de caracteres y al final un caracter es un numero del 0 al 255 y ese numero es lo que tenemos que convertir en binario con esta funcion.

```cpp
//===== Funcion convierte un numero ENTERO a BINARIO =============
inline string base64::int2bin(int n, int bits = 8) {
	string r = string(bits, '0');
	while (n) {
		r.at(--bits) = ((n & 1) + 48);
		n >>= 1;
	}
```

 Por tanto:

```cpp
/===================FUNCION PARA CIFRAR =================================
inline string base64::Cifrar(string t) {
	if (t == "") return "";//si el texto es nulo devolvera nulo

	string b = "", r = "", extra = "";
	for (auto c : t) b += int2bin(c);
```

Lo que haremos es un String unicamente que tenga 0 y 1, que coincida con el texo y ademas para cada caracter que haya en el texto, lo que tendremos que hacer es agregarle la representacion de ese texto en binario. por lo que seria: **b += int2bin(c);**   por lo que ya se tendria el texto en binario.

Ahora unicamente lo que se tendria que hacer es recorrer el texto por grupos de 6, el cual lo lograriamos con un bucle FOR.

```cpp
// recorremos en grupos de 6 todo el texto en binario.
	**for (int i = 0; i < b.length(); i += 6)** r += BASE64[bin2int(b.substr(i, 6))];
	return r + extra;
```

- Para i que empezaria en 0, donde i tendria que ser menor a la longitud del texto en binario y como lso grupos son de 6 la i avanzara 6 en 6.

Ahora  lo que haremos  es convertir aquel grupo de bits que al gfinal es un string con unos y ceros a un entero, por lo que agregamos al texto **bin2int** y pondremos el substring por tanto el grupo **substr(i, 6)**   desde la i coja 6 caracteres. Entonces lo que sucederia es que en el primer bucle cogera del 0 al 5, en el segundo como el bucle avanza de (6 en 6), cogera el 6 al 11 y asi sucesivamente.

```cpp
// recorremos en grupos de 6 todo el texto en binario.
	for (int i = 0; i < b.length(); i += 6) **r += BASE64[bin2int(b.substr(i, 6))];**
	return r + extra;
```

Entonces como esto son  6 bits va dar un resultado entre el 0 y el 63, pero si esto se deja asi cogera un caracter del codigo ASCCI que sea (i), para que no suceda esto se define el alfabeto en BASE 64 en orden.

```cpp
#define BASE64 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
```

Por tanto, si esta funcion de recorrido devuelve el priemr caracter tendremos que irnos al primero el cual seria A si fuero al quinto seria E.

Es por ello que para que tenemos que coger el indice del BASE64 mediante:

```cpp
**BASE64[bin2int(b.substr(i, 6))];**
return r + extra;
```

y luego simplemente devolvemos en texto a traves de un return r.

### Funcion Decifrar

```cpp
//===================== FUNCION PARA DESIFRAR =============================
inline string base64::Descifrar(string t) {
	if (t == "") return "";

	int numero_ceros = 0;
	while (t.at(t.length() - 1) == '=') {
		numero_ceros += 2;
		t = t.substr(0, t.length() - 1);
	}

	string b = "", r = "";
	for (auto c : t) b += int2bin(string(BASE64).find(c), 6);

	b += string('0', numero_ceros);
	for (int i = 0; i < b.length(); i += 8) r += bin2int(b.substr(i, 8));
	return r;
}
```

Se sabe que el texto se encuentra en BASE64, (string t), por lo tanto ya no tendra que pensar en 8 bits por caracter si no que 6 bits por caracter y posterior a ello convertirlo a 8 bits y por tanto lo que se debe hacer es convertir el texto a binario.

```cpp
for (auto c : t) b += int2bin(string(BASE64).find(c), 6);
```

Para lograrlo hacerlo usarios el procedimiento de conversion pero esta vez ocurre que trabajamos con 6 bits y no con 8 bits, muy parte de ello esto esta en ASSCII, para ello tendro que usar la funcion invertida:

```cpp
#define BASE64 "ABCD**E**FGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
```

Por ejemplo, si yo quiero conseguir la E (BASE64), al obtener el indice este se encontraria en 4.

Ahora ese resultado lo queremos convertir en binario es decir 6 bits por tanto lo que se haria seria en vez de C se pondria que los valores de  BASE64 los trate como String y pondremos que encuentre el indice en el que esta el caracter ya que el texto solo podra tener caracteres del ABCdario por que si no, este no estara cifrado en BASE64

```cpp
for (auto c : t) b += **int2bin(string(BASE64).find(c), 6);**
```

Luego haremos lo que haremos sera reecorrer tomando grupo de 8 bits, por que el texto inicialmente estaba en 6 bits y lo pasamos a 8 bits

```cpp
for (int i = 0; i < b.length(); **i += 8)** r += **bin2int**(b.substr(i, 8));
	return r;
```

### Agregando igual a la conversión segun bits

Ahora agregaremos iguales segun se necesite para que al  momento de la conversión cumpla con la regla de 6 bits.

Por lo tanto si ponemos 2 caracteres, es decir 3k-1 lo que se hara es agragar 1 igual =

![Untitled](Encryptar%20texto%20en%20BASE64%206d7085c89ea74c0cba120882dba7de4d/Untitled.png)

Pero si es 1 caracter, es decir 3k+1, lo que se hara es agragr 2 iguales ==

![Untitled](Encryptar%20texto%20en%20BASE64%206d7085c89ea74c0cba120882dba7de4d/Untitled%201.png)

- Ahora lo que tendremos que hacer es agregar la logica al codigo, decimos para el priemr caso, si la logitud del texto divida por 3  el resto es 1, hay que agregarle 4 ceros mas y  al resultado final tendremos que agregarle 2 iguales:
    
    ```cpp
    if (t.length() % 3 == 1) {// 3k + 1
    		**b += "0000";**
    		**extra = "==";**
    	}
    ```
    
    asi que el resaultado final sera todo lo que haga mas el extra:
    
    ```cpp
    // recorremos en grupos de 6 todo el texto en binario.
    	for (int i = 0; i < b.length(); i += 6) r += BASE64[bin2int(b.substr(i, 6))];
    	**return r + extra;**
    ```
    
- En cambio si  no es un multiplo de 3 pero es de la forma 3k-1, simplemente hay que agregarle 1 igual = y 2 ceros.
    
    ```cpp
    if (t.length() % 3 == 2) {// 3k - 1
    		**b += "00";**
    		**extra = "=";**
    	}
    ```
    

### Comprobar logitud del texto

Se tiene que comprar la longitud del texto para saber al final tiene o no un igual. Es por ello que al principio del codigo decifrar tendremos que comprobar cuantos ceros añadir al mensaje, por lo tanto pondremos **int numero_ceros = 0;,** y pondremos que el ultimo caracter que es **t.length() - 1)** es igual a un solo =, tendremos que añadir 2 ceros.

```cpp
inline string base64::Descifrar(string t) {
	if (t == "") return "";

	**int numero_ceros = 0;**
	**while (t.at(t.length() - 1) == '=')** {
		**numero_ceros += 2;**
		t = t.substr(0, t.length() - 1);
	}

	string b = "", r = "";
	for (auto c : t) b += int2bin(string(BASE64).find(c), 6);

	b += string('0', numero_ceros);
	for (int i = 0; i < b.length(); i += 8) r += bin2int(b.substr(i, 8));
	return r;
}
```

Sin embargo ocurre que el ABCedario de BASE 64 no incluy eel igual, lo que se tendria que hacer es que si sabemos que esta ahi y hemos configurado esa variable, lo que tendriamos que hacer al texto es quitar ese igual.

```cpp
**int numero_ceros = 0;**
	**while (t.at(t.length() - 1) == '=')** {
		**numero_ceros += 2;**
		t = t.substr(0, t.length() - 1);
	}
```

Por lo tanto: t sub string desde 0 y cogeremos los caracteres que tenga excepto 1 el ultimo. 

```cpp
**t = t.substr(0, t.length() - 1);**
```

Ahora que ocurriria si hay 2 iguales, pues volveriamos a realizar esta comprobación, pero por que esta si es el  penultimo y no el ultimo, por que hemos quitado el ultimo y por tanto ahora el penultimo caracter vendria a ser el ultimo.

Por ejemplo, si tenemos abc, el caracter ultimo es c por lo que lo quitariamos quedando solo ab, ahora si nos fijamos b antes erea el penultimo pero ahora es el ultimo y por tanto seria 4 ceros mas.

Lo que tenemos que hacer es que justo antes de  pacer a caracteres tenemos que añadir aquello ceros de mas **b += string('0', numero_ceros);,** al texto ponemos un nuevo String  que sera el caracter 0 tantas veces como le hayamos dicho.

```cpp
//===================== FUNCION PARA DESIFRAR =============================
inline string base64::Descifrar(string t) {
	if (t == "") return "";

	int numero_ceros = 0;
	while (t.at(t.length() - 1) == '=') {
		numero_ceros += 2;
		t = t.substr(0, t.length() - 1);
	}

	string b = "", r = "";
	for (auto c : t) b += int2bin(string(BASE64).find(c), 6);

	**b += string('0', numero_ceros);**
	for (int i = 0; i < b.length(); i += 8) r += bin2int(b.substr(i, 8));
	return r;
}
```

## Github

[https://github.com/guiratec/Encriptador_BASE64](https://github.com/guiratec/Encriptador_BASE64)
