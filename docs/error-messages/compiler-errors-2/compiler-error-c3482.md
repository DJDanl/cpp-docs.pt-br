---
title: Erro do compilador C3482
ms.date: 11/04/2016
f1_keywords:
- C3482
helpviewer_keywords:
- C3482
ms.assetid: bf99558e-bef4-421c-bb16-dcd9c54c1011
ms.openlocfilehash: 0463f6de51e324bd02c8b766fd39909ee2803ecd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212573"
---
# <a name="compiler-error-c3482"></a>Erro do compilador C3482

' this ' só pode ser usado como uma captura de lambda dentro de uma função membro não estática

Você não pode passar **`this`** para a lista de captura de uma expressão lambda que é declarada em um método estático ou uma função global.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Converter a função de circunscrição em um método não estático ou

- Remova o **`this`** ponteiro da lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3482:

```cpp
// C3482.cpp
// compile with: /c

class C
{
public:
   static void staticMethod()
   {
      [this] {}(); // C3482
   }
};
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
