---
title: Erro do compilador C3498
ms.date: 11/04/2016
f1_keywords:
- C3498
helpviewer_keywords:
- C3498
ms.assetid: 0a5a7817-0872-4119-83bf-980a19113374
ms.openlocfilehash: 463e210e5a1ac5eb6d197062ed8921f9bbae4ad2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62380990"
---
# <a name="compiler-error-c3498"></a>Erro do compilador C3498

'var': não é possível capturar uma variável que tem um gerenciado ou WinRTtype

Não é possível capturar uma variável que tem um tipo gerenciado ou um tipo de tempo de execução do Windows em um lambda.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Passe o gerenciado ou variável de tempo de execução do Windows para a lista de parâmetros da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3498 como uma variável que tem um tipo gerenciado aparece na lista de captura de uma expressão lambda:

```
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

O exemplo a seguir resolve C3498, passando a variável gerenciada `s` à lista de parâmetros da expressão lambda:

```
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