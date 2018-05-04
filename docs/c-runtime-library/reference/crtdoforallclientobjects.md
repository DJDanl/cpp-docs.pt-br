---
title: _CrtDoForAllClientObjects | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _CrtDoForAllClientObjects
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
- _CrtDoForAllClientObjects
- CrtDoForAllClientObjects
- crtdbg/_CrdDoForAllClientObjects
dev_langs:
- C++
helpviewer_keywords:
- _CrtDoForAllClientObjects function
- CrtDoForAllClientObjects function
ms.assetid: d0fdb835-3cdc-45f1-9a21-54208e8df248
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 889c3c4060098927df08d785e85b64e7e7becc2c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="crtdoforallclientobjects"></a>_CrtDoForAllClientObjects

Chama uma função de aplicativo fornecido para todos os **client_block** tipos no heap (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void _CrtDoForAllClientObjects(
   void ( * pfn )( void *, void * ),
   void *context
);
```

### <a name="parameters"></a>Parâmetros

*pfn* ponteiro para a função de retorno de chamada de função fornecidas pelo aplicativo. O primeiro parâmetro para essa função aponta para os dados. O segundo parâmetro é o ponteiro de contexto que é passado para a chamada para **crtdoforallclientobjects**.

*contexto* ponteiro para o contexto fornecido pelo aplicativo para passar para a função fornecida pelo aplicativo.

## <a name="remarks"></a>Comentários

O **crtdoforallclientobjects** função pesquisa a lista vinculada do heap para os blocos de memória com o **client_block** tipo e chama a função fornecida pelo aplicativo quando um bloco deste tipo foi encontrada. O bloco encontrado e o *contexto* parâmetro são passados como argumentos para a função fornecida pelo aplicativo. Durante a depuração, um aplicativo pode acompanhar um grupo específico de alocações de chamar explicitamente a depuração de funções de heap alocar a memória e especificando que os blocos de ser atribuído a **client_block** bloquear tipo. Esses blocos podem ser rastreados separadamente e relatados de modo diferente durante a detecção de vazamento e o relatório de estado da memória.

Se o **crtdbg_alloc_mem_df** campo de bits de [crtdbgflag](../../c-runtime-library/crtdbgflag.md) sinalizador não está ativado, **crtdoforallclientobjects** retorna imediatamente. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtdoforallclientobjects** são removidos durante o pré-processamento.

Para obter mais informações sobre o **client_block** de tipo e como ele pode ser usado por outras funções de depuração, consulte [tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

Se *pfn* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, [errno, doserrno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como **EINVAL** e a função retorna.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtDoForAllClientObjects**|\<crtdbg.h>, \<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** somente versões de depuração de bibliotecas universais em tempo de execução C.

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtSetDbgFlag](crtsetdbgflag.md)<br/>
[Funções de emissão de relatórios de estado de heap](/visualstudio/debugger/crt-debug-heap-details)<br/>
[_CrtReportBlockType](crtreportblocktype.md)<br/>
