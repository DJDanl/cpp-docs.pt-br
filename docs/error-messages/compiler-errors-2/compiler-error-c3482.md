---
title: Erro do compilador C3482
ms.date: 11/04/2016
f1_keywords:
- C3482
helpviewer_keywords:
- C3482
ms.assetid: bf99558e-bef4-421c-bb16-dcd9c54c1011
ms.openlocfilehash: 6ff269d719dd354932ef79946ae99a9b60490199
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173217"
---
# <a name="compiler-error-c3482"></a>Erro do compilador C3482

'this' só pode ser usado como uma captura de lambda dentro de uma função de membro não estático

Não é possível passar `this` à lista de captura de uma expressão lambda que é declarada em um método estático ou uma função global.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Converter função em um método não estático, ou

- Remover o `this` ponteiro da lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3482:

```
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

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)