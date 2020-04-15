---
title: calloc
description: A função c runtime library calloc aloca memória inicializada zero.
ms.date: 4/2/2020
api_name:
- calloc
- _o_calloc
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
- calloc
helpviewer_keywords:
- memory allocation, arrays
- calloc function
ms.assetid: 17bb79a1-98cf-4096-90cb-1f9365cd6829
ms.openlocfilehash: fb4f7d6dc059023d34cb0b811edf5dfb48cb7a34
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333644"
---
# <a name="calloc"></a>calloc

Aloca uma matriz na memória com elementos inicializados como 0.

## <a name="syntax"></a>Sintaxe

```C
void *calloc(
   size_t number,
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*number*<br/>
Número de elementos.

*Tamanho*<br/>
O comprimento, em bytes, de cada elemento.

## <a name="return-value"></a>Valor retornado

**calloc** retorna um ponteiro para o espaço alocado. O espaço de armazenamento ao qual o valor retornado apontou com certeza estará alinhado de modo adequado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo diferente de **vazio,** use um tipo de elenco sobre o valor de retorno.

## <a name="remarks"></a>Comentários

A função **calloc** aloca espaço de armazenamento para uma matriz de elementos *numéricos,* cada um dos bytes de *tamanho* de comprimento. Cada elemento é inicializado como 0.

**calloc** define **errno** ao **ENOMEM** se uma alocação de memória falhar ou se a quantidade de memória solicitada exceder **_HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Na implementação da Microsoft, se o *número* ou *tamanho* for zero, **o calloc** retorna um ponteiro para um bloco alocado de tamanho não zero. Uma tentativa de ler ou escrever através do ponteiro retornado leva a um comportamento indefinido.

**calloc** usa a função [C++ _set_new_mode](set-new-mode.md) para definir o novo modo *de manipulador*. O novo modo de manipulador indica se, em falha, **o calloc** deve chamar a nova rotina do manipulador conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, **o calloc** não chama a nova rotina de manipulador em falha na alocação de memória. Você pode substituir esse comportamento padrão para que, quando o **calloc** não aloque a memória, ele chame a nova rotina do manipulador da mesma forma que o **novo** operador faz quando falha pelo mesmo motivo. Para substituir o padrão, chame

```C
_set_new_mode(1);
```

no início do seu programa, ou link com *NEWMODE. OBJ* (ver [Opções de Link](../../c-runtime-library/link-options.md)).

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, **o calloc** resolve [_calloc_dbg](calloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**calloc** é `__declspec(noalias)` `__declspec(restrict)`marcado e , o que significa que a função é garantida para não modificar variáveis globais, e que o ponteiro retornado não é aliased. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**calloc**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_calloc.c
// This program uses calloc to allocate space for
// 40 long integers. It initializes each element to zero.

#include <stdio.h>
#include <malloc.h>

int main( void )
{
   long *buffer;

   buffer = (long *)calloc( 40, sizeof( long ) );
   if( buffer != NULL )
      printf( "Allocated 40 long integers\n" );
   else
      printf( "Can't allocate memory\n" );
   free( buffer );
}
```

```Output
Allocated 40 long integers
```

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[Livre](free.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
