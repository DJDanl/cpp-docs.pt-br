---
title: _RTC_SetErrorType | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _RTC_SetErrorType
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
- RTC_SetErrorType
- _RTC_SetErrorType
dev_langs:
- C++
helpviewer_keywords:
- run-time errors
- RTC_SetErrorType function
- _RTC_SetErrorType function
ms.assetid: f5f99be7-d357-4b11-b8f5-ddd3428f2b06
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f9fcca983247f0f5e0c09899e7ebec2774ca92e6
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="rtcseterrortype"></a>_RTC_SetErrorType

Associa um erro que é detectado pelas RTCs (verificações de erro em tempo de execução) com um tipo. O manipulador de erro processa a saída dos erros do tipo especificado.

## <a name="syntax"></a>Sintaxe

```C
int _RTC_SetErrorType(
   _RTC_ErrorNumber errnum,
   int ErrType
);
```

### <a name="parameters"></a>Parâmetros

*errnum*<br/>
Um número entre zero e um a menos do que o valor retornado por [_RTC_NumErrors](rtc-numerrors.md).

*ErrType*<br/>
O valor a ser atribuído a esse *errnum*. Por exemplo, você pode usar **_CRT_ERROR**. Se você estiver usando **crtdbgreport** como seu manipulador de erro, *ErrType* só pode ser um dos símbolos definidos no [CrtSetReportMode](crtsetreportmode.md). Se você tiver seu próprio manipulador de erro ([_RTC_SetErrorFunc](rtc-seterrorfunc.md)), poderá ter tantos *ErrType*s quantos *errnum*s.

Um *ErrType* de _RTC_ERRTYPE_IGNORE tem um significado especial para **CrtSetReportMode**; o erro será ignorado.

## <a name="return-value"></a>Valor de retorno

O valor anterior para o tipo de erro *tipo*.

## <a name="remarks"></a>Comentários

Por padrão, todos os erros são definidos como *ErrType* = 1, que corresponde a **_CRT_ERROR**. Para obter mais informações sobre os tipos de erro padrão como **_CRT_ERROR**, consulte [_CrtDbgReport](crtdbgreport-crtdbgreportw.md).

Antes de chamar essa função, você deve chamar primeiro uma das funções de inicialização de verificação de erro em tempo de execução; consulte [Usando as verificações de tempo de execução sem a Biblioteca em Tempo de Execução C](/visualstudio/debugger/using-run-time-checks-without-the-c-run-time-library)

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_RTC_SetErrorType**|\<rtcapi.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[_RTC_GetErrDesc](rtc-geterrdesc.md)<br/>
[Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)<br/>
