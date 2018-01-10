---
title: __vmx_on | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __vmx_on
dev_langs: C++
helpviewer_keywords:
- VMXON instruction
- __vmx_on intrinsic
ms.assetid: 16804991-6a75-4adf-8ec2-bc95acfa4801
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 457866d54fe3f290c40ca70b07e19ec3f337de41
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="vmxon"></a>__vmx_on
**Seção específica da Microsoft**  
  
 Ativa a operação de extensões (VMX) da máquina virtual no processador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char __vmx_on(  
   unsigned __int64 *VmsSupportPhysicalAddress  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `VmsSupportPhysicalAddress`  
 Um ponteiro para um endereço físico de 64 bits que aponta para uma estrutura de controle de máquina virtual (VMCS).  
  
## <a name="return-value"></a>Valor de retorno  
  
|Valor|Significado|  
|-----------|-------------|  
|0|A operação foi bem-sucedida.|  
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|  
|2|Falha na operação sem status disponível.|  
  
## <a name="remarks"></a>Comentários  
 O `__vmx_on` função corresponde do `VMXON` instrução da máquina. Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, no [Intel Corporation](http://go.microsoft.com/fwlink/p/?linkid=127) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__vmx_on`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)