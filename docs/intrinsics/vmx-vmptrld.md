---
title: __vmx_vmptrld | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __vmx_vmptrld
dev_langs: C++
helpviewer_keywords:
- __vmx_vmptrld intrinsic
- VMPTRLD instruction
ms.assetid: 95c9ec5b-1a81-41ba-983e-327bd6a65fcb
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 78c6ba1a4545a03ae7f67821cf649eb936b4ed8a
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="vmxvmptrld"></a>__vmx_vmptrld
**Seção específica da Microsoft**  
  
 Carrega o ponteiro para a estrutura atual do controle de máquina virtual (VMCS) do endereço especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int __vmx_vmptrld(   
   unsigned __int64 *VmcsPhysicalAddress   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] *`VmcsPhysicalAddress`  
 O endereço onde o ponteiro VMCS está armazenado.  
  
## <a name="return-value"></a>Valor de retorno  
 0  
 A operação foi bem-sucedida.  
  
 1  
 A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.  
  
 2  
 Falha na operação sem status disponível.  
  
## <a name="remarks"></a>Comentários  
 O ponteiro VMCS é um endereço físico de 64 bits.  
  
 O `__vmx_vmptrld` função é equivalente a `VMPTRLD` instrução da máquina. Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, no [Intel Corporation](http://go.microsoft.com/fwlink/p/?linkid=127) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__vmx_vmptrld`|[!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__vmx_vmptrst](../intrinsics/vmx-vmptrst.md)