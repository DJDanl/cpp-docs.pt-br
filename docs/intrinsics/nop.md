---
title: "__nop | Microsoft Docs"
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
  - "__nop"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução Nop"
  - "intrínseco Nop"
ms.assetid: 7a2a938b-87e0-476d-a348-03ea7635b6b9
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __nop
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera o código de máquina específico da plataforma que não executa nenhuma operação.  
  
## Sintaxe  
  
```  
void __nop();  
```  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__nop`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Comentários  
 O `__nop` função é equivalente a `NOP` instrução da máquina.  Para obter mais informações, procure o documento, "Manual do desenvolvedor de Software da arquitetura Intel, Volume 2: referência de conjunto de instruções," com o [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_noop](../intrinsics/noop.md)