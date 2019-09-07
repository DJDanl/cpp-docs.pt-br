---
title: _CrtMemDumpStatistics
ms.date: 11/04/2016
apiname:
- _CrtMemDumpStatistics
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
- CrtMemDumpStatistics
- _CrtMemDumpStatistics
helpviewer_keywords:
- _CrtMemDumpStatistics function
- CrtMemDumpStatistics function
ms.assetid: 27b9d731-3184-4a2d-b9a7-6566ab28a9fe
ms.openlocfilehash: 66eb58b65f3fa20e01ad16d68f3fe1baafd8cd04
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70739805"
---
# <a name="_crtmemdumpstatistics"></a>_CrtMemDumpStatistics

Despeja as informações de cabeçalho de depuração de um estado de heap especificado em um formato legível pelo usuário (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _CrtMemDumpStatistics(
   const _CrtMemState *state
);
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Ponteiro para o estado de heap a ser despejado.

## <a name="remarks"></a>Comentários

A função **_CrtMemDumpStatistics** despeja as informações do cabeçalho de depuração para um estado especificado do heap em um formulário legível pelo usuário. As estatísticas de despejo podem ser usadas pelo aplicativo para acompanhar as alocações e detectar problemas de memória. O estado de memória pode conter um estado de heap específico ou a diferença entre dois estados. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtMemDumpStatistics** são removidas durante o pré-processamento.

O parâmetro *State* deve ser um ponteiro para uma estrutura **_CrtMemState** que tenha sido preenchida por [_CrtMemCheckpoint](crtmemcheckpoint.md) ou retornado por [_CrtMemDifference](crtmemdifference.md) antes de **_CrtMemDumpStatistics** ser chamado. Se o *estado* for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e nenhuma ação será executada. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter mais informações sobre as funções de estado de heap e a estrutura **_CrtMemState** , consulte [heap State Reporting Functions](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**_CrtMemDumpStatistics**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**DLLs** Depurar versões somente de [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md) .

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
