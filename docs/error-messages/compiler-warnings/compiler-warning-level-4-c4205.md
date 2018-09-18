---
title: Compilador aviso (nível 4) C4205 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4205
dev_langs:
- C++
helpviewer_keywords:
- C4205
ms.assetid: 39b5108c-7230-41b4-b2fe-2293eb6aae28
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9847e3c009e132993bcbb6aa94d2064d61e40421
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46042358"
---
# <a name="compiler-warning-level-4-c4205"></a>Compilador aviso (nível 4) C4205

extensão não padrão usada: declaração de função estática no escopo de função

Com extensões da Microsoft (/Ze) **estático** funções podem ser declaradas dentro de outra função. A função tem escopo global.

## <a name="example"></a>Exemplo

```
// C4205.c
// compile with: /W4
void func1()
{
   static int func2();  // C4205
};

int main()
{
}
```

Essas inicializações são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).