---
title: realloc
description: Referência de API para realloc (); que Realoca os blocos de memória.
ms.date: 9/11/2020
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
ms.openlocfilehash: c68909b2f5d73959465d63af522ceeb00c8ce23e
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90075810"
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

*`memblock`*\
Ponteiro para o bloco de memória alocado anteriormente.

*`size`*\
Novo tamanho em bytes.

## <a name="return-value"></a>Valor de retorno

**`realloc`** Retorna um **`void`** ponteiro para o bloco de memória realocada (e possivelmente movida).

Se não houver memória suficiente disponível para expandir o bloco para o tamanho fornecido, o bloco original permanecerá inalterado e **`NULL`** será retornado.

Se *`size`* for zero, o bloco apontado por *`memblock`* será liberado; o valor de retorno será **`NULL`** e *`memblock`* será deixado apontando para um bloco liberado.

O valor de retorno aponta para um espaço de armazenamento que é adequadamente alinhado para o armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo diferente de **`void`** , use uma conversão de tipo no valor de retorno.

## <a name="remarks"></a>Comentários

> [!NOTE]
> **`realloc`** Não foi atualizado para implementar o comportamento de C17 porque o novo comportamento não é compatível com o sistema operacional Windows.

A **`realloc`** função altera o tamanho de um bloco de memória alocado. O *`memblock`* argumento aponta para o início do bloco de memória. Se *`memblock`* for **`NULL`** , **`realloc`** comporta-se da mesma forma que **`malloc`** e aloca um novo bloco de *`size`* bytes. Se *`memblock`* não for **`NULL`** , deve ser um ponteiro retornado por uma chamada anterior para **`calloc`** , **`malloc`** ou **`realloc`** .

O *`size`* argumento fornece o novo tamanho do bloco, em bytes. O conteúdo do bloco fica inalterado até o menor dos tamanhos novos e antigos, embora o novo bloco possa estar em um local diferente. Como o novo bloco pode estar em um novo local de memória, o ponteiro retornado por **`realloc`** não é garantido como sendo o ponteiro passado pelo *`memblock`* argumento. **`realloc`** não oferece nenhuma memória alocada recentemente no caso do crescimento do buffer.

**`realloc`** define **`errno`** como **`ENOMEM`** se a alocação de memória falhar ou se a quantidade de memória solicitada excede **`_HEAP_MAXREQ`** . Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

**`realloc`** chamadas para **`malloc`** usar a função de [_set_new_mode](set-new-mode.md) C++ para definir o novo modo de manipulador. O novo modo de manipulador indica se, em caso de falha, **`malloc`** é chamar a nova rotina do manipulador, conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, **`malloc`** o não chama a nova rotina do manipulador em caso de falha para alocar memória. Você pode substituir esse comportamento padrão para que, quando **`realloc`** o falhar para alocar memória, **`malloc`** chame a nova rotina do manipulador da mesma maneira que o **`new`** operador faz quando ele falha pelo mesmo motivo. Para substituir o padrão, chame

```C
_set_new_mode(1);
```

no início do seu programa ou vincule com NEWMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)).

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, o **`realloc`** resolve para [_realloc_dbg](realloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**`realloc`** é marcado `__declspec(noalias)` e `__declspec(restrict)` , o que significa que a função tem a garantia de não modificar variáveis globais e que o ponteiro retornado não tem um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**`realloc`**|\<stdlib.h> e \<malloc.h>|

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

[Alocação de memória](../../c-runtime-library/memory-allocation.md)\
[calloc](calloc.md)\
[informações](free.md)\
[malloc](malloc.md)
