---
title: "_CIlog10 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CIlog10"
apilocation: 
  - "msvcr100.dll"
  - "msvcr120.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr110_clr0400.dll"
  - "msvcrt.dll"
  - "msvcr110.dll"
apitype: "DLLExport"
f1_keywords: 
  - "CIlog10"
  - "_CIlog10"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Intrínseco _CIlog10"
  - "Intrínseco CIlog10"
ms.assetid: 05d7fcaa-3cff-4cc5-8d44-015e7cacba24
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CIlog10
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Executa uma operação de `log10` no valor superior da pilha.  
  
## Sintaxe  
  
```  
void __cdecl _CIlog10();  
```  
  
## Comentários  
 Essa versão da função de `log10` tem uma convenção chamando especializada que o compilador entenda.  A função acelera a execução porque impede que as cópias são geradas e ajuda a alocação do registro.  
  
 O valor resultante é forçada na parte superior da pilha.  
  
## Requisitos  
 **Plataforma:** x86  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [log, logf, log10, log10f](../Topic/log,%20logf,%20log10,%20log10f.md)