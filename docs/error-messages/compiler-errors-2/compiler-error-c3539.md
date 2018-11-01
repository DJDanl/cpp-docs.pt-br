---
title: Erro do compilador C3539
ms.date: 11/04/2016
f1_keywords:
- C3539
helpviewer_keywords:
- C3539
ms.assetid: 34a33a0f-d1b6-498f-b312-ffad2d4799b3
ms.openlocfilehash: 7cba9e0271d16420c5cfe4adbed2c7121d139d8f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523898"
---
# <a name="compiler-error-c3539"></a>Erro do compilador C3539

'type': um argumento de modelo não pode ser um tipo que contenha 'auto'

O tipo de argumento de modelo indicado não pode conter um uso do `auto` palavra-chave.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não especifique o argumento de modelo com o `auto` palavra-chave.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3539.

```
// C3539.cpp
// Compile with /Zc:auto
template<class T> class C{};
int main()
{
   C<auto> c;   // C3539
   return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)