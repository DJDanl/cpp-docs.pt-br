---
title: _seh_filter_dll, _seh_filter_exe | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _XcptFilter
- _seh_filter_dll
- _seh_filter_exe
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- XcptFilter
- _XcptFilter
- _seh_filter_dll
- _seh_filter_exe
- corecrt_startup/_seh_filter_exe
- corecrt_startup/_seh_filter_dll
dev_langs:
- C++
helpviewer_keywords:
- XcptFilter function
- _XcptFilter function
- _seh_filter_dll function
- _seh_filter_exe function
ms.assetid: 747e5963-3a12-4bf5-b5c4-d4c1b6068e15
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 75b5b1b22067566d0096aa7ab616fb32c3850998
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32406470"
---
# <a name="sehfilterdll-sehfilterexe"></a>_seh_filter_dll, _seh_filter_exe

Identifica a exceção e a ação relacionada a ser executada.

## <a name="syntax"></a>Sintaxe

```C
int __cdecl _seh_filter_dll(
   unsigned long _ExceptionNum,
   struct _EXCEPTION_POINTERS* _ExceptionPtr
);
int __cdecl _seh_filter_exe(
   unsigned long _ExceptionNum,
   struct _EXCEPTION_POINTERS* _ExceptionPtr
);
```

### <a name="parameters"></a>Parâmetros

*_ExceptionNum*<br/>
O identificador para a exceção.

*_ExceptionPtr*<br/>
Um ponteiro para as informações de exceção.

## <a name="return-value"></a>Valor de retorno

Um inteiro que indica a ação a ser executada, com base no resultado do processamento de exceção.

## <a name="remarks"></a>Comentários

Esses métodos são chamados pela expressão de filtro de exceção de [Instrução try-except](../../cpp/try-except-statement.md). O método consulta uma tabela interna constante para identificar a exceção e determinar a ação apropriada, conforme mostrado aqui. Os números de exceção são definidos em winnt.h e os números de sinal são definidos em signal.h.

|Número de exceção (unsigned long)|Número de sinal|
|----------------------------------------|-------------------|
|STATUS_ACCESS_VIOLATION|SIGSEGV|
|STATUS_ILLEGAL_INSTRUCTION|SIGILL|
|STATUS_PRIVILEGED_INSTRUCTION|SIGILL|
|STATUS_FLOAT_DENORMAL_OPERAND|SIGFPE|
|STATUS_FLOAT_DIVIDE_BY_ZERO|SIGFPE|
|STATUS_FLOAT_INEXACT_RESULT|SIGFPE|
|STATUS_FLOAT_INVALID_OPERATION|SIGFPE|
|STATUS_FLOAT_OVERFLOW|SIGFPE|
|STATUS_FLOAT_STACK_CHECK|SIGFPE|
|STATUS_FLOAT_UNDERFLOW|SIGFPE|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corecrt_startup.h

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
