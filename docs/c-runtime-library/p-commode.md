---
title: __p__commode
ms.date: 4/2/2020
api_name:
- __p__commode
- _o___p__commode
api_location:
- msvcr110.dll
- msvcrt.dll
- msvcr120.dll
- msvcr90.dll
- msvcr100.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __p__commode
helpviewer_keywords:
- __p__commode
ms.assetid: 4380acb8-e3e4-409c-a60f-6205ac5189ce
ms.openlocfilehash: fa589c1972d27854e3f794d8283f49d9db5d053a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81349316"
---
# <a name="__p__commode"></a>__p__commode

Aponta para a variável global `_commode`, que especifica o *modo de confirmação de arquivos* padrão para operações de E/S de arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
int * __p__commode(
   );
```

## <a name="return-value"></a>Valor retornado

Ponteiro para a variável global `_commode`.

## <a name="remarks"></a>Comentários

A função `__p__commode` destina-se apenas ao uso interno e não deve ser chamada do código do usuário.

O modo de confirmação de arquivo especifica quando os dados críticos são gravados no disco. Para obter mais informações, consulte [fflush](../c-runtime-library/reference/fflush.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|__p\__commode|internal.h|
