---
title: __vmx_on
ms.date: 09/02/2019
f1_keywords:
- __vmx_on
helpviewer_keywords:
- VMXON instruction
- __vmx_on intrinsic
ms.assetid: 16804991-6a75-4adf-8ec2-bc95acfa4801
ms.openlocfilehash: b6041711d9b6806362b856475151f2c4f63750cb
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219582"
---
# <a name="__vmx_on"></a>__vmx_on

**Seção específica da Microsoft**

Ativa a operação VMX (extensões de máquina virtual) no processador.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __vmx_on(
   unsigned __int64 *VmsSupportPhysicalAddress
);
```

### <a name="parameters"></a>Parâmetros

*VmsSupportPhysicalAddress*\
no Um ponteiro para um endereço físico de 64 bits que aponta para uma estrutura de controle de máquina virtual (VMCS).

## <a name="return-value"></a>Valor retornado

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com o status estendido disponível `VM-instruction error field` no do VMCs atual.|
|2|A operação falhou sem status disponível.|

## <a name="remarks"></a>Comentários

A `__vmx_on` função corresponde à instrução `VMXON` da máquina. Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, procure o documento "Especificação técnica de virtualização da Intel para a arquitetura Intel IA-32", número de documento C97063-002, no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_on`|X64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
