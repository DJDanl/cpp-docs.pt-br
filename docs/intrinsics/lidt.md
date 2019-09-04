---
title: __lidt
ms.date: 09/02/2019
f1_keywords:
- __lidt
- __lidt_cpp
helpviewer_keywords:
- LIDT instruction
- __lidt intrinsic
ms.assetid: 8298d25d-a19e-4900-828d-6b3b09841882
ms.openlocfilehash: 24778b761ada56830b155a2fc65e90f54ba729ed
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217515"
---
# <a name="__lidt"></a>__lidt

**Seção específica da Microsoft**

Carrega o IDTR (registro de tabela do descritor de interrupção) com o valor no local da memória especificado.

## <a name="syntax"></a>Sintaxe

```C
void __lidt(void * Source);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Source*|no Ponteiro para o valor a ser copiado para o IDTR.|

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__lidt`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

A `__lidt` função é equivalente à instrução `LIDT` da máquina e está disponível somente no modo kernel. Para obter mais informações, pesquise o documento "manual do desenvolvedor de software de arquitetura Intel, volume 2: Referência de conjunto de instruções ", no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__sidt](../intrinsics/sidt.md)
