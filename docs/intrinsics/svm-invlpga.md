---
title: "__svm_invlpga | Microsoft Docs"
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
  - "__svm_invlpga"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__svm_invlpga intrínseco"
  - "Instrução INVLPGA"
ms.assetid: aa6578ce-8278-464b-8815-a0fc45330915
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __svm_invlpga
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Invalida a entrada de mapeamento de endereço no buffer de look\-aside de tradução do computador.  Parâmetros especificam o endereço virtual e o identificador de espaço de endereço da página para invalidar.  
  
## Sintaxe  
  
```  
void __svm_invlpga(  
     void *Va,  
     int ASID);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|\[in\]`Va`|O endereço virtual da página para invalidar.|  
|\[in\]`ASID`|O identificador do espaço de endereço \(ASID\) da página para invalidar.|  
  
## Comentários  
 O `__svm_invlpga` função é equivalente a `INVLPGA` instrução da máquina.  Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Manual de volumes do programador de arquitetura AMD64 2: programação de sistema," documento número 24593, revisão 3.11, no [corporation AMD](http://go.microsoft.com/fwlink/?LinkId=23746) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__svm_invlpga`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)