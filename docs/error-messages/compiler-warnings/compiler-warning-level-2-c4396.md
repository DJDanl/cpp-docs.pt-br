---
title: Compilador aviso (nível 2) C4396 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4396
dev_langs:
- C++
helpviewer_keywords:
- C4396
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa0a084e90db9d48f517bfe65c6340eb532f0ae6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118564"
---
# <a name="compiler-warning-level-2-c4396"></a>Compilador aviso (nível 2) C4396

"name": o especificador embutido não pode ser usado quando uma declaração friend se refere a uma especialização de um modelo de função

Uma especialização de um modelo de função não é possível especificar qualquer um dos [embutido](../../cpp/inline-functions-cpp.md) especificadores. O compilador emite aviso C4396 e ignora o especificador embutido.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remover o `inline`, `__inline`, ou `__forceinline` especificador da declaração da função de amigo.

## <a name="example"></a>Exemplo

O código exemplo seguinte mostra um amigo inválido de função declaração com um `inline` especificador.

```
// C4396.cpp
// compile with: /W2 /c

class X;
template<class T> void Func(T t, int i);

class X {
    friend inline void Func<char>(char t, int i);  //C4396
// try the following line instead
//    friend void Func<char>(char t, int i);
    int i;
};
```