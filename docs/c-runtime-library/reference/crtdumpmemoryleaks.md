---
title: _CrtDumpMemoryLeaks
ms.date: 11/04/2016
apiname:
- _CrtDumpMemoryLeaks
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
ms.openlocfilehash: baf4f8d8234ba744acda20541d37bbc3ed076678
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62339449"
---
# <a name="crtdumpmemoryleaks"></a>_CrtDumpMemoryLeaks

Despeja todos os blocos de memória no heap de depuração quando ocorre uma perda de memória (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C

int _CrtDumpMemoryLeaks( void );
```

## <a name="return-value"></a>Valor de retorno

**Crtdumpmemoryleaks** retorna TRUE se um vazamento de memória for encontrado. Caso contrário, a função retorna FALSE.

## <a name="remarks"></a>Comentários

O **crtdumpmemoryleaks** função determina se um vazamento de memória ocorreu desde o início da execução do programa. Quando uma perda é encontrada, as informações de cabeçalho de depuração de todos os objetos no heap são despejadas em um formato legível pelo usuário. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtdumpmemoryleaks** são removidas durante o pré-processamento.

**Crtdumpmemoryleaks** frequentemente é chamado no final da execução do programa para verificar se toda a memória alocada pelo aplicativo foi liberada. A função pode ser chamada automaticamente no encerramento do programa ao ativar o **crtdbg_leak_check_df** campo de bits a [crtdbgflag](../../c-runtime-library/crtdbgflag.md) sinalizador usando o [crtsetdbgflag](crtsetdbgflag.md)função.

**Crtdumpmemoryleaks** chamadas [crtmemcheckpoint](crtmemcheckpoint.md) para obter o estado atual do heap e, em seguida, verifica o estado dos blocos que não foram liberados. Quando um bloco não liberado é encontrado, **crtdumpmemoryleaks** chamadas [crtmemdumpallobjectssince](crtmemdumpallobjectssince.md) para despejar informações de todos os objetos alocados no heap desde o início da execução do programa.

Por padrão, os blocos internos de tempo de execução C (**crt_block**) não são incluídos em operações de despejo de memória. O [crtsetdbgflag](crtsetdbgflag.md) função pode ser usada para ativar o **crtdbg_check_crt_df** um pouco de **crtdbgflag** para incluir esses blocos no processo de detecção de vazamento.

Para obter mais informações sobre as funções de estado de heap e o **crtmemstate** estrutura, consulte [funções de relatório de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtDumpMemoryLeaks**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar **crtdumpmemoryleaks**, consulte [crt_dbg1](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg1).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
