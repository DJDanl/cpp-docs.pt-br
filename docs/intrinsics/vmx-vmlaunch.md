---
title: __vmx_vmlaunch | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __vmx_vmlaunch
dev_langs: C++
helpviewer_keywords:
- VMLAUNCH instruction
- __vmx_vmlaunch intrinsic
ms.assetid: 708f7c38-b7c1-4ee7-bfc4-0daeb9cc9360
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 45986af1a63f79e4466227f767fdf96fd1c2cb35
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="vmxvmlaunch"></a>__vmx_vmlaunch
**Seção específica da Microsoft**  
  
 Coloca o aplicativo de chamada no estado de operação não raiz VMX (VM enter) usando a estrutura atual do controle de máquina virtual (VMCS).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char __vmx_vmlaunch(  
   void);  
```  
  
## <a name="return-value"></a>Valor de retorno  
  
|Valor|Significado|  
|-----------|-------------|  
|0|A operação foi bem-sucedida.|  
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|  
|2|Falha na operação sem status disponível.|  
  
## <a name="remarks"></a>Comentários  
 Um aplicativo pode executar uma operação de inserir a VM usando o [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função. O [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) função pode ser usada somente com um VMCS cujo estado da inicialização `Clear`e o [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função pode ser usada somente com um VMCS cujo estado de inicialização é `Launched`. Consequentemente, use o [__vmx_vmclear](../intrinsics/vmx-vmclear.md) função para definir o estado de inicialização de um VMCS para `Clear`e, em seguida, use o [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) função para a primeira operação de VM-enter e o [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função para operações subsequentes de VM-enter.  
  
 O `__vmx_vmlaunch` função é equivalente a `VMLAUNCH` instrução da máquina. Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, no [Intel Corporation](http://go.microsoft.com/fwlink/p/?linkid=127) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__vmx_vmlaunch`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__vmx_vmresume](../intrinsics/vmx-vmresume.md)   
 [__vmx_vmclear](../intrinsics/vmx-vmclear.md)