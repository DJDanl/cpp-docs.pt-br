---
title: _expand
ms.date: 4/2/2020
api_name:
- _expand
- _o__expand
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
- _bexpand
- fexpand
- expand
- nexpand
- _fexpand
- _nexpand
- bexpand
- _expand
helpviewer_keywords:
- memory blocks, changing size
- _expand function
- expand function
ms.assetid: 4ac55410-39c8-45c7-bccd-3f1042ae2ed3
ms.openlocfilehash: 8878bb046a122b545f969dd067c37eeb97126387
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82920251"
---
# <a name="_expand"></a>_expand

Altera o tamanho de um bloco de memória.

## <a name="syntax"></a>Sintaxe

```C
void *_expand(
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

**_expand** retorna um ponteiro void para o bloco de memória realocada. **_expand**, diferente de **realloc**, não pode mover um bloco para alterar seu tamanho. Portanto, se houver memória suficiente disponível para expandir o bloco sem movê-lo, o parâmetro *memblock* para **_expand** será o mesmo que o valor de retorno.

**_expand** retorna **NULL** quando um erro é detectado durante sua operação. Por exemplo, se **_expand** for usado para reduzir um bloco de memória, ele poderá detectar corrupção no pequeno heap de blocos ou um ponteiro de bloco inválido e retornar **NULL**.

Se não houver memória suficiente disponível para expandir o bloco para o tamanho especificado sem movê-lo, a função retornará **NULL**. **_expand** nunca retorna um bloco expandido para um tamanho menor que o solicitado. Se ocorrer uma falha, **errno** indica a natureza da falha. Para obter mais informações sobre **errno**, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para verificar o novo tamanho do item, use **_msize**. Para obter um ponteiro para um tipo diferente de **void**, use uma conversão de tipo no valor de retorno.

## <a name="remarks"></a>Comentários

A função **_expand** altera o tamanho de um bloco de memória alocado anteriormente tentando expandir ou contrair o bloco sem mover seu local no heap. O parâmetro *memblock* aponta para o início do bloco. O parâmetro *size* fornece o novo tamanho do bloco, em bytes. O conteúdo do bloco é inalterado até o menor dos tamanhos novos e antigos. *memblock* não deve ser um bloco que foi liberado.

> [!NOTE]
> Em plataformas de 64 bits, **_expand** pode não contratar o bloco se o novo tamanho for menor que o tamanho atual; em particular, se o bloco tiver sido menor que 16K em tamanho e, portanto, alocado no heap de baixa fragmentação, **_expand** deixar o bloco inalterado e retornar *memblock*.

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, **_expand** é resolvido para [_expand_dbg](expand-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

Essa função valida seus parâmetros. Se *memblock* for um ponteiro NULL, essa função invocará um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **NULL**. Se *size* for maior que **_HEAP_MAXREQ**, **errno** será definido como **ENOMEM** e a função retornará **NULL**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_expand**|\<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_expand.c

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main( void )
{
   char *bufchar;
   printf( "Allocate a 512 element buffer\n" );
   if( (bufchar = (char *)calloc( 512, sizeof( char ) )) == NULL )
      exit( 1 );
   printf( "Allocated %d bytes at %Fp\n",
         _msize( bufchar ), (void *)bufchar );
   if( (bufchar = (char *)_expand( bufchar, 1024 )) == NULL )
      printf( "Can't expand" );
   else
      printf( "Expanded block to %d bytes at %Fp\n",
            _msize( bufchar ), (void *)bufchar );
   // Free memory
   free( bufchar );
   exit( 0 );
}
```

```Output
Allocate a 512 element buffer
Allocated 512 bytes at 002C12BC
Expanded block to 1024 bytes at 002C12BC
```

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[informações](free.md)<br/>
[malloc](malloc.md)<br/>
[_msize](msize.md)<br/>
[realloc](realloc.md)<br/>
