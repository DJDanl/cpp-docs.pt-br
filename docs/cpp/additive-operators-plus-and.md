---
title: 'Operadores aditivos: + e - | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- +
- '-'
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], addition
- subtraction operator [C++], additive operators
- + operator [C++], additive operators
- additive operators [C++]
- arithmetic operators [C++], additive operators
- '- operator [C++], additive operators in C++'
ms.assetid: d4afafe7-e201-4c69-a649-37f17756e784
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d1096565843cfe150530a825254e9ad6c24b5ec8
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="additive-operators--and--"></a>Operadores aditivos: + e -
## <a name="syntax"></a>Sintaxe  
  
```  
expression + expression   
expression - expression  
```  
  
## <a name="remarks"></a>Comentários  
 Os operadores de adição são:  
  
-   Adição (**+**)  
  
-   Subtração (**-**)  
  
 Esses operadores binários possuem associatividade da esquerda para a direita.  
  
 Os operadores de adição usam operandos de tipos aritméticos ou ponteiro. O resultado da adição (**+**) operador é a soma dos operandos. O resultado da subtração (**-**) operador é a diferença entre os operandos. Se um ou ambos os operandos forem ponteiros, eles devem ser ponteiros para os objetos, não para funções. Se ambos os operandos forem ponteiros, os resultados não serão significativos a menos que ambos sejam ponteiros para os objetos na mesma matriz.  
  
 Operadores aditivos usam operandos de *aritméticas*, *integral*, e *escalar* tipos. Eles são definidos na tabela a seguir.  
  
### <a name="types-used-with-additive-operators"></a>Tipos usados com operadores de adição  
  
|Tipo|Significado|  
|----------|-------------|  
|*arithmetic*|Os tipos integral e flutuante são coletivamente chamados de tipos “aritméticos”.|  
|*integral*|Os tipos char e int de todos os tamanhos (curto, longo) e enumerações são os tipos “integrais”.|  
|*scalar*|Os operandos escalares são operandos aritméticos ou de ponteiro.|  
  
 As combinações legais para usar esses operadores são:  
  
 *aritmética* + *aritmético*  
  
 *scalar* + *integral*  
  
 *integral* + *scalar*  
  
 *aritmética* - *aritmético*  
  
 *scalar* - *scalar*  
  
 Observe que a adição e subtração não são operações equivalentes.  
  
 Se ambos os operandos forem do tipo aritmético, as conversões abordados [conversões padrão](standard-conversions.md) são aplicadas para os operandos e o resultado é do tipo convertido.  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_Additive_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
#define SIZE 5  
using namespace std;  
int main() {  
   int i = 5, j = 10;  
   int n[SIZE] = { 0, 1, 2, 3, 4 };  
   cout  << "5 + 10 = " << i + j << endl  
         << "5 - 10 = " << i - j << endl;  
  
   // use pointer arithmetic on array  
  
   cout << "n[3] = " << *( n + 3 ) << endl;  
}  
```  
  
## <a name="pointer-addition"></a>Adição de ponteiro  
 Se um dos operandos em uma operação de adição é um ponteiro para uma matriz de objetos, o outro deve ser do tipo integral. O resultado é um ponteiro que tem o mesmo tipo do ponteiro original e que aponta para outro elemento da matriz. O fragmento de código a seguir ilustra esse conceito:  
  
```  
short IntArray[10]; // Objects of type short occupy 2 bytes  
short *pIntArray = IntArray;  
  
for( int i = 0; i < 10; ++i )  
{  
    *pIntArray = i;  
    cout << *pIntArray << "\n";  
    pIntArray = pIntArray + 1;  
}  
```  
  
 Embora o valor de integral 1 seja adicionado a `pIntArray`, isso não significa "adicionar 1 ao endereço"; significa "ajustar o ponteiro de modo a apontar para o próximo objeto na matriz" que esteja afastado por 2 bytes (ou `sizeof( int )`).  
  
> [!NOTE]
>  O código do formato `pIntArray = pIntArray + 1` raramente é encontrado em programas C++; para executar um incremento, estes formatos são preferíveis: `pIntArray++` ou `pIntArray += 1`.  
  
## <a name="pointer-subtraction"></a>Subtração de ponteiro  
 Se ambos os operandos forem ponteiros, o resultado da subtração será a diferença (em elementos de matriz) entre os operandos. A expressão de subtração gerará um resultado de inteiro assinado de tipo ptrdiff_t (definidos no arquivo de inclusão padrão \<stddef.h >).  
  
 Um dos operandos pode ser do tipo integral, desde que seja o segundo operando. O resultado da subtração é do mesmo tipo do ponteiro original. O valor de subtração é um ponteiro para o (*n* - *i*) elemento de matriz th, onde *n* é o elemento apontado por o ponteiro original e *i* é o valor integral do segundo operando.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores aditivos C](../c-language/c-additive-operators.md)
