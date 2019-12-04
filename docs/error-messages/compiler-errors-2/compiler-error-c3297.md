---
title: Erro do compilador C3297
ms.date: 11/04/2016
f1_keywords:
- C3297
helpviewer_keywords:
- C3297
ms.assetid: 2a718b4c-6cdb-4418-92c0-fc3a259431c4
ms.openlocfilehash: 6fed01b0dcf50a657b6eb457ab8e546d0648beec
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760082"
---
# <a name="compiler-error-c3297"></a>Erro do compilador C3297

' constraint_2 ': não é possível usar ' constraint_1 ' como uma restrição porque ' constraint_1 ' tem a restrição de valor

As classes de valor são lacradas. Se uma restrição for uma classe de valor, outra restrição nunca poderá ser derivada dela.

Confira mais informações em [Restrições em parâmetros de tipo genérico (C++/CLI)](../../extensions/constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3297.

```cpp
// C3297.cpp
// compile with: /clr /c
generic<class T, class U>
where T : value class
where U : T   // C3297
public ref struct R {};
```
