---
title: __svm_vmrun | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __svm_vmrun
dev_langs:
- C++
helpviewer_keywords:
- __svm_vmrun intrinsic
- VMRUN instruction
ms.assetid: ae98a781-fc17-47b2-b40f-86fcebf1867b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3777492212bbff368902acf589f0a3c46ea4ac18
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718649"
---
# <a name="svmvmrun"></a>__svm_vmrun
**Seção específica da Microsoft**  
  
 Inicia a execução do código de convidado de máquina virtual que corresponde ao bloco de controle de máquina virtual especificada (VMCB).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __svm_vmrun(  
   size_t VmcbPhysicalAddress  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*VmcbPhysicalAddress*|[in] O endereço físico do VMCB.|  
  
## <a name="remarks"></a>Comentários  
 O `__svm_vmrun` função usa uma quantidade mínima de informações no VMCB para começar a executar o código de convidado da máquina virtual. Use o [__svm_vmsave](../intrinsics/svm-vmsave.md) ou [__svm_vmload](../intrinsics/svm-vmload.md) funcionar se você precisar de mais informações para lidar com uma interrupção complexa ou alternar para outra convidada.  
  
 O `__svm_vmrun` função é equivalente ao `VMRUN` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento "Volume de Manual do programador da arquitetura AMD64 2: programação do sistema," número de documento 24593, revisão 3.11 ou posterior, no [corporation AMD](https://developer.amd.com/resources/developer-guides-manuals/) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__svm_vmrun`|x86, x64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__svm_vmsave](../intrinsics/svm-vmsave.md)   
 [__svm_vmload](../intrinsics/svm-vmload.md)