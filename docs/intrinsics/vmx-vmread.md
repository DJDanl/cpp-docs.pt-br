---
title: "__vmx_vmread | Microsoft Docs"
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
  - "__vmx_vmread"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Instrução VMREAD"
  - "__vmx_vmread intrínseco"
ms.assetid: 08bdd7a0-6435-4ea6-b9a0-f592d870e5aa
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __vmx_vmread
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Lê um campo especificado a partir da atual estrutura de controle de máquina virtual \(VMCS\) e o coloca no local especificado.  
  
## Sintaxe  
  
```  
unsigned char __vmx_vmread(  
   size_t Field,  
   size_t *FieldValue  
);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|\[in\]`Field`|O campo VMCS ler.|  
|\[in\]`FieldValue`|Ler de um ponteiro para o local para armazenar o valor do campo VMCS especificado pelo `Field` parâmetro.|  
  
## Valor de retorno  
  
|Valor|Significado|  
|-----------|-----------------|  
|0|A operação foi bem\-sucedida.|  
|1|A operação falhou com status estendido disponível na `VM-instruction error field` do VMCS atual.|  
|2|A operação falhou sem status disponível.|  
  
## Comentários  
 O `__vmx_vmread` função é equivalente a `VMREAD` instrução da máquina.  O valor da `Field` parâmetro é um índice de campo codificado que é descrito na documentação da Intel.  Para obter mais informações, procure o documento, "Intel Virtualization técnico especificação para a arquitetura IA\-32 Intel," documento número C97063\-002, no [Intel Corporation](http://go.microsoft.com/fwlink/?LinkId=127) do site, em seguida, consulte o Apêndice C do documento.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`__vmx_vmread`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Específicos do Microsoft final  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [\_\_vmx\_vmwrite](../intrinsics/vmx-vmwrite.md)