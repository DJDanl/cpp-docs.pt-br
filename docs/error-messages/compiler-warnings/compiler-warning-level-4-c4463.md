---
title: Compilador (nível 4) de aviso C4463 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4463
dev_langs:
- C++
helpviewer_keywords:
- C4463
ms.assetid: a07ae70c-db4e-472b-8b58-9137d9997323
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3c13e0a79c667ecedbf3fd065338892d3af9c2ee
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4463"></a>Compilador C4463 de aviso (nível 4)  
  
> estouro; atribuindo *valor* para o campo de bits que pode conter apenas valores de *low_value* para *high_value*  
  
Atribuída *valor* está fora do intervalo de valores que o campo de bits pode conter. Tipos de campo de bits assinados usam a ordem de alto bit de entrada, portanto, se *n* é o tamanho de campo de bits, o intervalo para campos de bits assinados -2<sup>n-1</sup> 2<sup>n-1</sup>-1, embora não assinado os campos de bits têm um intervalo de 0 a 2<sup>n</sup>-1.  
  
## <a name="example"></a>Exemplo  
  
Este exemplo gera C4463 porque ele tenta atribuir um valor de 3 a um campo de bits de tipo `int` com um tamanho de 2, que tem um intervalo de -2 para 1.  
  
Para corrigir esse problema, você pode alterar o valor atribuído para um valor no intervalo permitido. Se o campo de bits destina-se para manter os valores não assinados no intervalo de 0 a 3, você pode alterar o tipo de declaração para `unsigned`. Se o campo foi criado para manter os valores no intervalo -4 para 3, você pode alterar o tamanho de campo de bits para 3.  
  
```cpp  
// C4463_overflow.cpp
// compile with: cl /W4 /EHsc C4463_overflow.cpp
struct S { 
    int x : 2; // int type treats high-order bit as sign
}; 

int main() { 
    S s; 
    s.x = 3; // warning C4463: overflow; assigning 3 
    // to bit-field that can only hold values from -2 to 1 
    // To fix, change assigned value to fit in range,
    // increase size of bitfield, and/or change base type 
    // to unsigned.
} 
```  
