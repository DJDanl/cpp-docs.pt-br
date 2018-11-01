---
title: __vmx_vmptrld
ms.date: 11/04/2016
f1_keywords:
- __vmx_vmptrld
helpviewer_keywords:
- __vmx_vmptrld intrinsic
- VMPTRLD instruction
ms.assetid: 95c9ec5b-1a81-41ba-983e-327bd6a65fcb
ms.openlocfilehash: 4079eadc1f2d655c14192c8c4286ad240b1c1dbe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50571373"
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

### <a name="parameters"></a>Parâmetros

*VmcsPhysicalAddress*<br/>
[in] O endereço onde o ponteiro VMCS está armazenado.

## <a name="return-value"></a>Valor de retorno

0<br/>
A operação foi bem-sucedida.

1<br/>
A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.

2<br/>
Falha na operação sem status disponível.

## <a name="remarks"></a>Comentários

O ponteiro VMCS é um endereço físico de 64 bits.

O `__vmx_vmptrld` função é equivalente ao `VMPTRLD` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/articles/intel-sdm) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmptrld`|X64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__vmx_vmptrst](../intrinsics/vmx-vmptrst.md)