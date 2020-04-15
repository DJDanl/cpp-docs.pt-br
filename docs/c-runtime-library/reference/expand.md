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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 7f2a789bc5f475411808bc00a4280b7573b67cf2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347539"
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

*Tamanho*<br/>
Novo tamanho em bytes.

## <a name="return-value"></a>Valor retornado

**_expand** retorna um ponteiro vazio para o bloco de memória realocado. **_expand**, ao contrário **do realloc**, não pode mover um bloco para alterar seu tamanho. Assim, se houver memória suficiente disponível para expandir o bloco sem movê-lo, o parâmetro *memblock* para **_expand** é o mesmo que o valor de retorno.

**_expand** retorna **NULO** quando um erro é detectado durante sua operação. Por exemplo, se **_expand** for usado para encolher um bloco de memória, ele poderá detectar corrupção no pequeno heap de bloco ou em um ponteiro de bloco inválido e retornar **NULL**.

Se houver memória insuficiente disponível para expandir o bloco para o tamanho dado sem movê-lo, a função retorna **NULL**. **_expand** nunca retorna um bloco expandido para um tamanho menor do que o solicitado. Se ocorrer uma falha, **errno** indica a natureza da falha. Para obter mais informações sobre **errno,** consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para verificar o novo tamanho do item, use **_msize**. Para obter um ponteiro para um tipo diferente de **vazio,** use um tipo de elenco sobre o valor de retorno.

## <a name="remarks"></a>Comentários

A função **_expand** altera o tamanho de um bloco de memória previamente alocado, tentando expandir ou contrair o bloco sem mover sua localização no heap. O *parâmetro memblock* aponta para o início do bloco. O parâmetro *de tamanho* dá o novo tamanho do bloco, em bytes. O conteúdo do bloco é inalterado até o menor dos tamanhos novos e antigos. *memblock* não deve ser um bloco que foi libertado.

> [!NOTE]
> Em plataformas de 64 bits, **_expand** pode não contratar o bloco se o novo tamanho for menor que o tamanho atual; em particular, se o bloco tiver menos de 16K de tamanho e, portanto, alocado no Heap de Baixa Fragmentação, **_expand** deixa o bloco inalterado e retorna *memblock*.

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, **_expand** resolve [_expand_dbg](expand-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

Essa função valida seus parâmetros. Se *memblock* for um ponteiro nulo, esta função invoca um manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **NULL**. Se *o tamanho* for maior que **_HEAP_MAXREQ,** **errno** está definido como **ENOMEM** e a função retorna **NULL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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
[Livre](free.md)<br/>
[malloc](malloc.md)<br/>
[_msize](msize.md)<br/>
[realloc](realloc.md)<br/>
