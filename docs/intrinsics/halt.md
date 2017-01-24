---
title: "__halt | Microsoft Docs"
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
  - "__halt"
  - "__halt_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__halt intrínseco"
  - "Instrução HLT"
ms.assetid: a074f44a-101c-45a5-8a5e-cfd223c34002
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __halt
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Interrompe o microprocessador até que ocorra uma interrupção habilitada, uma interrupção de nonmaskable \(NMI\) ou uma reinicialização.  
  
## Sintaxe  
  
```  
void __halt( void );  
```  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__halt`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O `__halt` função é equivalente do `HLT` instruções de máquina e está disponível somente no modo kernel.  Para obter mais informações, procure o documento, "Manual do desenvolvedor de Software da arquitetura Intel, Volume 2: referência de conjunto de instruções," com o [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)