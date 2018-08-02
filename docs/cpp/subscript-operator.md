---
title: 'Operador Subscript: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '[]'
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], subscript
- postfix operators [C++]
- '[] operator'
- subscript operator [C++], syntax
ms.assetid: 69c31494-52da-4dd0-8bbe-6ccbfd50f197
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fbdeac996320d885e4d6e131dcb735ac369b09f5
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39467904"
---
# <a name="subscript-operator"></a>Operador Subscript:
## <a name="syntax"></a>Sintaxe  
  
```  
postfix-expression [ expression ]  
```  
  
## <a name="remarks"></a>Comentários  
 Uma expressão de pós-fixação (que também pode ser uma expressão primária) seguida pelo operador de subscrito **[]**, especifica a indexação de matriz.  
  
 Para obter informações sobre matrizes gerenciadas, consulte [matrizes](../windows/arrays-cpp-component-extensions.md).  
  
 Geralmente, o valor representado pelo *postfix-expression* é um valor de ponteiro, como um identificador de matriz, e *expressão* é um valor integral (incluindo tipos enumerados). No entanto, tudo o que é necessário sintaticamente é que uma das expressões seja do tipo ponteiro e a outra seja do tipo integral. Assim que o valor integral pode estar na *postfix-expression* posição e o valor do ponteiro pode estar entre colchetes na *expressão* ou posição de subscrito. Considere o fragmento de código a seguir:  
  
```cpp 
int nArray[5] = { 0, 1, 2, 3, 4 };  
cout << nArray[2] << endl;            // prints "2"  
cout << 2[nArray] << endl;            // prints "2"  
```  
  
 No exemplo acima, a expressão `nArray[2]` é idêntica a `2[nArray]`. O motivo é que o resultado de uma expressão de subscrito *e1 * * * [** *e2* **]** é dado por:  
  
 **\*( (** *e2* **)** *+* **(***e1***) )**  
  
 O endereço gerado pela expressão não é *e2* bytes do endereço *e1*. Em vez disso, o endereço é dimensionado para gerar o próximo objeto na matriz *e2*. Por exemplo:  
  
```cpp 
double aDbl[2];  
```  
  
 Os endereços dos `aDb[0]` e `aDb[1]` são 8 bytes distância — o tamanho de um objeto do tipo **duplo**. Esse dimensionamento de acordo com o tipo de objeto é feito automaticamente pela linguagem C++ e é definido em [operadores aditivos](../cpp/additive-operators-plus-and.md) em que a adição e subtração de operandos do tipo de ponteiro é discutido.  
  
 Uma expressão subscrita também pode ter vários subscritos, como segue:  
  
 *Expression1* **[***expression2***] [***expression3***]**...  
  
 As expressões subscritas são associadas da esquerda para a direita. A expressão subscrita mais à esquerda, *expression1 ***[*** expression2***]**, é avaliada primeiro. O endereço resultante da adição de *expression1* e *expression2* forma uma expressão do ponteiro; *expression3* é adicionada a essa expressão de ponteiro para formar uma nova expressão de ponteiro e assim por diante até que a última expressão subscrita seja adicionada. O operador de indireção (**\***) é aplicado depois que a última expressão Subscrita é avaliada, a menos que o valor do ponteiro final resolve um tipo de matriz.  
  
 As expressões com vários subscritos referem-se aos elementos de matrizes multidimensionais. Uma matriz multidimensional é uma matriz cujos elementos são matrizes. Por exemplo, o primeiro elemento de uma matriz tridimensional é uma matriz com duas dimensões. O exemplo a seguir declara e inicializa uma matriz bidimensional simples de caracteres:  
  
```cpp 
// expre_Subscript_Operator.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
#define MAX_ROWS 2  
#define MAX_COLS 2  
  
int main() {  
   char c[ MAX_ROWS ][ MAX_COLS ] = { { 'a', 'b' }, { 'c', 'd' } };  
   for ( int i = 0; i < MAX_ROWS; i++ )  
      for ( int j = 0; j < MAX_COLS; j++ )  
         cout << c[ i ][ j ] << endl;  
}  
```  
  
## <a name="positive-and-negative-subscripts"></a>Subscritos positivos e negativos  
 O primeiro elemento de uma matriz é o elemento 0. O intervalo de uma matriz de C++ é de *array*[0] para *array*[*tamanho* - 1]. No entanto, o C++ oferece suporte a subscritos positivos e negativos. Os subscritos negativos devem estar dentro dos limites da matriz, se não estiverem, os resultados serão imprevisíveis. O código a seguir mostra os subscritos positivo e negativo da matriz:  
  
```cpp 
#include <iostream>  
using namespace std;  
  
int main() {  
    int intArray[1024];  
    for (int i = 0, j = 0; i < 1024; i++)  
    {  
        intArray[i] = j++;  
    }  
  
    cout << intArray[512] << endl;// 512  
  
    int *midArray = &intArray[512];  // pointer to the middle of the array  
  
    cout << midArray[-256] << endl;   // 256  
  
    cout << intArray[-256] << endl; // unpredictable  
}  
```  
  
 O subscrito negativo na última linha pode gerar um erro em tempo de execução porque aponta para um endereço 256 bytes mais baixo na memória do que a origem da matriz. O ponteiro `midArray` é inicializado na metade de `intArray`; em virtude disso, é possível usar os índices positivo e negativo da matriz nele. Os erros de subscrito de matriz não geram erros de tempo de compilação, mas geram resultados imprevisíveis.  
  
 O operador subscrito é comutativo. Portanto, as expressões *array*[*índice*] e *matriz*[*matriz*] têm garantia de serem equivalentes, enquanto o subscrito operador não está sobrecarregado (consulte [operadores sobrecarregados](../cpp/operator-overloading.md)). O primeiro formulário é a prática de codificação mais comum, mas ambas funcionam.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões pós-fixadas](../cpp/postfix-expressions.md)   
 [Operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Matrizes](../cpp/arrays-cpp.md)   
 [Matrizes unidimensionais](../c-language/one-dimensional-arrays.md)   
 [Matrizes multidimensionais](../c-language/multidimensional-arrays-c.md)