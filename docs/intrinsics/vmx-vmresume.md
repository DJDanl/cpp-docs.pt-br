---
title: __vmx_vmresume
ms.date: 09/02/2019
f1_keywords:
- __vmx_vmresume
helpviewer_keywords:
- __vmx_vmresume intrinsic
- VMRESUME instruction
ms.assetid: 233fe1b6-c727-493a-a484-1b2363732281
ms.openlocfilehash: 34d0e6814dd00da07076e644513400bd5be36bd3
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219444"
---
# <a name="__vmx_vmresume"></a>__vmx_vmresume

**Seção específica da Microsoft**

Retoma a operação de não raiz VMX usando a VMCS (estrutura de controle de máquina virtual) atual.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __vmx_vmresume(
   void);
```

## <a name="return-value"></a>Valor retornado

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com o status estendido disponível `VM-instruction error field` no do VMCs atual.|
|2|A operação falhou sem status disponível.|

## <a name="remarks"></a>Comentários

Um aplicativo pode executar uma operação de entrada de VM usando a função [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou `__vmx_vmresume` . A `__vmx_vmlaunch` função pode ser usada somente com um VMCs cujo estado de inicialização `Clear`seja, e `__vmx_vmresume` a função pode ser usada somente com um VMCs cujo estado de `Launched`inicialização seja. Consequentemente, use a função [__vmx_vmclear](../intrinsics/vmx-vmclear.md) para definir o estado de inicialização de um `Clear`VMCs como e, em `__vmx_vmlaunch` seguida, use a função para sua primeira operação de `__vmx_vmresume` entrada de VM e a função para operações de entrada de VM subsequentes.

A `__vmx_vmresume` função é equivalente à instrução `VMRESUME` da máquina. Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, procure o documento PDF, "Especificação técnica de virtualização da Intel para a arquitetura Intel IA-32", número de documento C97063-002, no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmresume`|X64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md)\
[__vmx_vmclear](../intrinsics/vmx-vmclear.md)
