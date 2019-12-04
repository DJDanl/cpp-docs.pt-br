---
title: Erro do compilador C3530
ms.date: 11/04/2016
f1_keywords:
- C3530
helpviewer_keywords:
- C3530
ms.assetid: 21be81ce-b699-4c74-81bc-80a0c34d2d5a
ms.openlocfilehash: 3766eaa83457ba6cffaf8b1599983a065772911c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74750137"
---
# <a name="compiler-error-c3530"></a>Erro do compilador C3530

' auto ' não pode ser combinado com nenhum outro especificador de tipo

Um especificador de tipo é usado com a palavra-chave `auto`.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Não use um especificador de tipo em uma declaração de variável que usa a palavra-chave `auto`.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3530 porque a variável `x` é declarada com a palavra-chave `auto` e o tipo `int`, e porque o exemplo é compilado com **/Zc: auto**.

```cpp
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
