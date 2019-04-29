---
title: __lidt
ms.date: 11/04/2016
f1_keywords:
- __lidt
- __lidt_cpp
helpviewer_keywords:
- LIDT instruction
- __lidt intrinsic
ms.assetid: 8298d25d-a19e-4900-828d-6b3b09841882
ms.openlocfilehash: 757309603af48820a17668cfe272bbeaad9239b3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62263679"
---
# <a name="lidt"></a>__lidt

**Seção específica da Microsoft**

Carrega o registro de tabela de descritor de interrupção (IDTR) com o valor no local da memória especificado.

## <a name="syntax"></a>Sintaxe

```
void __lidt(void * Source);
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Source*|[in] Ponteiro para o valor a ser copiado para IDTR.|

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__lidt`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O `__lidt` função é equivalente ao `LIDT` instruções de máquina e está disponível apenas no modo kernel. Para obter mais informações, pesquise o documento, "Manual do desenvolvedor de Software de arquitetura Intel, Volume 2: Instrução definir Reference"na [Intel Corporation](https://software.intel.com/articles/intel-sdm) site.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__sidt](../intrinsics/sidt.md)