---
title: __RTDynamicCast
ms.date: 11/04/2016
api_name:
- __RTDynamicCast
api_location:
- msvcr90.dll
- msvcr110.dll
- msvcr120.dll
- msvcrt.dll
- msvcr100.dll
- msvcr80.dll
- msvcr110_clr0400.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __RTDynamicCast
helpviewer_keywords:
- __RTDynamicCast
ms.assetid: 56aa2d7a-aa47-46ef-830d-e37175611239
ms.openlocfilehash: a5384966ff96c4e4831ba06f7c67467156a9ecd2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170066"
---
# <a name="__rtdynamiccast"></a>__RTDynamicCast

Implementação de runtime do operador [dynamic_cast](../cpp/dynamic-cast-operator.md).

## <a name="syntax"></a>Sintaxe

```cpp
PVOID __RTDynamicCast (
   PVOID inptr,
   LONG VfDelta,
   PVOID SrcType,
   PVOID TargetType,
   BOOL isReference
   ) throw(...)
```

#### <a name="parameters"></a>parâmetros

*inptr*<br/>
Ponteiro para um objeto polimórfico.

*VfDelta*<br/>
Deslocamento do ponteiro de função virtual no objeto.

*SrcType*<br/>
O tipo estático do objeto apontado pelo parâmetro `inptr`.

*TargetType*<br/>
Resultado desejado da conversão.

*isReference*<br/>
**true** se a entrada for uma referência; **false** se a entrada for um ponteiro.

## <a name="return-value"></a>Valor retornado

Ponteiro para o subobjeto apropriado, se for bem-sucedido; caso contrário, **NULL**.

## <a name="exceptions"></a>Exceções

`bad_cast()` se a entrada para `dynamic_cast<>` for uma referência e a conversão falhar.

## <a name="remarks"></a>Comentários

Converte `inptr` em um objeto do tipo `TargetType`. O tipo de `inptr` deve ser um ponteiro se `TargetType` for um ponteiro, ou um l-value se `TargetType` for uma referência. `TargetType` deve ser um ponteiro ou uma referência a um tipo de classe previamente definido ou a um “ponteiro para nulo”.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__RTDynamicCast|rtti.h|
