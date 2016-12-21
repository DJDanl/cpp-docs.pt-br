---
title: "_CIsin | Microsoft Docs"
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
  - "_CIsin"
apilocation: 
  - "msvcr80.dll"
  - "msvcr100.dll"
  - "msvcrt.dll"
  - "msvcr110.dll"
  - "msvcr120.dll"
  - "msvcr90.dll"
  - "msvcr110_clr0400.dll"
apitype: "DLLExport"
f1_keywords: 
  - "CIsin"
  - "_CIsin"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Intrínseco _CIsin"
  - "CIsin intrínseco"
ms.assetid: f215f39a-2341-4f1c-ba8e-cb522451ceb2
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CIsin
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Calcula o seno de valor superior da pilha.  
  
## Sintaxe  
  
```  
void __cdecl _CIsin();  
```  
  
## Comentários  
 Essa versão da função de `sin` tem uma convenção chamando especializada que o compilador entenda.  Acelera a execução porque impede que as cópias são geradas e ajuda a alocação do registro.  
  
 O valor resultante é forçada na parte superior da pilha.  
  
## Requisitos  
 **Plataforma:** x86  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [sin, sinf, sinl, sinh, sinhf, sinhl](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)