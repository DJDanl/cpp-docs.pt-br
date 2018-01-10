---
title: "Compilador (nível 1) de aviso C4730 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4730
dev_langs: C++
helpviewer_keywords: C4730
ms.assetid: 11303e3f-162b-4b19-970a-479686123a68
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 334c53b030097dc822451b0e555a51c90e70d904
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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