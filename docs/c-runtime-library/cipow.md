---
title: "_CIpow | Microsoft Docs"
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
  - "_CIpow"
apilocation: 
  - "msvcr100.dll"
  - "msvcr110.dll"
  - "msvcr120.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
  - "msvcrt.dll"
  - "msvcr90.dll"
apitype: "DLLExport"
f1_keywords: 
  - "CIpow"
  - "_CIpow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CIpow intrínseco"
  - "Intrínseco _CIpow"
ms.assetid: 477aaf0c-ac58-4252-89dd-9f3e35d47536
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CIpow
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*x* calcula elevado à potência de *y* com base nos valores superiores na pilha.  
  
## Sintaxe  
  
```  
void __cdecl _CIpow();  
```  
  
## Comentários  
 Essa versão da função de `pow` tem uma convenção chamando especializada que o compilador entenda.  Acelera a execução porque impede que as cópias são geradas e ajuda a alocação do registro.  
  
 O valor resultante é forçada na parte superior da pilha.  
  
## Requisitos  
 **Plataforma:** x86  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [pow, powf, powl](../Topic/pow,%20powf,%20powl.md)