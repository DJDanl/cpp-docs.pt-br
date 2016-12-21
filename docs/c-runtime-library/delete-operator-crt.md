---
title: "operator delete(CRT) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr90.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
  - "msvcr80.dll"
apitype: "DLLExport"
f1_keywords: 
  - "delete[]"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "operator delete[]"
  - "exclusão de vetor"
ms.assetid: e91bd0df-3815-40ca-950a-67b470518aed
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# operator delete(CRT)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Frees atribuiu o bloco.  
  
## Sintaxe  
  
```  
  
      void __cdecl operator delete[](void * object);  
void __cdecl operator delete[](void * object,   
   void * memory) throw();  
void __cdecl operator delete[](void * object,   
   const std::nothrow_t&) throw();  
```  
  
#### Parâmetros  
 *memória*  
 O local de memória que está sendo liberado.  
  
 *objeto*  
 Um ponteiro para o objeto que está sendo excluído.  
  
## Comentários  
 Esse formulário de **operator delete** é conhecido como a exclusão de vetor, em contraste com o formulário escalar de exclusão \([a exclusão do operador](../c-runtime-library/operator-delete-crt.md)\).  
  
 **operator** `delete[]` libera memória alocada por [operador novo &#91;&#93;](../c-runtime-library/new-operator-crt.md).  
  
 O primeiro formulário desse operador é conhecido como o formulário de nonplacement.  O segundo e o terceiro formas desse operador não serão chamados em geral de código mas para existir para dar ao compilador uma exclusão compatível para chamar quando uma nova posição falha.  
  
 O primeiro formulário do operador é definido pelo compilador e não requer new.h ser incluído em seu programa.  
  
 Com exceção do comportamento de reprodução ou de reprodução, o CRT **operator** `delete[]` se comporta como [a exclusão do operador &#91;&#93;](../Topic/operator%20delete\(%3Cnew%3E\).md) na biblioteca padrão C\+\+.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`delete[]`|\<new.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 Consulte [operador novo &#91;&#93;](../c-runtime-library/new-operator-crt.md) para obter exemplos de uso do operador **delete**.  
  
## Consulte também  
 [Alocação de memória](../c-runtime-library/memory-allocation.md)