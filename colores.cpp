/*Documentar de conversion a escala de grises
Como se estructura un archivo BMP
Un archivo BM es un archivo de imagen en formato BMP (Bitmap), el cual es un formato estándar de imágenes de mapa de bits desarrollado por Microsoft para almacenar gráficos. 
Los archivos BMP son ampliamente utilizados en sistemas Windows debido a su simplicidad y compatibilidad nativa.
En este programa un archivo BMP tiene dos encabezados principales seguidos de los datos de la imagen, (BITMAPFILEHEADER) y (BITMAPINFOHEADER).
Encabezado del archivo (BITMAPFILEHEADER): Define información general del archivo, como su tamaño, el tipo ("BM") y la posición donde comienzan los datos de la imagen.
Encabezado de la información (BITMAPINFOHEADER): Contiene detalles específicos de la imagen, como dimensiones y formato de color. 
nota: si bien esta es una forma general de estructurar archivos bmp tambien se suele utilizar tablas de colores
en ste archivo las variables de (BITMAPFILEHEADER) contienen:
bfType (2 bytes): Identifica el archivo como BMP (siempre "BM").
bfSize (4 bytes): Tamaño total del archivo en bytes.
bfReserved1 y bfReserved2 (2 bytes cada uno): Reservados (normalmente 0).
bfOffBits (4 bytes): Offset (en bytes) desde el inicio del archivo hasta los datos de la imagen.
en ste archivo las variables de (BITMAPINFOHEADER) contienen:
biSize: Tamaño de este encabezado.
biWidth y biHeight: Ancho y alto de la imagen (en píxeles).
biPlanes: Siempre 1.
biBitCount: Bits por píxel (1, 4, 8, 16, 24 o 32).
biCompression: Método de compresión (0 para sin compresión).
biSizeImage: Tamaño de los datos de la imagen en bytes.
Resolución: biXPelsPerMeter y biYPelsPerMeter (píxeles por metro).
Colores: biClrUsed y biClrImportant (colores usados y esenciales).
Que es el padding
El padding es relleno necesario para que cada fila de píxeles tenga un tamaño múltiplo de 4 bytes.
Que son los #pragma
Los pragmas son directivas especiales del preprocesador en los lenguajes de programación, que envían instrucciones específicas al compilador
 para modificar o controlar ciertos aspectos del proceso de compilación
 En este programa, se usa para garantizar que las estructuras BITMAPFILEHEADER y BITMAPINFOHEADER coincidan exactamente con el formato de archivo BMP.
*/
#include <stdio.h>
#include <stdlib.h>
 
#pragma pack(push, 1) // vita el padding al modificar la alineación por defecto que el compilador aplica a los miembros de las estructuras. 
//Esto lo logra cambiando el tamaño en bytes al que se deben alinear los datos en memoria.
typedef struct {
    unsigned char  bfType[2];  // identificador de archivo
    unsigned int   bfSize;     // solicita los bytes
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;  // Offset hasta los datos de la imagen
} BITMAPFILEHEADER; //declaracion de estructura bitmapfileheader
 
typedef struct {
    unsigned int   biSize;         // Tamaño de este encabezado
    int            biWidth;        // Ancho de la imagen
    int            biHeight;       // Alto de la imagen
    unsigned short biPlanes;
    unsigned short biBitCount;     // Bits por píxel (debe ser 24 para este ejemplo)
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} BITMAPINFOHEADER//declaracion de estructura bitinfoheader
#pragma pack(pop)
 
// Función para convertir un píxel BGR a escala de grises
unsigned char convertirAGris(unsigned char b, unsigned char g, unsigned char r) {
    return (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
}
 
// Función para convertir la imagen BMP a escala de grises
void convertirBMPBlancoNegro(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");//se abre el archivo , en caso de que no haya notificar el error
    if (input_file == NULL) {
        fprintf(stderr, "No se puede abrir el archivo %s\n", input_filename);
        return;
    }
 
    // Leer el encabezado del archivo BMP
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, input_file);//toma informacion como la posicion de la imagen que tan grande es la imagen y su tipo de archivo
 
    // Leer el encabezado de la información BMP
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, input_file);// describe su ancho y largo su profundidad de color y su comprension en este caso su profundidad es de 24 bits
 
    // Verificar si es un archivo BMP de 24 bits
    if (fileHeader.bfType[0] != 'B' || fileHeader.bfType[1] != 'M' || infoHeader.biBitCount != 24) {
        fprintf(stderr, "El archivo no es un BMP de 24 bits\n");
        fclose(input_file);
        return;
    }
 
    // Crear el archivo de salida
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "No se puede crear el archivo %s\n", output_filename);
        fclose(input_file);
        return;
    }//el programa no soporta archivo que no sean de 24 bits por lo tanto los retira
 
    // Escribir los encabezados al archivo de salida sin cambiar el archivo
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output_file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, output_file);
 
    // Calcular el padding (relleno) de cada fila
    int padding = (4 - (infoHeader.biWidth * 3) % 4) % 4;
 
    // Leer, convertir y escribir cada fila de píxeles
    for (int i = 0; i < infoHeader.biHeight; i++) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            unsigned char bgr[3];  // Buffer para un píxel (B, G, R)
            fread(bgr, 3, 1, input_file);
 
            // Convertir el píxel a escala de grises
            unsigned char gris = convertirAGris(bgr[0], bgr[1], bgr[2]);
 
            // Escribir el píxel convertido en blanco y negro
            unsigned char gris_pixel[3] = {gris, gris, gris};
            fwrite(gris_pixel, 3, 1, output_file);
        }
 
        // Saltar el relleno (padding) en el archivo original
        fseek(input_file, padding, SEEK_CUR);
 
        // Añadir el relleno al archivo de salida
        unsigned char padding_bytes[3] = {0, 0, 0};  // Máximo de 3 bytes de padding
        fwrite(padding_bytes, padding, 1, output_file);
    }
 
    // Cerrar los archivos
    fclose(input_file);
    fclose(output_file);
 
    printf("Imagen convertida a blanco y negro y guardada en %s\n", output_filename);
}
 
int main(int argc, char *argv[])
{
    const char *archivo_entrada = "avion.bmp"; //cadena de caracteres con los nombres del archivo de entrada y de salida
    const char *archivo_salida = "avion_bn.bmp";
 
    convertirBMPBlancoNegro(archivo_entrada, archivo_salida);//saca la imagen de color y la imagen transformada
 
    return 0;
}
