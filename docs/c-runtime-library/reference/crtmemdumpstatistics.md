---
title: _CrtMemDumpStatistics | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- _CrtMemDumpStatistics function
- CrtMemDumpStatistics function
ms.assetid: 27b9d731-3184-4a2d-b9a7-6566ab28a9fe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 655d9be75fa031cc2cbebfd65c4634528f410e85
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44110520"
---
# <a name="crtmemdumpstatistics"></a>_CrtMemDumpStatistics

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

O **crtmemdumpstatistics** função Despeja as informações de cabeçalho de depuração para um estado especificado do heap em um formato legível pelo usuário. As estatísticas de despejo podem ser usadas pelo aplicativo para acompanhar as alocações e detectar problemas de memória. O estado de memória pode conter um estado de heap específico ou a diferença entre dois estados. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtmemdumpstatistics** são removidas durante o pré-processamento.

O *estado* parâmetro deve ser um ponteiro para um **crtmemstate** estrutura tenha sido preenchida por [crtmemcheckpoint](crtmemcheckpoint.md) ou retornada por [_ CrtMemDifference](crtmemdifference.md) antes de **crtmemdumpstatistics** é chamado. Se *estado* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e nenhuma ação será tomada. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter mais informações sobre as funções de estado de heap e o **crtmemstate** estrutura, consulte [funções de relatório de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**_CrtMemDumpStatistics**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
