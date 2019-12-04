---
title: Erro do compilador C3489
ms.date: 11/04/2016
f1_keywords:
- C3489
helpviewer_keywords:
- C3489
ms.assetid: 47b58d69-459d-4499-abc7-5f0b9303d773
ms.openlocfilehash: 67eaa9806dff96783f391c46c890b34e1ceef5a3
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738408"
---
# <a name="compiler-error-c3489"></a>Erro do compilador C3489

' var ' é necessário quando o modo de captura padrão é por valor

Quando você especifica que o modo de captura padrão para uma expressão lambda é por valor, não é possível passar uma variável por valor para a cláusula Capture dessa expressão.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Não passe explicitamente a variável para a cláusula Capture ou

- Não especifique por valor como o modo de captura padrão ou

- Especifique by-reference como o modo de captura padrão ou

- Passe a variável por referência à cláusula Capture. (Isso pode alterar o comportamento da expressão lambda.)

## <a name="example"></a>Exemplo

O exemplo a seguir gera a variável C3489 `n` aparece pelo valor na cláusula Capture de uma expressão lambda cujo modo padrão é por valor:

```cpp
// C3489a.cpp

int main()
{
   int n = 5;
   [=, n]() { return n; } (); // C3489
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra quatro resoluções possíveis para C3489:

```cpp
// C3489b.cpp

int main()
{
   int n = 5;

   // Possible resolution 1:
   // Do not explicitly pass n to the capture clause.
   [=]() { return n; } ();

   // Possible resolution 2:
   // Do not specify by-value as the default capture mode.
   [n]() { return n; } ();

   // Possible resolution 3:
   // Specify by-reference as the default capture mode.
   [&, n]() { return n; } ();

   // Possible resolution 4:
   // Pass n by reference to the capture clause.
   [&n]() { return n; } ();
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
