---
title: "Compilador (nível 1) de aviso C4730 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4730
dev_langs:
- C++
helpviewer_keywords:
- C4730
ms.assetid: 11303e3f-162b-4b19-970a-479686123a68
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0f0820a61293856fedad2e08ab60208ac8ce64da
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4730"></a>Aviso C4730 (compilador) (nível 1)
'principal': uma combinação de m64 e expressões podem resultar em código incorreto de ponto flutuante  
  
 Usa uma função [m64](../../cpp/m64.md) e **float**/**duplo** tipos. Como MMX e registros de ponto flutuante compartilham o mesmo físico registrar espaço (não podem ser usados simultaneamente), usando `__m64` e **float**/**duplo** tipos na mesma função podem resultar em dados corrompidos, possivelmente fazendo com que uma exceção.  
  
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
