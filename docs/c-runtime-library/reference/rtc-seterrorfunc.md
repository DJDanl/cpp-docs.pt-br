---
title: _RTC_SetErrorFunc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _RTC_SetErrorFunc
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
- RTC_SetErrorFunc
- _RTC_SetErrorFunc
dev_langs:
- C++
helpviewer_keywords:
- RTC_SetErrorFunc function
- _RTC_SetErrorFunc function
ms.assetid: b2292722-0d83-4092-83df-3d5b19880666
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c3d83690ceed2fec75da266d409e8323bc057028
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="rtcseterrorfunc"></a>_RTC_SetErrorFunc

Designa uma função como o manipulador para RTCs (verificações de erro em tempo de execução). Essa função é preterida; Use **RTC_SetErrorFuncW** em vez disso.

## <a name="syntax"></a>Sintaxe

```C
_RTC_error_fn _RTC_SetErrorFunc(
   _RTC_error_fn function
);
```

### <a name="parameters"></a>Parâmetros

*function*<br/>
O endereço da função que manipulará verificações de erro em tempo de execução.

## <a name="return-value"></a>Valor de retorno

A função de erro definida anteriormente. Se não houver nenhuma função definida anteriormente, retorna NULL.

## <a name="remarks"></a>Comentários

Não use essa função; em vez disso, use **RTC_SetErrorFuncW**. Ela é mantida apenas para fins de compatibilidade com versões anteriores.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_RTC_SetErrorFunc**|\<rtcapi.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[_CrtDbgReport, _CrtDbgReportW](crtdbgreport-crtdbgreportw.md)<br/>
[Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)<br/>
