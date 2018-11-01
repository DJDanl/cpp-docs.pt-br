---
title: __vmx_vmresume
ms.date: 11/04/2016
f1_keywords:
- __vmx_vmresume
helpviewer_keywords:
- __vmx_vmresume intrinsic
- VMRESUME instruction
ms.assetid: 233fe1b6-c727-493a-a484-1b2363732281
ms.openlocfilehash: 4be197566f32c5edf49a9036b1ac641416d28fc4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50616847"
---
# <a name="vmxvmresume"></a>__vmx_vmresume

**Seção específica da Microsoft**

Reinicia a operação de não-raiz VMX usando a estrutura de controle da máquina virtual atual (VMCS).

## <a name="syntax"></a>Sintaxe

```
unsigned char __vmx_vmresume(
   void);
```

## <a name="return-value"></a>Valor de retorno

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|
|2|Falha na operação sem status disponível.|

## <a name="remarks"></a>Comentários

Um aplicativo pode executar uma operação de inserir a VM usando o [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou `__vmx_vmresume` função. O `__vmx_vmlaunch` função pode ser usada somente com um VMCS cujo estado de inicialização `Clear`e o `__vmx_vmresume` função pode ser usada somente com um VMCS cujo estado de inicialização é `Launched`. Consequentemente, usar o [__vmx_vmclear](../intrinsics/vmx-vmclear.md) função para definir o estado de inicialização de um VMCS para `Clear`e, em seguida, usar os `__vmx_vmlaunch` função para sua primeira operação de VM-enter e o `__vmx_vmresume` função para inserir subsequentes de VM operações.

O `__vmx_vmresume` função é equivalente ao `VMRESUME` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento PDF, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/articles/intel-sdm) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmresume`|X64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md)<br/>
[__vmx_vmclear](../intrinsics/vmx-vmclear.md)