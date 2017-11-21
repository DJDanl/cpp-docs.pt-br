---
title: "Compilador (nível 1) de aviso C4391 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4391
dev_langs: C++
helpviewer_keywords: C4391
ms.assetid: 95c6182c-fae9-4174-8f7b-98aa352e68ca
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 91ee6716ee5139da02319925609777ebfec08a56
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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