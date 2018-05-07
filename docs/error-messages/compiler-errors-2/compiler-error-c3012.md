---
title: C3012 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3012
dev_langs:
- C++
helpviewer_keywords:
- C3012
ms.assetid: cc7040b1-b3fb-4da6-a474-877914d30332
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d30a7fbb50a984c8cec6b45a0ab4759a0578de7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3012"></a>C3012 de erro do compilador
  
> '*intrínseco*': função intrínseca não permitida diretamente dentro de uma região parallel  
  
 Um [intrínseco do compilador](../../intrinsics/compiler-intrinsics.md) função não é permitida em um `omp parallel` região. Para corrigir esse problema, mover intrínsecos fora da região ou substituí-las por equivalentes intrínsecos.   
  
## <a name="example"></a>Exemplo  
  
 O exemplo a seguir gera C3012 e mostra uma maneira de corrigir isso:  
  
```cpp  
// C3012.cpp  
// compile with: /openmp  
#ifdef __cplusplus  
extern "C" {  
#endif  
void* _ReturnAddress();  
#ifdef __cplusplus  
}  
#endif  
  
int main()  
{  
   #pragma omp parallel  
   {  
      _ReturnAddress();   // C3012  
   }  
   _ReturnAddress();      // OK  
}  
```