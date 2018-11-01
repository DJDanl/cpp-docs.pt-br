---
title: _calloc_dbg
ms.date: 11/04/2016
apiname:
- _calloc_dbg
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
- _calloc_dbg
- calloc_dbg
helpviewer_keywords:
- _calloc_dbg function
- calloc_dbg function
ms.assetid: 7f62c42b-eb9f-4de5-87d0-df57036c87de
ms.openlocfilehash: c525aa2f19b39ba3cb8304c59c96196707ad859c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50454386"
---
# <a name="callocdbg"></a>_calloc_dbg

Aloca vários blocos de memória no heap com espaço adicional para um cabeçalho de depuração e buffers de substituição (apenas versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
void *_calloc_dbg(
   size_t num,
   size_t size,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*número*<br/>
Número necessário de blocos de memória.

*size*<br/>
Tamanho necessário de cada bloco de memória (bytes).

*blockType*<br/>
Tipo de bloco de memória solicitado: **client_block** ou **normal_block**.

Para obter informações sobre os tipos de bloco de alocação e como eles são usados, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nulo**.

O *filename* e *linenumber* parâmetros estão disponíveis somente quando **calloc_dbg** tiver sido chamado explicitamente ou o [crtdbg_map_alloc](../../c-runtime-library/crtdbg-map-alloc.md)constante do pré-processador foi definido.

## <a name="return-value"></a>Valor de retorno

Após a conclusão bem-sucedida, essa função retorna um ponteiro para a parte do usuário do último bloco de memória alocado, chama a nova função de manipulador ou retorna **nulo**. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [calloc](calloc.md).

## <a name="remarks"></a>Comentários

**calloc_dbg** é uma versão de depuração de [calloc](calloc.md) função. Quando [Debug](../../c-runtime-library/debug.md) não estiver definido, cada chamada para **calloc_dbg** é reduzida a uma chamada para **calloc**. Ambos **calloc** e **calloc_dbg** alocar *número* blocos de memória no heap de base, mas **calloc_dbg** oferece vários depuração recursos:

- Buffers em ambos os lados da parte do usuário do bloco a testar quanto a vazamentos.

- Um parâmetro de tipo de bloco para controlar os tipos de alocação específicos.

- *nome do arquivo*/*linenumber* informações para determinar a origem das solicitações de alocação.

**calloc_dbg** aloca cada bloco de memória com um pouco mais de espaço que o solicitado *tamanho*. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.

**calloc_dbg** define **errno** à **ENOMEM** se uma alocação de memória falhar; **EINVAL** será retornado se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) excede **heap_maxreq**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_calloc_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_callocd.c
// This program uses _calloc_dbg to allocate space for
// 40 long integers. It initializes each element to zero.

#include <stdio.h>
#include <malloc.h>
#include <crtdbg.h>

int main( void )
{
    long *bufferN, *bufferC;

    // Call _calloc_dbg to include the filename and line number
    // of our allocation request in the header and also so we can
    // allocate CLIENT type blocks specifically
    bufferN = (long *)_calloc_dbg( 40, sizeof(long), _NORMAL_BLOCK, __FILE__, __LINE__ );
    bufferC = (long *)_calloc_dbg( 40, sizeof(long), _CLIENT_BLOCK, __FILE__, __LINE__ );
    if( bufferN != NULL && bufferC != NULL )
        printf( "Allocated memory successfully\n" );
    else
        printf( "Problem allocating memory\n" );

    / _free_dbg must be called to free CLIENT type blocks
    free( bufferN );
    _free_dbg( bufferC, _CLIENT_BLOCK );
}
```

```Output
Allocated memory successfully
```

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[calloc](calloc.md)<br/>
[_malloc_dbg](malloc-dbg.md)<br/>
[_DEBUG](../../c-runtime-library/debug.md)<br/>
