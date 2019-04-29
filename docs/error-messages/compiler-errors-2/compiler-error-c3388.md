---
title: Erro do compilador C3388
ms.date: 11/04/2016
f1_keywords:
- C3388
helpviewer_keywords:
- C3388
ms.assetid: 34336545-ed13-4d81-ab5f-f869799fe4c2
ms.openlocfilehash: 3b56aae115b1a1721f3f8a8688e36b25edc7f33f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328725"
---
# <a name="compiler-error-c3388"></a>Erro do compilador C3388

'type': não permitido como uma restrição, assumindo 'classe ref' para continuar análise

Uma restrição foi especificada em um tipo genérico, mas a restrição não foi especificada corretamente. Ver [restrições em parâmetros de tipo genéricos (C++/CLI)](../../extensions/constraints-on-generic-type-parameters-cpp-cli.md) para obter mais informações.

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