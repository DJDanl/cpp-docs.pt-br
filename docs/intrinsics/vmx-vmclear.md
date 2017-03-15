---
title: "__vmx_vmclear | Microsoft Docs"
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
  - "__vmx_vmclear"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução VMCLEAR"
  - "__vmx_vmclear intrínseco"
ms.assetid: e3eb98e4-50fc-4c93-9bac-340fd1f0a466
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __vmx_vmclear
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Inicializa a estrutura de controle da máquina virtual especificada \(VMCS\) e define seu estado de inicialização `Clear`.  
  
## Sintaxe  
  
```  
unsigned char __vmx_vmclear(  
   unsigned __int64 *VmcsPhysicalAddress  
);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|\[in\]`VmcsPhysicalAddress`|Um ponteiro para um local de memória de 64 bits que contém o endereço físico de limpar o VMCS.|  
  
## Valor de retorno  
  
|Valor|Significado|  
|-----------|-----------------|  
|0|A operação foi bem\-sucedida.|  
|1|A operação falhou com status estendido disponível na `VM-instruction error field` do VMCS atual.|  
|2|A operação falhou sem status disponível.|  
  
## Comentários  
 Um aplicativo pode executar uma operação de inserir a VM usando o [\_\_vmx\_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou [\_\_vmx\_vmresume](../intrinsics/vmx-vmresume.md) função.  O [\_\_vmx\_vmlaunch](../intrinsics/vmx-vmlaunch.md) função pode ser usada somente com um estado cujo lançamento é de VMCS `Clear`e o [\_\_vmx\_vmresume](../intrinsics/vmx-vmresume.md) função pode ser usada somente com um estado cujo lançamento é de VMCS `Launched`.  Conseqüentemente, usar o [\_\_vmx\_vmclear](../intrinsics/vmx-vmclear.md) função para definir o estado de início de um VMCS para `Clear`.  Use o [\_\_vmx\_vmlaunch](../intrinsics/vmx-vmlaunch.md) função sua primeira operação do VM\-enter e o [\_\_vmx\_vmresume](../intrinsics/vmx-vmresume.md) função para operações subseqüentes de VM\-enter.  
  
 O `__vmx_vmclear` função é equivalente a `VMCLEAR` instrução da máquina.  Esta função oferece suporte a interação do monitor de máquina virtual de um host com um sistema operacional e seus aplicativos de convidado.  Para obter mais informações, procure o documento, "Intel Virtualization técnico especificação para a arquitetura IA\-32 Intel," documento número C97063\-002, no [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) site.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__vmx_vmclear`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_vmx\_vmlaunch](../intrinsics/vmx-vmlaunch.md)   
 [\_\_vmx\_vmresume](../intrinsics/vmx-vmresume.md)