---
title: __vmx_vmlaunch
ms.date: 09/02/2019
f1_keywords:
- __vmx_vmlaunch
helpviewer_keywords:
- VMLAUNCH instruction
- __vmx_vmlaunch intrinsic
ms.assetid: 708f7c38-b7c1-4ee7-bfc4-0daeb9cc9360
ms.openlocfilehash: 8d78e5181fdd43e10431e12d0cf540c8c9c2e719
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219551"
---
# <a name="__vmx_vmlaunch"></a>__vmx_vmlaunch

**Seção específica da Microsoft**

Coloca o aplicativo de chamada em estado de operação não raiz VMX (VM Enter) usando a estrutura de controle de máquina virtual (VMCS) atual.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __vmx_vmlaunch(void);
```

## <a name="return-value"></a>Valor retornado

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com o status estendido disponível `VM-instruction error field` no do VMCs atual.|
|2|A operação falhou sem status disponível.|

## <a name="remarks"></a>Comentários

Um aplicativo pode executar uma operação de entrada de VM usando a função [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) ou [__vmx_vmresume](../intrinsics/vmx-vmresume.md) . A função [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) pode ser usada somente com um VMCs cujo estado de inicialização `Clear`é, e a função [__vmx_vmresume](../intrinsics/vmx-vmresume.md) pode ser usada somente com um VMCs cujo estado de `Launched`inicialização é. Consequentemente, use a função [__vmx_vmclear](../intrinsics/vmx-vmclear.md) para definir o estado de inicialização de um `Clear`VMCs como e, em seguida, use a função [__vmx_vmlaunch](../intrinsics/vmx-vmlaunch.md) para sua primeira operação de entrada de VM e a função [__vmx_vmresume](../intrinsics/vmx-vmresume.md) para VM subsequente-Enter das.

A `__vmx_vmlaunch` função é equivalente à instrução `VMLAUNCH` da máquina. Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, procure o documento "Especificação técnica de virtualização da Intel para a arquitetura Intel IA-32", número de documento C97063-002, no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmlaunch`|X64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__vmx_vmresume](../intrinsics/vmx-vmresume.md)\
[__vmx_vmclear](../intrinsics/vmx-vmclear.md)
