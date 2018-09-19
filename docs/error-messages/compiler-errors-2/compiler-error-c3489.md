---
title: Erro do compilador C3489 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3489
dev_langs:
- C++
helpviewer_keywords:
- C3489
ms.assetid: 47b58d69-459d-4499-abc7-5f0b9303d773
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5b1631c9be33204edfa697cb349148d274fe30e6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081215"
---
# <a name="compiler-error-c3489"></a>Erro do compilador C3489

'var' é necessária quando o modo de captura padrão é por valor

Quando você especifica o modo de captura padrão para uma expressão lambda é por valor, uma variável não pode ser passada por valor para a cláusula capture dessa expressão.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Não passar explicitamente a variável para a cláusula de captura ou

- Não especifique por valor como o modo de captura padrão, ou

- Especifique por referência como o modo de captura padrão, ou

- Passe a variável por referência para a cláusula de captura. (Isso pode mudar o comportamento da expressão lambda).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3489 variável `n` é exibida pelo valor na cláusula de captura de uma expressão lambda cujo modo padrão é por valor:

```
// C3489a.cpp

int main()
{
   int n = 5;
   [=, n]() { return n; } (); // C3489
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra quatro possíveis resoluções para C3489:

```
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