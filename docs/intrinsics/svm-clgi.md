---
title: "__svm_clgi | Microsoft Docs"
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
  - "__svm_clgi"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução CLGI"
  - "__svm_clgi intrínseco"
ms.assetid: 6640f5ab-9472-46f9-a042-e15c4f1ff858
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __svm_clgi
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Limpa o sinalizador global de interrupção.  
  
## Sintaxe  
  
```  
void __svm_clgi( void );  
```  
  
## Comentários  
 O `__svm_clgi` função é equivalente a `CLGI` instrução da máquina.  O indicador de interrupção global determina se o microprocessador ignora, adia ou trata de interrupções devido a eventos como, por exemplo, uma exceção de debug, um alerta de temperatura de hardware ou uma conclusão de e\/S.  
  
 Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Manual de volumes do programador de arquitetura AMD64 2: programação de sistema," documento número 24593, revisão 3.11, no [corporation AMD](http://go.microsoft.com/fwlink/?LinkId=23746) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__svm_clgi`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_svm\_stgi](../intrinsics/svm-stgi.md)