---
title: "__vmx_vmptrld | Microsoft Docs"
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
  - "__vmx_vmptrld"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__vmx_vmptrld intrínseco"
  - "Instrução VMPTRLD"
ms.assetid: 95c9ec5b-1a81-41ba-983e-327bd6a65fcb
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __vmx_vmptrld
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Carrega o ponteiro para a estrutura atual do controle da máquina virtual \(VMCS\) do endereço especificado.  
  
## Sintaxe  
  
```  
int __vmx_vmptrld(   
   unsigned __int64 *VmcsPhysicalAddress   
);  
```  
  
#### Parâmetros  
 \[in\] \*`VmcsPhysicalAddress`  
 O endereço onde o ponteiro VMCS está armazenado.  
  
## Valor de retorno  
 0  
 A operação foi bem\-sucedida.  
  
 1  
 A operação falhou com status estendido disponível na `VM-instruction error field` do VMCS atual.  
  
 2  
 A operação falhou sem status disponível.  
  
## Comentários  
 O ponteiro VMCS é um endereço físico de 64 bits.  
  
 O `__vmx_vmptrld` função é equivalente a `VMPTRLD` instrução da máquina.  Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Intel Virtualization técnico especificação para a arquitetura IA\-32 Intel," documento número C97063\-002, no [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__vmx_vmptrld`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_vmx\_vmptrst](../intrinsics/vmx-vmptrst.md)