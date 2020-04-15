---
title: _heapchk
ms.date: 4/2/2020
api_name:
- _heapchk
- _o__heapchk
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
- _heapchk
- heapchk
helpviewer_keywords:
- debugging [CRT], heap-related problems
- consistency checking of heaps
- heapchk function
- heaps, checking consistency
- _heapchk function
ms.assetid: 859619a5-1e35-4f02-9e09-11d9fa266ec0
ms.openlocfilehash: 21c7f9e22728109676d3fc611405ccd43ac773f8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344053"
---
# <a name="_heapchk"></a>_heapchk

Executa verificações de consistência no heap.

## <a name="syntax"></a>Sintaxe

```C
int _heapchk( void );
```

## <a name="return-value"></a>Valor retornado

**_heapchk** retorna uma das seguintes constantes de manifesto inteiro definidas em Malloc.h.

|Valor retornado|Condição|
|-|-|
| **_HEAPBADBEGIN** | As informações de cabeçalho iniciais são inválidas ou não foram encontradas. |
| **_HEAPBADNODE** | Um nó inválido foi encontrado ou o heap está danificado. |
| **_HEAPBADPTR** | O ponteiro para o heap não é válido. |
| **_HEAPEMPTY** | O heap não foi inicializado. |
| **_HEAPOK** | O heap parece ser consistente. |

Além disso, se ocorrer um erro, **_heapchk** define **errno** para **ENOSYS**.

## <a name="remarks"></a>Comentários

A função **_heapchk** ajuda a depurar problemas relacionados a pilhas, verificando a consistência mínima do heap. Se o sistema operacional não suportar **_heapchk**(por exemplo, Windows 98), a função retorna **_HEAPOK** e define **errno** para **ENOSYS**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_heapchk**|\<malloc.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_heapchk.c
// This program checks the heap for
// consistency and prints an appropriate message.

#include <malloc.h>
#include <stdio.h>

int main( void )
{
   int  heapstatus;
   char *buffer;

   // Allocate and deallocate some memory
   if( (buffer = (char *)malloc( 100 )) != NULL )
      free( buffer );

   // Check heap status
   heapstatus = _heapchk();
   switch( heapstatus )
   {
   case _HEAPOK:
      printf(" OK - heap is fine\n" );
      break;
   case _HEAPEMPTY:
      printf(" OK - heap is empty\n" );
      break;
   case _HEAPBADBEGIN:
      printf( "ERROR - bad start of heap\n" );
      break;
   case _HEAPBADNODE:
      printf( "ERROR - bad node in heap\n" );
      break;
   }
}
```

```Output
OK - heap is fine
```

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[_heapadd](../../c-runtime-library/heapadd.md)<br/>
[_heapmin](heapmin.md)<br/>
[_heapset](../../c-runtime-library/heapset.md)<br/>
[_heapwalk](heapwalk.md)<br/>
