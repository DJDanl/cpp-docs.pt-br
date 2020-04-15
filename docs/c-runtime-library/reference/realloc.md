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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 964c465a95d44de9d8a4d399f23ec43f8a3a6692
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332928"
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

*Tamanho*<br/>
Novo tamanho em bytes.

## <a name="return-value"></a>Valor retornado

**realloc** retorna um ponteiro **vazio** para o bloco de memória realocado (e possivelmente movido).

Se não houver memória disponível suficiente para expandir o bloco para o tamanho dado, o bloco original será deixado inalterado e **NULL** será devolvido.

Se *o tamanho* for zero, então o bloco apontado por *memblock* é liberado; o valor de retorno é **NULL**, e *memblock* é deixado apontando para um bloco liberado.

O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo diferente de **vazio,** use um tipo de elenco sobre o valor de retorno.

## <a name="remarks"></a>Comentários

A função **realloc** altera o tamanho de um bloco de memória alocado. O *argumento memblock* aponta para o início do bloco de memória. Se *o memblock* for **NULL**, **realloc** se comporta da mesma forma que **malloc** e aloca um novo bloco de bytes de *tamanho.* Se *o memblock* não for **NULO,** deve ser um ponteiro devolvido por uma chamada anterior para **calloc**, **malloc**ou **realloc**.

O argumento *de tamanho* dá o novo tamanho do bloco, em bytes. O conteúdo do bloco fica inalterado até o menor dos tamanhos novos e antigos, embora o novo bloco possa estar em um local diferente. Como o novo bloco pode estar em um novo local de memória, o ponteiro retornado pelo **realloc** não é garantido ser o ponteiro passado através do argumento *memblock.* **realloc** não zero memória recém-alocada no caso de crescimento de buffer.

**realloc** define **errno** ao **ENOMEM** se a alocação de memória falhar ou se a quantidade de memória solicitada exceder **_HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

**realloc** chama **malloc** para usar a função C++ [_set_new_mode](set-new-mode.md) para definir o novo modo de manipulador. O novo modo de manipulador indica se, em falha, **malloc** deve chamar a nova rotina de manipulador conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, **o malloc** não chama a nova rotina de manipulador na falha de alocar memória. Você pode substituir esse comportamento padrão para que, quando **o realloc** não aloca memória, **o malloc** chame a nova rotina de manipulador da mesma forma que o **novo** operador faz quando falha pelo mesmo motivo. Para substituir o padrão, chame

```C
_set_new_mode(1);
```

no início do seu programa ou vincule com NEWMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)).

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas c de tempo de execução, **realloc** resolve [_realloc_dbg](realloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**realloc** é `__declspec(noalias)` `__declspec(restrict)`marcado e , o que significa que a função é garantida para não modificar variáveis globais, e que o ponteiro retornado não é aliased. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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
[Livre](free.md)<br/>
[malloc](malloc.md)<br/>
