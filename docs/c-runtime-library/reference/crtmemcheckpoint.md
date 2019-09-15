---
title: _CrtMemCheckpoint
ms.date: 11/04/2016
api_name:
- _CrtMemCheckpoint
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
- CrtMemCheckpoint
- _CrtMemCheckpoint
- crtdbg/_CrtMemCheckpoint
helpviewer_keywords:
- CrtMemCheckpoint function
- _CrtMemCheckpoint function
ms.assetid: f1bacbaa-5a0c-498a-ac7a-b6131d83dfbc
ms.openlocfilehash: edf91cd8c76fd080326e2e5eeac98f7f81ab90cf
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70942358"
---
# <a name="_crtmemcheckpoint"></a>_CrtMemCheckpoint

Obtém o estado atual do heap de depuração e armazena em uma estrutura **_CrtMemState** fornecida pelo aplicativo (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _CrtMemCheckpoint(
   _CrtMemState *state
);
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Ponteiro para a estrutura **_CrtMemState** para preencher com o ponto de verificação de memória.

## <a name="remarks"></a>Comentários

A função **_CrtMemCheckpoint** cria um instantâneo do estado atual do heap de depuração em qualquer momento determinado. Esse instantâneo pode ser usado por outras funções de estado de heap como [_CrtMemDifference](crtmemdifference.md) para ajudar a detectar perdas de memória e outros problemas. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtMemState** são removidas durante o pré-processamento.

O aplicativo deve passar um ponteiro para uma instância alocada anteriormente da estrutura **_CrtMemState** , definida em CRTDBG. h, no parâmetro *State* . Se **_CrtMemCheckpoint** encontrar um erro durante a criação do ponto de verificação, a função gerará um relatório de depuração **_CRT_WARN** descrevendo o problema.

Para obter mais informações sobre as funções de estado de heap e a estrutura **_CrtMemState** , consulte [heap State Reporting Functions](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

Se o *estado* for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) for definido como **EINVAL** e a função retornar.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtMemCheckpoint**|\<crtdbg.h>, \<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**DLLs** Depurar versões somente do UCRT.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtMemDifference](crtmemdifference.md)<br/>
