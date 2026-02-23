Se usa la librería fstream.

`ifstream` para la la entrada y `ofstream` para la salida.

para leer un fichero:

```c++
ifstream file;
file.open("archivo.ext") //Nosotros lo usaremos para leer usuarios.csv

//una vez abierto lo comprobamos.
string cad;

if(file.is_open()){
    getline(file, cad);
    file.close(); //Importante cerrar después
} else cerr << "Error abriendo el archivo"
```
