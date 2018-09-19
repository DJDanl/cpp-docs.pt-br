---
title: Erro do compilador C3482 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3482
dev_langs:
- C++
helpviewer_keywords:
- C3482
ms.assetid: bf99558e-bef4-421c-bb16-dcd9c54c1011
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9921c25575888ab2db1c092f9325002d1becb921
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053369"
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