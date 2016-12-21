---
title: "__svm_vmrun | Microsoft Docs"
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
  - "__svm_vmrun"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__svm_vmrun intrínseco"
  - "Instrução VMRUN"
ms.assetid: ae98a781-fc17-47b2-b40f-86fcebf1867b
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __svm_vmrun
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Inicia a execução do código do convidado de máquina virtual que corresponde ao bloco de controle de máquina virtual especificada \(VMCB\).  
  
## Sintaxe  
  
```  
void __svm_vmrun(  
   size_t VmcbPhysicalAddress  
);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|\[in\]`VmcbPhysicalAddress`|O endereço físico do VMCB.|  
  
## Comentários  
 O `__svm_vmrun` função usa uma quantidade mínima de informações no VMCB para começar a executar o código de convidado da máquina virtual.  Use o [\_\_svm\_vmsave](../intrinsics/svm-vmsave.md) ou [\_\_svm\_vmload](../intrinsics/svm-vmload.md) funcionar se você precisar de mais informações para lidar com uma interrupção complexa ou alternar para outro convidado.  
  
 O `__svm_vmrun` função é equivalente a `VMRUN` instrução da máquina.  Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Manual de volumes do programador de arquitetura AMD64 2: programação de sistema," número do documento 24593, revisão 3.11 ou mais recente, no [corporation AMD](http://go.microsoft.com/fwlink/?LinkId=23746) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__svm_vmrun`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_svm\_vmsave](../intrinsics/svm-vmsave.md)   
 [\_\_svm\_vmload](../intrinsics/svm-vmload.md)