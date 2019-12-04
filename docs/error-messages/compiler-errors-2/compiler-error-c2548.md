---
title: Erro do compilador C2548
ms.date: 11/04/2016
f1_keywords:
- C2548
helpviewer_keywords:
- C2548
ms.assetid: 01e9c835-9bf3-4020-9295-5ee448c519f3
ms.openlocfilehash: f89208314c1d2e8ddb5100da72aa600a411b4608
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756793"
---
# <a name="compiler-error-c2548"></a>Erro do compilador C2548

' classe:: membro ': faltando parâmetro padrão para parâmetro de parâmetro

A lista de parâmetros padrão não tem um parâmetro. Se você fornecer um parâmetro padrão em qualquer lugar em uma lista de parâmetros, deverá definir parâmetros padrão para todos os parâmetros subsequentes.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2548:

```cpp
// C2548.cpp
// compile with: /c
void func( int = 1, int, int = 3);  // C2548

// OK
void func2( int, int, int = 3);
void func3( int, int = 2, int = 3);
```
