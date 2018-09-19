---
title: Erro do compilador C3920 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3920
dev_langs:
- C++
helpviewer_keywords:
- C3920
ms.assetid: 66e91f28-ed82-4ce2-bf22-c0c74905b1ed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b85638907f350eb3545a858f1319e56b2459f09
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46112701"
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