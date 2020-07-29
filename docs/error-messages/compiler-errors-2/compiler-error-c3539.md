---
title: Erro do compilador C3539
ms.date: 11/04/2016
f1_keywords:
- C3539
helpviewer_keywords:
- C3539
ms.assetid: 34a33a0f-d1b6-498f-b312-ffad2d4799b3
ms.openlocfilehash: 813da5a2fd79c191df731937e58100d749f8690c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223402"
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

## <a name="see-also"></a>Confira também

[Palavra-chave auto](../../cpp/auto-keyword.md)
