---
title: calloc
ms.date: 11/04/2016
apiname:
- calloc
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- calloc
helpviewer_keywords:
- memory allocation, arrays
- calloc function
ms.assetid: 17bb79a1-98cf-4096-90cb-1f9365cd6829
ms.openlocfilehash: 59aa535136cf32ea5dd68b8917ec969eee41e2ae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62347724"
---
# <a name="calloc"></a>calloc

Aloca uma matriz na memória com elementos inicializados como 0.

## <a name="syntax"></a>Sintaxe

```C
void *calloc(
   size_t num,
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*number*<br/>
Número de elementos.

*size*<br/>
O comprimento, em bytes, de cada elemento.

## <a name="return-value"></a>Valor de retorno

**calloc** retorna um ponteiro para o espaço alocado. O espaço de armazenamento ao qual o valor retornado apontou com certeza estará alinhado de modo adequado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo diferente de **void**, use uma conversão no valor de retorno de tipo.

## <a name="remarks"></a>Comentários

O **calloc** função aloca espaço de armazenamento para uma matriz de *número* elementos, cada um comprimento *tamanho* bytes. Cada elemento é inicializado como 0.

**calloc** define **errno** à **ENOMEM** se uma alocação de memória falhar ou se a quantidade de memória solicitada exceder **heap_maxreq**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

**calloc** chamadas **malloc** para usar o C++ [set_new_mode](set-new-mode.md) função para definir o novo modo do manipulador. O novo modo do manipulador indica se, em caso de falha, **malloc** é chamar a nova rotina do manipulador conforme definido pela [set_new_handler](set-new-handler.md). Por padrão, **malloc** não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando **calloc** falhar ao alocar memória, **malloc** chame a nova rotina do manipulador da mesma forma que o **novo** operador faz Quando ele falha pelo mesmo motivo. Para substituir o padrão, chame

```C
_set_new_mode(1);
```

com antecedência em seu programa ou vincule com NEWMODE. OBJ (consulte [Opções de link](../../c-runtime-library/link-options.md)).

Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas de tempo de execução C, **calloc** resolve [calloc_dbg](calloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**calloc** está marcada `__declspec(noalias)` e `__declspec(restrict)`, que significa que a função não é garantido que modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**calloc**|\<stdlib.h> e \<malloc.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[free](free.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
