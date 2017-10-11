---
title: C3899 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3899
dev_langs:
- C++
helpviewer_keywords:
- C3899
ms.assetid: 14e07e4a-f7a7-4309-baaa-649d69e12e23
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c7d9d32b3063dbecde375159ad90eec5bf128d56
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3899"></a>C3899 de erro do compilador
'var': uso l-value de membro de dados initonly não é permitido diretamente dentro de uma região parallel na classe 'class'  
  
 Um [initonly (C + + CLI)](../../dotnet/initonly-cpp-cli.md) membro de dados não pode ser inicializado em parte de um construtor que está em um [paralela](../../parallel/openmp/reference/parallel.md) região.  Isso ocorre porque o compilador faz uma realocação interna do código, que, efetivamente não faz parte do construtor.  
  
 Para resolver, inicialize o membro de dados initonly no construtor, mas fora da região paralela.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3899.  
  
```  
// C3899.cpp  
// compile with: /clr /openmp  
#include <omp.h>   
  
public ref struct R {  
   initonly int x;  
   R() {  
      x = omp_get_thread_num() + 1000;   // OK  
      #pragma omp parallel num_threads(5)  
      {  
         // cannot assign to 'x' here  
         x = omp_get_thread_num() + 1000;   // C3899  
         System::Console::WriteLine("thread {0}", omp_get_thread_num());  
      }  
      x = omp_get_thread_num() + 1000;   // OK  
   }  
};  
  
int main() {  
   R^ r = gcnew R;  
   System::Console::WriteLine(r->x);  
}  
```
