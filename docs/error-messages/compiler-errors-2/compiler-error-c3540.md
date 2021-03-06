---
title: Erro do compilador C3540
ms.date: 11/04/2016
f1_keywords:
- C3540
helpviewer_keywords:
- C3540
ms.assetid: 3c0c959c-e3b7-40eb-b922-ccac44bd9d85
ms.openlocfilehash: 897defd5643a90234c2ae3b7bb4f58904864e858
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508087"
---
# <a name="compiler-error-c3540"></a>Erro do compilador C3540

' type ': sizeof não pode ser aplicado a um tipo que contém ' auto '

O operador [sizeof](../../cpp/sizeof-operator.md) não pode ser aplicado ao tipo indicado porque ele contém o **`auto`** especificador.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3540.

```cpp
// C3540.cpp
// Compile with /Zc:auto
int main() {
    auto x = 123;
    sizeof(x);    // OK
    sizeof(auto); // C3540
    return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-cpp.md)<br/>
[/Zc: auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)<br/>
[Operador sizeof](../../cpp/sizeof-operator.md)
