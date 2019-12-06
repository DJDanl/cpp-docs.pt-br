---
title: noinline
ms.date: 11/04/2016
f1_keywords:
- noinline_cpp
helpviewer_keywords:
- noinline __declspec keyword
- __declspec keyword [C++], noinline
ms.assetid: f259d55b-dec7-4bde-8cf9-14521e4fdc42
ms.openlocfilehash: 6e424846c46dd50852b62008c4f1f38827da849c
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857405"
---
# <a name="noinline"></a>noinline

**Seção específica da Microsoft**

**__declspec (sem linha)** diz ao compilador para nunca embutir uma função de membro específica (função em uma classe).

Pode ser válido não embutir uma função quando ela é pequena e não é crítica para o desempenho do seu código. Ou seja, se a função for pequena e se for improvável que ela seja chamada com frequência, como uma função que trata de uma condição de erro.

Tenha em mente que, se uma função for marcada como não **embutida**, a função de chamada será menor e, portanto, uma candidata para o embutimento de compilador.

```cpp
class X {
   __declspec(noinline) int mbrfunc() {
      return 0;
   }   // will not inline
};
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[inline, __inline, \__forceinline](inline-functions-cpp.md)
