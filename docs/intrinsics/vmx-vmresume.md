---
title: __vmx_vmresume | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __vmx_vmresume
dev_langs:
- C++
helpviewer_keywords:
- __vmx_vmresume intrinsic
- VMRESUME instruction
ms.assetid: 233fe1b6-c727-493a-a484-1b2363732281
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8809489a71410af21e47d8771ec208340fc893a7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33330873"
---
# <a name="vmxvmresume"></a>__vmx_vmresume
**Seção específica da Microsoft**  
  
 Reinicia a operação de raiz não VMX usando a estrutura de controle da máquina virtual atual (VMCS).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char __vmx_vmresume(  
   void);  
```  
  
## <a name="return-value"></a>Valor de retorno  
  
|Valor|Significado|  
|-----------|-------------|  
|0|A operação foi bem-sucedida.|  
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|  
|2|Falha na operação sem status disponível.|  
  
## <a name="remarks"></a>Comentários  
 Um aplicativo pode executar uma operação de inserir a VM usando o [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou `__vmx_vmresume` função. O `__vmx_vmlaunch` função pode ser usada somente com um VMCS cujo estado da inicialização `Clear`e o `__vmx_vmresume` função pode ser usada somente com um VMCS cujo estado de inicialização é `Launched`. Consequentemente, use o [__vmx_vmclear](../intrinsics/vmx-vmclear.md) função para definir o estado de inicialização de um VMCS para `Clear`e, em seguida, use o `__vmx_vmlaunch` função para a primeira operação de VM-enter e o `__vmx_vmresume` função para inserir subsequentes de VM operações.  
  
 O `__vmx_vmresume` função é equivalente a `VMRESUME` instrução da máquina. Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento PDF, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, no [Intel Corporation](http://go.microsoft.com/fwlink/p/?linkid=127) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__vmx_vmresume`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md)   
 [__vmx_vmclear](../intrinsics/vmx-vmclear.md)