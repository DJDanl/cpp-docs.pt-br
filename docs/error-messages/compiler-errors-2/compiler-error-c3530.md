---
title: Erro do compilador C3530 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3530
dev_langs:
- C++
helpviewer_keywords:
- C3530
ms.assetid: 21be81ce-b699-4c74-81bc-80a0c34d2d5a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5866e2ea44b84f3afeb0cef8423abc28f8e056ab
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094787"
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