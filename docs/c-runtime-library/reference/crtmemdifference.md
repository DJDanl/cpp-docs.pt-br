---
title: _CrtMemDifference
ms.date: 11/04/2016
api_name:
- _CrtMemDifference
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
- _CrtMemDifference
- CrtMemDifference
helpviewer_keywords:
- CrtMemDifference function
- _CrtMemDifference function
ms.assetid: 0f327278-b551-482f-958b-76941f796ba4
ms.openlocfilehash: 51bfa014d54f55843fcb112f318f143774abf8f3
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938706"
---
# <a name="_crtmemdifference"></a>_CrtMemDifference

Compara dois estados de memória e retorna suas diferenças (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
int _CrtMemDifference(
   _CrtMemState *stateDiff,
   const _CrtMemState *oldState,
   const _CrtMemState *newState
);
```

### <a name="parameters"></a>Parâmetros

*stateDiff*<br/>
Ponteiro para uma estrutura **_CrtMemState** que é usada para armazenar as diferenças entre os dois Estados de memória (retornados).

*oldState*<br/>
Ponteiro para um estado de memória anterior (estrutura **_CrtMemState** ).

*newState*<br/>
Ponteiro para um estado de memória posterior (estrutura **_CrtMemState** ).

## <a name="return-value"></a>Valor de retorno

Se os Estados de memória forem significativamente diferentes, **_CrtMemDifference** retornará true. Caso contrário, a função retorna FALSE.

## <a name="remarks"></a>Comentários

A função **_CrtMemDifference** compara *oldState* e *NewState* e armazena suas diferenças no *stateDiff*, que podem ser usadas pelo aplicativo para detectar vazamentos de memória e outros problemas de memória. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtMemDifference** são removidas durante o pré-processamento.

*NewState* e *oldState* devem ser um ponteiro válido para uma estrutura **_CrtMemState** , definida em CRTDBG. h, que foi preenchida por [_CrtMemCheckpoint](crtmemcheckpoint.md) antes de chamar **_CrtMemDifference**. *stateDiff* deve ser um ponteiro para uma instância alocada anteriormente da estrutura **_CrtMemState** . Se *stateDiff*, *NewState*ou *oldState* for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) for definido como **EINVAL** e a função retornar false.

**_CrtMemDifference** compara os valores de campo **_CrtMemState** dos blocos em *oldState* para aqueles no *NewState* e armazena o resultado em *stateDiff*. Quando o número de tipos de bloco alocados ou o número total de blocos alocados para cada tipo diferir entre os dois estados de memória, os estados serão considerados significativamente diferentes. A diferença entre o maior valor já alocado de uma vez para os dois Estados e a diferença entre as alocações totais para os dois Estados também são armazenadas em *stateDiff*.

Por padrão, os blocos de tempo de execução C internos ( **_CRT_BLOCK**) não são incluídos nas operações de estado da memória. A função [_CrtSetDbgFlag](crtsetdbgflag.md) pode ser usada para ativar o **_CRTDBG_CHECK_CRT_DF** bit de **_crtDbgFlag** para incluir esses blocos na detecção de vazamentos e outras operações de estado de memória. Os blocos de memória liberada ( **_FREE_BLOCK**) não fazem com que **_CRTMEMDIFFERENCE** retorne true.

Para obter mais informações sobre as funções de estado de heap e a estrutura **_CrtMemState** , consulte [heap State Reporting Functions](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtMemDifference**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**DLLs** Depurar versões somente de [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md) .

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)<br/>
