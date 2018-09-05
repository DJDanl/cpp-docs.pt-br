---
title: __vmx_vmwrite | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __vmx_vmwrite
dev_langs:
- C++
helpviewer_keywords:
- __vmx_vmwrite intrinsic
- VMWRITE instruction
ms.assetid: 88139792-fd3f-4210-97ca-9d84f43a0252
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 132841c8c24e2b625dad218aaaef2a19cba0a264
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43680492"
---
# <a name="vmxvmwrite"></a>__vmx_vmwrite
**Seção específica da Microsoft**  
  
 Grava o valor especificado para o campo especificado na estrutura de controle de máquina virtual atual (VMCS).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned char __vmx_vmwrite(   
   size_t Field,  
   size_t FieldValue  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `Field`|O campo VMCS para gravar.|  
|[in] `FieldValue`|O valor a ser gravado para o campo VMCS.|  
  
## <a name="return-value"></a>Valor de retorno  
 0  
 A operação foi bem-sucedida.  
  
 1  
 A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.  
  
 2  
 Falha na operação sem status disponível.  
  
## <a name="remarks"></a>Comentários  
 O `__vmx_vmwrite` função é equivalente ao `VMWRITE` instruções de máquina. O valor da `Field` parâmetro é um índice de campo codificado que é descrito na documentação da Intel. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/en-us/articles/intel-sdm) do site e, em seguida, consulte o Apêndice C do que documento.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__vmx_vmwrite`|X64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__vmx_vmread](../intrinsics/vmx-vmread.md)