---
title: _CrtSetBreakAlloc
ms.date: 11/04/2016
api_name:
- _CrtSetBreakAlloc
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
- CrtSetBreakAlloc
- _CrtSetBreakAlloc
helpviewer_keywords:
- CrtSetBreakAlloc function
- _CrtSetBreakAlloc function
ms.assetid: 33bfc6af-a9ea-405b-a29f-1c2d4d9880a1
ms.openlocfilehash: e13c908c1efd1af9196885dee6e3b0f45845946b
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70942310"
---
# <a name="_crtsetbreakalloc"></a>_CrtSetBreakAlloc

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

O **_CrtSetBreakAlloc** permite que um aplicativo execute a detecção de vazamento de memória, dividindo um ponto específico de alocação de memória e rastreando de volta para a origem da solicitação. A função usa o número da ordem de alocação do objeto sequencial atribuído ao bloco de memória quando ele foi alocado no heap. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtSetBreakAlloc** são removidas durante o pré-processamento.

O número de ordem de alocação do objeto é armazenado no campo *lRequest* da estrutura **_CrtMemBlockHeader**, definida em Crtdbg.h. Quando informações sobre um bloco de memória são relatadas por uma das funções de despejo de depuração, esse número é colocado entre chaves {36}, como.

Para obter mais informações sobre como o **_CrtSetBreakAlloc** pode ser usado com outras funções de gerenciamento de memória, consulte [acompanhamento de solicitações de alocação de heap](/visualstudio/debugger/crt-debug-heap-details). Para obter mais informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap base, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

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
