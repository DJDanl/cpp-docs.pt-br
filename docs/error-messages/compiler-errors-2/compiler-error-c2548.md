---
title: Erro do compilador C2548
ms.date: 11/04/2016
f1_keywords:
- C2548
helpviewer_keywords:
- C2548
ms.assetid: 01e9c835-9bf3-4020-9295-5ee448c519f3
ms.openlocfilehash: 2c680d86a0ea69d67f9e53a481f2f096f4cc7878
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50659570"
---
# <a name="compiler-error-c2548"></a>Erro do compilador C2548

'class::member': faltando parâmetro padrão para o parâmetro de parâmetro

A lista de parâmetros padrão não tem um parâmetro. Se você fornecer um parâmetro padrão em qualquer lugar em uma lista de parâmetros, você deve definir os parâmetros padrão para todos os parâmetros subsequentes.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2548:

```
// C2548.cpp
// compile with: /c
void func( int = 1, int, int = 3);  // C2548

// OK
void func2( int, int, int = 3);
void func3( int, int = 2, int = 3);
```