---
title: __svm_invlpga
ms.date: 11/04/2016
f1_keywords:
- __svm_invlpga
helpviewer_keywords:
- __svm_invlpga intrinsic
- INVLPGA instruction
ms.assetid: aa6578ce-8278-464b-8815-a0fc45330915
ms.openlocfilehash: 2d356cf7426c558c8ac0312eff02c0cb9de9c859
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544294"
---
# <a name="svminvlpga"></a>__svm_invlpga

**Seção específica da Microsoft**

Invalida a entrada de mapeamento de endereço no buffer de à parte de translação do computador. Os parâmetros especificam o endereço virtual e o identificador de espaço de endereço da página a ser invalidada.

## <a name="syntax"></a>Sintaxe

```
void __svm_invlpga(void *Va, int ASID);
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*VA*|[in] O endereço virtual da página ser invalidada.|
|*ASID*|[in] O identificador do espaço de endereço (ASID) da página ser invalidada.|

## <a name="remarks"></a>Comentários

O `__svm_invlpga` função é equivalente ao `INVLPGA` instruções de máquina. Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento "Volume de Manual do programador da arquitetura AMD64 2: programação do sistema," número 24593, 3.11, de revisão de documentos na [corporation AMD](https://developer.amd.com/resources/developer-guides-manuals/) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_invlpga`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)