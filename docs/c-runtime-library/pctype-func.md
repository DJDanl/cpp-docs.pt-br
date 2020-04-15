---
title: __pctype_func
ms.date: 4/2/2020
api_name:
- __pctype_func
- _o___pctype_func
api_location:
- msvcrt.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr120.dll
- msvcr90.dll
- msvcr100.dll
- msvcr80.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __pctype_func
helpviewer_keywords:
- __pctype_func
ms.assetid: d52b8add-d07d-4516-a22f-e836cde0c57f
ms.openlocfilehash: 78562a29c89abe5b649444ae9223cf219488e009
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81349202"
---
# <a name="__pctype_func"></a>__pctype_func

Recupera um ponteiro para uma matriz de informações de classificação de caracteres.

## <a name="syntax"></a>Sintaxe

```cpp
const unsigned short *__pctype_func(
   )
```

## <a name="return-value"></a>Valor retornado

Um ponteiro para uma matriz de informações de classificação de caracteres.

## <a name="remarks"></a>Comentários

As informações na tabela de classificação de caracteres destina-se apenas a uso interno e são usadas por várias funções que classificam caracteres do tipo `char`. Para obter mais informações, consulte a seção `Remarks` de [_pctype, _pwctype, _wctype, _mbctype, _mbcasemap](../c-runtime-library/pctype-pwctype-wctype-mbctype-mbcasemap.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__pctype_func|ctype.h|

## <a name="see-also"></a>Confira também

[_pctype, _pwctype, _wctype, _mbctype, _mbcasemap](../c-runtime-library/pctype-pwctype-wctype-mbctype-mbcasemap.md)
