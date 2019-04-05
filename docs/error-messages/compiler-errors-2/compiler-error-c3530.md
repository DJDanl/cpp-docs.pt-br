---
title: Erro do compilador C3530
ms.date: 11/04/2016
f1_keywords:
- C3530
helpviewer_keywords:
- C3530
ms.assetid: 21be81ce-b699-4c74-81bc-80a0c34d2d5a
ms.openlocfilehash: dd4368faaf323a75116128ec3a47666260436fce
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59029113"
---
# <a name="compiler-error-c3530"></a>Erro do compilador C3530

'auto' não pode ser combinado com qualquer outro especificador de tipo

Um especificador de tipo é usado com o `auto` palavra-chave.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não use um especificador de tipo em uma declaração de variável que usa o `auto` palavra-chave.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3530 porque variável `x` é declarado com ambos os `auto` palavra-chave e o tipo `int`, e como o exemplo é compilado com **/ZC: auto**.

```
// C3530.cpp
// Compile with /Zc:auto
int main()
{
   auto int x;   // C3530
   return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)