---
title: __vmx_vmptrld
ms.date: 09/02/2019
f1_keywords:
- __vmx_vmptrld
helpviewer_keywords:
- __vmx_vmptrld intrinsic
- VMPTRLD instruction
ms.assetid: 95c9ec5b-1a81-41ba-983e-327bd6a65fcb
ms.openlocfilehash: 79b5a8b34b652ae1f011e89c793a7157c9e435ee
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219498"
---
# <a name="__vmx_vmptrld"></a>__vmx_vmptrld

**Seção específica da Microsoft**

Carrega o ponteiro para a estrutura de controle de máquina virtual (VMCS) atual do endereço especificado.

## <a name="syntax"></a>Sintaxe

```C
int __vmx_vmptrld(
   unsigned __int64 *VmcsPhysicalAddress
);
```

### <a name="parameters"></a>Parâmetros

*VmcsPhysicalAddress*\
no O endereço onde o ponteiro VMCS é armazenado.

## <a name="return-value"></a>Valor retornado

0
A operação foi bem-sucedida.

uma
A operação falhou com o status estendido disponível `VM-instruction error field` no do VMCs atual.

2
A operação falhou sem status disponível.

## <a name="remarks"></a>Comentários

O ponteiro VMCS é um endereço físico de 64 bits.

A `__vmx_vmptrld` função é equivalente à instrução `VMPTRLD` da máquina. Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, procure o documento "Especificação técnica de virtualização da Intel para a arquitetura Intel IA-32", número de documento C97063-002, no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmptrld`|X64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__vmx_vmptrst](../intrinsics/vmx-vmptrst.md)
