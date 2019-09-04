---
title: __svm_vmsave
ms.date: 09/02/2019
f1_keywords:
- __svm_vmsave
helpviewer_keywords:
- VMSAVE instruction
- __svm_vmsave intrinsic
ms.assetid: 617a60bd-8514-4ba1-8066-bcf4dd481030
ms.openlocfilehash: f91efa7116a8a8e9ebe27c7e5e4e64c4f1533e9d
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219786"
---
# <a name="__svm_vmsave"></a>__svm_vmsave

**Seção específica da Microsoft**

Armazena um subconjunto do estado do processador no bloco de controle de máquina virtual especificado (VMCB).

## <a name="syntax"></a>Sintaxe

```C
void __svm_vmsave(
   size_t VmcbPhysicalAddress
);
```

### <a name="parameters"></a>Parâmetros

*VmcbPhysicalAddress*\
no O endereço físico do VMCB.

## <a name="remarks"></a>Comentários

A `__svm_vmsave` função é equivalente à instrução `VMSAVE` da máquina. Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, pesquise o documento "o volume manual do programador de arquitetura AMD64 2: Programação do sistema, "número do documento 24593, revisão 3,11 ou posterior, no site da [AMD Corporation](https://developer.amd.com/resources/developer-guides-manuals/) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_vmsave`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__svm_vmrun](../intrinsics/svm-vmrun.md)\
[__svm_vmload](../intrinsics/svm-vmload.md)
