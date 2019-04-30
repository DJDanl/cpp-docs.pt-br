---
title: Erro do compilador C3539
ms.date: 11/04/2016
f1_keywords:
- C3539
helpviewer_keywords:
- C3539
ms.assetid: 34a33a0f-d1b6-498f-b312-ffad2d4799b3
ms.openlocfilehash: be1051859ebbcbdc22a9b71f8c5adba2e75c4e92
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64344654"
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