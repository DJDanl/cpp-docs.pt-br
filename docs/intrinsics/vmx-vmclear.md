---
title: __vmx_vmclear
ms.date: 09/02/2019
f1_keywords:
- __vmx_vmclear
helpviewer_keywords:
- VMCLEAR instruction
- __vmx_vmclear intrinsic
ms.assetid: e3eb98e4-50fc-4c93-9bac-340fd1f0a466
ms.openlocfilehash: 3b5807402cf0a9d8a9ef1ded1d112d22a801633e
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219534"
---
# <a name="__vmx_vmclear"></a>__vmx_vmclear

**Seção específica da Microsoft**

Inicializa a estrutura de controle de máquina virtual (VMCS) especificada e define seu estado `Clear`de inicialização como.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __vmx_vmclear(
   unsigned __int64 *VmcsPhysicalAddress
);
```

### <a name="parameters"></a>Parâmetros

*VmcsPhysicalAddress*\
no Um ponteiro para um local de memória de 64 bits que contém o endereço físico do VMCS para limpar.

## <a name="return-value"></a>Valor retornado

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com o status estendido disponível `VM-instruction error field` no do VMCs atual.|
|2|A operação falhou sem status disponível.|

## <a name="remarks"></a>Comentários

Um aplicativo pode executar uma operação de entrada de VM usando a função [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou [__vmx_vmresume](../intrinsics/vmx-vmresume.md) . A função [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) pode ser usada somente com um VMCs cujo estado de inicialização `Clear`é, e a função [__vmx_vmresume](../intrinsics/vmx-vmresume.md) pode ser usada somente com um VMCs cujo estado de `Launched`inicialização é. Consequentemente, use a função [__vmx_vmclear](../intrinsics/vmx-vmclear.md) para definir o estado de inicialização de um `Clear`VMCs como. Use a função [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) para sua primeira operação de entrada de VM e a função [__vmx_vmresume](../intrinsics/vmx-vmresume.md) para operações de entrada de VM subsequentes.

A `__vmx_vmclear` função é equivalente à instrução `VMCLEAR` da máquina. Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, procure o documento "Especificação técnica de virtualização da Intel para a arquitetura Intel IA-32", número de documento C97063-002, no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmclear`|X64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md)\
[__vmx_vmresume](../intrinsics/vmx-vmresume.md)
