---
title: _CrtDoForAllClientObjects
ms.date: 11/04/2016
api_name:
- _CrtDoForAllClientObjects
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
- _CrtDoForAllClientObjects
- CrtDoForAllClientObjects
- crtdbg/_CrdDoForAllClientObjects
helpviewer_keywords:
- _CrtDoForAllClientObjects function
- CrtDoForAllClientObjects function
ms.assetid: d0fdb835-3cdc-45f1-9a21-54208e8df248
ms.openlocfilehash: 4626df0db1956efd26ee267cb8cacf8ea4a4570c
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70942526"
---
# <a name="_crtdoforallclientobjects"></a>_CrtDoForAllClientObjects

Chama uma função fornecida pelo aplicativo para todos os tipos de **_CLIENT_BLOCK** no heap (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _CrtDoForAllClientObjects(
   void ( * pfn )( void *, void * ),
   void *context
);
```

### <a name="parameters"></a>Parâmetros

*pfn*<br/>
Ponteiro para a função de retorno de chamada da função fornecida pelo aplicativo. O primeiro parâmetro para essa função aponta para os dados. O segundo parâmetro é o ponteiro de contexto que é passado para a chamada para **_CrtDoForAllClientObjects**.

*context*<br/>
Ponteiro para o contexto fornecido pelo aplicativo para enviar à função fornecida pelo aplicativo.

## <a name="remarks"></a>Comentários

A função **_CrtDoForAllClientObjects** pesquisa a lista vinculada do heap para blocos de memória com o tipo **_CLIENT_BLOCK** e chama a função fornecida pelo aplicativo quando um bloco desse tipo é encontrado. O bloco encontrado e o parâmetro de *contexto* são passados como argumentos para a função fornecida pelo aplicativo. Durante a depuração, um aplicativo pode rastrear um grupo específico de alocações chamando explicitamente as funções de heap de depuração para alocar a memória e especificando que os blocos sejam atribuídos ao tipo de bloco **_CLIENT_BLOCK** . Esses blocos podem ser rastreados separadamente e relatados de modo diferente durante a detecção de vazamento e o relatório de estado da memória.

Se o campo **_CRTDBG_ALLOC_MEM_DF** bit do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) não estiver ativado, **_CrtDoForAllClientObjects** retornará imediatamente. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtDoForAllClientObjects** são removidas durante o pré-processamento.

Para obter mais informações sobre o tipo **_CLIENT_BLOCK** e como ele pode ser usado por outras funções de depuração, consulte [tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

Se *PFN* for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) for definido como **EINVAL** e a função retornar.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtDoForAllClientObjects**|\<crtdbg.h>, \<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**DLLs** Depuração de versões somente de bibliotecas de tempo de execução universal C.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtSetDbgFlag](crtsetdbgflag.md)<br/>
[Funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details)<br/>
[_CrtReportBlockType](crtreportblocktype.md)<br/>
