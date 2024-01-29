/*
 Fecha      : 2024-01-28
 Autor      : Mario A. N. Zavala
 Descripción: 
	      El siguiente programa implementa dos algoritmos fundamentales para la
	      optimización de recursos computacionales cuando de búsqueda se trata:
              "Binary Search the answer" y "Slide Window".
	      El primero nos permite establecer una función que, al retornar true o
	      false, nos indica si habremos de seguir iterando sobre un arreglo de
	      datos o no.
	      El segundo trabaja directamente en la iteración dividiendo en subsegmentos
              el arreglo para obtener "vetanas" que son, en la práctica, valores
	      acomulados (si se trata de datos numéricos) de los valores anteriores a la
	      celda actual.
	      
	      Para que esto quede más claro, vamos al código. 
	      En éste hay dos funciones definidas: 
              minSubArrayLen que es nuestra función de falso/verdadero y
	      obtiene nustras vetanas, y la segunda es la función main que crea el
	      arreglo de datos entero con el que trabajará minSubArrayLen y en dónde
	      será llamado para su ejecución.
          
              A continuación más detalles sobre el proceso antes descrito.
*/

#include <iostream> // Librería estándar para la entrada y salida de datos
#include <vector> // Librería que nos permite definir un vector y utilizar sus métodos

using namespace std;


/* 
  Retorna falso o verdadero dependiendo si es capaz de formar
  ventanas/slides de tamaño 'k' sobre un vector llamado "nums"
*/ 
bool binarySearchTheAnswer(int k, vector<int>& nums) {
    int size = nums.size(); // De la clase vector, size() nos permite obtener su tamaño
    int result = INT_MAX; // INT_MAX es el máximo valor entero permitido, esto es 2,147,483,647  

    /* 
       Esto es una lambda expression que captura todas la variables que define su scope
       (todo lo que hay entre '{' y '}') POR REFERENCIA (&).
       Cómo es esto? 
       Ok, primero la palabra reservada auto es usada para deducir de forma automática
       el tipo de dato (entero, float, char, etc) de una variable.
       Ok, si yo sé que el valor retornado es int, porqué entonces usar auto?
       Es aconsejable por si el tipo de dato cambia en el futuro, ser conciso y es mejor
       para la legibilidad. *Recomiendo investigar más al respecto.
       `&` captura las variables por referencia, ¿qué significa esto?
       Que las variables dentro de la función lambda se referirán a las mismas que están
       afuera. Si quitan el & dentro de los [], les dará error en las variables de afuera
       que está usando (size, result, nums!).
       (int sumThreshold) son los parámetros de la función lambda, y significa umbral.
    */
    auto minSubarrayLength = [&](int sumThreshold) {
        int windowSum = 0, start = 0, minLength = INT_MAX;

        for (int end = 0; end < size; ++end) {
            
            windowSum += nums[end];

            while (windowSum >= sumThreshold) {
                minLength = min(minLength, end - start + 1);
                windowSum -= nums[start];
                ++start;
            }
        }
	cout << windowSum << endl;

        return minLength;
    };

    int low = 1, high = size;

    while (low <= high) {
        int middle = (low + high) / 2;

        if (minSubarrayLength(middle) >= k) {
            result = min(result, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (result != INT_MAX) ? true : false;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 3;

    bool result = binarySearchTheAnswer(target, nums);

    cout << "Con el arreglo " << endl;
    cout << "Result: " << boolalpha << result << endl;  // Output: 2

    return 0;
}
