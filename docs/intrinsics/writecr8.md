---
title: "__writecr8 | Microsoft Docs"
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
  - "_writecr8"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_writecr8 intrínseco"
ms.assetid: 6f8bd632-dddb-4335-971e-1acee24aa2b9
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __writecr8
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Grava o valor `Data` registrar CR8.  
  
## Sintaxe  
  
```  
void writecr8(   
   unsigned __int64 Data   
);  
```  
  
#### Parâmetros  
 \[in\]`Data`  
 O valor para gravar o registro de CR8.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__writecr8`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Nesse intrínseca está disponível somente no modo kernel e a rotina só está disponível como um intrínseco.  
  
## END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)