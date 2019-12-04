---
title: Erro do compilador C3488
ms.date: 11/04/2016
f1_keywords:
- C3488
helpviewer_keywords:
- C3488
ms.assetid: 0a6fcd76-dd3b-48d7-abb3-22eccda96034
ms.openlocfilehash: 2b69ed4ac8b7e706096d107e9dfaa4447ca1bc79
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738421"
---
# <a name="compiler-error-c3488"></a>Erro do compilador C3488

' var ' não é permitido quando o modo de captura padrão é por referência

Quando você especifica que o modo de captura padrão para uma expressão lambda é por referência, não é possível passar uma variável por referência à cláusula Capture dessa expressão.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Não passe explicitamente a variável para a cláusula Capture ou

- Não especifique by-reference como o modo de captura padrão ou

- Especificar por valor como o modo de captura padrão ou

- Passe a variável por valor para a cláusula Capture. (Isso pode alterar o comportamento da expressão lambda.)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3488 porque uma referência à variável `n` aparece na cláusula Capture de uma expressão lambda cujo modo padrão é por referência:

```cpp
// C3488a.cpp

int main()
{
   int n = 5;
   [&, &n]() { return n; } (); // C3488
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra quatro resoluções possíveis para C3488:

```cpp
// C3488b.cpp

int main()
{
   int n = 5;

   // Possible resolution 1:
   // Do not explicitly pass &n to the capture clause.
   [&]() { return n; } ();

   // Possible resolution 2:
   // Do not specify by-reference as the default capture mode.
   [&n]() { return n; } ();

   // Possible resolution 3:
   // Specify by-value as the default capture mode.
   [=, &n]() { return n; } ();

   // Possible resolution 4:
   // Pass n by value to the capture clause.
   [n]() { return n; } ();
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
