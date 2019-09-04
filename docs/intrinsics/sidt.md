---
title: __sidt
ms.date: 09/02/2019
f1_keywords:
- __sidt
helpviewer_keywords:
- sidt instruction
- __sidt intrinsic
ms.assetid: 01e83d14-6e63-4dea-8f64-5a0339d69641
ms.openlocfilehash: d6b685da0e02373307a3149c5b7b28213f37ad40
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222331"
---
# <a name="__sidt"></a>__sidt

**Seção específica da Microsoft**

Armazena o valor do registro de tabela do descritor de interrupção (IDTR) no local da memória especificado.

## <a name="syntax"></a>Sintaxe

```C
void __sidt(void * Destination);
```

### <a name="parameters"></a>Parâmetros

*Destino*\
no Um ponteiro para o local da memória onde o IDTR é armazenado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__sidt`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

A `__sidt` função é equivalente à instrução `SIDT` da máquina. Para obter mais informações, pesquise o documento "manual do desenvolvedor de software de arquitetura Intel, volume 2: Referência de conjunto de instruções ", no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__lidt](../intrinsics/lidt.md)
