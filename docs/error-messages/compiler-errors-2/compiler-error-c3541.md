---
title: Erro do compilador C3541
ms.date: 11/04/2016
f1_keywords:
- C3541
helpviewer_keywords:
- C3541
ms.assetid: 252cfd4c-5fd2-415e-a17d-6b0c254350db
ms.openlocfilehash: 356936ee09b75b6930840e015d00ccebb2fd8bc2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596372"
---
# <a name="compiler-error-c3541"></a>Erro do compilador C3541

'type': typeid não pode ser aplicado a um tipo que contenha 'auto'

O [typeid](../../windows/typeid-cpp-component-extensions.md) operador não pode ser aplicado para o tipo indicado, porque ela contém o `auto` especificador.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3541.

```
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

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[/Zc:auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)<br/>
[TypeId](../../windows/typeid-cpp-component-extensions.md)