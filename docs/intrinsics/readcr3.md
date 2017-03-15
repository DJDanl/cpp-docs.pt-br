---
title: "__readcr3 | Microsoft Docs"
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
  - "__readcr3"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__readcr3 intrínseco"
ms.assetid: e24392c3-cad7-4788-8f31-94bf2e9e0053
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __readcr3
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Lê o registro de CR3 e retorna seu valor.  
  
## Sintaxe  
  
```  
unsigned __int64 __readcr3(void);  
```  
  
## Valor de retorno  
 O valor no registrador CR3.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__readcr3`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Nesse intrínseca está disponível somente no modo kernel e a rotina só está disponível como um intrínseco.  
  
## END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)