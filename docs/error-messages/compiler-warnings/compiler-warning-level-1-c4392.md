---
title: "Compilador aviso (nível 1) C4392 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4392
dev_langs:
- C++
helpviewer_keywords:
- C4392
ms.assetid: 817806ad-06a6-4b9e-8355-e25687c782dc
caps.latest.revision: 6
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
ms.openlocfilehash: 09f4d01ede8cd7f3e359b3da1d7d06ae3a2cd7f9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4392"></a>Compilador C4392 de aviso (nível 1)
'assinatura': número incorreto de argumentos para a função intrínseca, esperado 'números' argumentos  
  
 Uma declaração de função para um compilador intrínseco tinha um número incorreto de argumentos. A imagem resultante pode não funcionar corretamente.  
  
 Para corrigir esse aviso, corrija a declaração ou excluir a declaração e simplesmente #include do arquivo de cabeçalho apropriado.  
  
 O exemplo a seguir gera C4392:  
  
```  
// C4392.cpp  
// compile with: /W1  
// processor: x86  
// uncomment the following line and delete the line that  
// generated the warning to resolve  
// #include "xmmintrin.h"  
  
#ifdef  __cplusplus  
extern "C" {  
#endif  
  
extern void _mm_stream_pd(double *dp);   // C4392  
  
#ifdef  __cplusplus  
}  
#endif  
  
int main()  
{  
}  
```
