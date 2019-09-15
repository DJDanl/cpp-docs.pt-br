---
title: _CrtDumpMemoryLeaks
ms.date: 11/04/2016
api_name:
- _CrtDumpMemoryLeaks
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
- CRTDBG_LEAK_CHECK_DF
- CRTDBG_CHECK_CRT_DF
- _CRTDBG_LEAK_CHECK_DF
- CrtDumpMemoryLeaks
- _CrtDumpMemoryLeaks
- _CRTDBG_CHECK_CRT_DF
helpviewer_keywords:
- CrtDumpMemoryLeaks function
- CRTDBG_LEAK_CHECK_DF macro
- _CRTDBG_LEAK_CHECK_DF macro
- _CrtDumpMemoryLeaks function
- CRTDBG_CHECK_CRT_DF macro
- _CRTDBG_CHECK_CRT_DF macro
ms.assetid: 71b2eab4-7f55-44e8-a55a-bfea4f32d34c
ms.openlocfilehash: dae93577f5c0c0297606577c05d6b6ef2040c831
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938823"
---
# <a name="_crtdumpmemoryleaks"></a>_CrtDumpMemoryLeaks

Despeja todos os blocos de memória no heap de depuração quando ocorre uma perda de memória (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C

int _CrtDumpMemoryLeaks( void );
```

## <a name="return-value"></a>Valor de retorno

**_CrtDumpMemoryLeaks** retornará true se um vazamento de memória for encontrado. Caso contrário, a função retorna FALSE.

## <a name="remarks"></a>Comentários

A função **_CrtDumpMemoryLeaks** determina se um vazamento de memória ocorreu desde o início da execução do programa. Quando uma perda é encontrada, as informações de cabeçalho de depuração de todos os objetos no heap são despejadas em um formato legível pelo usuário. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtDumpMemoryLeaks** são removidas durante o pré-processamento.

**_CrtDumpMemoryLeaks** é frequentemente chamado no final da execução do programa para verificar se toda a memória alocada pelo aplicativo foi liberada. A função pode ser chamada automaticamente no encerramento do programa ativando o campo de bit **_CRTDBG_LEAK_CHECK_DF** do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) usando a função [_CrtSetDbgFlag](crtsetdbgflag.md) .

**_CrtDumpMemoryLeaks** chama [_CrtMemCheckpoint](crtmemcheckpoint.md) para obter o estado atual do heap e verifica o estado em busca de blocos que não foram liberados. Quando um bloco não liberado é encontrado, **_CrtDumpMemoryLeaks** chama [_CrtMemDumpAllObjectsSince](crtmemdumpallobjectssince.md) para despejar informações de todos os objetos alocados no heap desde o início da execução do programa.

Por padrão, os blocos de tempo de execução C internos ( **_CRT_BLOCK**) não são incluídos nas operações de despejo de memória. A função [_CrtSetDbgFlag](crtsetdbgflag.md) pode ser usada para ativar o **_CRTDBG_CHECK_CRT_DF** bit de **_crtDbgFlag** para incluir esses blocos no processo de detecção de vazamento.

Para obter mais informações sobre as funções de estado de heap e a estrutura **_CrtMemState** , consulte [heap State Reporting Functions](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtDumpMemoryLeaks**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar o **_CrtDumpMemoryLeaks**, consulte [crt_dbg1](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg1).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
