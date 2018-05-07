---
title: Compilador (nível 1) de aviso C4391 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4391
dev_langs:
- C++
helpviewer_keywords:
- C4391
ms.assetid: 95c6182c-fae9-4174-8f7b-98aa352e68ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0152d6e04d40e3e0389cf51ba7bdf71de4cd4791
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4391"></a>Compilador C4391 de aviso (nível 1)
'assinatura': tipo de retorno incorreto para função intrínseca, esperado 'type'  
  
 Uma declaração de função para um intrínseco do compilador tinha o tipo de retorno incorreto. A imagem resultante pode não funcionar corretamente.  
  
 Para corrigir esse aviso, corrija a declaração ou excluir a declaração e simplesmente #include arquivo de cabeçalho adequado.  
  
 O exemplo a seguir gera C4391:  
  
```  
// C4391.cpp  
// compile with: /W1  
// processor: x86  
// uncomment the following line and delete the line that  
// generated the warning to resolve  
// #include "xmmintrin.h"  
  
#ifdef  __cplusplus  
extern "C" {  
#endif  
  
extern void _mm_load_ss(float *p);   // C4391  
  
#ifdef  __cplusplus  
}  
#endif  
  
int main()  
{  
}  
```