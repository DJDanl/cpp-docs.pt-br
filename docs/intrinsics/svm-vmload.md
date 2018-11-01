---
title: __svm_vmload
ms.date: 11/04/2016
f1_keywords:
- __svm_vmload
helpviewer_keywords:
- __svm_vmload intrinsic
- VMLOAD instruction
ms.assetid: b46a5592-db76-4ffc-8694-2f3494e28bed
ms.openlocfilehash: 31f60096b60db7d8b135c686af87464060e0401a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50584763"
---
# <a name="svmvmload"></a>__svm_vmload

**Seção específica da Microsoft**

Carrega um subconjunto de estado do processador do bloco de controle de máquina virtual especificada (VMCB).

## <a name="syntax"></a>Sintaxe

```
void __svm_vmload(
   size_t VmcbPhysicalAddress
);
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*VmcbPhysicalAddress*|[in] O endereço físico do VMCB.|

## <a name="remarks"></a>Comentários

O `__svm_vmload` função é equivalente ao `VMLOAD` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento "Volume de Manual do programador da arquitetura AMD64 2: programação do sistema," número 24593, 3.11, de revisão de documentos na [corporation AMD](https://developer.amd.com/resources/developer-guides-manuals/) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_vmload`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__svm_vmrun](../intrinsics/svm-vmrun.md)<br/>
[__svm_vmsave](../intrinsics/svm-vmsave.md)