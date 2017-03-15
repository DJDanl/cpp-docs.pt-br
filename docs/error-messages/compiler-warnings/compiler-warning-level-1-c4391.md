---
title: "Compilador aviso (nível 1) C4391 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4391
dev_langs:
- C++
helpviewer_keywords:
- C4391
ms.assetid: 95c6182c-fae9-4174-8f7b-98aa352e68ca
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 81b7e6ba142edb94dd77f4a63c42b245b61ccc45
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4391"></a>Compilador C4391 de aviso (nível 1)
'assinatura': tipo de retorno incorreto para a função intrínseca, esperado 'type'  
  
 Uma declaração de função para um compilador intrínseco tinha o tipo de retorno incorreto. A imagem resultante pode não funcionar corretamente.  
  
 Para corrigir esse aviso, corrija a declaração ou excluir a declaração e simplesmente #include do arquivo de cabeçalho apropriado.  
  
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
