---
title: __vmx_off | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __vmx_off
dev_langs:
- C++
helpviewer_keywords:
- VMXOFF instruction
- __vmx_off intrinsic
ms.assetid: 78a32d46-9291-406c-b982-a550855aff18
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 82d94d1cd08d08a57cedf3709d18a46639e56925
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33335400"
---
# <a name="vmxoff"></a>__vmx_off
**Seção específica da Microsoft**  
  
 Desativa a operação de extensões (VMX) da máquina virtual no processador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __vmx_off();  
```  
  
## <a name="remarks"></a>Comentários  
 O `__vmx_off` função é equivalente a `VMXOFF` instrução da máquina. Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, no [Intel Corporation](http://go.microsoft.com/fwlink/p/?linkid=127) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__vmx_off`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)