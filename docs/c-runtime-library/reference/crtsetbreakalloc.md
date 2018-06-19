---
title: _CrtSetBreakAlloc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _CrtSetBreakAlloc
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
- CrtSetBreakAlloc
- _CrtSetBreakAlloc
dev_langs:
- C++
helpviewer_keywords:
- CrtSetBreakAlloc function
- _CrtSetBreakAlloc function
ms.assetid: 33bfc6af-a9ea-405b-a29f-1c2d4d9880a1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 32e8fedcd70d0e901c63cd5e794773451f436326
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32395429"
---
# <a name="crtsetbreakalloc"></a>_CrtSetBreakAlloc

Estabelece um ponto de interrupção em um número de ordem de alocação de objeto especificado (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
long _CrtSetBreakAlloc(
   long lBreakAlloc
);
```

### <a name="parameters"></a>Parâmetros

*lBreakAlloc*<br/>
Número da ordem de alocação para qual o ponto de interrupção deve ser definido.

## <a name="return-value"></a>Valor de retorno

Retorna o número da ordem de alocação do objeto anterior que continha um ponto de interrupção definido.

## <a name="remarks"></a>Comentários

**Crtsetbreakalloc** permite que um aplicativo executar detecção de vazamento de memória por quebra em um momento específico de alocação de memória e o rastreamento de volta para a origem da solicitação. A função usa o número da ordem de alocação do objeto sequencial atribuído ao bloco de memória quando ele foi alocado no heap. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtsetbreakalloc** são removidos durante o pré-processamento.

O número de ordem de alocação do objeto é armazenado no campo *lRequest* da estrutura **_CrtMemBlockHeader**, definida em Crtdbg.h. Quando as informações sobre um bloco de memória são relatadas por uma das funções de despejo de depuração, esse número fica entre chaves, como {36}.

Para obter mais informações sobre como **crtsetbreakalloc** pode ser usado com outras funções de gerenciamento de memória, consulte [Controlando solicitações de alocação de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtSetBreakAlloc**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_setbrkal.c
// compile with: -D_DEBUG /MTd -Od -Zi -W3 /c /link -verbose:lib -debug

/*
* In this program, a call is made to the _CrtSetBreakAlloc routine
* to verify that the debugger halts program execution when it reaches
* a specified allocation number.
*/

#include <malloc.h>
#include <crtdbg.h>

int main( )
{
        long allocReqNum;
        char *my_pointer;

        /*
         * Allocate "my_pointer" for the first
         * time and ensure that it gets allocated correctly
         */
        my_pointer = malloc(10);
        _CrtIsMemoryBlock(my_pointer, 10, &allocReqNum, NULL, NULL);

        /*
         * Set a breakpoint on the allocation request
         * number for "my_pointer"
         */
        _CrtSetBreakAlloc(allocReqNum+2);

        /*
         * Alternate freeing and reallocating "my_pointer"
         * to verify that the debugger halts program execution
         * when it reaches the allocation request
         */
        free(my_pointer);
        my_pointer = malloc(10);
        free(my_pointer);
        my_pointer = malloc(10);
        free(my_pointer);
}
```

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
