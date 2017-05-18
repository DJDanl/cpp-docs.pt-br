---
title: C3899 de erro do compilador | Documentos do Microsoft
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 58d6cf8cbfe1bd8b649861f436a0c6dfb5e4accb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3899"></a>C3899 de erro do compilador
'var': uso de l-value initonly do membro de dados não é permitido dentro de uma região paralela na classe 'class'  
  
 Um [initonly (C + + / CLI)](../../dotnet/initonly-cpp-cli.md) membro de dados não pode ser inicializado em que parte de um construtor que está em uma [paralela](../../parallel/openmp/reference/parallel.md) região.  Isso ocorre porque o compilador faz uma realocação interna desse código, de modo que, efetivamente não é parte do construtor.  
  
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
