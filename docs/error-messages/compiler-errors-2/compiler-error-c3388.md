---
title: Erro do compilador C3388
ms.date: 11/04/2016
f1_keywords:
- C3388
helpviewer_keywords:
- C3388
ms.assetid: 34336545-ed13-4d81-ab5f-f869799fe4c2
ms.openlocfilehash: 1f6e51542cc852543d648f9f94a964ae0cab3b30
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50512656"
---
# <a name="compiler-error-c3388"></a>Erro do compilador C3388

'type': não permitido como uma restrição, assumindo 'classe ref' para continuar análise

Uma restrição foi especificada em um tipo genérico, mas a restrição não foi especificada corretamente. Ver [restrições em parâmetros de tipo genéricos (C + + c++ CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3388.

```
// C3388.cpp
// compile with: /clr /c
interface class AA {};

generic <class T>
where T : interface class   // C3388
ref class C {};

// OK
generic <class T>
where T : AA
ref class D {};
```