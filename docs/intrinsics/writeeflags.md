---
title: __writeeflags
ms.date: 09/02/2019
f1_keywords:
- __writeeflags
helpviewer_keywords:
- __writeeflags intrinsics
ms.assetid: a62a522c-d7fa-4f10-a620-a3b32bdf3f17
ms.openlocfilehash: 6b9b6976369ed810789e5749a2e30029cad4c2d7
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74858042"
---
# <a name="__writeeflags"></a>__writeeflags

**Seção específica da Microsoft**

Grava o valor especificado para o registro de status e controle do programa (EFLAGS).

## <a name="syntax"></a>Sintaxe

```C
void __writeeflags(unsigned Value); /* x86 */
void __writeeflags(unsigned __int64 Value); /* x64 */
```

### <a name="parameters"></a>Parâmetros

*Value*\
no O valor a ser gravado no registro de EFLAGS. O parâmetro `Value` tem 32 bits de comprimento para uma plataforma de 32 bits e 64 bits de comprimento para uma plataforma de 64 bits.

## <a name="remarks"></a>Comentários

Essas rotinas estão disponíveis somente como intrínsecas.

## <a name="requirements"></a>Requisitos do

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__writeeflags`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

\ [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
[__readeflags](../intrinsics/readeflags.md)
