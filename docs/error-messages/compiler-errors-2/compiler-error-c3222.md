---
title: Erro do compilador C3222
ms.date: 11/04/2016
f1_keywords:
- C3222
helpviewer_keywords:
- C3222
ms.assetid: 5624bde8-2fd0-4b8b-92ce-5dfbaf91cf93
ms.openlocfilehash: 96a6b1b81d2d82328dcb4ceaca376f247f785c13
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74737940"
---
# <a name="compiler-error-c3222"></a>Erro do compilador C3222

' Parameter ': não é possível declarar argumentos padrão para funções membro de um tipo gerenciado ou WinRT ou funções genéricas

Não é permitido declarar um parâmetro de método com um argumento padrão. Uma forma sobrecarregada do método é uma forma de contornar esse problema. Ou seja, defina um método com o mesmo nome sem parâmetros e, em seguida, inicialize a variável no corpo do método.

O exemplo a seguir gera C3222:

```cpp
// C3222_2.cpp
// compile with: /clr
public ref class G {
   void f( int n = 0 );   // C3222
};
```
