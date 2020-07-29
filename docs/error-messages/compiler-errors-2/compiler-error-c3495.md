---
title: Erro do compilador C3495
ms.date: 11/04/2016
f1_keywords:
- C3495
helpviewer_keywords:
- C3495
ms.assetid: 1fd40cb8-8373-403d-b8a8-f08424a50807
ms.openlocfilehash: a67d4d859e3a9dd2241f14a476492df0fd3e6b8d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223415"
---
# <a name="compiler-error-c3495"></a>Erro do compilador C3495

' var ': uma captura de lambda deve ter duração de armazenamento automática

Você não pode capturar uma variável que não tenha duração de armazenamento automática, como uma variável que está marcada **`static`** ou **`extern`** .

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Não passe uma **`static`** variável ou **`extern`** para a lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3495 porque a **`static`** variável `n` aparece na lista de captura de uma expressão lambda:

```cpp
// C3495.cpp

int main()
{
   static int n = 66;
   [&n]() { return n; }(); // C3495
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
