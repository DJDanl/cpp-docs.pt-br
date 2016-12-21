---
title: "_CItan | Microsoft Docs"
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
  - "_CItan"
apilocation: 
  - "msvcr100.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr80.dll"
  - "msvcrt.dll"
  - "msvcr110.dll"
  - "msvcr90.dll"
  - "msvcr120.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_CItan"
  - "CItan"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CItan intrínseco"
  - "Intrínseco _CItan"
ms.assetid: d1ea3113-50a2-45a6-b6bc-680fcdcc0928
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CItan
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Calcula a tangente de valor superior da pilha.  
  
## Sintaxe  
  
```  
void __cdecl _CItan();  
```  
  
## Comentários  
 Essa versão da função de `tan` tem uma convenção chamando especializada que o compilador entenda.  A função acelera a execução porque impede que as cópias são geradas e ajuda a alocação do registro.  
  
 O valor resultante é forçada na parte superior da pilha.  
  
## Requisitos  
 **Plataforma:** x86  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [tan, tanf, tanl, tanh, tanhf, tanhl](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)