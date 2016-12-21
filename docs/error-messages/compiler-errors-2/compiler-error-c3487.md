---
title: "Erro do Compilador C3487 | Microsoft Docs"
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
  - "C3487"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3487"
ms.assetid: 39bda474-4418-4a79-98bf-2b22fa92eaaa
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3487
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

tipo de retorno: todos retornam expressões devem deduzir o mesmo tipo: anteriormente era 'tipo de retorno'  
  
 Um lambda deve especificar seu tipo de retorno, a menos que ela contém uma única instrução return.  Se uma lambda contiver várias instruções de retorno, eles devem todos ter o mesmo tipo.  
  
### Para corrigir este erro  
  
-   Especifique um tipo de retorno à direita para o lambda.  Verifique se todas as devoluções de lambda são do mesmo tipo ou podem ser convertidas implicitamente para o tipo de retorno.  
  
## Exemplo  
 O exemplo a seguir gera C3487 porque os tipos de retorno do lambda não coincidem:  
  
```  
// C3487.cpp  
// Compile by using: cl /c /W4 C3487.cpp  
  
int* test(int* pi) {  
   // To fix the error, uncomment the trailing return type below  
   auto odd_pointer = [=]() /* -> int* */ {  
      if (*pi % 2)   
         return pi;  
      return nullptr; // C3487 - nullptr is not an int* type  
   };  
   return odd_pointer();  
}  
```  
  
## Consulte também  
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)