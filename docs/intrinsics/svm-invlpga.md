---
title: __svm_invlpga
ms.date: 09/02/2019
f1_keywords:
- __svm_invlpga
helpviewer_keywords:
- __svm_invlpga intrinsic
- INVLPGA instruction
ms.assetid: aa6578ce-8278-464b-8815-a0fc45330915
ms.openlocfilehash: e0f8ef02efdb64f70bb65f6f017449fcc03beca1
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219891"
---
# <a name="__svm_invlpga"></a>__svm_invlpga

**Seção específica da Microsoft**

Invalida a entrada de mapeamento de endereço no buffer de procura de tradução do computador. Parâmetros especifique o endereço virtual e o identificador de espaço de endereço da página a ser invalidada.

## <a name="syntax"></a>Sintaxe

```C
void __svm_invlpga(void *Vaddr, int as_id);
```

### <a name="parameters"></a>Parâmetros

*Vaddr*\
no O endereço virtual da página a ser invalidada.

*as_id*\
no O identificador de espaço de endereço (ASID) da página a ser invalidado.

## <a name="remarks"></a>Comentários

A `__svm_invlpga` função é equivalente à instrução `INVLPGA` da máquina. Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, pesquise o documento "o volume manual do programador de arquitetura AMD64 2: Programação do sistema, "número do documento 24593, revisão 3,11, no site da [AMD Corporation](https://developer.amd.com/resources/developer-guides-manuals/) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_invlpga`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
