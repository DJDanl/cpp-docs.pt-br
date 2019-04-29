---
title: _RTC_GetErrDesc
ms.date: 11/04/2016
apiname:
- _RTC_GetErrDesc
apilocation:
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
apitype: DLLExport
f1_keywords:
- RTC_GetErrDesc
- _RTC_GetErrDesc
helpviewer_keywords:
- run-time errors
- _RTC_GetErrDesc function
- RTC_GetErrDesc function
ms.assetid: 7994ec2b-5488-4fd4-806d-a166c9a9f927
ms.openlocfilehash: d164626ea89bbe10f5b2ffe4224bf6381e40bab0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62357376"
---
# <a name="rtcgeterrdesc"></a>_RTC_GetErrDesc

Retorna uma breve descrição de um tipo RTC (verificação de erro em tempo de execução).

## <a name="syntax"></a>Sintaxe

```C
const char * _RTC_GetErrDesc(
   _RTC_ErrorNumber errnum
);
```

### <a name="parameters"></a>Parâmetros

*errnum*<br/>
Um número entre zero e um a menos do que o valor retornado por **_RTC_NumErrors**.

## <a name="return-value"></a>Valor de retorno

Uma cadeia de caracteres que contém uma breve descrição de um dos tipos de erro detectados pelo sistema de verificação de erro em tempo de execução. Se o erro é menor que zero ou maior que ou igual ao valor retornado por [RTC_NumErrors](rtc-numerrors.md), **RTC_GetErrDesc** retorna **nulo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_RTC_GetErrDesc**|\<rtcapi.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[_RTC_NumErrors](rtc-numerrors.md)<br/>
[Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)<br/>
