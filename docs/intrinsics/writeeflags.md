---
title: __writeeflags
ms.date: 09/02/2019
f1_keywords:
- __writeeflags
helpviewer_keywords:
- __writeeflags intrinsics
ms.assetid: a62a522c-d7fa-4f10-a620-a3b32bdf3f17
ms.openlocfilehash: e43789d2fbed1bdc52665531c61c6c932a27f5ab
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219150"
---
# <a name="__writeeflags"></a>__writeeflags

Grava o valor especificado para o registro de status e controle do programa (EFLAGS).

## <a name="syntax"></a>Sintaxe

```C
void __writeeflags(unsigned Value); /* x86 */
void __writeeflags(unsigned __int64 Value); /* x64 */
```

### <a name="parameters"></a>Parâmetros

*Valor*\
no O valor a ser gravado no registro de EFLAGS. O `Value` parâmetro tem 32 bits de comprimento para uma plataforma de 32 bits e 64 bits de comprimento para uma plataforma de 64 bits.

## <a name="remarks"></a>Comentários

Essas rotinas estão disponíveis somente como intrínsecas.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writeeflags`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__readeflags](../intrinsics/readeflags.md)
