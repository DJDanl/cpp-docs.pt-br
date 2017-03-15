---
title: "__vmx_vmwrite | Microsoft Docs"
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
  - "__vmx_vmwrite"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__vmx_vmwrite intrínseco"
  - "Instrução VMWRITE"
ms.assetid: 88139792-fd3f-4210-97ca-9d84f43a0252
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __vmx_vmwrite
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Grava o valor especificado no campo especificado na estrutura de controle de máquina virtual atual \(VMCS\).  
  
## Sintaxe  
  
```  
unsigned char __vmx_vmwrite(   
   size_t Field,  
   size_t FieldValue  
);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|\[in\]`Field`|O campo VMCS para escrever.|  
|\[in\]`FieldValue`|O valor para gravar o campo VMCS.|  
  
## Valor de retorno  
 0  
 A operação foi bem\-sucedida.  
  
 1  
 A operação falhou com status estendido disponível na `VM-instruction error field` do VMCS atual.  
  
 2  
 A operação falhou sem status disponível.  
  
## Comentários  
 O `__vmx_vmwrite` função é equivalente a `VMWRITE` instrução da máquina.  O valor da `Field` parâmetro é um índice de campo codificado que é descrito na documentação da Intel.  Para obter mais informações, procure o documento, "Intel Virtualization técnico especificação para a arquitetura IA\-32 Intel," documento número C97063\-002, no [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) do site e, em seguida, consulte o Apêndice C do documento.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__vmx_vmwrite`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_vmx\_vmread](../intrinsics/vmx-vmread.md)