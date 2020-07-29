---
title: _RTC_NumErrors
ms.date: 11/04/2016
api_name:
- _RTC_NumErrors
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _RTC_NumErrors
- RTC_NumErrors
helpviewer_keywords:
- run-time errors
- _RTC_NumErrors function
- RTC_NumErrors function
ms.assetid: 7e82adae-38e2-4f8b-bc0b-37bda8109fd1
ms.openlocfilehash: 0e0af8596dbc7f48bc3f6b996219ec7c7a57749d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234023"
---
# <a name="_rtc_numerrors"></a>_RTC_NumErrors

Retorna o número total de erros que podem ser detectados por RTC (verificação de erro em tempo de execução). Você pode usar esse número como o controle em um **`for`** loop, onde cada valor no loop é passado para [_RTC_GetErrDesc](rtc-geterrdesc.md).

## <a name="syntax"></a>Sintaxe

```C

int _RTC_NumErrors( void );
```

## <a name="return-value"></a>Valor retornado

Um inteiro cujo valor representa o número total de erros que podem ser detectados pelas verificações de erro em tempo de execução do Visual C++.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_RTC_NumErrors**|\<rtcapi.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Confira também

[_RTC_GetErrDesc](rtc-geterrdesc.md)<br/>
[Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)<br/>
