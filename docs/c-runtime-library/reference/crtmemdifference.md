---
title: _CrtMemDifference | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CrtMemDifference function
- _CrtMemDifference function
ms.assetid: 0f327278-b551-482f-958b-76941f796ba4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 66bb770c2f24c0312277d23c14beef09e2265f88
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
Ponteiro para um **crtmemstate** estrutura que é usada para armazenar as diferenças entre os estados de duas memória (retornados).

*oldState*<br/>
Ponteiro para um estado anterior de memória (**crtmemstate** estrutura).

*newState*<br/>
Ponteiro para um estado de memória mais recente (**crtmemstate** estrutura).

## <a name="return-value"></a>Valor de retorno

Se a memória estados são significativamente diferentes, **crtmemdifference** retorna TRUE. Caso contrário, a função retorna FALSE.

## <a name="remarks"></a>Comentários

O **crtmemdifference** função compara *oldState* e *newState* e armazena as suas diferenças em *stateDiff*, que pode, em seguida, ser usado pelo aplicativo para detectar vazamentos de memória e outros problemas de memória. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtmemdifference** são removidos durante o pré-processamento.

*newState* e *oldState* devem ser um ponteiro válido para uma **crtmemstate** estrutura, definida em crtdbg. h, que tenha sido preenchido pelo [crtmemcheckpoint](crtmemcheckpoint.md)antes de chamar **crtmemdifference**. *stateDiff* deve ser um ponteiro para uma instância alocada anteriormente o **crtmemstate** estrutura. Se *stateDiff*, *newState*, ou *oldState* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [ Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como **EINVAL** e a função retornará FALSE.

**Crtmemdifference** compara o **crtmemstate** campo valores blocos no *oldState* às *newState* e armazena o resultado em *stateDiff*. Quando o número de tipos de bloco alocados ou o número total de blocos alocados para cada tipo diferir entre os dois estados de memória, os estados serão considerados significativamente diferentes. A diferença entre a maior quantidade já alocada ao mesmo tempo para os dois estados e a diferença entre o total de alocações para os dois estados também são armazenados no *stateDiff*.

Por padrão, os blocos de tempo de execução C internos (**crt_block**) não são incluídas em operações de estado de memória. O [crtsetdbgflag](crtsetdbgflag.md) função pode ser usada para ativar o **crtdbg_check_crt_df** um pouco de **crtdbgflag** a incluir esses blocos na detecção de escape e outro estado de memória operações. Liberação de blocos de memória (**free_block**) não causam **crtmemdifference** para retornar TRUE.

Para obter mais informações sobre funções de estado de heap e a **crtmemstate** estrutura, consulte [funções de emissão de relatórios de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_CrtMemDifference**|\<crtdbg.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração dos [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)<br/>
