---
title: Erro do compilador C3495
ms.date: 11/04/2016
f1_keywords:
- C3495
helpviewer_keywords:
- C3495
ms.assetid: 1fd40cb8-8373-403d-b8a8-f08424a50807
ms.openlocfilehash: 3e387fe77c521a4f25ba67205f1fbd552397e272
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59035816"
---
# <a name="compiler-error-c3495"></a>Erro do compilador C3495

'var': uma captura de lambda deve ter a duração de armazenamento automático

Não é possível capturar uma variável que não tem duração de armazenamento automático, como uma variável que é marcada `static` ou `extern`.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Não passe um `static` ou `extern` variável à lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3495 porque o `static` variável `n` aparece na lista de captura de uma expressão lambda:

```
// C3495.cpp

int main()
{
   static int n = 66;
   [&n]() { return n; }(); // C3495
}
```

## <a name="see-also"></a>Consulte também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)

