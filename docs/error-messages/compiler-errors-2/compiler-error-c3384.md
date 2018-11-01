---
title: Erro do compilador C3384
ms.date: 11/04/2016
f1_keywords:
- C3384
helpviewer_keywords:
- C3384
ms.assetid: c9f92c6a-62a9-4333-b2b1-bc55c7f288b6
ms.openlocfilehash: 0c9804666bfd73f98541f95434b9cebf5185d2ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50566810"
---
# <a name="compiler-error-c3384"></a>Erro do compilador C3384

'type_parameter': a restrição de valor e a restrição ref são mutuamente exclusivas

Não é possível restringir um tipo genérico para ambos `value class` e `ref class`.

Ver [restrições em parâmetros de tipo genéricos (C + + c++ CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3384.

```
// C3384.cpp
// compile with: /c /clr
generic <typename T>
where T : ref class
where T : value class   // C3384
ref class List {};
```