---
title: Erro do compilador C3498
ms.date: 11/04/2016
f1_keywords:
- C3498
helpviewer_keywords:
- C3498
ms.assetid: 0a5a7817-0872-4119-83bf-980a19113374
ms.openlocfilehash: 771e8c72ab4386bb45a11983318f412e784f5bc9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738096"
---
# <a name="compiler-error-c3498"></a>Erro do compilador C3498

' var ': não é possível capturar uma variável que tenha um Managed ou WinRTtype

Você não pode capturar uma variável que tenha um tipo gerenciado ou um tipo de Windows Runtime em um lambda.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Passe a variável gerenciada ou Windows Runtime para a lista de parâmetros da expressão lambda.

## <a name="example"></a>Exemplo

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

## <a name="example"></a>Exemplo

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

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
