Instruccions per instal�lar els fitxers de la llibreria gr�fica i crear un projecte en Visual Studio que les integri.

1. Descomprimir tots els fitxers a la carpeta arrel del projecte
2. Afegir tots els fitxers font del directori \lib al projecte. Es recomena afegir-los dins subcarpetes \lib a les carpetes \source i \include del projecte
3. Afegir als directoris include del projecte els seg�ents:
	$(SolutionDir)\extlibs\SDL\include
	$(SolutionDir)\extlibs\libpng
4. Afegir als directoris lib del projecte el seg�ent:
	$(SolutionDir)\extlibs
5. Afegir com a depend�ncies addicionals (Propiedades - vinculador - entrada - dependencias adicionales) els seg�ents fitxers:
	libpng16.lib
	SDL2.lib
	SDL2_image.lib
6. A Propiedades - general
	Directorio de salida = $(SolutionDir)\Program
7. A Propiedades - Depuraci�n
	Directorio de trabajo = $(ProjectDir)\Program
	