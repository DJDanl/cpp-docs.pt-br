---
title: Erro do compilador C3222
ms.date: 11/04/2016
f1_keywords:
- C3222
helpviewer_keywords:
- C3222
ms.assetid: 5624bde8-2fd0-4b8b-92ce-5dfbaf91cf93
ms.openlocfilehash: 9f2c245e98609c8da8f5f89902d5c51bbf9d2b4f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50638666"
---
# <a name="compiler-error-c3222"></a>Erro do compilador C3222

'parameter': não é possível declarar argumentos padrão para o membro de tipo de WinRT ou funções de um ou funções genéricas

Não é permitido para declarar um parâmetro de método com um argumento padrão. Um formulário sobrecarregado do método é uma maneira de contornar esse problema. Ou seja, definir um método com o mesmo nome sem parâmetros e, em seguida, inicialize a variável no corpo do método.

O exemplo a seguir gera C3222:

```
// C3222_2.cpp
// compile with: /clr
public ref class G {
   void f( int n = 0 );   // C3222
};
```
