---
title: Erro do compilador C3498
ms.date: 11/04/2016
f1_keywords:
- C3498
helpviewer_keywords:
- C3498
ms.assetid: 0a5a7817-0872-4119-83bf-980a19113374
ms.openlocfilehash: f1b978a585f3404cd3a881f25d6ef6a0f66b212d
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686149"
---
# <a name="compiler-error-c3498"></a>Erro do compilador C3498

' var ': não é possível capturar uma variável que tenha um Managed ou WinRTtype

Você não pode capturar uma variável que tenha um tipo gerenciado ou um tipo de Windows Runtime em um lambda.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Passe a variável gerenciada ou Windows Runtime para a lista de parâmetros da expressão lambda.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3498 porque uma variável que tem um tipo gerenciado é exibida na lista de captura de uma expressão lambda:

```cpp
// C3498a.cpp
// compile with: /clr
using namespace System;

int main()
{
   String ^ s = "Hello";
   [&s](String ^ r)
      { return String::Concat(s, r); } (", World!"); // C3498
}
```

O exemplo a seguir resolve C3498 passando a variável gerenciada `s` para a lista de parâmetros da expressão lambda:

```cpp
// C3498b.cpp
// compile with: /clr
using namespace System;

int main()
{
   String ^ s = "Hello";
   [](String ^ s, String ^ r)
      { return String::Concat(s, r); } (s, ", World!");
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
