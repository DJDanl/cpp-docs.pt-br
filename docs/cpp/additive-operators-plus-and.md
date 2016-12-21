---
title: "Operadores aditivos: + e - | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "-"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador -, operadores aditivos em C++"
  - "Operador +, operadores aditivos"
  - "operadores aditivos"
  - "operadores aritméticos [C++], operadores aditivos"
  - "operadores [C++], adição"
  - "Operador de subtração, operadores aditivos"
ms.assetid: d4afafe7-e201-4c69-a649-37f17756e784
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores aditivos: + e -
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
expression + expression   
expression – expression  
```  
  
## Comentários  
 Os operadores de adição são:  
  
-   Adição \(**\+**\)  
  
-   Subtração \(**–**\)  
  
 Esses operadores binários possuem associatividade da esquerda para a direita.  
  
 Os operadores de adição usam operandos de tipos aritméticos ou ponteiro.  O resultado do operador de adição \(**\+**\) é a soma dos operandos.  O resultado do operador de subtração \(**–**\) é a diferença entre os operandos.  Se um ou ambos os operandos forem ponteiros, eles devem ser ponteiros para os objetos, não para funções.  Se ambos os operandos forem ponteiros, os resultados não serão significativos a menos que ambos sejam ponteiros para os objetos na mesma matriz.  
  
 Os operadores de adição usam operandos dos tipos *aritmético*, *integral* e *escalar*.  Eles são definidos na tabela a seguir.  
  
### Tipos usados com operadores de adição  
  
|Tipo|Significado|  
|----------|-----------------|  
|*aritmético*|Os tipos integral e flutuante são coletivamente chamados de tipos “aritméticos”.|  
|*integral*|Os tipos char e int de todos os tamanhos \(curto, longo\) e enumerações são os tipos “integrais”.|  
|*escalar*|Os operandos escalares são operandos aritméticos ou de ponteiro.|  
  
 As combinações legais para usar esses operadores são:  
  
 *aritméticas* \+ *aritméticas*  
  
 *escalar* \+ *integral*  
  
 *integral* \+ *escalar*  
  
 *aritméticas* – *aritméticas*  
  
 *escalar* – *escalar*  
  
 Observe que a adição e subtração não são operações equivalentes.  
  
 Se ambos os operandos forem do tipo aritmético, as conversões abordadas em [Conversões aritméticas](../misc/arithmetic-conversions.md) são aplicadas aos operandos, e o resultado é do tipo convertido.  
  
## Exemplo  
  
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
  
## Adição de ponteiro  
 Se um dos operandos em uma operação de adição é um ponteiro para uma matriz de objetos, o outro deve ser do tipo integral.  O resultado é um ponteiro que tem o mesmo tipo do ponteiro original e que aponta para outro elemento da matriz.  O fragmento de código a seguir ilustra esse conceito:  
  
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
  
 Embora o valor de integral 1 seja adicionado a `pIntArray`, isso não significa "adicionar 1 ao endereço"; significa "ajustar o ponteiro de modo a apontar para o próximo objeto na matriz" que esteja afastado por 2 bytes \(ou `sizeof( int )`\).  
  
> [!NOTE]
>  O código do formato `pIntArray = pIntArray + 1` raramente é encontrado em programas C\+\+; para executar um incremento, estes formatos são preferíveis: `pIntArray++` ou `pIntArray += 1`.  
  
## Subtração de ponteiro  
 Se ambos os operandos forem ponteiros, o resultado da subtração será a diferença \(em elementos de matriz\) entre os operandos.  A expressão de subtração gera um resultado integral com sinal do tipo ptrdiff\_t \(definido no arquivo de inclusão padrão STDDEF.H\).  
  
 Um dos operandos pode ser do tipo integral, desde que seja o segundo operando.  O resultado da subtração é do mesmo tipo do ponteiro original.  O valor da subtração é um ponteiro para o \(*n* – *i*\)º elemento de matriz, onde *n* é o elemento apontado pelo ponteiro original e *i* é o valor integral do segundo operando.  
  
## Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Adição de tipos de ponteiro](../misc/addition-of-pointer-types.md)   
 [Subtração de tipos de ponteiro](../misc/subtraction-of-pointer-types.md)   
 [Operadores aditivos C](../c-language/c-additive-operators.md)