---
title: noinline
ms.date: 11/04/2016
f1_keywords:
- noinline_cpp
helpviewer_keywords:
- noinline __declspec keyword
- __declspec keyword [C++], noinline
ms.assetid: f259d55b-dec7-4bde-8cf9-14521e4fdc42
ms.openlocfilehash: bedf17072c06ec893b9cbd83b46403dcd3bc1560
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87186679"
---
# <a name="noinline"></a>noinline

**Específico da Microsoft**

**`__declspec(noinline)`** informa ao compilador para nunca embutir uma função de membro específica (função em uma classe).

Pode ser válido não embutir uma função quando ela é pequena e não é crítica para o desempenho do seu código. Ou seja, se a função for pequena e se for improvável que ela seja chamada com frequência, como uma função que trata de uma condição de erro.

Tenha em mente que, se uma função estiver marcada **`noinline`** , a função de chamada será menor e, portanto, uma candidata para a entrada de compilador.

```cpp
class X {
   __declspec(noinline) int mbrfunc() {
      return 0;
   }   // will not inline
};
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[inline, __inline, \_ _forceinline](inline-functions-cpp.md)
