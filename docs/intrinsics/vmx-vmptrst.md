---
title: __vmx_vmptrst
ms.date: 11/04/2016
f1_keywords:
- __vmx_vmptrst
helpviewer_keywords:
- __vmx_vmptrst intrinsic
- VMPTRST instruction
ms.assetid: 8dc66e47-03a0-41b0-8e25-c1485f42817a
ms.openlocfilehash: 4d7e2ed29daac276c9b6cba07a727371a212fd4a
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51331887"
---
# <a name="vmxvmptrst"></a>__vmx_vmptrst

**Seção específica da Microsoft**

Armazena o ponteiro para a estrutura atual do controle de máquina virtual (VMCS) no endereço especificado.

## <a name="syntax"></a>Sintaxe

```
void __vmx_vmptrst(
   unsigned __int64 *VmcsPhysicalAddress
);
```

### <a name="parameters"></a>Parâmetros

*VmcsPhysicalAddress*<br/>
[in] O endereço onde o ponteiro VMCS atual é armazenado.

## <a name="remarks"></a>Comentários

O ponteiro VMCS é um endereço físico de 64 bits.

O `__vmx_vmptrst` função é equivalente ao `VMPTRST` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/articles/intel-sdm) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmptrst`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__vmx_vmptrld](../intrinsics/vmx-vmptrld.md)