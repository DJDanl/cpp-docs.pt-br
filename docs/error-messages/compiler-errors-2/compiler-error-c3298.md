---
title: Erro do compilador C3298
ms.date: 11/04/2016
f1_keywords:
- C3298
helpviewer_keywords:
- C3298
ms.assetid: 458c2680-95bb-4d5e-895f-ce4115844193
ms.openlocfilehash: fe6913d402c6ce4df3551c159eb56a12590799cb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62222525"
---
# <a name="compiler-error-c3298"></a>Erro do compilador C3298

'constraint_1': não é possível usar 'constraint_2' como uma restrição porque 'constraint_2' tem a restrição ref e 'constraint_1' tem a restrição de valor

Você não pode especificar características mutuamente exclusivas para uma restrição. Por exemplo, um parâmetro de tipo genérico não pode ser restrito a um tipo de valor e um tipo de referência.

Para obter mais informações, consulte [restrições em parâmetros de tipo genéricos (C++/CLI)](../../extensions/constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3298.

```
// C3298.cpp
// compile with: /clr /c
generic<class T, class U>
where T : ref class
where U : T, value class   // C3298
public ref struct R {};
```