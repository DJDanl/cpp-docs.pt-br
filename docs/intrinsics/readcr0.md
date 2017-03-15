---
title: "__readcr0 | Microsoft Docs"
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
  - "__readcr0"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__readcr0 intrínseca"
ms.assetid: 25bdb093-d83c-48d7-9c0f-224de8e2c61c
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __readcr0
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Lê o registro CR0 e retorna seu valor.  
  
## Sintaxe  
  
```  
unsigned long __readcr0(void);  /* X86 */ unsigned __int64 __readcr0(void);  /* X64 */   
```  
  
## Valor de retorno  
 O valor no registro CR0.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__readcr0`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)