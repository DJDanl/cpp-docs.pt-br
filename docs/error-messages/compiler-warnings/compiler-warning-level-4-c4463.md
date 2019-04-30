---
title: Compilador aviso (nível 4) C4463
ms.date: 11/04/2016
f1_keywords:
- C4463
helpviewer_keywords:
- C4463
ms.assetid: a07ae70c-db4e-472b-8b58-9137d9997323
ms.openlocfilehash: e125a532f87533958ec43ed5580665ad4108856b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400793"
---
# <a name="compiler-warning-level-4-c4463"></a>Compilador aviso (nível 4) C4463

> estouro; atribuindo *valor* ao campo de bits que pode conter apenas valores de *low_value* para *high_value*

Atribuído *valor* está fora do intervalo de valores que o campo de bits pode conter. Tipos de campo de bits com sinal usam a ordem de alto bit para o sinal, portanto, se *n* é o tamanho de campo de bits, o intervalo para campos de bits com sinal é -2<sup>n-1</sup> 2<sup>n-1</sup>-1, embora não assinado campos de bits têm um intervalo de 0 a 2<sup>n</sup>-1.

## <a name="example"></a>Exemplo

Este exemplo gera C4463 porque ele tenta atribuir um valor de 3 a um campo de bits do tipo `int` com um tamanho de 2, que tem um intervalo de -2 para 1.

Para corrigir esse problema, você pode alterar o valor atribuído para algo no intervalo permitido. Se o campo de bits destina-se para armazenar valores sem sinal no intervalo de 0 a 3, você pode alterar o tipo de declaração para `unsigned`. Se o campo destina-se para armazenar valores no intervalo -4 para 3, você pode alterar o tamanho do campo de bits para 3.

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
