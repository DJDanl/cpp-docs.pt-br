---
title: Erro do compilador C3539
ms.date: 11/04/2016
f1_keywords:
- C3539
helpviewer_keywords:
- C3539
ms.assetid: 34a33a0f-d1b6-498f-b312-ffad2d4799b3
ms.openlocfilehash: e30ea0713229bfd8da395baef710571f8dfd49e9
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508152"
---
# <a name="compiler-error-c3539"></a>Erro do compilador C3539

' type ': um argumento de template não pode ser um tipo que contenha ' auto '

O tipo de argumento de modelo indicado não pode conter um uso da **`auto`** palavra-chave.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não especifique o argumento de modelo com a **`auto`** palavra-chave.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3539.

```cpp
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

[Palavra-chave auto](../../cpp/auto-cpp.md)
