---
title: __lidt | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __lidt
- __lidt_cpp
dev_langs:
- C++
helpviewer_keywords:
- LIDT instruction
- __lidt intrinsic
ms.assetid: 8298d25d-a19e-4900-828d-6b3b09841882
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f07f4aee87df98b93c5aca54d1435339bf546539
ms.sourcegitcommit: a738519aa491a493a8f213971354356c0e6a5f3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/05/2018
ms.locfileid: "48820653"
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

O `__lidt` função é equivalente ao `LIDT` instruções de máquina e está disponível apenas no modo kernel. Para obter mais informações, pesquise o documento, "Manual do desenvolvedor de Software de arquitetura Intel, Volume 2: referência de conjunto de instruções," no [Intel Corporation](https://software.intel.com/articles/intel-sdm) site.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__sidt](../intrinsics/sidt.md)