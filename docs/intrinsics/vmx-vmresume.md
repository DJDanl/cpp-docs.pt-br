---
title: "__vmx_vmresume | Microsoft Docs"
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
  - "__vmx_vmresume"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__vmx_vmresume intrínseco"
  - "Instrução VMRESUME"
ms.assetid: 233fe1b6-c727-493a-a484-1b2363732281
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __vmx_vmresume
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Reinicia a operação de raiz não VMX usando a estrutura de controle da máquina virtual atual \(VMCS\).  
  
## Sintaxe  
  
```  
unsigned char __vmx_vmresume(  
   void);  
```  
  
## Valor de retorno  
  
|Valor|Significado|  
|-----------|-----------------|  
|0|A operação foi bem\-sucedida.|  
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|  
|2|Falha na operação sem status disponível.|  
  
## Comentários  
 Um aplicativo pode executar uma operação de inserir a VM usando o [\_\_vmx\_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou `__vmx_vmresume` função. O `__vmx_vmlaunch` função pode ser usada apenas com um VMCS cujo estado de inicialização é `Clear`, e o `__vmx_vmresume` função pode ser usada apenas com um VMCS cujo estado de inicialização é `Launched`. Conseqüentemente, usar o [\_\_vmx\_vmclear](../intrinsics/vmx-vmclear.md) função para definir o estado de inicialização de um VMCS para `Clear`, e, em seguida, usar o `__vmx_vmlaunch` função para a primeira operação insira VM e o `__vmx_vmresume` função para operações subsequentes VM\-enter.  
  
 O `__vmx_vmresume` função é equivalente de `VMRESUME` instruções de máquina. Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento PDF, "Intel Virtualization técnico especificação para a arquitetura IA\-32 Intel," documento número C97063\-002, o [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__vmx_vmresume`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \< intrin. h \>  
  
## FIM de específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_vmx\_vmlaunch](../intrinsics/vmx-vmlaunch.md)   
 [\_\_vmx\_vmclear](../intrinsics/vmx-vmclear.md)