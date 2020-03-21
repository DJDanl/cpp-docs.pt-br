---
title: Erro do compilador C3495
ms.date: 11/04/2016
f1_keywords:
- C3495
helpviewer_keywords:
- C3495
ms.assetid: 1fd40cb8-8373-403d-b8a8-f08424a50807
ms.openlocfilehash: 6fe4286142c90f341925d7e76ca8de6d3b7daa9f
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80075004"
---
# <a name="compiler-error-c3495"></a>Erro do compilador C3495

' var ': uma captura de lambda deve ter duração de armazenamento automática

Não é possível capturar uma variável que não tenha duração de armazenamento automática, como uma variável marcada `static` ou `extern`.

### <a name="to-correct-this-error"></a>Para corrigir este erro

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

## <a name="see-also"></a>Confira também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
