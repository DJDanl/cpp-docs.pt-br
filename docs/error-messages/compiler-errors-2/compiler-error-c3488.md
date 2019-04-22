---
title: Erro do compilador C3488
ms.date: 11/04/2016
f1_keywords:
- C3488
helpviewer_keywords:
- C3488
ms.assetid: 0a6fcd76-dd3b-48d7-abb3-22eccda96034
ms.openlocfilehash: ed3cccb77a40ab646c9a6375cf4c182de62aa478
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59025053"
---
# <a name="compiler-error-c3488"></a>Erro do compilador C3488

'var' não é permitida quando o modo de captura padrão é por referência

Quando você especifica que o modo de captura padrão para uma expressão lambda por referência, você não pode passar uma variável por referência para a cláusula capture dessa expressão.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Não passar explicitamente a variável para a cláusula de captura ou

- Não especifique por referência como o modo de captura padrão, ou

- Especifique por valor como o modo de captura padrão, ou

- A variável passada por valor para a cláusula de captura. (Isso pode mudar o comportamento da expressão lambda).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3488 porque uma referência à variável `n` aparece na cláusula de captura de uma expressão lambda cujo padrão é por referência:

```
// C3488a.cpp

int main()
{
   int n = 5;
   [&, &n]() { return n; } (); // C3488
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra quatro possíveis resoluções para C3488:

```
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