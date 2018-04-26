---
title: _RTC_SetErrorFuncW | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- run-time errors
- RTC_SetErrorFuncW function
- _RTC_error_fnW typedef
- _RTC_SetErrorFuncW function
- RTC_error_fnW typedef
ms.assetid: b3e0d71f-1bd3-4c37-9ede-2f638eb3c81a
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1eb3b8e5f6fb602675538c6588372b87df8781ac
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

A função de erro definido anteriormente. ou **nulo** se não houver nenhuma função definida anteriormente.

## <a name="remarks"></a>Comentários

No novo código, use somente **RTC_SetErrorFuncW**. **Rtc_seterrorfunc** está incluído somente na biblioteca para compatibilidade com versões anteriores.

O **RTC_SetErrorFuncW** retorno de chamada se aplica somente ao componente que ele foi vinculado, mas não global.

Verifique se o endereço que você passa para **RTC_SetErrorFuncW** é que uma função de tratamento de erros válido.

Se um erro foi atribuído um tipo de -1 usando [RTC_SetErrorType](rtc-seterrortype.md), a função de tratamento de erros não for chamado.

Antes de chamar essa função, você deve chamar primeiro uma das funções de inicialização de verificação de erro em tempo de execução. Para obter mais informações, consulte [Usando verificações de tempo de execução sem a Biblioteca em Tempo de Execução C](/visualstudio/debugger/using-run-time-checks-without-the-c-run-time-library).

**_RTC_error_fnW** é definido da seguinte forma:

> **TypeDef int ( cdecl \*_RTC_error_fnW) (int** *errorType* **, wchar_t const \***  *filename* **, int***linenumber* **, wchar_t const \***  *moduleName* **, wchar_t const \***  *formato* **,...);** 

em que:

*errorType* o tipo de erro que é especificado pelo [RTC_SetErrorType](rtc-seterrortype.md).

*nome de arquivo* o arquivo de origem onde a falha ocorreu, ou nulo se nenhuma informação de depuração está disponível.

*LineNumber* a linha em *filename* onde a falha ocorreu, ou 0 se não há informações de depuração.

*moduleName* DLL ou nome do arquivo executável onde a falha ocorreu.

*formato* printf a cadeia de caracteres de estilo para exibir uma mensagem de erro, usando os parâmetros restantes. O primeiro argumento do VA_ARGLIST é o número de erro RTC que ocorreu.

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
