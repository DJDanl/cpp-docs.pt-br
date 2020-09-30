---
title: Erro do compilador C3541
ms.date: 11/04/2016
f1_keywords:
- C3541
helpviewer_keywords:
- C3541
ms.assetid: 252cfd4c-5fd2-415e-a17d-6b0c254350db
ms.openlocfilehash: 2d6179657462325a30de0c4548becff4b4cf86c9
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508064"
---
# <a name="compiler-error-c3541"></a>Erro do compilador C3541

' type ': typeid não pode ser aplicado a um tipo que contém ' auto '

Não é possível aplicar o operador [typeid](../../extensions/typeid-cpp-component-extensions.md) ao tipo indicado porque ele contém o **`auto`** especificador.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3541.

```cpp
// C3541.cpp
// Compile with /Zc:auto
#include <typeinfo>
int main() {
    auto x = 123;
    typeid(x);    // OK
    typeid(auto); // C3541
    return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-cpp.md)<br/>
[/Zc: auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)<br/>
[identificação](../../extensions/typeid-cpp-component-extensions.md)
