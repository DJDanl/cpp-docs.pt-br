---
title: Erro do compilador C3920
ms.date: 11/04/2016
f1_keywords:
- C3920
helpviewer_keywords:
- C3920
ms.assetid: 66e91f28-ed82-4ce2-bf22-c0c74905b1ed
ms.openlocfilehash: 416752054f7397a058329e1ee4bdaef693dd0d28
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758457"
---
# <a name="compiler-error-c3920"></a>Erro do compilador C3920

' operator ' ': não é possível definir um operador de sufixo de incremento/do WinRT ou CLR chamando o sufixo WinRT ou o operador CLR chamará o prefixo correspondente WinRT ou o operador CLR (op_Increment/op_Decrement), mas com semântica de sufixo

O Windows Runtime e o CLR não dão suporte ao operador de sufixo e os operadores de sufixo definidos pelo usuário não são permitidos.  Você pode definir um operador de prefixo e o operador de prefixo será usado para operações anteriores e posteriores ao incremento.

O exemplo a seguir gera C3920 e mostra como corrigi-lo:

```cpp
// C3920.cpp
// compile with: /clr /LD
public value struct V {
   static V operator ++(V me, int)
   // try the following line instead
   // static V operator ++(V me)
   {   // C3920
      me.m_i++;
      return me;
   }

   int m_i;
};
```
