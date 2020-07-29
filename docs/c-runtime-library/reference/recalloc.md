---
title: _recalloc
ms.date: 4/2/2020
api_name:
- _recalloc
- _o__recalloc
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
- _recalloc
- recalloc
helpviewer_keywords:
- _recalloc function
- recalloc function
ms.assetid: 1db8305a-3f03-418c-8844-bf9149f63046
ms.openlocfilehash: 45f483bcaa397969a81097768ebbd1ed4cda288b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226184"
---
# <a name="_recalloc"></a>_recalloc

Uma combinação de **realloc** e **calloc**. Realoca uma matriz na memória e inicializa seus elementos como 0.

## <a name="syntax"></a>Sintaxe

```C
void *_recalloc(
   void *memblock
   size_t num,
   size_t size
);
```

### <a name="parameters"></a>parâmetros

*memblock*<br/>
Ponteiro para o bloco de memória alocado anteriormente.

*number*<br/>
Número de elementos.

*size*<br/>
O comprimento, em bytes, de cada elemento.

## <a name="return-value"></a>Valor retornado

**_recalloc** retorna um **`void`** ponteiro para o bloco de memória realocado (e possivelmente movido).

Se não houver memória suficiente disponível para expandir o bloco para o tamanho fornecido, o bloco original permanecerá inalterado e será retornado **NULL** .

Se o tamanho solicitado for zero, o bloco apontado por *memblock* será liberado; o valor de retorno é **NULL**e *memblock* é deixado apontando para um bloco liberado.

O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo diferente de **`void`** , use uma conversão de tipo no valor de retorno.

## <a name="remarks"></a>Comentários

A função **_recalloc** altera o tamanho de um bloco de memória alocado. O argumento *memblock* aponta para o início do bloco de memória. Se *memblock* for **nulo**, **_recalloc** se comformará da mesma maneira que [calloc](calloc.md) e alocará um novo bloco de *number*  *  bytes de*tamanho* de número. Cada elemento é inicializado como 0. Se *memblock* não for **NULL**, ele deverá ser um ponteiro retornado por uma chamada anterior para **calloc**, [malloc](malloc.md)ou [realloc](realloc.md).

Como o novo bloco pode estar em um novo local de memória, o ponteiro retornado pelo **_recalloc** não é garantido como sendo o ponteiro passado pelo argumento *memblock* .

**_recalloc** define **errno** como **ENOMEM** se a alocação de memória falhar ou se a quantidade de memória solicitada excede **_HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

**recalloc** chama **realloc** para usar a função [_set_new_mode](set-new-mode.md) do C++ para definir o novo modo de manipulador. O novo modo de manipulador indica se, em caso de falha, a **realocação** é chamar a nova rotina do manipulador, conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, a **realocação** não chama a nova rotina do manipulador em caso de falha para alocar memória. Você pode substituir esse comportamento padrão para que, quando **_recalloc** falhar ao alocar memória, a **realocação** chame a nova rotina do manipulador da mesma maneira que o **`new`** operador faz quando ele falha pelo mesmo motivo. Para substituir o padrão, chame

```C
_set_new_mode(1);
```

no início do programa ou vincule com NEWMODE.OBJ.

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, **_recalloc** é resolvido para [_recalloc_dbg](recalloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**_recalloc** é marcado `__declspec(noalias)` e `__declspec(restrict)` , o que significa que a função tem a garantia de não modificar variáveis globais e que o ponteiro retornado não tem um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_recalloc**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[_recalloc_dbg](recalloc-dbg.md)<br/>
[_aligned_recalloc](aligned-recalloc.md)<br/>
[_aligned_offset_recalloc](aligned-offset-recalloc.md)<br/>
[informações](free.md)<br/>
[Opções de link](../../c-runtime-library/link-options.md)<br/>
