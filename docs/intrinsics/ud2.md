---
title: "__ud2 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "__ud2"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução UD2"
  - "__ud2 intrínseco"
ms.assetid: 0831cd5a-8b65-402e-bb57-11e1d5d7ffd2
caps.latest.revision: 7
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __ud2
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera uma instrução indefinida.  
  
## Sintaxe  
  
```  
void __ud2();  
```  
  
## Comentários  
 O processador gerará uma exceção de opcode inválido se você executar uma instrução indefinida.  
  
 O `__ud2` função é equivalente do `UD2` instruções de máquina e está disponível somente no modo kernel.  Para obter mais informações, procure o documento, "Manual do desenvolvedor de Software da arquitetura Intel, Volume 2: referência de conjunto de instruções," com o [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__ud2`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Exemplo  
 O exemplo a seguir executa uma instrução indefinida, o que gera uma exceção.  O manipulador de exceção, em seguida, altera o código de retorno de zero a um.  
  
```  
// __ud2_intrinsic.cpp  
#include <stdio.h>  
#include <intrin.h>  
#include <excpt.h>  
// compile with /EHa  
  
int main() {  
  
// Initialize the return code to 0.  
 int ret = 0;  
  
// Attempt to execute an undefined instruction.  
  printf("Before __ud2(). Return code = %d.\n", ret);  
  __try {   
  __ud2();   
  }  
  
// Catch any exceptions and set the return code to 1.  
  __except(EXCEPTION_EXECUTE_HANDLER){  
  printf("  In the exception handler.\n");  
  ret = 1;  
  }  
  
// Report the value of the return code.   
  printf("After __ud2().  Return code = %d.\n", ret);  
  return ret;  
}  
```  
  
  **Antes de \_\_ud2\(\).  Código de retorno \= 0.  No manipulador de exceção.  Depois de \_\_ud2\(\).  Código de retorno \= 1.**    
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)