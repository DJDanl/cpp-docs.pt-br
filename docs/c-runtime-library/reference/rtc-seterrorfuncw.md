---
title: _RTC_SetErrorFuncW
ms.date: 11/04/2016
apiname:
- _RTC_SetErrorFuncW
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
- _RTC_SetErrorFuncW
- RTC_SetErrorFuncW
helpviewer_keywords:
- run-time errors
- RTC_SetErrorFuncW function
- _RTC_error_fnW typedef
- _RTC_SetErrorFuncW function
- RTC_error_fnW typedef
ms.assetid: b3e0d71f-1bd3-4c37-9ede-2f638eb3c81a
ms.openlocfilehash: 03e9f540a215550a698700f28e5722b33b119149
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62357220"
---
# <a name="rtcseterrorfuncw"></a>_RTC_SetErrorFuncW

Designa uma função como o manipulador para relatar RTCs (verificações de erro em tempo de execução).

## <a name="syntax"></a>Sintaxe

```C
_RTC_error_fnW _RTC_SetErrorFuncW(
   _RTC_error_fnW function
);
```

### <a name="parameters"></a>Parâmetros

*function*<br/>
O endereço da função que manipulará verificações de erro em tempo de execução.

## <a name="return-value"></a>Valor de retorno

A função de erro definida anteriormente. ou **nulo** se não houver nenhuma função definida anteriormente.

## <a name="remarks"></a>Comentários

No novo código, use somente **RTC_SetErrorFuncW**. **Rtc_seterrorfunc** só é incluída na biblioteca para compatibilidade com versões anteriores.

O **RTC_SetErrorFuncW** retorno de chamada se aplica somente ao componente que ele estava vinculado, mas não globalmente.

Certifique-se de que o endereço que você passa para **RTC_SetErrorFuncW** é o de um função de tratamento de erro válido.

Se um erro foi atribuído um tipo de -1 usando [RTC_SetErrorType](rtc-seterrortype.md), a função de tratamento de erro não é chamado.

Antes de chamar essa função, você deve chamar primeiro uma das funções de inicialização de verificação de erro em tempo de execução. Para obter mais informações, consulte [Usando verificações de tempo de execução sem a Biblioteca em Tempo de Execução C](/visualstudio/debugger/using-run-time-checks-without-the-c-run-time-library).

**_RTC_error_fnW** é definido da seguinte forma:

```cpp
typedef int (__cdecl * _RTC_error_fnW)(
    int errorType,
    const wchar_t * filename,
    int linenumber,
    const wchar_t * moduleName,
    const wchar_t * format,
    ... );
```

em que:

*errorType*<br/>
O tipo de erro que é especificado pelo [_RTC_SetErrorType](rtc-seterrortype.md).

*filename*<br/>
O arquivo de origem no qual a falha ocorreu ou nulo se nenhuma informação de depuração estiver disponível.

*linenumber*<br/>
A linha em *filename* em que a falha ocorreu ou 0 se nenhuma informação de depuração estiver disponível.

*moduleName*<br/>
A DLL ou o nome do executável em que a falha ocorreu.

*format*<br/>
A cadeia de estilo printf para exibir uma mensagem de erro usando os parâmetros restantes. O primeiro argumento do VA_ARGLIST é o número de erro RTC que ocorreu.

Para obter um exemplo que mostra como usar **_RTC_error_fnW**, consulte [Personalização de verificações em tempo de execução nativo](/visualstudio/debugger/native-run-time-checks-customization).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_RTC_SetErrorFuncW**|\<rtcapi.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[_CrtDbgReport, _CrtDbgReportW](crtdbgreport-crtdbgreportw.md)<br/>
[Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)<br/>
