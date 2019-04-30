---
title: Erro do compilador C3920
ms.date: 11/04/2016
f1_keywords:
- C3920
helpviewer_keywords:
- C3920
ms.assetid: 66e91f28-ed82-4ce2-bf22-c0c74905b1ed
ms.openlocfilehash: d7163cf07a440a0afd1216b3e5cf665326ffb963
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386597"
---
# <a name="compiler-error-c3920"></a>Erro do compilador C3920

' operador ': não é possível definir um incremento/decremento de sufixo WinRT ou chamar o sufixo de operador CLR operador WinRT ou CLR chamará o prefixo correspondente WinRT ou CLR operador (op_Increment/op_Decrement), mas com semântica de pós-fixo

O tempo de execução do Windows e o CLR não têm suporte para o operador de sufixo e operadores de sufixo definida pelo usuário não são permitidos.  Você pode definir um operador de prefixo e o operador de prefixo que será usado para operações de pré e pós-incremento.

O exemplo a seguir gera C3920 e mostra como corrigi-lo:

```
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