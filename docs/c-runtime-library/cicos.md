---
title: "_CIcos | Microsoft Docs"
ms.custom: ""
ms.date: "11/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CIcos"
apilocation: 
  - "msvcr90.dll"
  - "msvcrt.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr110.dll"
apitype: "DLLExport"
f1_keywords: 
  - "CIcos"
  - "_CIcos"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Intrínseco _CIcos"
  - "CIcos intrínseco"
ms.assetid: 6fc203fb-66f3-4ead-9784-f85833c26f1b
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CIcos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Calcula o cosseno de valor superior da pilha.  
  
## Sintaxe  
  
```  
void __cdecl _CIcos();  
```  
  
## Comentários  
 Essa versão da função de `cos` tem uma convenção chamando especializada que o compilador entenda.  Acelera a execução porque impede que as cópias são geradas e ajuda a alocação do registro.  
  
 O valor resultante é forçada na parte superior da pilha.  
  
## Requisitos  
 **Plataforma:** x86  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [cos, cosf, cosl, cosh, coshf, coshl](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)