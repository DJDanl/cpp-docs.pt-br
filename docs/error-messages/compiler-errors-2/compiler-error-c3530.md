---
title: Erro do compilador C3530
ms.date: 11/04/2016
f1_keywords:
- C3530
helpviewer_keywords:
- C3530
ms.assetid: 21be81ce-b699-4c74-81bc-80a0c34d2d5a
ms.openlocfilehash: 023d7f0a5d509c4b301a9985da8ea7feb1f3d203
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228824"
---
# <a name="compiler-error-c3530"></a>Erro do compilador C3530

' auto ' não pode ser combinado com nenhum outro especificador de tipo

Um especificador de tipo é usado com a **`auto`** palavra-chave.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não use um especificador de tipo em uma declaração de variável que use a **`auto`** palavra-chave.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3530 porque `x` a variável é declarada com a **`auto`** palavra-chave e o tipo **`int`** , e porque o exemplo é compilado com **/Zc: auto**.

```cpp
// C3530.cpp
// Compile with /Zc:auto
int main()
{
   auto int x;   // C3530
   return 0;
}
```

## <a name="see-also"></a>Confira também

[Palavra-chave auto](../../cpp/auto-keyword.md)
