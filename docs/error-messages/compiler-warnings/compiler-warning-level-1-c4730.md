---
title: Compilador (nível 1) de aviso C4730 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4730
dev_langs:
- C++
helpviewer_keywords:
- C4730
ms.assetid: 11303e3f-162b-4b19-970a-479686123a68
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 467d9fd04e2fef78d480fc4db1417b6e4c8d5641
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4730"></a>Aviso C4730 (compilador) (nível 1)
'main': misturar m64 e expressões podem resultar em código incorreto de ponto flutuante  
  
 Uma função usa [m64](../../cpp/m64.md) e **float**/**duplo** tipos. Como o MMX e registros de ponto flutuantes compartilham o mesmo físico registrar espaço (não podem ser usados simultaneamente), usando `__m64` e **float**/**duplo** tipos na mesma função pode resultar em corrupção de dados, possivelmente fazendo com que uma exceção.  
  
 Para usar com segurança `__m64` tipos e tipos de ponto flutuante na mesma função, cada instrução que usa um dos tipos deve ser separada pelo **_m_empty()** (para MMX) ou **_m_femms()** (para 3DNow!) intrínseco.  
  
 O exemplo a seguir gera C4730:  
  
```  
// C4730.cpp  
// compile with: /W1  
// processor: x86  
#include "mmintrin.h"  
  
void func(double)  
{  
}  
  
int main(__m64 a, __m64 b)  
{  
   __m64 m;  
   double f;  
   f = 1.0;  
   m = _m_paddb(a, b);  
   // uncomment the next line to resolve C4730  
   // _m_empty();  
   func(f * 3.0);   // C4730  
}  
```