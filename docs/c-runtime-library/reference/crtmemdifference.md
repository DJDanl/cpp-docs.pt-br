---
title: _CrtMemDifference
ms.date: 11/04/2016
apiname:
- _CrtMemDifference
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
- _CrtMemDifference
- CrtMemDifference
helpviewer_keywords:
- CrtMemDifference function
- _CrtMemDifference function
ms.assetid: 0f327278-b551-482f-958b-76941f796ba4
ms.openlocfilehash: f2c6306bf604737d0ace142674b21845a08e2dee
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62339462"
---
# <a name="crtmemdifference"></a>_CrtMemDifference

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
Ponteiro para um **crtmemstate** estrutura que é usada para armazenar as diferenças entre os dois estados de memória (retornados).

*oldState*<br/>
Ponteiro para um estado de memória anterior (**crtmemstate** estrutura).

*newState*<br/>
Ponteiro para um estado de memória posterior (**crtmemstate** estrutura).

## <a name="return-value"></a>Valor de retorno

Se os estados de memória forem significativamente diferentes, **crtmemdifference** retorna TRUE. Caso contrário, a função retorna FALSE.

## <a name="remarks"></a>Comentários

O **crtmemdifference** funcionar compara *oldState* e *newState* e armazena suas diferenças em *stateDiff*, que pode, em seguida, ser usado pelo aplicativo para detectar vazamentos de memória e outros problemas de memória. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtmemdifference** são removidas durante o pré-processamento.

*newState* e *oldState* devem ser um ponteiro válido para um **crtmemstate** estrutura, definida em crtdbg. h, que tenha sido preenchida por [crtmemcheckpoint](crtmemcheckpoint.md)antes de chamar **crtmemdifference**. *stateDiff* deve ser um ponteiro para uma instância previamente alocada dos **crtmemstate** estrutura. Se *stateDiff*, *newState*, ou *oldState* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como **EINVAL** e a função retornará FALSE.

**Crtmemdifference** compara a **crtmemstate** campo valores blocos no *oldState* às *newState* e armazena o resultado no *stateDiff*. Quando o número de tipos de bloco alocados ou o número total de blocos alocados para cada tipo diferir entre os dois estados de memória, os estados serão considerados significativamente diferentes. A diferença entre a maior quantidade alocada ao mesmo tempo para os dois estados e a diferença entre o total de alocações para os dois estados também são armazenados no *stateDiff*.

Por padrão, os blocos internos de tempo de execução C (**crt_block**) não são incluídos em operações de estado de memória. O [crtsetdbgflag](crtsetdbgflag.md) função pode ser usada para ativar o **crtdbg_check_crt_df** um pouco de **crtdbgflag** para incluir esses blocos na detecção de vazamento e em outro estado de memória operações. Blocos de memória liberados (**free_block**) não causam **crtmemdifference** retorne TRUE.

Para obter mais informações sobre as funções de estado de heap e o **crtmemstate** estrutura, consulte [funções de relatório de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtMemDifference**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** Versões de depuração [recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md) apenas.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)<br/>
