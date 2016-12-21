---
title: "Erro do Compilador C3899 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3899"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3899"
ms.assetid: 14e07e4a-f7a7-4309-baaa-649d69e12e23
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3899
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

var “”: o uso de l\- valor do membro de dados não é permitido initonly diretamente dentro de uma região paralelo em classes das classes  
  
 Um membro de dados de [initonly](../../dotnet/initonly-cpp-cli.md) não pode ser inicializado naquela parte de um construtor que está em uma região de [parallel](../../parallel/openmp/reference/parallel.md) .  Isso ocorre porque o compilador faz uma realocação interno do código, de modo que, é efetivamente já não faz parte do construtor.  
  
 Para resolver, inicializar initonly o membro de dados no construtor, mas fora da região paralela.  
  
## Exemplo  
 O exemplo a seguir produz C3899.  
  
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