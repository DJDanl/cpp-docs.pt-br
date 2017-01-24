---
title: "Verificando substitui&#231;&#245;es de mem&#243;ria | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "memória, substitui"
ms.assetid: da7c5d77-a267-415f-a8ab-ee5ce5bfc286
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Verificando substitui&#231;&#245;es de mem&#243;ria
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Se ocorrer uma violação de acesso em uma chamada a uma função de manipulação de heap, é possível que o programa danificou o heap.  Um sintoma comum dessa situação seria:  
  
```  
Access Violation in _searchseg  
```  
  
 A função de [\_heapchk](../../c-runtime-library/reference/heapchk.md) está disponível em construções de depuração e de versão \(Windows NT\) somente para verificar a integridade do heap da biblioteca de tempo de execução.  Você pode usar `_heapchk` de forma semelhante à função de `AfxCheckMemory` para isolar um heap substituir, por exemplo:  
  
```  
if(_heapchk()!=_HEAPOK)  
   DebugBreak();  
```  
  
 Se essa função nunca falha, você precisa isolar\-se em que ponto o heap tiver sido danificado.  
  
## Consulte também  
 [Corrigindo problemas de compilação da versão](../../build/reference/fixing-release-build-problems.md)