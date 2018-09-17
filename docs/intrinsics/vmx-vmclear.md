---
title: __vmx_vmclear | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __vmx_vmclear
dev_langs:
- C++
helpviewer_keywords:
- VMCLEAR instruction
- __vmx_vmclear intrinsic
ms.assetid: e3eb98e4-50fc-4c93-9bac-340fd1f0a466
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fd5661a2b6aa257c91babcc3d17b1babb0b4d2c2
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707155"
---
# <a name="vmxvmclear"></a>__vmx_vmclear
**Seção específica da Microsoft**  
  
 Inicializa a estrutura de controle de máquina virtual especificada (VMCS) e define seu estado de inicialização para `Clear`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char __vmx_vmclear(  
   unsigned __int64 *VmcsPhysicalAddress  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*VmcsPhysicalAddress*|[in] Um ponteiro para um local de memória de 64 bits que contém o endereço físico do VMCS para limpar.|  
  
## <a name="return-value"></a>Valor de retorno  
  
|Valor|Significado|  
|-----------|-------------|  
|0|A operação foi bem-sucedida.|  
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|  
|2|Falha na operação sem status disponível.|  
  
## <a name="remarks"></a>Comentários  
 Um aplicativo pode executar uma operação de inserir a VM usando o [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função. O [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) função pode ser usada somente com um VMCS cujo estado de inicialização `Clear`e o [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função pode ser usada somente com um VMCS cujo estado de inicialização é `Launched`. Consequentemente, usar o [__vmx_vmclear](../intrinsics/vmx-vmclear.md) função para definir o estado de inicialização de um VMCS para `Clear`. Use o [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) função para a operação de inserir a VM primeiro e o [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função para operações subsequentes de VM-enter.  
  
 O `__vmx_vmclear` função é equivalente ao `VMCLEAR` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/en-us/articles/intel-sdm) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__vmx_vmclear`|X64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md)   
 [__vmx_vmresume](../intrinsics/vmx-vmresume.md)