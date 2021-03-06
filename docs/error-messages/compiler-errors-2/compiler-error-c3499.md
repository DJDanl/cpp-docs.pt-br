---
title: Erro do compilador C3499
ms.date: 11/04/2016
f1_keywords:
- C3499
helpviewer_keywords:
- C3499
ms.assetid: 6717de5c-ae0f-4024-bdf2-b5598009e7b6
ms.openlocfilehash: b49c868b696df75a5b5148d32fb286019c6293e4
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686129"
---
# <a name="compiler-error-c3499"></a>Erro do compilador C3499

um lambda que foi especificado para ter um tipo de retorno void não pode retornar um valor

O compilador gera esse erro quando uma expressão lambda que especifica **`void`** como o tipo de retorno retorna um valor; ou quando uma expressão lambda contém mais de uma instrução e retorna um valor, mas não especifica seu tipo de retorno.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Não retornar um valor da expressão lambda ou

- Forneça o tipo de retorno da expressão lambda ou

- Combine as instruções que compõem o corpo da expressão lambda em uma única instrução.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3499 porque o corpo de uma expressão lambda contém várias instruções e retorna um valor, mas a expressão lambda não especifica o tipo de retorno:

```cpp
// C3499a.cpp

int main()
{
   [](int x) { int n = x * 2; return n; } (5); // C3499
}
```

O exemplo a seguir mostra duas resoluções possíveis para C3499. A primeira resolução fornece o tipo de retorno da expressão lambda. A segunda resolução combina as instruções que compõem o corpo da expressão lambda em uma única instrução.

```cpp
// C3499b.cpp

int main()
{
   // Possible resolution 1:
   // Provide the return type of the lambda expression.
   [](int x) -> int { int n = x * 2; return n; } (5);

   // Possible resolution 2:
   // Combine the statements that make up the body of
   // the lambda expression into a single statement.
   [](int x) { return x * 2; } (5);
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
