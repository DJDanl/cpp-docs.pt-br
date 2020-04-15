---
title: _aligned_offset_recalloc
ms.date: 4/2/2020
api_name:
- _aligned_offset_recalloc
- _o__aligned_offset_recalloc
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
- aligned_offset_recalloc
- _aligned_offset_recalloc
helpviewer_keywords:
- aligned_offset_recalloc function
- _aligned_offset_recalloc function
ms.assetid: a258f54e-eeb4-4853-96fc-007d710f98e9
ms.openlocfilehash: 4c710712138d07191468cdc7ef02fc75e2f46dad
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81350539"
---
# <a name="_aligned_offset_recalloc"></a>_aligned_offset_recalloc

Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](aligned-malloc.md) ou [_aligned_offset_malloc](aligned-offset-malloc.md) e inicializa a memória como 0.

## <a name="syntax"></a>Sintaxe

```C
void * _aligned_offset_recalloc(
   void *memblock,
   size_t num,
   size_t size,
   size_t alignment,
   size_t offset
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
O ponteiro do bloco de memória atual.

*number*<br/>
Número de elementos.

*Tamanho*<br/>
O comprimento, em bytes, de cada elemento.

*alinhamento*<br/>
O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.

*deslocamento*<br/>
O deslocamento na alocação de memória para forçar o alinhamento.

## <a name="return-value"></a>Valor retornado

**_aligned_offset_recalloc** retorna um ponteiro vazio para o bloco de memória realocado (e possivelmente movido). O valor de retorno é **NULO** se o tamanho for zero e o argumento de buffer não for **NULO,** ou se não houver memória disponível suficiente para expandir o bloco para o tamanho dado. No primeiro caso, o bloco original é liberado. No segundo caso, ele permanece inalterado. O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.

**_aligned_offset_recalloc** é `__declspec(noalias)` `__declspec(restrict)`marcado e , o que significa que a função é garantida para não modificar variáveis globais e que o ponteiro retornado não é aliased. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

## <a name="remarks"></a>Comentários

Assim [como _aligned_offset_malloc,](aligned-offset-malloc.md) **_aligned_offset_recalloc** permite que uma estrutura seja alinhada em um deslocamento dentro da estrutura.

**_aligned_offset_recalloc** é baseado em **malloc**. Para obter mais informações sobre como usar **_aligned_offset_malloc,** consulte [malloc](malloc.md). Se *o bloco é* **NULO,** a função chama **_aligned_offset_malloc** internamente.

Esta função define **errno** ao **ENOMEM** se a alocação de memória falhou ou se o tamanho solicitado *(tamanho**de número)* * for maior que **_HEAP_MAXREQ**. Para obter mais informações sobre **errno,** consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, **_aligned_offset_recalloc** valida seus parâmetros. Se *o alinhamento* não for uma potência de 2 ou se a *compensação* for maior ou igual ao tamanho e não zero solicitados, esta função invoca o manipulador de parâmetros inválido, conforme descrito na Validação de [Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função retorna **NULL** e define **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_aligned_offset_recalloc**|\<malloc.h>|

## <a name="see-also"></a>Confira também

[Alinhamento de dados](../../c-runtime-library/data-alignment.md)<br/>
[_recalloc](recalloc.md)<br/>
[_aligned_recalloc](aligned-recalloc.md)<br/>
