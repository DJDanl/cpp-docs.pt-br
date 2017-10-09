---
title: Matrizes multidimensionais (C) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- arrays [C], multidimensional
- multidimensional arrays
- subscript expressions
ms.assetid: 4ba5c360-1f17-4575-b370-45f62e1f2bc2
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: fbc5ca61d1a45521c67426144ad5991170849230
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="multidimensional-arrays-c"></a>Matrizes multidimensionais (C)
Uma expressão subscrita também pode ter vários subscritos, como segue:  
  
```  
  
expression1  
[  
expression2  
] [  
expression3  
]...  
```  
  
 As expressões subscritas são associadas da esquerda para a direita. A expressão subscrita mais à esquerda, *expression1***[***expression2***]**, é avaliada primeiro. O endereço resultante da adição de *expression1* e *expression2* forma uma expressão do ponteiro; *expression3* é adicionada a essa expressão de ponteiro para formar uma nova expressão de ponteiro e assim por diante até que a última expressão subscrita seja adicionada. O operador de indireção (**\***) é aplicado depois que a última expressão subscrita é avaliada, a menos que o valor do ponteiro final trate de um tipo de matriz (veja os exemplos abaixo).  
  
 As expressões com vários subscritos referem-se aos elementos de "matrizes multidimensionais". Uma matriz multidimensional é uma matriz cujos elementos são matrizes. Por exemplo, o primeiro elemento de uma matriz tridimensional é uma matriz com duas dimensões.  
  
## <a name="examples"></a>Exemplos  
 Para os exemplos a seguir, uma matriz chamada `prop` é declarada com três elementos, cada um deles sendo uma matriz 4 por 6 de valores `int`.  
  
```  
int prop[3][4][6];  
int i, *ip, (*ipp)[6];  
```  
  
 Uma referência à matriz `prop` é semelhante a esta:  
  
```  
i = prop[0][0][1];  
```  
  
 O exemplo acima mostra como referenciar o segundo elemento individual `int` de `prop`. As matrizes são armazenadas por linha, de modo que o último subscrito varie mais rapidamente; a expressão `prop[0][0][2]` se refere ao próximo (terceiro) elemento da matriz, e assim por diante.  
  
```  
i = prop[2][1][3];  
```  
  
 Essa instrução é uma referência mais complexa a um elemento individual de `prop`. A expressão é avaliada como segue:  
  
1.  O primeiro subscrito, `2`, é multiplicado pelo tamanho de uma matriz `int` 4 por 6 e é adicionado ao valor do ponteiro `prop`. O resultado aponta para a terceira matriz 4 por 6 de `prop`.  
  
2.  O segundo subscrito, `1`, é multiplicado pelo tamanho da matriz `int` de 6 elementos e é adicionado ao endereço representado por `prop[2]`.  
  
3.  Cada elemento da matriz de 6 elementos é um valor `int`, então, o subscrito final, `3`, é multiplicado pelo tamanho de `int` antes de ser adicionado a `prop[2][1]`. O ponteiro resultante é pertinente ao quarto elemento da matriz de 6 elementos.  
  
4.  O operador de indireção é aplicado ao valor do ponteiro. O resultado é o elemento `int` nesse endereço.  
  
 Os dois próximos exemplos mostra casos em que o operador de indireção não é aplicado.  
  
```  
ip = prop[2][1];  
  
ipp = prop[2];  
```  
  
 Na primeira dessas instruções, a expressão `prop[2][1]` é uma referência válida para a matriz tridimensional `prop`; refere-se a uma matriz de 6 elementos (declarada acima). Como o valor do ponteiro é pertinente a uma matriz, o operador de indireção não é aplicado.  
  
 Da mesma forma, o resultado da expressão `prop[2]` na segunda instrução `ipp = prop[2];` é um valor de ponteiro pertinente a uma matriz bidimensional.  
  
## <a name="see-also"></a>Consulte também  
 [Operador subscript:](../cpp/subscript-operator.md)
