---
title: __readeflags
ms.date: 09/02/2019
f1_keywords:
- __readeflags
helpviewer_keywords:
- __readeflags intrinsic
ms.assetid: f9d2f4d8-c428-491f-b8de-04d0566b2b6b
ms.openlocfilehash: 6afdc0f20a3ae72865a80ba2eb7f896f79f63171
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857899"
---
# <a name="__readeflags"></a>__readeflags

**Seção específica da Microsoft**

Lê o registro de status e controle (EFLAGS) do programa.

## <a name="syntax"></a>Sintaxe

```C
unsigned     int __readeflags(void); /* x86 */
unsigned __int64 __readeflags(void); /* x64 */
```

## <a name="return-value"></a>Valor retornado

O valor do registro EFLAGS. O valor de retorno é de 32 bits de comprimento em uma plataforma de 32 bits e 64 bits de comprimento em uma plataforma de 64 bits.

## <a name="remarks"></a>Comentários

Essas rotinas estão disponíveis somente como intrínsecas.

## <a name="requirements"></a>Requisitos do

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__readeflags`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

\ [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
[__writeeflags](../intrinsics/writeeflags.md)
