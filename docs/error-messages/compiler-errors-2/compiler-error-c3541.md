---
title: Erro do compilador C3541
ms.date: 11/04/2016
f1_keywords:
- C3541
helpviewer_keywords:
- C3541
ms.assetid: 252cfd4c-5fd2-415e-a17d-6b0c254350db
ms.openlocfilehash: 32926d0ef9343bad9ed73458e4d52d317b628109
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221036"
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

## <a name="see-also"></a>Confira também

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[/Zc: auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)<br/>
[identificação](../../extensions/typeid-cpp-component-extensions.md)
