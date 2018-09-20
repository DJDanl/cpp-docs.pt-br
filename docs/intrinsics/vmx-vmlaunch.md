---
title: __vmx_vmlaunch | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __vmx_vmlaunch
dev_langs:
- C++
helpviewer_keywords:
- VMLAUNCH instruction
- __vmx_vmlaunch intrinsic
ms.assetid: 708f7c38-b7c1-4ee7-bfc4-0daeb9cc9360
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a511a70c1f6cecd9c2a6dd489f11d5c18b655f3d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373328"
---
# <a name="vmxvmlaunch"></a>__vmx_vmlaunch

**Seção específica da Microsoft**

Coloca o aplicativo de chamada no estado de operação não raiz VMX (insira VM) usando a estrutura atual do controle de máquina virtual (VMCS).

## <a name="syntax"></a>Sintaxe

```
unsigned char __vmx_vmlaunch(
   void);
```

## <a name="return-value"></a>Valor de retorno

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|
|2|Falha na operação sem status disponível.|

## <a name="remarks"></a>Comentários

Um aplicativo pode executar uma operação de inserir a VM usando o [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função. O [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) função pode ser usada somente com um VMCS cujo estado de inicialização `Clear`e o [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função pode ser usada somente com um VMCS cujo estado de inicialização é `Launched`. Consequentemente, usar o [__vmx_vmclear](../intrinsics/vmx-vmclear.md) função para definir o estado de inicialização de um VMCS para `Clear`e, em seguida, usar os [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) função para sua primeira operação de VM-enter e o [__vmx_vmresume](../intrinsics/vmx-vmresume.md) função para operações subsequentes de VM-enter.

O `__vmx_vmlaunch` função é equivalente ao `VMLAUNCH` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/en-us/articles/intel-sdm) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmlaunch`|X64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__vmx_vmresume](../intrinsics/vmx-vmresume.md)<br/>
[__vmx_vmclear](../intrinsics/vmx-vmclear.md)