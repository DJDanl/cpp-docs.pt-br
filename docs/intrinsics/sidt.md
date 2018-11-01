---
title: __sidt
ms.date: 11/04/2016
f1_keywords:
- __sidt
helpviewer_keywords:
- sidt instruction
- __sidt intrinsic
ms.assetid: 01e83d14-6e63-4dea-8f64-5a0339d69641
ms.openlocfilehash: 2188b2cdbf5c5f8836197f8cf2ee33928b7e9425
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50624452"
---
# <a name="sidt"></a>__sidt

**Seção específica da Microsoft**

Armazena o valor do registro de tabela de descritor (IDTR) interrupção no local da memória especificado.

## <a name="syntax"></a>Sintaxe

```
void __sidt(void * Destination);
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Destino*|[in] Um ponteiro para o local da memória onde IDTR está armazenado.|

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__sidt`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O `__sidt` função é equivalente ao `SIDT` instruções de máquina. Para obter mais informações, pesquise o documento, "Manual do desenvolvedor de Software de arquitetura Intel, Volume 2: referência de conjunto de instruções," no [Intel Corporation](https://software.intel.com/articles/intel-sdm) site.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__lidt](../intrinsics/lidt.md)