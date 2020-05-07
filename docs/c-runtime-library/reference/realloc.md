---
title: realloc
ms.date: 4/2/2020
api_name:
- realloc
- _o_realloc
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
- api-ms-win-crt-heap-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _brealloc
- _nrealloc
- realloc
- _frealloc
helpviewer_keywords:
- _brealloc function
- realloc function
- nrealloc function
- frealloc function
- _nrealloc function
- memory blocks, reallocating
- memory, reallocating
- _frealloc function
- reallocate memory blocks
ms.assetid: 2b2239de-810b-4b11-9438-32ab0a244185
ms.openlocfilehash: 15c818ee6f70d02fb9b63f12deef6b1bf3698322
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82917935"
---
# <a name="realloc"></a>realloc

Realocar blocos de memória.

## <a name="syntax"></a>Sintaxe

```C
void *realloc(
   void *memblock,
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Ponteiro para o bloco de memória alocado anteriormente.

*size*<br/>
Novo tamanho em bytes.

## <a name="return-value"></a>Valor retornado

**realloc** retorna um ponteiro **void** para o bloco de memória realocado (e possivelmente movido).

Se não houver memória suficiente disponível para expandir o bloco para o tamanho fornecido, o bloco original permanecerá inalterado e será retornado **NULL** .

Se o *tamanho* for zero, o bloco apontado por *memblock* será liberado; o valor de retorno é **NULL**e *memblock* é deixado apontando para um bloco liberado.

O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo diferente de **void**, use uma conversão de tipo no valor de retorno.

## <a name="remarks"></a>Comentários

A função de **realocação** altera o tamanho de um bloco de memória alocado. O argumento *memblock* aponta para o início do bloco de memória. Se *memblock* for **NULL**, a **realocação** se comporta da mesma forma que **malloc** e aloca um novo bloco de bytes de *tamanho* . Se *memblock* não for **NULL**, ele deverá ser um ponteiro retornado por uma chamada anterior para **calloc**, **malloc**ou **realloc**.

O argumento *size* fornece o novo tamanho do bloco, em bytes. O conteúdo do bloco fica inalterado até o menor dos tamanhos novos e antigos, embora o novo bloco possa estar em um local diferente. Como o novo bloco pode estar em um novo local de memória, o ponteiro retornado pela **realocação** não é garantido como sendo o ponteiro passado pelo argumento *memblock* . a **realocação** não Zera a memória alocada recentemente no caso do crescimento do buffer.

**realloc** define **errno** como **ENOMEM** se a alocação de memória falhar ou se a quantidade de memória solicitada excede **_HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

**realloc** chama **malloc** para usar a função [_set_new_mode](set-new-mode.md) do C++ para definir o novo modo de manipulador. O novo modo de manipulador indica se, em caso de falha, **malloc** é chamar a nova rotina do manipulador, conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, o **malloc** não chama a nova rotina do manipulador em caso de falha para alocar memória. Você pode substituir esse comportamento padrão para que, quando a **realocação** falhar ao alocar memória, **malloc** chame a nova rotina do manipulador da mesma maneira que o **novo** operador faz quando ele falha pelo mesmo motivo. Para substituir o padrão, chame

```C
_set_new_mode(1);
```

no início do seu programa ou vincule com NEWMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)).

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, a **realocação** é resolvida para [_realloc_dbg](realloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

a **realocação** é marcada `__declspec(noalias)` e `__declspec(restrict)`, o que significa que a função tem a garantia de não modificar variáveis globais e que o ponteiro retornado não tem um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**realloc**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_realloc.c
// This program allocates a block of memory for
// buffer and then uses _msize to display the size of that
// block. Next, it uses realloc to expand the amount of
// memory used by buffer and then calls _msize again to
// display the new amount of memory allocated to buffer.

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main( void )
{
   long *buffer, *oldbuffer;
   size_t size;

   if( (buffer = (long *)malloc( 1000 * sizeof( long ) )) == NULL )
      exit( 1 );

   size = _msize( buffer );
   printf_s( "Size of block after malloc of 1000 longs: %u\n", size );

   // Reallocate and show new size:
   oldbuffer = buffer;     // save pointer in case realloc fails
   if( (buffer = realloc( buffer, size + (1000 * sizeof( long )) ))
        ==  NULL )
   {
      free( oldbuffer );  // free original block
      exit( 1 );
   }
   size = _msize( buffer );
   printf_s( "Size of block after realloc of 1000 more longs: %u\n",
            size );

   free( buffer );
   exit( 0 );
}
```

```Output
Size of block after malloc of 1000 longs: 4000
Size of block after realloc of 1000 more longs: 8000
```

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[informações](free.md)<br/>
[malloc](malloc.md)<br/>
