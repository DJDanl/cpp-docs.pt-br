---
title: Aviso do compilador (nível 3) C4018
description: Aviso do compilador C/C++ da Microsoft C4018, suas causas e resolução.
ms.date: 10/16/2020
f1_keywords:
- C4018
helpviewer_keywords:
- C4018
ms.openlocfilehash: b9d01f6b733c2ca18880aa6f4b6fca9771f8123f
ms.sourcegitcommit: f19f02f217b80804ab321d463c76ce6f681abcc6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/19/2020
ms.locfileid: "92176168"
---
# <a name="compiler-warning-level-3-c4018"></a>Aviso do compilador (nível 3) C4018

> '*token*': incompatibilidade de assinado/não assinado

Usar o operador de *token* para comparar **`signed`** e **`unsigned`** números exigiam que o compilador converta o **`signed`** valor para **`unsigned`** .

## <a name="remarks"></a>Comentários

Uma maneira de corrigir esse aviso é se você converter um dos dois tipos ao comparar **`signed`** e **`unsigned`** tipos.

## <a name="example"></a>Exemplo

Este exemplo gera C4018 e mostra como corrigi-lo:

```cpp
// C4018.cpp
// compile with: cl /EHsc /W4 C4018.cpp
int main() {
    unsigned int uc = 0;
    int c = 0;
    unsigned int c2 = c; // implicit conversion

    if (uc < c)           // C4018
        uc = 0;

    if (uc < unsigned(c)) // OK
        uc = 0;

    if (uc < c2)          // Also OK
       uc = 0;
}
```

## <a name="see-also"></a>Confira também

[Aviso do compilador (nível 4) C4388](c4388.md)\
[Aviso do compilador (nível 4) C4389](compiler-warning-level-4-c4389.md)
