---
title: Erro do compilador C3495
ms.date: 11/04/2016
f1_keywords:
- C3495
helpviewer_keywords:
- C3495
ms.assetid: 1fd40cb8-8373-403d-b8a8-f08424a50807
ms.openlocfilehash: 1a61d4f2472ef6da8aedcf8a8ef90b70de47d8af
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738265"
---
# <a name="compiler-error-c3495"></a>Erro do compilador C3495

' var ': uma captura de lambda deve ter duração de armazenamento automática

Não é possível capturar uma variável que não tenha duração de armazenamento automática, como uma variável marcada `static` ou `extern`.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Não passe uma variável `static` ou `extern` para a lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3495 porque a variável `static` `n` aparece na lista de captura de uma expressão lambda:

```cpp
// C3495.cpp

int main()
{
   static int n = 66;
   [&n]() { return n; }(); // C3495
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)

