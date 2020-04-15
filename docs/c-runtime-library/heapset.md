---
title: _heapset
ms.date: 11/04/2016
api_name:
- _heapset
api_location:
- msvcr90.dll
- msvcr80.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr120.dll
- msvcr100.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _heapset
- heapset
helpviewer_keywords:
- checking heap
- heapset function
- heaps, checking
- debugging [CRT], heap-related problems
- _heapset function
ms.assetid: 9667eeb0-55bc-4c19-af5f-d1fd0a142b3c
ms.openlocfilehash: 2a0aea37237f04939579eb059a42dd33771339ad
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351270"
---
# <a name="_heapset"></a>_heapset

Verifica heaps quanto à consistência mínima e configura as entradas livres com um valor especificado.

> [!IMPORTANT]
> Essa função está obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.

## <a name="syntax"></a>Sintaxe

```
int _heapset(
   unsigned int fill
);
```

#### <a name="parameters"></a>Parâmetros

*Preencher*<br/>
Caractere de preenchimento.

## <a name="return-value"></a>Valor retornado

`_heapset` retorna uma das seguintes constantes de manifesto de inteiro definidas em Malloc.h.

|||
|-|-|
| `_HEAPBADBEGIN`  | As informações do cabeçalho inicial são inválidas ou não foram encontradas.  |
| `_HEAPBADNODE`  | Heap danificado ou nó inválido encontrado.  |
| `_HEAPEMPTY`  | Heap não inicializado.  |
| `_HEAPOK`  | O heap parece ser consistente.  |

Além disso, se ocorrer um erro, `_heapset` definirá `errno` como `ENOSYS`.

## <a name="remarks"></a>Comentários

A função `_heapset` mostra locais com memória livre ou nós que foram substituídos acidentalmente.

`_heapset` verifica a consistência mínima no heap e define cada byte das entradas livres do heap para o valor `fill`. Esse valor conhecido mostra quais locais de memória do heap contêm nós livres e quais contêm dados que foram gravados acidentalmente na memória liberada. Se o sistema operacional não der suporte a `_heapset` (por exemplo, Windows 98), a função retornará `_HEAPOK` e definirá `errno` como `ENOSYS`.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|`_heapset`|\<malloc.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.

## <a name="example"></a>Exemplo

```c
// crt_heapset.c
// This program checks the heap and
// fills in free entries with the character 'Z'.

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   int heapstatus;
   char *buffer;

   if( (buffer = malloc( 1 )) == NULL ) // Make sure heap is
      exit( 0 );                        //    initialized
   heapstatus = _heapset( 'Z' );        // Fill in free entries
   switch( heapstatus )
   {
   case _HEAPOK:
      printf( "OK - heap is fine\n" );
      break;
   case _HEAPEMPTY:
      printf( "OK - heap is empty\n" );
      break;
   case _HEAPBADBEGIN:
      printf( "ERROR - bad start of heap\n" );
      break;
   case _HEAPBADNODE:
      printf( "ERROR - bad node in heap\n" );
      break;
   }
   free( buffer );
}
```

```Output
OK - heap is fine
```

## <a name="see-also"></a>Confira também

[Alocação de memória](../c-runtime-library/memory-allocation.md)<br/>
[_heapadd](../c-runtime-library/heapadd.md)<br/>
[_heapchk](../c-runtime-library/reference/heapchk.md)<br/>
[_heapmin](../c-runtime-library/reference/heapmin.md)<br/>
[_heapwalk](../c-runtime-library/reference/heapwalk.md)
