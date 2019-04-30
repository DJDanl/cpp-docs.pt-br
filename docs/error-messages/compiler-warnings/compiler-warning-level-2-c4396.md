---
title: Compilador aviso (nível 2) C4396
ms.date: 11/04/2016
f1_keywords:
- C4396
helpviewer_keywords:
- C4396
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
ms.openlocfilehash: 84045ea2c285be8b1c1c9d1fd62b417db00dd29c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402444"
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