---
title: ___setlc_active_func, ___unguarded_readlc_active_add_func
ms.date: 11/04/2016
api_name:
- ___setlc_active_func
- ___unguarded_readlc_active_add_func
api_location:
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr110.dll
- msvcr80.dll
- msvcr120.dll
- msvcr100.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- ___unguarded_readlc_active_add_func
- ___setlc_active_func
helpviewer_keywords:
- ___setlc_active_func
- ___unguarded_readlc_active_add_func
ms.assetid: 605ec4e3-81e5-4ece-935a-f434768cc702
ms.openlocfilehash: a7dd7d74992aeddffead1c6ef0d52cbc69848dad
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957282"
---
# <a name="___setlc_active_func-___unguarded_readlc_active_add_func"></a>___setlc_active_func, ___unguarded_readlc_active_add_func

OBSOLETO. O CRT exporta essas funções internas somente para preservar a compatibilidade binária.

## <a name="syntax"></a>Sintaxe

```cpp
int ___setlc_active_func(void);
int * ___unguarded_readlc_active_add_func(void);
```

## <a name="return-value"></a>Valor de retorno

O valor retornado não é significativo.

## <a name="remarks"></a>Comentários

Embora as funções CRT internas `___setlc_active_func` e `___unguarded_readlc_active_add_func` sejam obsoletas e não sejam mais utilizadas, elas são exportadas pela biblioteca do CRT para preservar a compatibilidade binária. O propósito original de `___setlc_active_func` era retornar o número de chamadas ativas no momento para a função `setlocale`. O propósito original de `___unguarded_readlc_active_add_func` era retornar o número de funções que faziam referência ao código de idioma sem bloqueá-lo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`___setlc_active_func`, `___unguarded_readlc_active_add_func`|nenhum|

## <a name="see-also"></a>Consulte também

[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)
