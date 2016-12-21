---
title: "__vmx_vmptrst | Microsoft Docs"
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
  - "__vmx_vmptrst"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__vmx_vmptrst intrínseco"
  - "Instrução VMPTRST"
ms.assetid: 8dc66e47-03a0-41b0-8e25-c1485f42817a
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __vmx_vmptrst
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Armazena o ponteiro para a estrutura atual do controle da máquina virtual \(VMCS\) no endereço especificado.  
  
## Sintaxe  
  
```  
void __vmx_vmptrst(   
   unsigned __int64 *VmcsPhysicalAddress   
);  
```  
  
#### Parâmetros  
 \[in\] \*`VmcsPhysicalAddress`  
 O endereço onde o ponteiro VMCS atual está armazenado.  
  
## Comentários  
 O ponteiro VMCS é um endereço físico de 64 bits.  
  
 O `__vmx_vmptrst` função é equivalente a `VMPTRST` instrução da máquina.  Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Intel Virtualization técnico especificação para a arquitetura IA\-32 Intel," documento número C97063\-002, no [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__vmx_vmptrst`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_vmx\_vmptrld](../intrinsics/vmx-vmptrld.md)