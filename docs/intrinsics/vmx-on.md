---
title: "__vmx_on | Microsoft Docs"
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
  - "__vmx_on"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução VMXON"
  - "__vmx_on intrínseco"
ms.assetid: 16804991-6a75-4adf-8ec2-bc95acfa4801
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __vmx_on
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Ativa a operação de extensões \(VMX\) da máquina virtual no processador.  
  
## Sintaxe  
  
```  
unsigned char __vmx_on(  
   unsigned __int64 *VmsSupportPhysicalAddress  
);  
```  
  
#### Parâmetros  
 \[in\]`VmsSupportPhysicalAddress`  
 Um ponteiro para um endereço físico de 64 bits que aponta para uma estrutura de controle da máquina virtual \(VMCS\).  
  
## Valor de retorno  
  
|Valor|Significado|  
|-----------|-----------------|  
|0|A operação foi bem\-sucedida.|  
|1|A operação falhou com status estendido disponível na `VM-instruction error field` do VMCS atual.|  
|2|A operação falhou sem status disponível.|  
  
## Comentários  
 O `__vmx_on` função corresponde do `VMXON` instruções de máquina.  Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Intel Virtualization técnico especificação para a arquitetura IA\-32 Intel," documento número C97063\-002, no [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__vmx_on`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)