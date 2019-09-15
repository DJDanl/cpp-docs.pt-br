---
title: _CrtCheckMemory
ms.date: 11/04/2016
api_name:
- _CrtCheckMemory
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
- CrtCheckMemory
- _CrtCheckMemory
helpviewer_keywords:
- _CrtCheckMemory function
- CrtCheckMemory function
ms.assetid: 457cc72e-60fd-4177-ab5c-6ae26a420765
ms.openlocfilehash: 7e458825a81b7032310458ccda52d9299e126a35
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938868"
---
# <a name="_crtcheckmemory"></a>_CrtCheckMemory

Confirma a integridade dos blocos de memória alocados no heap de depuração (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C

int _CrtCheckMemory( void );
```

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **_CrtCheckMemory** retornará true; caso contrário, a função retornará FALSE.

## <a name="remarks"></a>Comentários

A função **_CrtCheckMemory** valida a memória alocada pelo Gerenciador de heap de depuração verificando o heap base subjacente e inspecionando cada bloco de memória. Se uma inconsistência de erro ou memória for encontrada no heap base subjacente, as informações de cabeçalho de depuração ou os buffers de substituição, **_CrtCheckMemory** gerará um relatório de depuração com informações que descrevem a condição de erro. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtCheckMemory** são removidas durante o pré-processamento.

O comportamento de **_CrtCheckMemory** pode ser controlado definindo os campos de bits do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) usando a função [_CrtSetDbgFlag](crtsetdbgflag.md) . Transformar o campo de bits **_CRTDBG_CHECK_ALWAYS_DF** em resultados em **_CrtCheckMemory** sendo chamado sempre que uma operação de alocação de memória é solicitada. Embora esse método reduza a velocidade de execução, ele é útil para capturar erros rapidamente. DESATIVAR o campo de **_CRTDBG_ALLOC_MEM_DF** de bits faz com que **_CrtCheckMemory** não verifique o heap e imediatamente retorna **verdadeiro**.

Como essa função retorna **TRUE** ou **FALSE**, ela pode ser passada para uma das macros [_ASSERT](assert-asserte-assert-expr-macros.md) para criar um mecanismo simples de tratamento de erro de depuração. O seguinte exemplo causa uma falha de asserção se o dano é detectado no heap:

```C
_ASSERTE( _CrtCheckMemory( ) );
```

Para obter mais informações sobre como o **_CrtCheckMemory** pode ser usado com outras funções de depuração, consulte [funções de relatório de estado de heap](/visualstudio/debugger/crt-debug-heap-details). Para obter uma visão geral do gerenciamento de memória e do heap de depuração, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtCheckMemory**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar o **_CrtCheckMemory**, consulte [crt_dbg1](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg1).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)<br/>
[_CrtSetDbgFlag](crtsetdbgflag.md)<br/>
