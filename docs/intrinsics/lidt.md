---
title: "__lidt | Microsoft Docs"
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
  - "__lidt"
  - "__lidt_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução LIDT"
  - "__lidt intrínseco"
ms.assetid: 8298d25d-a19e-4900-828d-6b3b09841882
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __lidt
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Carrega o registro de tabela de descritor de interrupção \(IDTR na\) com o valor no local de memória especificado.  
  
## Sintaxe  
  
```  
void __lidt(  
     void *Source);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|\[in\]`Source`|Ponteiro para o valor a ser copiado para IDTR na.|  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__lidt`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O `__lidt` função é equivalente do `LIDT` instruções de máquina e está disponível somente no modo kernel.  Para obter mais informações, procure o documento, "Manual do desenvolvedor de Software da arquitetura Intel, Volume 2: referência de conjunto de instruções," com o [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_sidt](../Topic/__sidt.md)