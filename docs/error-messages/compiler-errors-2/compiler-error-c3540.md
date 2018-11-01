---
title: Erro do compilador C3540
ms.date: 11/04/2016
f1_keywords:
- C3540
helpviewer_keywords:
- C3540
ms.assetid: 3c0c959c-e3b7-40eb-b922-ccac44bd9d85
ms.openlocfilehash: d0c4f1b71ccd12ad39fb25ef3411d2fb46b89da7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665810"
---
# <a name="compiler-error-c3540"></a>Erro do compilador C3540

'type': sizeof não pode ser aplicado a um tipo que contenha 'auto'

O [sizeof](../../cpp/sizeof-operator.md) operador não pode ser aplicado para o tipo indicado, porque ela contém o `auto` especificador.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3540.

```
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

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[/Zc:auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)<br/>
[Operador sizeof](../../cpp/sizeof-operator.md)