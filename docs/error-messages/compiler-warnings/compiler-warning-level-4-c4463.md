---
title: Aviso do compilador (nível 4) C4463
ms.date: 11/04/2016
f1_keywords:
- C4463
helpviewer_keywords:
- C4463
ms.assetid: a07ae70c-db4e-472b-8b58-9137d9997323
ms.openlocfilehash: acc7957493942a9c0e19ce098b74ed0b5d75a12d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214354"
---
# <a name="compiler-warning-level-4-c4463"></a>Aviso do compilador (nível 4) C4463

> contra atribuindo *valor* ao campo de bits que só pode conter valores de *low_value* para *high_value*

O *valor* atribuído está fora do intervalo de valores que o campo de bits pode conter. Os tipos de campo de bits assinados usam o bit de ordem superior para o sinal; portanto, se *n* for o tamanho do campo de bits, o intervalo para campos de bits assinados será-2<sup>n-1</sup> a 2<sup>n-1</sup>-1, enquanto os campos de bits não assinados têm um intervalo de 0 a 2<sup>n</sup>-1.

## <a name="example"></a>Exemplo

Este exemplo gera C4463 porque tenta atribuir um valor de 3 a um campo de bits do tipo **`int`** com um tamanho de 2, que tem um intervalo de-2 a 1.

Para corrigir esse problema, você pode alterar o valor atribuído para algo no intervalo permitido. Se o campo de bits se destinar a manter valores não assinados no intervalo de 0 a 3, você poderá alterar o tipo de declaração para **`unsigned`** . Se o campo for destinado a conter valores no intervalo de-4 a 3, você poderá alterar o tamanho do campo de bits para 3.

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
